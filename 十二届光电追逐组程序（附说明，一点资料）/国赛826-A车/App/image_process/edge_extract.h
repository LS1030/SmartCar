#ifndef _EDGE_EXTRACT_H_
#define _EDGE_EXTRACT_H_

/*------------------------------�궨����--------------------------------*/


/*
int16 bar_range_col[CAMERA_H]={10,11,12,13,14,15,16,17,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,31,32,33,34,35,36,37,38,39,40,41,42,43,44,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,58,59,60,61,62,63,64,65};
a�����*/

/*���沿�ֺ궨��*/
#define PI                3.1415926       //piֵ

#define DOT_B             0               //�ڵ�ĻҶ�ֵ
#define DOT_W             255             //�׵�ĻҶ�ֵ
#define DOT_M             127             //�м�ĻҶ�ֵ

#define ROW_START         0               //��ɨ����ʼ��
#define ROW_END           (CAMERA_H-1)    //��ɨ����ֹ��

#define COL_START         0               //��ɨ����ʼ��
#define COL_END           (CAMERA_W-1)    //��ɨ����ֹ��

#define ROW_W_SUM         8               //����������ֵ
#define ROW_W_NUM         4               //���ѵõ��İ׵�����ֵ��������ֵ���ж�Ϊ���ű���
#define COL_W_NUM         8               //�M�ѵõ��İ׵�����ֵ��������ֵ���ж�Ϊ���ű���


#define curve_div         220             //���������������


#define s_start_row       (CAMERA_H-20)   //�յ���������������

#define straight_end      0               //ֱ��������������
#define straight_start    54              //ֱ��������ʼ����

#define loop_out_end      5               //��������������������
#define loop_per          75              //�����������
#define loop_out_l        3000            //��������

#define end_line_end      7               //�յ���������������
#define end_line_gray_add   10            //�յ����лҶȼ������ֵ


/*ʮ�ֲ��ֺ궨��*/
#define CROSS_UP_ROW      2               //����������ʮ��ֱ�ǹյ���
#define CROSS_UP_COL      4               //����ͻ���ж���ʮ��ֱ�ǹյ��з�ֵ
#define CROSS_ERTRACT     10              //������ʮ��ֱ�ǹյ���������
#define CROSS_DOWN_ROW    4               //����������ʮ��ֱ�ǹյ���
#define CROSS_DOWN_COL    8               //����ͻ���ж���ʮ��ֱ�ǹյ��з�ֵ
#define CROSS_START_ROW   (CAMERA_H-10)    //��ʼ����ʮ��ֱ�ǹյ���

#define L_CROSS_ADD       40              //��������㲢���������ʮ�ֱ�־ʱ������������Χ
#define L_LOST_CROSS      6               //����س���ʱ����߽��������ж����ʮ�֣����ڴ�ֵ��
#define R_CROSS_ADD       40              //�ұ������㲢�����ұ���ʮ�ֱ�־ʱ������������Χ
#define R_LOST_CROSS      (CAMERA_W-7)    //�ұ��س���ʱ����߽��������ж��ұ�ʮ�֣�С�ڴ�ֵ��

#define cross_k_add       40              //��ʮ��������Χ
#define cross_k_add_1     70              //��ʮ��������Χ
#define cross_k_1         0.16            //��ʮ��������Χϵ��
#define cross_k_2         280             //��ʮ��������Χϵ��


/*�ϰ����ֺ궨��*/
#define bar_search_end    35             //����ʹ�ÿ�������ϰ�������
#define BAR_UP_ROW        10             //���������ϰ���
#define BAR_ADD           6              //�ϰ���������
#define BAR_DIV           8              //�ϰ�����������ʹ��ԭ��bar_range_col[i]/BAR_DIV��


/*���߲��ֺ궨��*/
#define L_LOST            119             //����ض�ʧʱ������������Χ
#define L_EDGE_IN         60              //�����û������ʱ������������Χ
#define L_EDGE_OUT        60              //�����û������ʱ������������Χ
#define L_IN_2_IN         60              //���������ʱ������������Χ
#define L_IN_2_OUT        40              //���������ʱ������������Χ
#define L_OUT_2_IN        40              //���������ʱ������������Χ
#define L_OUT_2_OUT       40              //���������ʱ������������Χ
#define L_OUT_END         20              //��������㶪ʧ�����ж�
#define L_LOOP            20              //����ض�ʧ����������Χ

#define R_LOST            40              //�ұ��ض�ʧʱ������������Χ
#define R_EDGE_IN         60              //�����û������ʱ������������Χ
#define R_EDGE_OUT        60              //�����û������ʱ������������Χ
#define R_IN_2_IN         60              //�ұ�������ʱ������������Χ
#define R_IN_2_OUT        40              //�ұ�������ʱ������������Χ
#define R_OUT_2_IN        40              //�ұ�������ʱ������������Χ
#define R_OUT_2_OUT       40              //�ұ�������ʱ������������Χ
#define R_OUT_END         139             //�ұ������㶪ʧ�����ж�
#define R_LOOP            140             //�ұ��ض�ʧ����������Χ


/*�����������*/
#define edge_clean();           memset(left_edge,-1,sizeof(left_edge));             \
                                memset(right_edge,-1,sizeof(right_edge));           \
                                memset(L_down_cross,-1,sizeof(L_down_cross));       \
                                memset(L_up_cross,-1,sizeof(L_up_cross));           \
                                memset(R_down_cross,-1,sizeof(R_down_cross));       \
                                memset(R_up_cross,-1,sizeof(R_up_cross));           \
                                memset(midline,-1,sizeof(midline));                 \
                                //memset(left_down_edge,-1,sizeof(left_down_edge));   \
                                memset(right_down_edge,-1,sizeof(right_down_edge)); \
                                memset(midline_down_x,-1,sizeof(midline_down_x));   \
                                memset(midline_down_y,-1,sizeof(midline_down_y));   \

/*----------------------------------------------------------------------*/

/*------------------------------����������------------------------------*/

        /*���±���������Ҫ�����ⲿ����*/


extern double angle_aaa[4];

extern uint8 cross_num;                  //ʮ�ּ���

extern uint8 L_bar_num;                  //����ϰ������
extern uint8 R_bar_num;                  //�ұ��ϰ������

extern uint8 loop_num;                   //��������
extern uint8 end_line_num;             //�����߼���

extern uint8 car_over_able;              //����ʶ��ʹ�ܱ�־λ
extern uint8 car_over_ok;                //�����ɹ���־λ
extern int32 bar_car_val;                //��������

extern uint8 L_EDGE_NUM;                 //����ظ���
extern uint8 R_EDGE_NUM;                 //�ұ��ظ���

extern uint8 L_LINK_NUM;                 //��������ظ������������������Ϊ�����������ظ�����
extern uint8 R_LINK_NUM;                 //�����ұ��ظ������������������Ϊ�����������ظ�����

extern uint8 L_cross_flag;               //������жϽ���ʮ�ֱ�־
extern uint8 R_cross_flag;               //�ұ����жϽ���ʮ�ֱ�־
extern uint8 cross_flag;                 //�жϽ���ʮ�ֱ�־

extern uint8 L_search_end;               //���������������־
extern int16 L_end_row;                  //�������������ʱ����������
extern int16 L_down_end_row;             //�����������������ʱ����������

extern uint8 R_search_end;               //�ұ�������������־
extern int16 R_end_row;                  //�ұ�����������ʱ����������
extern int16 R_down_end_row;             //�ұ���������������ʱ����������

extern uint8 loop_able;                  //��������ʹ�ܱ�־
extern uint8 LOOP_FLAG;                  //����������־
extern uint8 LOOP_TEMP;                  //���������ݴ��־
extern uint32 LOOP_TEMP_1;               //���������ݴ��־_1
extern uint8 LOOP_IN;                    //�������������־
extern uint8 LOOP_OUT;                   //����������Ҫ�뿪��־
extern uint8 loop_l_r_flag;              //��������ת���жϱ�־��Ϊ1ʱ��ת��Ϊ0ʱ��ת��
extern int16 LOOP_IN_ROW;                //�������������
extern int16 LOOP_OUT_ROW;               //��������������
extern int16 out_row[2];                 //�������������д洢����
extern int32 loop_val;                   //��������

extern uint8 barrier_able;               //ʹ�ܼ���ϰ���־
extern uint8 L_barrier_flag;             //������ϰ���־
extern uint8 R_barrier_flag;             //�ұ����ϰ���־
extern int16 L_barrier_down_row;         //������ϰ����±�����
extern int16 L_barrier_up_row;           //������ϰ����ϱ�����
extern int16 R_barrier_down_row;         //�ұ����ϰ����±�����
extern int16 R_barrier_up_row;           //�ұ����ϰ����ϱ�����
extern int16 car_extract_row;            //���ǰ��������
extern uint8 car_extract_able;           //ǰ�����ʹ�ܱ�־

extern uint8 end_line_able;              //�յ���ʹ�ܼ���־
extern uint8 END_LINE_FLAG;              //�յ��߱�־
extern uint8 END_LINE_TEMP;              //�յ����ݴ��־
extern uint8 END_LINE_TEMP_1;            //�յ����ݴ��־_1
extern int16 end_line_row;               //�յ���������
extern int16 end_line_2[2];              //�յ�������������

extern uint8 L_TURN;                     //�����������ж�Ϊ��ת���־
extern uint8 R_TURN;                     //�����������ж�Ϊ��ת���־
extern int16 curve_in_row;               //��������
extern int16 curve_car_row;              //���ǰ������

extern uint8 STRAIGHT_FLAG;              //ֱ����־

extern uint8 S_FLAG;                     //S�� ������־
extern int16 L_s_temp;                   //������ж�S�� ������־
extern int16 R_s_temp;                   //�ұ����ж�S�� ������־
extern double s_down_dis;               //S�� ������ǰհ����

extern uint8 RAMP_FLAG;                  //�µ���־
extern uint8 RAMP_TEMP;                  //�µ��ݴ��־
extern int32 ramp_val;                   //�µ�����
extern uint8 ramp_able;                  //�µ�ʹ�ܼ���־

extern uint8 little_s_flag;              //СS�������־

extern double inv_distance[CAMERA_H];    //��͸�ӻ�ȡÿ��ʵ�ʾ�������
extern double bar_range_col[CAMERA_H];   //�ϰ���������Χ����

extern int16 L_down_cross[2];            //�����ʮ���·�ֱ�ǹյ����飨[0]Ϊʮ�ֹյ�������ֵ��[1]Ϊʮ�ֹյ�������ֵ��
extern int16 L_up_cross[2];              //�����ʮ���Ϸ�ֱ�ǹյ����飨[0]Ϊʮ�ֹյ�������ֵ��[1]Ϊʮ�ֹյ�������ֵ��

extern int16 R_down_cross[2];            //�ұ���ʮ���·�ֱ�ǹյ����飨[0]Ϊʮ�ֹյ�������ֵ��[1]Ϊʮ�ֹյ�������ֵ��
extern int16 R_up_cross[2];              //�ұ���ʮ���Ϸ�ֱ�ǹյ����飨[0]Ϊʮ�ֹյ�������ֵ��[1]Ϊʮ�ֹյ�������ֵ��

extern int16 left_edge[CAMERA_H];              //����ش������
extern int16 right_edge[CAMERA_H];             //�ұ��ش������

extern int16 left_down_edge[10];         //�½�����ش������
extern int16 right_down_edge[10];        //�½��ұ��ش������

/*----------------------------------------------------------------------*/

/*------------------------------����������------------------------------*/

extern void edge_extract();             //�˺���Ϊ������ȡ������

extern void tan_angle();                //�˺���Ϊб�ʽǶ��Ʊ���

extern void bar_range();                //�˺���Ϊÿ���ϰ���������Χ��ȡ����

extern void bar_car();                  //�˺���Ϊ�����жϺ���
/*----------------------------------------------------------------------*/






#endif