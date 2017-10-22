#ifndef _DAT_
#define _DAT_

#define RGates  460				//S BAND �����ʾ������
#define VGates  920				//S BAND �ٶȾ������
#define WGates  920				//S BAND �׿�������
#define MaxCuts		20			//������ǲ���
#define MaxRads		360			//ÿ�������ϵķ�λ��,ÿ�ȱ���һ������

#define CODE_INVALID 0			//����ֵ�е�������,��ʾ����Ч�۲�����
#define CODE_RANFOLD 1			//����ֵ�е�������,��ʾ�о���ģ��

#define VALUE_INVALID -999.		//ʵ��ֵ�е�������,��ʾ����Ч�۲�����
#define VALUE_RANFOLD  999.		//ʵ��ֵ�е�������,��ʾ�о���ģ��
#define VALUE_AINVALID -1;

#define RES_POINT_FIVE 2		//�ٶȾ�������,����ľ���Ϊ0.5 M/S
#define RES_ONE_POINT  4		//�ٶȾ�������,����ľ���Ϊ1.0 M/S

#define VOL_BEG 3				//��ɨ��ʼ״̬��־
#define VOL_END 4				//��ɨ����״̬��־
#define ELV_BEG 0				//���ǿ�ʼ״̬��־
#define ELV_END 2				//���ǽ���״̬��־


#define RADIAN  3.14159/180.
#define PI 3.14159
/*-----------�ֽ�˵��------
int             ռ4���ֽ�
unsigned int    ռ4���ֽ�
short int       ռ2���ֽ�       
-------------------------*/
//�����ļ�ͷ�ṹ��
typedef struct _RDABaseDataHead
{
unsigned short		temp1[7];						//����
	unsigned short		RadarStatus;					//1 - ��ʾΪ�״����� 
	unsigned short		temp2[6];						//����
	unsigned int		mSeconds;						//���������ռ�ʱ��
	unsigned short		JulianDate;						//��1970/1/1�������
	unsigned short		URange;							//��ģ������
	unsigned short		Az;								//��λ�Ƕ�
	unsigned short		RadialNumber;					//�����������
	unsigned short		RadialStatus;					//��������״̬
	unsigned short		El;								//����
	unsigned short		ElNumber;						//��ɨ�ڵ����Ǳ��
	short				RangeToFirstGateOfRef;			//��һ�����������ݱ�ʾ��ʵ�ʾ���(m)
	short				RangeToFirstGateOfDop;			//��һ�����������ݱ�ʾ��ʵ�ʾ���(m)
	unsigned short		GateSizeOfReflectivity;			//���������ݵľ���ⳤ(m)
	unsigned short		GateSizeOfDoppler;				//���������ݵľ���ⳤ(m)
	unsigned short		GatesNumberOfReflectivity;		//���������ݵľ������
	unsigned short		GatesNumberOfDoppler;			//���������ݵľ������
	unsigned short		CutSectorNumber; 				//������
	unsigned int		CalibrationConst; 				//�궨����
	unsigned short		PtrOfReflectivity;				//����������ָ��
	unsigned short		PtrOfVelocity;					//�ٶ�����ָ��
	unsigned short		PtrOfSpectrumWidth;				//�׿�����ָ��
	unsigned short		ResolutionOfVelocity;			//�������ٶȷֱ���
	unsigned short		VcpNumber;						//��ɨ��
	unsigned short		temp4[4];						//����
	unsigned short		PtrOfArcReflectivity;			//����������ָ��
	unsigned short		PtrOfArcVelocity;				//�ٶ�����ָ��
	unsigned short		PtrOfArcWidth;					//�׿�����ָ��
	unsigned short		Nyquist;						//��ģ���ٶ�
	unsigned short      temp46;                         //����
	unsigned short      temp47;                         //����
	unsigned short      temp48;                         //����
	unsigned short      CircleTotal;					//������
	unsigned char		temp5[30];						//����
	unsigned char		Echodata[RGates+VGates+WGates];	//129��588 ��460�ֽڷ���������
	unsigned char		temp[4];						//����
	//129��1508 ��1380�ֽ��ٶ����� 
	//129��2428 ��2300�ֽ��׿�����
}_tagRDABaseDataHead;


#endif