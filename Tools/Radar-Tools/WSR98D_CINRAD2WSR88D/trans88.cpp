#define _CRT_SECURE_NO_DEPRECATE 1
#include <stdio.h>
//#include <tchar.h>
#include <string.h>
///////////////////////////////////////////////////////////
//98D资料原始文件
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
struct	TArchive2//CINRAD-SA LEVEL II 数据格式
{
        //Channel Terminal Manager 12bytes
        unsigned short int CTM[6];
        //Message Header 16bytes
        unsigned short int MessageSize; //12~13 表示记录长度，双字节单位表示
                      char ChannelID;   //14    信号传输通道号(0,1,2)
                      char MessageType;  //15    记录数据类型,具体说明见6.1
                 short int IDSequence;  //16~17  记录顺序号，0~0x7FFF之间循环表示
        unsigned short int MessageGenerationDate; //18~19 记录产生日期,1/1/1970以来的Julian日期
        unsigned long  int MessageGenerationTime; //20~23 记录产生的GMT时间,以毫秒表示
                 short int MessageSegmentsNumber; //24~25 记录长度大于MessageSize时分段传输
                 short int MessageSegmentNumber; //26~27 记录传输段号

        //Digital Radar Data  Header 100bytes
        unsigned long  int RadialCollectionTime; //28~31 径向资料采集的GMT时间,以毫秒表示
        unsigned short int RadialCollectionDate; //32~33 径向资料采集日期,1/1/1970以来的Julian日期
        unsigned short int UnambiguousRange;  //34~35 不模糊距离,单位：0.1Km
        unsigned short int AzimuthAngle;  //36~37 方位角,实际值=(value>>3)*0.043945(度)
                 short int AzimuthNumber;     //38~39 本层仰角扫描的径向数
                 short int RadialStatus;  //40~41 径向位置参数
                                         //     0=开始新仰角
                                         //     1=同一仰角层径向数据
                                         //     2=本层仰角结束
                                         //     3=体扫开始
                                         //     4=体扫结束
                 short int ElevationAngle;  //42~43 仰角, 实际值=(value>>2)*0.043945(度)
                 short int ElevationNumber;   //44~45 体积扫描仰角数
                 short int FirstGateRangeOfRef;//46~47第一个强度库的距离(米)
                 short int FirstGateRangeOfDoppler;//48~49 第一个速度\谱宽库的距离(米)
                 short int ReflectivityGateSize; //50~51 强度库长(米)
                 short int DopplerGateSize; //52~53速度\谱宽库长(米)
                 short int ReflectivityGates;//54~55	强度库数
                 short int DopplerGates;//56~57	速度\谱宽库数
                 short int SectorNumber;//58~59	cut内的扇区数
                     float CalibrationConstant;//60~63 系统增益标校常数（dB）
        unsigned short int ReflectivityPointer;//64~65从雷达数据头到强度数据开始的字节数
        unsigned short int VelocityPointer;//66~67从雷达数据头到速度数据开始的字节数
        unsigned short int SpectrumWidthPointer;//68~69从雷达数据头到谱宽数据开始的字节数
                 short int VelocityResolution;//70~71 速度分辨率:2=0.5m/s,4=1.0m/s
                 short int VCP;//72~73体扫VCP方式（11、21、31、32）
                 short int Unused[4];//74~81 未用。
        unsigned short int RefPlaybackPointer;//82~83强度数据指针（用于RDA回放）
        unsigned short int VelPlaybackPointer;//84~85 速度数据指针（用于RDA回放）
        unsigned short int SWPlaybackPointer;//86~87	谱宽数据指针（用于RDA回放）
                 short int NyquistVelocity;//88~89 Nyquist速率(0.01m/s)
                 short int AAF;//90~91 Atmospheric Attenuation Factor(0.001 dB/Km)
                 short int TOVER;//92~93没有距离折叠两个回波功率之间最小差值门限（0.1瓦）
                 short int Spares[17];//94~127 未用。
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
