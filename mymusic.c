//---*---+-+-+-+---*---+-+-+-+---*---+-+-+-+---*---+-+-+-+---*---+-+-+-+---*---+-+-+-+---*---+-+-+-+---*---+-+-+-+---//
//ʹ�÷���:
//1: ��ʼ��: ����PWM��ʽ��ʼ��,���ʱ��������
//2: ����:   ����<��������>  <���߶���>  <��������>  <�������ݱ�>
//3: ��Ϊ��ͬ����ԴƵ�ʲ�ͬ,��Ƶϵ����ͬ,����Ҫ�ı�������Ӧ������,��ֱ���޸�<<��Ƭ�����ַ�����Ƶ�� ���ڹ�ϵ��.xls>>
//		�ж�Ӧ��������,Ȼ��ѽ�����Ƶ��������鼴��
//4: ���ֱ༭����Ϊ: ��1�ֽ�Ϊ����������,��λΪ1/8����,���һ������Ϊ1��,������Ϊ8,��������
//		��2�ֽ�Ϊ����,��Ӧ1~7�ĵ���(l1~l7) ����(m1~m7) ����(h1~h7),��ֹ��Ϊxz, ���ݼ��׻������ױ༭����
//5: ����ѡ��ͨ��Music_Select()ʵ��, �������ͨ��Musicing()ʵ��,ÿ10�������һ��.
//6: buzstpΪһ����־,musicing()����ֻ�����־,��λ��ʹ�ó������
//7: ԭ����ҵ��ʹ�õľɵ�����,���Ǳ�׼������,�������õ����ĳ���,ѡ�����ֺ�,��������music_sel_ts_flg=1;,���ñ�׼����,������0
//8: �����Ҫ�����������������,����Ҫ������ֹ��,��ֹ�����Ƶ��Ϊǰ��һ��Ƶ��,�����Ĺر�
//---*---+-+-+-+---*---+-+-+-+---*---+-+-+-+---*---+-+-+-+---*---+-+-+-+---*---+-+-+-+---*---+-+-+-+---*---+-+-+-+---//

//������Ϊ��ȫ���Լ�д�����ַ������򣬷ֳ������������1���ǵ��ֽڱ�ʾƵ�ʣ���һ����˫�ֽڱ�ʾƵ��
//�ֱ��Ӧ8λPWM��16λPWM��
//����8λPWM���������Ƶ����8M��64��Ƶ�󣬿����������490HZ�����125KHZ�����
//����16λPWM���������Ƶ����8M������Ƶ�������������122HZ�����8MHZ���������ʹ����Ƶ��16M����Ȼ����ʵ��
//����Do��262HZ���ķ��������ҷ���Ƶ��׼ȷ

//���ִ�Ÿ�ʽΪ��
//������֯��ÿ��88��(���Ǽ��㷽��,ȡÿ����93��,��ÿ��640����)Ϊ��׼,4������Ϊһ��,Ҳ����һ��Ϊ640����,
//�����1/8��Ϊ��λ,����80����Ϊ��λ��Ž��ĳ���
//��1�ֽ�Ϊ����, �����1/8��Ϊ��λ,�����Դ��32��,ʵ�ʴ��4�ļ���,�������3��λ
//��2�ֽ�Ϊ����,�ֱ�������Ķ������, ��һ������, ��Ÿ�����Ƶ�ʶ�Ӧ��PWM����ֵ
//�������ֵ������һ��EXCEL ��, ֻ������PWM�ź�ԴƵ�� ��Ƶֵ���ɵõ�.
//�����еĵ�Ƭ��ֻ��8λPWM,�������ֱ�,�ֱ����8λPWM��16λPWM
//������,0Ϊ��ֹ��,��ʵ�ʳ��򽫷���ս����Ϊ100%���ź�.

//��������ѡ��
#define MF2591	1
#define MF2165	2
#define MF2220	3
#define MF2294	4
#define MF2370	5
#define MF2427	6
#define MF2525	7
#define MF2564	8
#define MFPWON	9		//����
#define MFSTRT	10		//����
#define MFPASU	11		//��ͣ
#define MFERRO	12		//����
#define MFNWTR	13		//��ˮ���
#define MFZHQI	14		//���ڼ��
#define MFSELF	15		//�����Լ�
#define MFEND	16		//����
#define MFPOFF	17		//�ػ�
#define MF2304	18


//��������
#define xz  0	//��ֹ��
#define l1  1	//���� 1
#define l2  2	//���� 2
#define l3  3	//���� 3
#define l4  4	//���� 4
#define l5  5	//���� 5
#define l6  6	//���� 6
#define l7  7	//���� 7
#define m1  8	//���� 1
#define m2  9	//���� 2
#define m3  10	//���� 3
#define m4  11	//���� 4
#define m5  12	//���� 5
#define m6  13	//���� 6
#define m7  14	//���� 7
#define h1  15	//���� 1
#define h2  16	//���� 2
#define h3  17	//���� 3
#define h4  18	//���� 4
#define h5  19	//���� 5
#define h6  20	//���� 6
#define h7  21	//���� 7


//����Ƶ�����ִ����ö���,��дʱֱ��дY+Ƶ��ֵ����,�򵥷���
#define Y1543 1
#define Y1572 2
#define Y1736 3
#define Y1760 4
#define Y1838 5
#define Y1968 6
#define Y2049 7
#define Y2066 8
#define Y2092 9
#define Y2128 10
#define Y2165 11
#define Y2220 12
#define Y2228 13
#define Y2232 14
#define Y2242 15
#define Y2294 16
#define Y2304 17
#define Y2310 18
#define Y2347 19
#define Y2370 20
#define Y2404 21
#define Y2415 22
#define Y2427 23
#define Y2463 24
#define Y2525 25
#define Y2564 26
#define Y2577 27
#define Y2591 28
#define Y2604 29
#define Y2632 30
#define Y2732 31
#define Y2740 32
#define Y2809 33


//8λPWM ��Ӧ������ֵ
//const unsigned char pwm8b_mc[]={0,239,216,190,179,159,142,127,120,106,95,89,80,71,63,60,53,47,45,40,36,32};
const unsigned char pwm8b_mc[]={0,120,106,95,89,80,71,63,60,53,47,45,40,36,32,30,27,24,22,20,18,16,};

//16λPWM ��Ӧ������ֵ--���ֽ���ǰ
const unsigned char pwm16b_mc[]={0,0,59,192,54,17,47,108,44,197,39,220,35,131,31,161,
29,224,26,153,23,182,22,95,19,238,17,193,15,209,14,240,13,76,11,219,11,47,9,247,8,225,7,232};
//10λPWM ��Ӧ������ֵ--���ֽ���ǰ
const unsigned char pwm10b_mc[]={0,0,3,188,3,97,2,247,2,204,2,126,2,56,1,250,
1,222,1,170,1,123,1,102,1,63,1,28,0,253,0,239,0,213,0,190,0,179,0,159,0,142,0,127};

//�ֱ��ӦƵ��Ϊ 
//  Y1  Y2   Y3   Y4   Y5   Y6   Y7   Y8   Y9   Y10  Y11  Y12  Y13  Y14  Y15  Y16  Y17  Y18  Y19  Y20  Y21
//1572 1760 1968 2049 2092 2128 2165 2220 2228 2232 2242 2294 2304 2310 2347 2370 2404 2415 2427 2463 2525 
// Y22  Y23  Y24  Y25  Y26  Y27  Y28  Y29 
//2564 2577 2591 2604 2632 2732 2740 2809  ��PWMֵ   Y0Ϊ0
const unsigned char pwm8b_ts[]={0,81,80,72,71,68,64,61,61,60,59,58,56,56,56,56,54,54,54,53,53,52,52,52,51,50,49,49,48,48,47,46,46,44};


//���������ʽ: 
//  ������1�ֽ�,ȷ�����ֳ���,������2�ֽ�Ϊ��Ӧ���� .
//  ��1�ֽڵ�5λ����8�ͼ�ʱ��,���ڼ�ʱ,��ʱ��λΪ10����
//  ��2�ֽ��ٲ��pwm8b_mc[]��pwm10b_mc[]��pwm16b_mc[],�����ӦPWM����ֵ,��PWM���ڼĴ���.
//�������ֱ�ͷ��ַ��ͬʱ,�����ý����ֵ���������,Ҳ����ֱ��ʹ��SIZE OF ()αָ��ȡ�ó���,����2��Ϊ��������.

/***********************************************************************/
/*                                                                     */
/*  FILE        :MYMUSIC.c                                               */
/*  DATE        :Fri, Aug 26, 2005                                     */
/*  DESCRIPTION :Main Program                                          */
/*  CPU TYPE    :H8/36014F                                             */
/*                                                                     */
/*  This file is generated by Hitachi Project Generator (Ver.2.1).     */
/*                                                                     */
/***********************************************************************/
                  

#define uchar 		     unsigned char
#define uint		     unsigned int

void ini_pp(void);
void emi_p(void);
void ini_ram(void);
void delayus(uchar dlt);
void Buzzing(void);
void Music_Select(void);
void Musicing(void);


#include "iodefine.h"
#include <machine.h>

//-----------------------------------------------------------------
#define passz_kx	IO.PDR1.BIT.B7	//�������

#define Buzzeron()       	 TV.TCSRV.BIT.OS=6;
#define Buzzeroff()       	 TV.TCSRV.BIT.OS=0;

#define RESET_WATCHDOG() {WDT.TCSRWD.BIT.B6WI=0; WDT.TCSRWD.BIT.TCWE=1; WDT.TCWD=0x00; WDT.TCSRWD.BIT.TCWE=0; WDT.TCSRWD.BIT.B6WI=1;}

#define PORT1	IO.PDR1.BYTE
#define PORT2	IO.PDR2.BYTE
#define PORT5	IO.PDR5.BYTE
#define PORT7	IO.PDR7.BYTE
#define PORT8	IO.PDR8.BYTE
#define PORTB	IO.PDRB.BYTE

#define portmr1	IO.PMR1.BYTE
#define portmr5	IO.PMR5.BYTE

#define portcr1	IO.PCR1
#define portcr2	IO.PCR2
#define portcr5	IO.PCR5
#define portcr7	IO.PCR7
#define portcr8	IO.PCR8

#define portur1	IO.PUCR1.BYTE
#define portur5	IO.PUCR5.BYTE


//-----------------------------------------------------------------

union
{
unsigned char STAFLG;
struct {
    unsigned DYON_FLG:1;
    unsigned START_FLG:1;
    unsigned PAUSE_FLG:1;
    unsigned BOOK_FLG:1;
    unsigned :1;
    unsigned :1;
    unsigned HTTB:1;
    unsigned OPDR:1;
}STAFLGbits;
}STAFLGU;

#define staflg STAFLGU.STAFLG
#define dyonflg STAFLGU.STAFLGbits.DYON_FLG
#define startflg STAFLGU.STAFLGbits.START_FLG
#define pauseflg STAFLGU.STAFLGbits.PAUSE_FLG
#define bookflg STAFLGU.STAFLGbits.BOOK_FLG
	#define opendrflg STAFLGU.STAFLGbits.OPDR
	#define hurttbflg STAFLGU.STAFLGbits.HTTB


//////////////////////////�йض��忪ʼ//////////////////////////////////////

//-------------------- λ�������� --------------------
volatile union
{
	unsigned char BYTE;
	struct
	{
		unsigned S7:1;
		unsigned S6:1;
		unsigned S5:1;
		unsigned S4:1;
		unsigned S3:1;
		unsigned S2:1;
		unsigned S1:1;
		unsigned S0:1;
	}BIT;
}MFLGU;
	#define musicflg			MFLGU.BYTE
	#define mflg10ms			MFLGU.BIT.S7	//����10�����־,ÿ10���봦��һ������
	#define buzstp				MFLGU.BIT.S6	//�������ֹͣ��־ 0:ֹͣ  1:�������  �����־�������ַ�����������λ,ֻ��0
	#define musicruning			MFLGU.BIT.S5	//�����Ƿ��������  1:��  0:δ
	#define music_1st_flg		MFLGU.BIT.S4	//�������������ֺ�,���ν��������������  1:�� 0:���ν���
	#define music_sel_ts_flg	MFLGU.BIT.S3	//ѡ���������ֱ�־


//-------------------- �������� --------------------
unsigned char btMusicSet;		//����ѡ��
unsigned char music_pai_ct;		//�����������ʱ�䱣��
unsigned char music_yinf_nu;		//����������������
unsigned char music_peri;		//�������������ڱ���
unsigned char *music_ptr;		//������ʼ��ַ


//-------------------- ���⹦�ܼĴ������� --------------------
#define pwm_period 		TV.TCORA		//����
#define pwm_duty 		TV.TCORB		//ռ�ձ�
#define jiepai_kx 		IO.PDR1.BIT.B2		//���Ŀ���

#define pwm_period_h 		TV.TCORA		//����--���ֽ�
#define pwm_period_l 		TV.TCORA		//����--���ֽ�
#define pwm_duty_h 		TV.TCORB		//ռ�ձ�--���ֽ�
#define pwm_duty_l 		TV.TCORB		//ռ�ձ�--���ֽ�

//////////////////////////�йض������//////////////////////////////////////

uchar jsq10ms;		//10�����ʱ��


//���ִ�Ÿ�ʽΪ��
//������֯��ÿ��88*2��(���Ǽ��㷽��,ȡÿ����93*2��,��ÿ��320����)Ϊ��׼,4������Ϊһ��,Ҳ����һ��Ϊ320����,
//�����1/8��Ϊ��λ,����40����Ϊ��λ��Ž��ĳ���
//��1�ֽ�Ϊ����, �����1/8��Ϊ��λ,�����Դ��32��,ʵ�ʴ��4�ļ���,�������3��λ
//��2�ֽ�Ϊ����,�ֱ�������Ķ������, ��һ������, ��Ÿ�����Ƶ�ʶ�Ӧ��PWM����ֵ
//�������ֵ������һ��EXCEL ��, ֻ������PWM�ź�ԴƵ�� ��Ƶֵ���ɵõ�.
//�����еĵ�Ƭ��ֻ��8λPWM,�������ֱ�,�ֱ����8λPWM��16λPWM
//������,0Ϊ��ֹ��,��ʵ�ʳ��򽫷���ս����Ϊ100%���ź�.

//-------------------- �������ݱ� ------------------------------------------------------------
//My Bonnie
const unsigned char mybonie[]={8,l5,8,m3,8,m2,8,m1,8,m2,8,m1,8,l6,8,l5,8,l3,8,l3,8,l3,8,l3,8,l5,8,m3,8,m2,8,m1,8,m1,8,l7,8,m1,8,m2,8,m2,8,m2,
	8,m2,8,m2,8,l5,8,m3,8,m2,8,m1,8,m2,8,m1,8,l6,8,l5,8,l3,8,l3,16,l3,8,l5,8,l6,8,m2,8,m1,8,l7,8,l6,8,l7,8,m1,8,m1,8,m1};
//You are my sunshine
const unsigned char mysunshine[]={8,l5,8,m1,8,m2,16,m3,16,m3,16,m3,8,m2,8,m3,16,m1,16,m1,8,m1,8,m1,8,m2,8,m3,16,m4,
	16,m6,16,m5,8,m4,16,m3,16,m3,8,m3,8,m1,8,m2,8,m3,16,m4,16,m6,16,m6,8,m5,8,m4,16,m3,16,m1,24,m1,8,m2,24,m3,8,m4,
	24,m2,8,m3,32,m1,8,m1,8,l5,8,m1,8,m2,16,m3,16,m3,16,m3,8,m2,8,m3,32,m1,16,m1,8,m2,8,m3,16,m4,16,m6,16,m6,8,m5,8,m4,32,m3};
//����춣��
const unsigned char jingle_bell1[]=
{8,l5,8,m3,8,m2,8,m1,16,l5,8,0,4,l5,4,l5,
8,l5,8,m3,8,m2,8,m1,8,l6,8,l6,8,l6,8,0,
8,l6,8,m4,8,m3,8,m2,24,l7,8,0,
8,m5,8,m5,8,m4,8,m2,24,m3,8,0,
8,l5,8,m3,8,m2,8,m1,8,l5,8,l5,8,l5,8,0,
8,l5,8,m3,8,m2,8,m1,8,l6,8,l6,8,l6,8,l6,
8,l6,8,m4,8,m3,8,m2,8,m5,1,0,8,m5,1,0,8,m5,1,0,8,m5,
8,m6,8,m5,8,m4,8,m2,8,m1,24,0,

8,m3,1,0,8,m3,1,0,16,m3,1,0,8,m3,1,0,8,m3,1,0,16,m3,1,0,
8,m3,8,m5,12,m1,4,m2,24,m3,8,m3,
16,m4,1,0,12,m4,1,0,4,m4,1,0,8,m4,16,m3,4,m3,4,m2,
8,m3,8,m2,8,m2,8,m3,16,m2,16,m5,

8,m3,1,0,8,m3,1,0,16,m3,1,0,8,m3,1,0,8,m3,1,0,16,m3,1,0,
8,m3,8,m5,12,m1,4,m2,24,m3,8,m3,
16,m4,1,0,12,m4,1,0,4,m4,1,0,8,m4,16,m3,1,0,4,m3,1,0,4,m3,
8,m5,8,m4,8,m3,8,m2,32,m1,
};

//����춣��
const unsigned char jingle_bell2[]=
{
8,m3,1,0,8,m3,1,0,16,m3,1,0,8,m3,1,0,8,m3,1,0,16,m3,1,0,
8,m3,8,m5,12,m1,4,m2,24,m3,8,m3,
16,m4,1,0,12,m4,1,0,4,m4,1,0,8,m4,16,m3,1,0,4,m3,1,0,4,m3,
8,m5,8,m4,8,m3,8,m2,32,m1,
};

//�������
const unsigned char happy_new_year[]=
{
8,m1,1,0,8,m1,8,l5,8,m3,1,0,8,m3,8,m1,4,m1,4,m3,8,m5,8,m5,
4,m4,4,m3,16,m2,4,m2,4,m3,16,m4,4,m3,4,m2,8,m3,8,m1,
4,m1,4,m3,8,m2,8,l5,4,l7,4,m2,16,m1
};


//GOOD NIGHT
const unsigned char good_night[]=
{
8,m5,8,m6,8,m4,16,m3,1,0,8,m3,8,m2,8,m1,8,l7,
16,m1,8,m3,8,m4,8,m3,8,m6,7,m5,1,0,7,m5,1,0,7,m5,1,0,
8,m4,8,m3,8,m2,16,m3,8,m1,1,0,16,m1,1,0,8,m1,1,0,
16,m1,1,0,8,m1,16,l5,1,0,8,l5,16,m1
};

//СС�Ĵ�
const unsigned char small_boat[]=
{
8,h1,8,m7,8,h1,16,m6,8,m5,8,m4,8,m2,8,m6,24,m5,
16,m6,8,m5,8,m4,8,m2,8,m6,24,m4,8,m6,8,m5,8,m6,8,m4,1,0,8,m4,8,m2,8,m4,8,h1,8,m6,
24,m5,8,m6,8,m5,8,m6,8,h2,8,h3,8,h2,16,m6,8,m5,8,m4,8,m2,8,m4,24,m4
};

//��ɫ��觺�--��̫��,���Բ���
const unsigned char blue_danube[]=
{
8,m1,8,m3,8,m5,1,0,24,m5,1,0,24,m5,1,0,8,m5,8,0,8,m1,
8,m1,8,m3,8,m5,1,0,24,m5,1,0,24,m5,1,0,8,m5,8,0,8,l7,
8,l7,8,m2,8,m6,1,0,24,m6,1,0,24,m6,1,0,8,m6,8,0,8,l7,
8,l7,8,m2,8,m6,1,0,24,m6,1,0,24,m6,1,0,8,m6,8,0,8,m1,
8,m1,8,m3,8,m5,1,0,24,h1,1,0,24,h1,1,0,8,h1,8,0,8,m1,
8,m1,8,m3,8,m5,1,0,24,h1,1,0,24,h1,1,0,8,h1,8,0,8,m2,
8,m2,8,m4,8,m6,1,0,24,m6,1,0,8,m6,8,m4,8,m5,24,h3,
};

//�°���˿
const unsigned char to_anlice[]=
{
2,h3,2,h2,2,h3,2,h2,2,h3,2,h7,2,h2,2,h1,4,m6,2,0,2,m1,2,m3,2,m6,4,m7,2,0,2,m3,2,m5,2,m7,4,h1,
2,0,2,m3,2,h3,2,h2,2,h3,2,h2,2,h3,2,h7,2,h2,2,h1,4,m6,2,0,2,m1,2,m3,2,m6,4,m7,2,0,2,m3,2,h1,2,m7,4,m6,
2,0,2,m7,2,h1,2,h2,4,h3,2,0,2,m5,2,h4,2,h3,4,h2,2,0,2,m4,2,h3,2,h2,4,h1,2,0,2,m3,2,h2,2,h1,4,m7,
2,0,2,m3,2,h3,2,m3,2,h3,2,m3,2,m3,2,h2,2,h3,2,h2,2,h3,2,h2,2,h3,2,h2,2,h3,2,h2,2,h3,2,h2,2,h3,2,m7,2,h2,2,h1,4,m6,
2,0,2,m1,2,m3,2,m6,2,m7,2,0,2,m3,2,m5,2,m7,2,h1,2,0,2,m3,2,h3,2,h2,2,h3,2,m7,2,h2,2,h1,4,m6,
};


//�ؼ�
const unsigned char go_home[]=
{
8,0,8,0,4,m6,4,m5,1,m4,2,m3,1,m2,8,m1,1,0,7,m1,1,0,7,m1,1,0,7,m1,8,m1,1,0,7,m1,1,0,7,m1,8,0,
4,m2,4,m3,4,m3,4,m5,8,m5,8,0,4,m2,4,m3,4,m3,4,m5,8,m5,8,0,4,m5,4,m6,4,m6,2,m3,2,m1,4,m2,8,m2,1,0,7,m2,,1,0,7,m2,8,0,
4,m2,4,m3,4,m3,4,m5,8,m5,8,0,4,m2,4,m3,4,m3,4,m5,8,m5,8,0,4,m5,4,m6,4,m6,2,m3,2,m1,4,m2,8,m2,1,0,7,m2,,1,0,7,m2,4,m6,4,m7,
8,h1,4,m7,4,h1,4,h1,4,m6,4,m7,4,h1,8,h1,4,m7,4,h1,8,h1,2,0,2,m3,2,m6,2,m7,8,h1,2,m7,2,h1,4,h3,4,h3,4,h2,4,h1,4,m7,8,m7,1,0,8,m7,4,0,4,m3,4,m6,4,m7,
8,h1,4,m7,4,h1,4,h1,4,m6,4,m7,4,h1,8,h1,4,m7,4,h1,8,h1,2,0,2,m3,2,m6,2,m7,8,h1,2,m7,2,h1,4,h3,4,h3,4,h2,4,h1,4,m7,6,m2,2,m3,2,0,4,0,4,m3,4,m6,4,m7,
};

//����Ϊԭ����ҵ��ʹ�õ���������,��������˵��������⴦��
const unsigned char openbuz[]={10,Y2304,10,0,10,Y2463,10,0,10,Y2740,10,0};
const unsigned char closebuz[]={10,Y2304,10,0,10,Y2066,10,0,10,Y2304,10,0,10,Y1736,10,0,10,Y2066,10,0,10,Y1838,10,0,10,Y1543,10,0};
const unsigned char pausebuz[]=	{5,Y2732,15,0};
const unsigned char startbuz[]={5,Y2732,5,0,5,Y2564,5,0,5,Y2415,5,0,5,Y2310,5,0,5,Y2165,5,0};
const unsigned char endbuz[]=
	{10,Y1968,20,0,30,Y1572,20,0,10,Y1968,20,0,20,Y1572,15,0,5,Y1968,15,0,10,Y2347,15,0,10,Y2347,10,0,10,Y2092,10,0,10,Y1968,10,0,
10,Y1760,10,0,5,Y1572,10,0,5,Y1572,15,0};

const unsigned char errbuz[]=
{15,Y2732,10,0,15,Y2128,10,0,15,Y2732,10,0,15,Y2128,10,0,15,Y2732,10,0,15,Y2128,10,0,
15,Y2732,10,0,15,Y2128,10,0,15,Y2732,10,0,15,Y2128,10,0,15,Y2732,10,0,15,Y2128,10,0,
15,Y2732,10,0,15,Y2128,10,0,15,Y2732,10,0,15,Y2128,10,0,15,Y2732,10,0,15,Y2128,10,0,
15,Y2732,10,0,15,Y2128,10,0,15,Y2732,10,0,15,Y2128,10,0,15,Y2732,10,0,15,Y2128,10,0,
15,Y2732,10,0,15,Y2128,10,0,15,Y2732,10,0,15,Y2128,10,0,15,Y2732,10,0,15,Y2128,10,0,};

const unsigned char testbuz[]=
{5,Y2128,5,Y2242,5,0,5,Y2228,5,0,5,Y2564,5,0,5,Y2732,5,0,5,Y2294,5,0,5,Y2415,5,0,
5,Y2463,5,0,5,Y2347,5,0,5,Y2092,5,0,5,Y1968,5,0,5,Y2165,5,0,5,Y2128,5,0,
5,Y2049,5,0,5,Y2525,5,0,5,Y2604,5,0,5,Y2809,5,0,5,Y2404,5,0,5,Y2577,5,0,5,Y2632,5,0,5,Y2347,5,0,5,
Y2242,5,0,5,Y1968,5,0,5,Y2232,5,0,5,Y2128,5,0,5,Y2809,5,0};

const unsigned char lastbuz[]={5,Y2304,5,0,5,Y2463,5,0};

const unsigned char nwbuz[]={5,Y2732,5,0,5,Y2732,5,0};

const unsigned char lkeybuz[]={10,Y2304,10,0};

const unsigned char mf2591[]={5,Y2591,15,0};
const unsigned char mf2220[]={5,Y2220,15,0};
const unsigned char mf2165[]={5,Y2165,15,0};
const unsigned char mf2294[]={5,Y2294,15,0};
const unsigned char mf2370[]={5,Y2370,15,0};
const unsigned char mf2732[]={5,Y2732,15,0};
const unsigned char mf2427[]={5,Y2427,15,0};
const unsigned char mf2525[]={5,Y2525,15,0};
const unsigned char mf2564[]={5,Y2564,15,0};


//-------------------- �������ݱ�--���� ------------------------------------------------------------

#ifndef PWM8B_CM
#define PWM8B_CM
#endif


//-----------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif
void abort(void);
#ifdef __cplusplus
}
#endif

void main(void)
{
uchar lst1;
	nop();
	nop();
main_1:
	ini_ram();	//RAM��ʼ��,��Ҫд��0�������
	ini_pp();	//�˿ڼ���Χ���ܳ�ʼ��
	lst1=200;
	for(;;) 
	{
main_2:
		emi_p();
main_6:
		RESET_WATCHDOG(); 
		if (!mflg10ms) goto main_2;
		mflg10ms=0;
		lst1++;

		if (!buzstp)
		{
			if (lst1>=200)
			{
//				btMusicSet=MFSELF;
//				music_sel_ts_flg=1;
				btMusicSet=8;
				buzstp=1;
			}
		}
		else lst1=0;

		Music_Select();
		Musicing();
	}
}





//------******---START---******---��---******---��---******---��---******---��---******---START---******------//
//����ѡ��
//���ѡ����������,������btMusicSet��,��Ҫͬʱ����music_sel_ts_flg=1
void Music_Select(void)
{
	if (btMusicSet==0) return;
	if (!music_sel_ts_flg) goto Music_sel2;
	switch(btMusicSet)
	{
		case MF2591:	
			music_ptr=mf2591;
			music_yinf_nu=(sizeof(mf2591))/2;
			break;
		case MF2165:	
			music_ptr=mf2165;
			music_yinf_nu=(sizeof(mf2165))/2;
			break;
		case MF2220:
			music_ptr=mf2220;
			music_yinf_nu=(sizeof(mf2220))/2;
			break;
		case MF2294:	
			music_ptr=mf2294;
			music_yinf_nu=(sizeof(mf2294))/2;
			break;
		case MF2370:
			music_ptr=mf2370;
			music_yinf_nu=(sizeof(mf2370))/2;
			break;
		case MF2427:
			music_ptr=mf2427;
			music_yinf_nu=(sizeof(mf2427))/2;
			break;
		case MF2525:
			music_ptr=mf2525;
			music_yinf_nu=(sizeof(mf2525))/2;
			break;
		case MF2564:
			music_ptr=mf2564;
			music_yinf_nu=(sizeof(mf2564))/2;
			break;
		case MFPWON:
			music_ptr=openbuz;
			music_yinf_nu=(sizeof(openbuz))/2;
			break;
		case MFSTRT:
			music_ptr=startbuz;
			music_yinf_nu=(sizeof(startbuz))/2;
			break;
		case MFPASU:
			music_ptr=pausebuz;
			music_yinf_nu=(sizeof(pausebuz))/2;
			break;
		case MFERRO:
			music_ptr=errbuz;
			music_yinf_nu=(sizeof(errbuz))/2;
			break;
		case MFNWTR:
			music_ptr=nwbuz;
			music_yinf_nu=(sizeof(nwbuz))/2;
			break;
		case MFZHQI:
			music_ptr=lastbuz;
			music_yinf_nu=(sizeof(lastbuz))/2;
			break;
		case MFSELF:
			music_ptr=testbuz;
			music_yinf_nu=(sizeof(testbuz))/2;
			break;
		case MFEND:
			music_ptr=endbuz;
			music_yinf_nu=(sizeof(endbuz))/2;
			break;
		case MFPOFF:
			music_ptr=closebuz;
			music_yinf_nu=(sizeof(closebuz))/2;
			break;
		case MF2304:
			music_ptr=lkeybuz;
			music_yinf_nu=(sizeof(lkeybuz))/2;
			break;
		default:
			break;
	}

	goto Music_sel1;
Music_sel2:
	switch (btMusicSet)
	{
		case 1:
			music_ptr=mybonie;
			music_yinf_nu=(sizeof(mybonie))/2;
			break;
		case 2:
			music_ptr=mysunshine;
			music_yinf_nu=(sizeof(mysunshine))/2;
			break;
		case 3:
			music_ptr=jingle_bell1;
			music_yinf_nu=(sizeof(jingle_bell1))/2;
			break;
		case 4:
			music_ptr=jingle_bell2;
			music_yinf_nu=(sizeof(jingle_bell2))/2;
			break;
		case 5:
			music_ptr=blue_danube;
			music_yinf_nu=(sizeof(blue_danube))/2;
			break;
		case 6:
			music_ptr=happy_new_year;
			music_yinf_nu=(sizeof(happy_new_year))/2;
			break;
		case 7:
			music_ptr=good_night;
			music_yinf_nu=(sizeof(good_night))/2;
			break;
		case 8:
			music_ptr=small_boat;
			music_yinf_nu=(sizeof(small_boat))/2;
			break;
		case 9:
			music_ptr=happy_new_year;
			music_yinf_nu=(sizeof(happy_new_year))/2;
			break;
		case 10:
			music_ptr=happy_new_year;
			music_yinf_nu=(sizeof(happy_new_year))/2;
			break;
		default:
			break;
	}
Music_sel1:
	musicruning=1;
	btMusicSet=0;
	music_1st_flg=0;
	Buzzeron();

}

//�������
void Musicing(void)
{
	if (!musicruning)
	{
		jiepai_kx=0;	//ֹͣ���
		buzstp=0;
		return;
	}
	if (music_pai_ct==0)
	{//��ǰ��������
		if (music_yinf_nu!=0) 
		{//��һ������
			music_yinf_nu--;
			music_pai_ct=*music_ptr;	//�������������
			music_pai_ct&=0x1f;
			if (!music_sel_ts_flg) music_pai_ct*=4;
			music_ptr++;
			music_peri=*(music_ptr);
			if (music_peri==xz) 
			{
				music_peri=*(music_ptr-2);
				jiepai_kx=0;
			}
			else jiepai_kx=1;
			music_ptr++;

			#ifdef PWM8B_CM
			if (music_sel_ts_flg)
			{
				music_peri=pwm8b_ts[music_peri];
				pwm_period=music_peri;
				pwm_duty=music_peri/2;
			}
			else
			{
				music_peri=pwm8b_mc[music_peri];
				pwm_period=music_peri;
				pwm_duty=music_peri/2;
			}
			#endif

			#ifdef PWM10B_CM
			ls1=pwm10b_mc[music_peri*2];
			ls2=pwm10b_mc[music_peri*2+1];
			pwm_period_h=ls1;
			pwm_period_l=ls2;
			pwm_duty_h=ls1/2;
			pwm_duty_l=ls2/2;
			#endif

			#ifdef PWM16B_CM
			ls1=pwm16b_mc[music_peri*2];
			ls2=pwm16b_mc[music_peri*2+1];
			pwm_period_h=ls1;
			pwm_period_l=ls2;
			pwm_duty_h=ls1/2;
			pwm_duty_l=ls2/2;
			#endif
		}
		else
		{//����������
			musicruning=0;
			buzstp=0;
			jiepai_kx=0;
			music_sel_ts_flg=0;
			return;
		}
	}
	if (music_pai_ct!=0)	
	{
		music_pai_ct--;
	}
}



//------******---END---******---��---******---��---******---��---******---��---******---END---******------//


void pPIT_ISR_P (void)
{
	//1����
	TW.TSRW.BYTE&=0x7f;
	TW.TCNT=57536;		//1����
	jsq10ms++;
	if (jsq10ms>=10)
	{
		jsq10ms=0;
		mflg10ms=1;
//		lsct++;
	}
}






//----------------------------------------------------------------------//
//�ڲ�RAM��ʼ������,														//
//��00~1ffȫ����0
//----------------------------------------------------------------------//
void ini_ram(void)
{
uint *p;
uint i;
	p=&STAFLGU;
	for (i=0;i<400;i++)
	{
		*p=0;
		p++;
	}
}



//----------------------------------------------------------------------//
//�ڲ���Χ���ܳ�ʼ��--Ϊ������, �ٴ���
//----------------------------------------------------------------------//
void emi_p(void)
{
	portcr1 =0x67;	//0b01100111;	//����
	portcr2 =0x07;	//0b00000111;	//����
	portcr5 =0xff;	//0b11111111;	//����
	portcr7 =0x59;	//0b01011001;	//����
	portcr8 =0x0f;	//0b00001111;	//����
}


//----------------------------------------------------------------------//
void ini_pp(void)
{
	portmr1 =0x08;	//0b00001000;	// TXD2
	PORT1 =0x98;	//0b10011000;
	portur1=0x00;	//0b00000000;

	PORT2 =0x00;	//0b00000000;

	portmr5 =0x00;	//0b00000000;	//Ϊ��ͨIO
	PORT5 =0xc0;	//0b11000000;
	portur5=0x00;	//0b00000000;

	PORT7 =0x16;	//0b00010110;

	PORT8 =0x07;	//0b00000111;

	emi_p();

//TIMERV��ʼ��
//����ģʽ,ˮλ����
//	TV.TCNTV=0;
//	TV.TCRV0.BYTE=0x05;	//0b00000101	//�ⲿ����--����ģʽ


//TIMERV��ʼ��
//���2.5KƵ�� ����������
	TV.TCNTV=0;
	TV.TCRV0.BYTE=0x0b;	//0b00001011;	//��Aƥ�� ��������0  ��������Ϊ1/64��Ƶ��
//	TV.TCRV1.BIT.ICKS=1;
	TV.TCORA=0xFF;			//2.5K�Ƚϳ���
	TV.TCORB=0xFF;			//��50%ʱ��B�Ƚ�ƥ��, ������50%ռ�ձ�

/*
//TIMERV��ʼ��
//��ʱ1�����ж�
	TV.TCNTV=0;
	TV.TCRV0.BYTE=0x4a;	//01001010 ��Aƥ���ж�, ����0
	TV.TCSRV.BYTE=0x10;	//00010000
	TV.TCRV1.BYTE=0xe3;	//11100011
	TV.TCORA=250;
*/


//TIMERW��ʼ��
//��ʱ1����,������ʾɨ��Ͷ�ʱ��ʱ
	TW.GRA=0xffff;
	TW.GRB=0xffff;
	TW.GRC=0xffff;
	TW.GRD=0xffff;
	TW.TCNT=57536;	//1����						//25536;		//5����
	TW.TIOR0.BYTE=0x88;	//0b10001000;
	TW.TIOR1.BYTE=0x88;	//0b10001000;
	TW.TMRW.BYTE=0xc8;	//0b11001000;
	TW.TCRW.BYTE=0x80;	//0b10000000;
	TW.TSRW.BYTE=0x70;	//0b01110000
	TW.TIERW.BYTE=0xf0;	//0b11110000;
	TW.TMRW.BIT.CTS=1;	//START

/*
//TIMERW��ʼ��
//�ⲿ�����ˮλ
	TW.GRA=0xffff;
	TW.GRB=0xffff;
	TW.GRC=0xffff;
	TW.GRD=0xffff;
	TW.TCNT=0;	//
	TW.TIOR0.BYTE=0x88;	//10001000;
	TW.TIOR1.BYTE=0x88;	//0b10001000;
	TW.TMRW.BYTE=0xc8;	//0b11001000;
	TW.TCRW.BYTE=0x40;	//0b01000000;	//�ⲿ����
	TW.TSRW.BYTE=0x70;	//0b01110000
	TW.TIERW.BYTE=0x70;	//0b01110000;
	TW.TMRW.BIT.CTS=1;	//START
*/	

//ADC��ʼ��
	AD.ADCSR.BYTE=0x03;	//00000011   ����ģʽ 4ͨ��
/*
//SCI--2 ��ʼ��
//9600BPS 1����ʼ  1��ֹͣ ��У��
	SCI3_2.SCR3.BYTE=0x00;
	SCI3_2.SMR.BYTE=0x00;	//00000000  1 ��ʼ  1����  8���� �ڲ�1:1 ��У��
	SCI3_2.BRR=25;		//9600BPS
	delayus(120);
	SCI3_2.SSR.BYTE=(SCI3_2.SSR.BYTE|0x80)&0x80;
	SCI3_2.SCR3.BYTE=0x50;	//��������  ���ͽ�ֹ �����ж�����  �����жϽ�ֹ
*/
//WDT��ʼ��
//WDTʱ��Ϊ120����
	WDT.TMWD.BYTE  =0x0e;	//0b00001110;	//ʱ�䳣�� 
	WDT.TCSRWD.BIT.B4WI=0;
	WDT.TCSRWD.BIT.TCSRWE=1;
	WDT.TCSRWD.BIT.WDON=1;		//WDT����
	WDT.TCSRWD.BIT.TCSRWE=0;
	WDT.TCSRWD.BIT.B4WI=0;


//�жϳ�ʼ��
//  IRQ0�ж�  �����ر�
//	IENR1.BYTE=0x01;	//0b00000001;	IRQ3 disable  IRQ0 ENABLE
//	CCR.BIT.I=0;		//���ж�����
	set_imask_ccr(0);
}
