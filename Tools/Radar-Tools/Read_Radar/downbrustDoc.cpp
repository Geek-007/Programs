// downbrustDoc.cpp : implementation of the CDownbrustDoc class
//

#include "stdafx.h"
#include "downbrust.h"
#include "datahead.h"
#include "downbrustDoc.h"
#include "math.h"
#include <malloc.h>
#include "Windows.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDownbrustDoc

IMPLEMENT_DYNCREATE(CDownbrustDoc, CDocument)

BEGIN_MESSAGE_MAP(CDownbrustDoc, CDocument)
	//{{AFX_MSG_MAP(CDownbrustDoc)
	ON_COMMAND(ID_FILE_OPEN, OnFileOpen)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDownbrustDoc construction/destruction

CDownbrustDoc::CDownbrustDoc()
{
	// TODO: add one-time construction code here
}

CDownbrustDoc::~CDownbrustDoc()
{
	if(pOneRadial!=NULL)
	{
		delete pOneRadial;
		pOneRadial=NULL;
		
	}
}

BOOL CDownbrustDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CDownbrustDoc serialization

void CDownbrustDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CDownbrustDoc diagnostics

#ifdef _DEBUG
void CDownbrustDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDownbrustDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDownbrustDoc commands

float CDownbrustDoc::DecodeRef(unsigned char code)
{
	if(code==CODE_INVALID)		return VALUE_INVALID;
	else if(code==CODE_RANFOLD)	return VALUE_RANFOLD;
	else						
		return (float((code-2.)/2.-32.5));
}

float CDownbrustDoc::DecodeVel(unsigned char code, short ResType)
{
	if(code==CODE_INVALID)		return VALUE_INVALID;
	else if(code==CODE_RANFOLD)	return VALUE_RANFOLD;
	else						
	{
		if(ResType==RES_POINT_FIVE) //0.5 m/s 
			return (float((code-2.)/2.-63.5));
		else
			return (float((code-2)-127.));
	}
}

float CDownbrustDoc::DecodeSpw(unsigned char code)
{
	if(code==CODE_INVALID)		return VALUE_INVALID;
	else if(code==CODE_RANFOLD)	return VALUE_RANFOLD;
	else						
		return (float((code-2.)/2.-63.5));
}

void CDownbrustDoc::OnFileOpen() 
{
	// TODO: Add your command handler code here
	CString filter;
	filter="717�״������ļ�|*.???|";
	CFileDialog dlg(TRUE,NULL,"*.*",OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,filter);
	if(dlg.DoModal()==IDOK)
	{
		addressStr.Format("%s",dlg.GetPathName());
		lpszFileName=dlg.GetFileName();
		m_bDataLoad = Readdata_mestar();    //�������ݣ�����bool�ͱ���m_bDataLoad
		shibie=false;
		
		if(m_bDataLoad)
			AfxMessageBox("���ݼ��سɹ�");
		else
			AfxMessageBox("���ݼ���ʧ��");
	}
}

bool CDownbrustDoc::Readdata_mestar()
{
	FILE *fp=0;

	int FstBin,LstBin,BinNum;
	float CurAz,CurEl,time;
	int ptrPos;
	size_t readSize;
	int fileEndFlag;
	int lastAZindex;
	int TEMLASTAZ;


	bool VolBeg=false;
	bool VolEnd=false;
	bool interpol=false;

	bool RFlag,VFlag,WFlag;

	fp = fopen(lpszFileName,"rb");//���ļ�
	if(fp==0) return false;
	
	pOneRadial = new _tagRDABaseDataHead;//����������ļ�ͷ
	if(pOneRadial==NULL) 
	return false; 

	//��ʼ������ 
	for(ElIndex=0; ElIndex<MaxCuts; ElIndex++)//ElIndex���Ǻ�
	{
		ZBinNumber[ElIndex]=0;//ZBinNumber ���������ӿ���
		VBinNumber[ElIndex]=0;
		ZBinWidth[ElIndex]=0;
		for(AzIndex=0; AzIndex<MaxRads; AzIndex++)//AzIndex��λ��
		{
			for(BnIndex=0; BnIndex<RGates; BnIndex++)//BnIndex���
				RData[ElIndex][AzIndex][BnIndex] = VALUE_INVALID;//VALUE_INVALID=-999.
			for(BnIndex=0; BnIndex<VGates; BnIndex++)
				VData[ElIndex][AzIndex][BnIndex] = VALUE_INVALID;
			for(BnIndex=0; BnIndex<WGates; BnIndex++)
				WData[ElIndex][AzIndex][BnIndex] = VALUE_INVALID;
		}

		Elevation[ElIndex]=VALUE_INVALID;//Elevation�������
	}

    ///////////////////////////////////////////////////////////////////////////////////////
	do
	{
		//Initialize flags��ʼ����־
		RFlag=VFlag=WFlag=false;

		readSize = fread(pOneRadial,sizeof(_tagRDABaseDataHead),1,fp);//fread ����ֵ�Ǽ�¼��
		fileEndFlag = feof(fp);//�ļ�����������1����������ֵ

		//Start a volume scanuuu

		if(pOneRadial->RadialStatus == VOL_BEG) //RadialStatus����״̬VOL_BEG=3����ɨ��ʼ״̬��־
		{
			ElIndex=0;
			CurEl = float((pOneRadial->El/8.)*(180./4096.));
			Elevation[ElIndex] = CurEl;//��ȡ����
			ZBinNumber[ElIndex]=pOneRadial->GatesNumberOfReflectivity;//��ȡ����
			VBinNumber[ElIndex]=pOneRadial->GatesNumberOfDoppler;
			ZBinWidth[ElIndex]=pOneRadial->GateSizeOfReflectivity;
			time=pOneRadial->mSeconds;//��ȡʱ��
			VolBeg = true;
			AzIndex=-1;
		}
		//Find the beginning of the volume scan
		if(!VolBeg) continue;		

		//Start an elevation ��ʼ��ĳ���ǲ�����
		if(pOneRadial->RadialStatus == ELV_BEG)//RadialStatus���ǿ�ʼ״̬��־,ELV_BEG=0
		{
			CurEl = float((pOneRadial->El/8.)*(180./4096.));
			if(CurEl-Elevation[ElIndex] > 0.4)
			{//different elevation angle
				ElIndex++;
				Elevation[ElIndex] = CurEl;
				ZBinNumber[ElIndex]=pOneRadial->GatesNumberOfReflectivity;
				VBinNumber[ElIndex]=pOneRadial->GatesNumberOfDoppler;
				ZBinWidth[ElIndex]=pOneRadial->GateSizeOfReflectivity;
			}
			AzIndex=-1;
		}
		//Start an elevation
		if(pOneRadial->RadialStatus == VOL_END)
			VolEnd=true;

		//Calculate azimuth angle and Azimuth Index
		CurAz = float((pOneRadial->Az/8.)*(180./4096.));
		if(CurAz >= 360.) 
			CurAz = float(CurAz-360.);
			AzIndex = int(CurAz+0.5);
		if (pOneRadial->RadialStatus == ELV_BEG||pOneRadial->RadialStatus == VOL_BEG)
		{
			//��ʼ��
			lastAZindex=AzIndex;
		}
		else
		{
			if (lastAZindex==AzIndex)
			{
				AzIndex=int(CurAz+1);
			}
			else 
			{
				TEMLASTAZ=lastAZindex+2;
				if (TEMLASTAZ>=360)
				{
					TEMLASTAZ=TEMLASTAZ-360;
				}
				if (TEMLASTAZ==AzIndex)
				{
					AzIndex=int(CurAz);
				}

			}

		}
		if (AzIndex==360)
		{
			AzIndex=0;
		}
	
		//what kind of data in this cut
		if(pOneRadial->PtrOfReflectivity !=0) RFlag=true;
		if(pOneRadial->PtrOfVelocity !=0) VFlag=true;
		if(pOneRadial->PtrOfSpectrumWidth !=0) WFlag=true;
		//Save reflectivity data into the array
		if(RFlag)
		{
			//Get first bin, last bin, and number of bins
			FstBin = int(pOneRadial->RangeToFirstGateOfRef/pOneRadial->GateSizeOfReflectivity+0.5);
			BinNum = pOneRadial->GatesNumberOfReflectivity;
			if(FstBin<0)
			{
				BinNum = FstBin+BinNum;
				FstBin = -1*FstBin;
			}
			LstBin = FstBin + BinNum;
			ptrPos = pOneRadial->PtrOfReflectivity;

			//Save data
			for(BnIndex=FstBin; BnIndex<LstBin; BnIndex++)
			{
				RData[ElIndex][AzIndex][BnIndex] = DecodeRef(pOneRadial->Echodata[BnIndex]);
			}
			lastAZindex=AzIndex;
		}
		
		//Save velocity data into the array
		int ksd=pOneRadial->ResolutionOfVelocity;
		if(VFlag)
		{
			//Get first bin, last bin, and number of bins
			FstBin = int(pOneRadial->RangeToFirstGateOfDop/pOneRadial->GateSizeOfDoppler+0.5);
			BinNum = pOneRadial->GatesNumberOfDoppler;
			if(FstBin<0)
			{
				BinNum = FstBin+BinNum;
				FstBin = -1*FstBin;
			}
			LstBin = FstBin + BinNum;
			ptrPos = pOneRadial->PtrOfVelocity-100;
			//Save data
			for(BnIndex=FstBin; BnIndex<LstBin; BnIndex++)
			{

				VData[ElIndex][AzIndex][BnIndex] = 	DecodeVel(pOneRadial->Echodata[ptrPos+BnIndex],pOneRadial->ResolutionOfVelocity);
			}
		}
	
		//Save spectrum width data into the array
		if(WFlag)
		{
			//Get first bin, last bin, and number of bins
			FstBin = int(pOneRadial->RangeToFirstGateOfDop/pOneRadial->GateSizeOfDoppler+0.5);
			BinNum = pOneRadial->GatesNumberOfDoppler;
			if(FstBin<0)
			{
				BinNum = FstBin+BinNum;
				FstBin = -1*FstBin;
			}
			LstBin = FstBin + BinNum;
			ptrPos = pOneRadial->PtrOfSpectrumWidth-100;
			//Save data
			for(BnIndex=FstBin; BnIndex<LstBin; BnIndex++)
				WData[ElIndex][AzIndex][BnIndex] = DecodeSpw(pOneRadial->Echodata[ptrPos+BnIndex]);
		}

	}while(fileEndFlag==0 && !VolEnd && !(readSize<1));

	
	if(!VolEnd && VolBeg)
	{
		fclose(fp);
		free(pOneRadial);
		pOneRadial=NULL;
		return false;
	}

	NumValidCuts = ElIndex+1;

	fclose(fp);
	free(pOneRadial);
	pOneRadial=NULL;
	//����360������

	return true;
}

int CDownbrustDoc::Bin_SA(int x, int y)
{
	float distance;
	float dis=(float)sqrt((x-X0)*(x-X0)+(y-Y0)*(y-Y0));
	distance=int(dis);
	if(distance/R>1)
		distance=-1;
	else distance=distance/xianshijuli;//mBinNum�������ȡһ��ֵ mBinNum����������
	return distance;
}

double CDownbrustDoc::Azimuth(int x, int y)
{
	double angle,azi;
	azi=atan2(double(x-X0),double(y-Y0));//����
	angle=azi*180/pi;//����ɶ���
	return angle;
}











