#define _CRT_SECURE_NO_DEPRECATE 1
#include <stdio.h>
//#include <tchar.h>
#include <string.h>
///////////////////////////////////////////////////////////
//98D����ԭʼ�ļ�
#ifndef BASE_DATA_RADIAL_STRUCT
#define BASE_DATA_RADIAL_STRUCT
#pragma pack (push,1)

struct TArchiHeader
{
	char Filename[9];
	char Fileext[3];
	int  Date;
	int  Time;
	int  Unused;
};
//---------------------------------------------------------------------------
struct	TArchive2//CINRAD-SA LEVEL II ���ݸ�ʽ
{
        //Channel Terminal Manager 12bytes
        unsigned short int CTM[6];
        //Message Header 16bytes
        unsigned short int MessageSize; //12~13 ��ʾ��¼���ȣ�˫�ֽڵ�λ��ʾ
                      char ChannelID;   //14    �źŴ���ͨ����(0,1,2)
                      char MessageType;  //15    ��¼��������,����˵����6.1
                 short int IDSequence;  //16~17  ��¼˳��ţ�0~0x7FFF֮��ѭ����ʾ
        unsigned short int MessageGenerationDate; //18~19 ��¼��������,1/1/1970������Julian����
        unsigned long  int MessageGenerationTime; //20~23 ��¼������GMTʱ��,�Ժ����ʾ
                 short int MessageSegmentsNumber; //24~25 ��¼���ȴ���MessageSizeʱ�ֶδ���
                 short int MessageSegmentNumber; //26~27 ��¼����κ�

        //Digital Radar Data  Header 100bytes
        unsigned long  int RadialCollectionTime; //28~31 �������ϲɼ���GMTʱ��,�Ժ����ʾ
        unsigned short int RadialCollectionDate; //32~33 �������ϲɼ�����,1/1/1970������Julian����
        unsigned short int UnambiguousRange;  //34~35 ��ģ������,��λ��0.1Km
        unsigned short int AzimuthAngle;  //36~37 ��λ��,ʵ��ֵ=(value>>3)*0.043945(��)
                 short int AzimuthNumber;     //38~39 ��������ɨ��ľ�����
                 short int RadialStatus;  //40~41 ����λ�ò���
                                         //     0=��ʼ������
                                         //     1=ͬһ���ǲ㾶������
                                         //     2=�������ǽ���
                                         //     3=��ɨ��ʼ
                                         //     4=��ɨ����
                 short int ElevationAngle;  //42~43 ����, ʵ��ֵ=(value>>2)*0.043945(��)
                 short int ElevationNumber;   //44~45 ���ɨ��������
                 short int FirstGateRangeOfRef;//46~47��һ��ǿ�ȿ�ľ���(��)
                 short int FirstGateRangeOfDoppler;//48~49 ��һ���ٶ�\�׿��ľ���(��)
                 short int ReflectivityGateSize; //50~51 ǿ�ȿⳤ(��)
                 short int DopplerGateSize; //52~53�ٶ�\�׿�ⳤ(��)
                 short int ReflectivityGates;//54~55	ǿ�ȿ���
                 short int DopplerGates;//56~57	�ٶ�\�׿����
                 short int SectorNumber;//58~59	cut�ڵ�������
                     float CalibrationConstant;//60~63 ϵͳ�����У������dB��
        unsigned short int ReflectivityPointer;//64~65���״�����ͷ��ǿ�����ݿ�ʼ���ֽ���
        unsigned short int VelocityPointer;//66~67���״�����ͷ���ٶ����ݿ�ʼ���ֽ���
        unsigned short int SpectrumWidthPointer;//68~69���״�����ͷ���׿����ݿ�ʼ���ֽ���
                 short int VelocityResolution;//70~71 �ٶȷֱ���:2=0.5m/s,4=1.0m/s
                 short int VCP;//72~73��ɨVCP��ʽ��11��21��31��32��
                 short int Unused[4];//74~81 δ�á�
        unsigned short int RefPlaybackPointer;//82~83ǿ������ָ�루����RDA�طţ�
        unsigned short int VelPlaybackPointer;//84~85 �ٶ�����ָ�루����RDA�طţ�
        unsigned short int SWPlaybackPointer;//86~87	�׿�����ָ�루����RDA�طţ�
                 short int NyquistVelocity;//88~89 Nyquist����(0.01m/s)
                 short int AAF;//90~91 Atmospheric Attenuation Factor(0.001 dB/Km)
                 short int TOVER;//92~93û�о����۵������ز�����֮����С��ֵ���ޣ�0.1�ߣ�
                 short int Spares[17];//94~127 δ�á�
             unsigned char data[2300];
		//reflectivity data 460bytes
        //     unsigned char dBZ[460];
        //Velocity data 920bytes
        //     unsigned char Vel[920];
        //Spectrum Width data 920bytes
        //     unsigned char SW[920];
        //Referred to Frame Check Sequence
        unsigned long  int Trailer;
};

#pragma pack(pop)

#endif
//#include "wsr98dheader.h"
#define BYTE unsigned char

void JulianToDate(unsigned short Julian, unsigned short& year, BYTE& month, BYTE& day)
{
	int JLDAYN=Julian+2440587 ;
	int L=JLDAYN+68569 ;
	int N=4*L/146097 ;
	L=L-(146097*N+3)/4 ;
	int I=4000*(L+1)/1461001 ;
	L=L-1461*I/4+31 ;
	int J=80*L/2447 ;

	day=L-2447*J/80 ;

	L=J/11 ;
	month=J+2-12*L ;

	year=100*(N-49)+I+L ;

}

void SecondsToTime(unsigned long ulSeconds, BYTE &hour, BYTE &min, BYTE &sec)
{
	hour = (BYTE)(ulSeconds/3600);
	min =  (BYTE)((ulSeconds-hour*3600)/60);
	sec =  (BYTE)(ulSeconds-hour*3600-min*60);
}

void StoreTransfer(char* buf,int size)
{

	char buffr[50];
	int i;
	for(i=0;i<size;i++)
		buffr[i]=buf[i];

	for(i=0;i<size;i++)
		buf[i]=buffr[size-i-1];

}

void Data_Format_TransferArchi(TArchive2 *Arch)
{
	char*ppp;
	for(int i=0;i<6;i++)
	{
		ppp=(char*)&Arch->CTM[i];
		StoreTransfer(ppp,sizeof(short));
	}

	ppp=(char*)&Arch->MessageSize; 
	StoreTransfer(ppp,sizeof(short));

	ppp=(char*)&Arch->ChannelID; 
	StoreTransfer(ppp,sizeof(short));


	ppp=(char*)&Arch->IDSequence;   
	StoreTransfer(ppp,sizeof(short));
	ppp=(char*)&Arch->MessageGenerationDate;    
	StoreTransfer(ppp,sizeof(short));

	ppp=(char*)&Arch->MessageGenerationTime;  
	StoreTransfer(ppp,sizeof(int));

	ppp=(char*)&Arch->MessageSegmentsNumber;      
	StoreTransfer(ppp,sizeof(short));
	ppp=(char*)&Arch->MessageSegmentNumber;     
	StoreTransfer(ppp,sizeof(short));

	ppp=(char*)&Arch->RadialCollectionTime;    
	StoreTransfer(ppp,sizeof(int));
	ppp=(char*)&Arch->RadialCollectionDate; 
	StoreTransfer(ppp,sizeof(short));
	ppp=(char*)&Arch->UnambiguousRange;  
	StoreTransfer(ppp,sizeof(short));
	ppp=(char*)&Arch->AzimuthAngle; 
	StoreTransfer(ppp,sizeof(short));
	ppp=(char*)&Arch->AzimuthNumber;  
	StoreTransfer(ppp,sizeof(short));
	ppp=(char*)&Arch->RadialStatus;
	StoreTransfer(ppp,sizeof(short));



	ppp=(char*)&Arch->ElevationAngle;   
	StoreTransfer(ppp,sizeof(short));
	ppp=(char*)&Arch->ElevationNumber;
	StoreTransfer(ppp,sizeof(short));


	ppp=(char*)&Arch->FirstGateRangeOfRef; 
	StoreTransfer(ppp,sizeof(short));

	ppp=(char*)&Arch->FirstGateRangeOfDoppler;
	StoreTransfer(ppp,sizeof(short));

	ppp=(char*)&Arch->ReflectivityGateSize;  
	StoreTransfer(ppp,sizeof(short));

	/////////////////
	ppp=(char*)&Arch->DopplerGateSize;   
	StoreTransfer(ppp,sizeof(short));

	ppp=(char*)&Arch->ReflectivityGates; 
	StoreTransfer(ppp,sizeof(short));

	ppp=(char*)&Arch->DopplerGates;  
	StoreTransfer(ppp,sizeof(short));

	ppp=(char*)&Arch->SectorNumber;    
	StoreTransfer(ppp,sizeof(short));
	/////////////////////////////////
	ppp=(char*)&Arch->CalibrationConstant;   
	StoreTransfer(ppp,sizeof(float));

	ppp=(char*)&Arch->ReflectivityPointer;   
	StoreTransfer(ppp,sizeof(short));

	ppp=(char*)&Arch->VelocityPointer; 
	StoreTransfer(ppp,sizeof(short));

	ppp=(char*)&Arch->SpectrumWidthPointer;
	StoreTransfer(ppp,sizeof(short));

	ppp=(char*)&Arch->VelocityResolution;
	StoreTransfer(ppp,sizeof(short));

	ppp=(char*)&Arch->VCP;
	StoreTransfer(ppp,sizeof(short));

	ppp=(char*)&Arch->RefPlaybackPointer;
	StoreTransfer(ppp,sizeof(short));

	ppp=(char*)&Arch->VelPlaybackPointer; 
	StoreTransfer(ppp,sizeof(short));

	ppp=(char*)&Arch->SWPlaybackPointer;   
	StoreTransfer(ppp,sizeof(short));

	ppp=(char*)&Arch->NyquistVelocity;   
	StoreTransfer(ppp,sizeof(short));


	ppp=(char*)&Arch->AAF; 
	StoreTransfer(ppp,sizeof(short));

	ppp=(char*)&Arch->TOVER;  
	StoreTransfer(ppp,sizeof(short));

	ppp=(char*)&Arch->Trailer;
	StoreTransfer(ppp,sizeof(int));

}
int main(int argc,char *argv[])
{
	if (argc == 1)
	{
		printf("\tUsage: trans88 <WSR98D File Path> [Output File Path] ");
	}
	else if(argc == 2 || argc == 3)
	{


		FILE* fp=fopen(argv[1],"rb");
		if(!fp)
		{
			printf("Open File %s Error\n Check Whether File Exist or Correctly Formated",argv[1]);
			return 0;
		}

		TArchive2 Arch;
		fread(&Arch,sizeof(TArchive2),1,fp);
		if (3 != Arch.RadialStatus)
		{
//			printf("98D File Have Invalid Record or Badly Formated!\n");
//			return 0;
		}
		char  oFilePath[300];
        if (argc == 3)
        {
			strcpy(oFilePath,argv[2]);
        }
		else
		{
			char  buff[4];
			sprintf(buff,"%03i",0);


			unsigned short year;
			unsigned char month,day,hour,minute,second;
			JulianToDate(Arch.RadialCollectionDate, year, month, day) ;
			SecondsToTime(Arch.RadialCollectionTime/1000, hour, minute, second) ; 
			sprintf(oFilePath,"%04i%02i%02i%02i%02i%02i_VOL.",year,month,day,hour,minute,second);
			strcat(oFilePath,buff);
		}
		TArchiHeader   Header;
		strcpy(Header.Filename,"ARCHIVE2.");
		strcpy(Header.Fileext,"000");
		Header.Date=Arch.RadialCollectionDate;
		Header.Time=Arch.RadialCollectionTime;
		
		fclose(fp);
		FILE*fpin =fopen(argv[1],"rb");
		fp=fopen(oFilePath,"wb");
                int asize=sizeof(TArchive2);
                printf("size=%d",asize);
/*		char* ppp = (char*)&Header.Date; 
		StoreTransfer(ppp,sizeof(int));
		ppp=(char*)&Header.Time; 
		StoreTransfer(ppp,sizeof(int));
*/
		fwrite(&Header,1,sizeof(Header),fp);

		fseek(fpin,0,SEEK_SET);
		fread(&Arch,sizeof(TArchive2),1,fpin);
		int nnn=0;
		while(!feof(fpin))
		{
			nnn++;
			Data_Format_TransferArchi(&Arch);
                        if(nnn<1)
                        printf("statud = %d \n", Arch.RadialStatus);
			fwrite(&Arch,1,sizeof(TArchive2),fp);
			fread(&Arch,sizeof(TArchive2),1,fpin);

		}
//		for(int i=0;i<50;i++)
//		fwrite(&Arch,sizeof(TArchive2),1,fp);


		fclose(fp);
		fclose(fpin);
		printf(("\tFile Write to %s...\n\tTotal Read %5d Records\n"),oFilePath,nnn);
		return 1;
	}
	else
		printf(("Too Many Parameters!\n"));
	return 0;
}
