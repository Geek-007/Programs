#ifndef _DAT_
#define _DAT_

#define RGates  460				//S BAND 反射率距离库数
#define VGates  920				//S BAND 速度距离库数
#define WGates  920				//S BAND 谱宽距离库数
#define MaxCuts		20			//最大仰角层数
#define MaxRads		360			//每层仰角上的方位数,每度保留一个径向

#define CODE_INVALID 0			//编码值中的特殊标记,表示无有效观测数据
#define CODE_RANFOLD 1			//编码值中的特殊标记,表示有距离模糊

#define VALUE_INVALID -999.		//实际值中的特殊标记,表示无有效观测数据
#define VALUE_RANFOLD  999.		//实际值中的特殊标记,表示有距离模糊
#define VALUE_AINVALID -1;

#define RES_POINT_FIVE 2		//速度精度类型,代表的精度为0.5 M/S
#define RES_ONE_POINT  4		//速度精度类型,代表的精度为1.0 M/S

#define VOL_BEG 3				//体扫开始状态标志
#define VOL_END 4				//体扫结束状态标志
#define ELV_BEG 0				//仰角开始状态标志
#define ELV_END 2				//仰角结束状态标志


#define RADIAN  3.14159/180.
#define PI 3.14159
/*-----------字节说明------
int             占4个字节
unsigned int    占4个字节
short int       占2个字节       
-------------------------*/
//定义文件头结构体
typedef struct _RDABaseDataHead
{
unsigned short		temp1[7];						//保留
	unsigned short		RadarStatus;					//1 - 表示为雷达数据 
	unsigned short		temp2[6];						//保留
	unsigned int		mSeconds;						//径向数据收集时间
	unsigned short		JulianDate;						//从1970/1/1起的日期
	unsigned short		URange;							//不模糊距离
	unsigned short		Az;								//方位角度
	unsigned short		RadialNumber;					//径向数据序号
	unsigned short		RadialStatus;					//径向数据状态
	unsigned short		El;								//仰角
	unsigned short		ElNumber;						//体扫内的仰角编号
	short				RangeToFirstGateOfRef;			//第一个反射率数据表示的实际距离(m)
	short				RangeToFirstGateOfDop;			//第一个多普勒数据表示的实际距离(m)
	unsigned short		GateSizeOfReflectivity;			//反射率数据的距离库长(m)
	unsigned short		GateSizeOfDoppler;				//多普勒数据的距离库长(m)
	unsigned short		GatesNumberOfReflectivity;		//反射率数据的距离库数
	unsigned short		GatesNumberOfDoppler;			//多普勒数据的距离库数
	unsigned short		CutSectorNumber; 				//扇区号
	unsigned int		CalibrationConst; 				//标定常数
	unsigned short		PtrOfReflectivity;				//反射率数据指针
	unsigned short		PtrOfVelocity;					//速度数据指针
	unsigned short		PtrOfSpectrumWidth;				//谱宽数据指针
	unsigned short		ResolutionOfVelocity;			//多普勒速度分辨率
	unsigned short		VcpNumber;						//体扫号
	unsigned short		temp4[4];						//保留
	unsigned short		PtrOfArcReflectivity;			//反射率数据指针
	unsigned short		PtrOfArcVelocity;				//速度数据指针
	unsigned short		PtrOfArcWidth;					//谱宽数据指针
	unsigned short		Nyquist;						//不模糊速度
	unsigned short      temp46;                         //保留
	unsigned short      temp47;                         //保留
	unsigned short      temp48;                         //保留
	unsigned short      CircleTotal;					//仰角数
	unsigned char		temp5[30];						//保留
	unsigned char		Echodata[RGates+VGates+WGates];	//129－588 共460字节反射率数据
	unsigned char		temp[4];						//保留
	//129－1508 共1380字节速度数据 
	//129－2428 共2300字节谱宽数据
}_tagRDABaseDataHead;


#endif