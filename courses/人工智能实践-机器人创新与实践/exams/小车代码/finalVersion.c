#include <includes.h> 
int CHGCi;
//�趨������
#define right1 analog(1)  //��ǰ
#define right2 analog(2)
#define right3 analog(3)
#define right4 analog(4)
#define left4 analog(5)
#define left3 analog(6)
#define left2 analog(7)
#define left1 analog(8)//��ǰ
#define mid_left analog(17) //����
#define mid_right analog(18)//����
#define hdy analog(19)//ǰ����-123
#define hdy analog(20)//ǰ����-2
#define cz1 digital(1) 
#define cz2 digital(2)
#define cz3 digital(3)
#define W 400  //��ɫ
#define W5 400  //5��ɫ
#define Y 100//��ɫ
#define B 150//��ɫ 
#define G 200//1 8�� 
#define R 100//��ɫ
#define BORD 1 //����
#define V 50  // ����
void fzjs(void);//��ֵ����
void fzxs(void);//��ֵ��ʾ
void mdcs(void);//�������
void djcs (void);//�������
void run(int n, int p);//�����������ֵ���ٶ�
void line(int base);//ƽ������
void station1(int time1, int time2);//station1:��̨�ϵ�ͷ�Ĳ���
void motion(void);//motion:�������
void tai(int left, int right, int time1, int time2);//tai:��������̨����̨�Ĳ���
void turn_left(void);
void turn_left_45(void);
void turn_left_135(void);
void turn_right(void);
void turn_right_135(void);
void dt(int time);
void brline(int base);
void start(void);//��������
void run_utill(int speed, char color, char direction);
void line_black_brige(int base);
void line_small_1(int base);
void line_small_2(int base);
void from_0_to_1(void);
void from_1_to_2(void);
void from_2_to_3(void);
void from_3_to_4(void);
void peng(char color,char direction);
void peng2(char color,char direction);
void peng3(char color,char direction);
void neofrom_1_to_2(void);//m
void newfrom_1_to_2(void);
void door(void);
int hdb[28],hdh[28],fz[28],hdc[28];//hdb[28]��ɫ�Ҷ�ֵ��hdh[28]�̵�̺�Ҷ�ֵ��fz[28]��ֵ��hdc[28]�ҶȸߵͲ�ֵ��
int i,v=0,k=0,znz=0,z=0,d=34,b=0,a=0;
int flag=0;
void run_for_half_second(int m, int p);
void run_for_half_second(int m, int p) {
    run(m, p);       // �������
    delay(0, 500);   // �ӳ� 500 ���루0.5 �룩
    run(0, 0);       // ֹͣ���
}
void run(int m,int p)
{
	int rate = 1;
	motor(1,m * rate);
	motor(2,p * rate);
}
//line:ƽ������
void line(int base)
{
	if (base>0){
	     if( analog(4)>W&&analog(5)>W  )   //&&analog(1)<W&&analog(2)<W &&analog(3)<W &&analog(6)<W &&analog(7)<W &&analog(8)<W 
	     {
	          run(base,base);   
	      }
	     else if(analog(4)<W&&analog(5)>W) 
	     { 
	      run(0.9*base,1.1*base);   
	     }
	     else if(analog(4)>W&&analog(5)<W)   
	     { 
	      run(1.1*base,0.9*base);    
	     }
	     else if(analog(3)<W&&analog(6)>W) 
	     { 
	      run(0.8*base,1.3*base);   
	     }
	     else if(analog(3)>W&&analog(6)<W)   
	     {  
	      run(1.3*base,0.8*base);    
	     }
	     else if(analog(2)<W&&analog(7)>W)  
	     {  
	      run(0.5*base,1.5*base);   
	     }
	     else if(analog(7)<W&&analog(2)>W)   
	     {  
	      run(1.5*base,0.5*base);    
	     }
	     else if(analog(1)>	W&&analog(8)<W)
	     {
	      run(1.5*base,0.4*base);
	     }
	     else if(analog(8)>W&&analog(1)<W)
	     {
	      run(0.4*base,1.5*base);
	     }
    }
    else{
    	if( analog(4)>W&&analog(5)>W5)   
	     {
	          run(base,base);   
	      }
	     else if(analog(4)<W&&analog(5)>W5) 
	     { 
	      run(1.1*base,0.9*base);   
	     }
	     else if(analog(4)>W&&analog(5)<W5)   
	     { 
	      run(0.9*base,1.1*base);    
	     }
	     else if(analog(3)<W&&analog(6)>W) 
	     { 
	      run(1.3*base,0.8*base);   
	     }
	     else if(analog(3)>W&&analog(6)<W)   
	     {  
	      run(0.8*base,1.3*base);    
	     }
	     else if(analog(2)<W&&analog(7)>W)  
	     {  
	      run(1.5*base,0.5*base);   
	     }
	     else if(analog(7)<W&&analog(2)>W)   
	     {  
	      run(0.5*base,1.5*base);    
	     }
	     else if(analog(1)>	W&&analog(8)<W)
	     {
	      run(0.4*base,1.5*base);
	     }
	     else if(analog(8)>W&&analog(1)<W)
	     {
	      run(1.5*base,0.4*base);
	     }
	}
}
void brline(int base)
{
	if (base>0){
	     if( analog(4)<V&&analog(5)<V  )   //&&analog(1)<W&&analog(2)<W &&analog(3)<W &&analog(6)<W &&analog(7)<W &&analog(8)<W 
	     {
	          run(base,base);   
	      }
	     else if(analog(4)<V&&analog(5)>V) 
	     { 
	      run(1.1*base,0.9*base);   
	     }
	     else if(analog(4)>V&&analog(5)<V)   
	     { 
	      run(0.9*base,1.1*base);    
	     }
	     
	     else if(analog(3)<V&&analog(6)>V) 
	     { 
	      run(1.3*base,0.8*base);   
	     }
	     else if(analog(3)>V&&analog(6)<V)   
	     {  
	      run(0.8*base,1.3*base);    
	     }
	     
	     else if(analog(2)<V&&analog(7)>V)  
	     {  
	      run(1.5*base,0.5*base);   
	     }
	     else if(analog(7)<V&&analog(2)>V)   
	     {  
	      run(0.5*base,1.5*base);    
	     }
	     else if (analog(4)>100&&analog(5)>100&&analog(1)<100&&analog(8)<100){
		run(base,base);
		delay(0,300);	     
	     }

	     else if(analog(1)>	G&&analog(8)<G)
	     {
	      run(1.5*base,0.4*base);
	     }
	     else if(analog(8)>G&&analog(1)<G)
	     {
	      run(0.4*base,1.5*base);
	     }
	     
    }
}


//station1:��̨�ϵ�ͷ�Ĳ���
void station1(int time1, int time2){
	run(0,0);
	delay(0,500);
	servo(1,880);delay(0,300);
	motor(1, 60);motor(2 , -60);delay(time1,time2);
	servo(1,200);delay(0,100);
	run(0,0);
	delay(0,500);
}

//motion:�������
void motion(void){
//	servo(2,980 );delay( 0,100);		// ������
  	servo(3,800 );servo(4, 800);servo(5,800 );delay(0 ,300);//ͷ������ҡ�ڣ��ֱ����°ڶ�����3/4/5�Ŷ��100<��ֵ<800��
      servo(3,200 );servo(4, 200);servo(5,200 );delay(0 ,300);//ͷ������ҡ�ڣ��ֱ����°ڶ���3/4/5�Ŷ��100<��ֵ<800��
	servo(3,800 );servo(4, 800);servo(5,800 );delay(0 ,300);//ͷ������ҡ�ڣ��ֱ����°ڶ�����3/4/5�Ŷ��100<��ֵ<800��
      servo(3,200 );servo(4, 200);servo(5,200 );delay(0 ,300);//ͷ������ҡ�ڣ��ֱ����°ڶ���3/4/5�Ŷ��100<��ֵ<800��
 // 	servo(2,500 );delay( 0,100);		// ������
}

//tai:��������̨����̨�Ĳ���
void tai(int left, int right, int time1, int time2){
	run(left,right);
	delay(0, 800);
	run(0,0);
	delay(0,500);
	dt(time2);
		run(0,0);
	delay(0,500);
	//תȦ180��
	//��̨
	/*run(30,30);
	delay(0,450);
	run(0,0);
	delay(0,200);
	if(!(analog(1)>W||analog(2)>W||analog(2)>W||analog(3)>W||analog(4)>W||analog(5)>W||analog(6)>W||analog(8)>W))
		while(!(analog(2)>W||analog(3)>W||analog(4)>W||analog(5)>W||analog(6)>W||analog(7)>W))
			run(20,-20);
	*/
}


void dt(int time){
		display_str(4,17,"4:");
	run(0,0);
	delay(0,150);
	motor(1, -25);motor(2 , 25);delay(0,time*2);// ��ת	
	//motor(1, -40);motor(2 , 40);delay(0,time);  //ԭʼ����  ע�⣺��ѹ�ߵ�ʱ�����ת��Сһ�㣬��ѹ�͵�ʱ����Ҫ�ʵ�����ת�����ٶ�
	//��ѹ23.1~23.9��23*2  ��ѹ24��40
}
//turn_left:��ת
void turn_left(void){
	run(20,20);
	delay(0,120);
	run(0,0);
	delay(0,150);
	motor(1, -10);motor(2 , 40);delay(0,320);// ��ת//380	//320
}
void turn_left_45(void){
	run(20,20);
	delay(0,225);
	run(0,0);
	delay(0,150);
	motor(1, -10);motor(2 , 50);delay(0,200);// ��ת	
}
void turn_left_135(void){
	run(20,20);
	delay(0,225);
	run(0,0);
	delay(0,150);
	motor( 1, -50);motor(2 , 50);delay(0,270);// ��ת//270	
}

//turn_right��ת
void turn_right(void){
	run(20,20);
	delay(0,120);
	run(0,0);
	delay(0,150);
	motor( 1, 50);motor(2 , -10);delay(0,380);// ��ת//380
}
void turn_right_135(void){
	run(20,20);
	delay(0,225);
	run(0,0);
	delay(0,150);
	motor( 1, 50);motor(2 , -50);delay(0,270);// ��ת//270	
}

void line_small_1(int base){
	//��������������ֹͣ 
	while (analog(3)>25&&analog(4)>25&&analog(5)>25&&analog(6)>25)
	{	display_str(4,1,"small_1");
		if (base>0){
	     	if(analog(4)<100&&analog(5)<100)   
	     	{
	        	run(base,base);   
	     	}
	     	else if(analog(4)>100&&analog(5)<100) 
	     	{ 
	      		run(0.9*base,1.1*base);   
	     	}
	     	else if(analog(4)<100&&analog(5)>100)   
	     	{ 
	      		run(1.1*base,0.9*base);    
	     	}
	     	else if(analog(3)>100&&analog(6)<100) 
	     	{ 
	      		run(0.8*base,1.3*base);   
	     	}
	     	else if(analog(3)<100&&analog(6)>100)   
	     	{  
	      		run(1.3*base,0.8*base);    
	     	}
	     	else if(analog(2)>100&&analog(7)<100)  
	     	{  
	      		run(0.5*base,1.5*base);   
	     	}
	     	else if(analog(7)<100&&analog(2)>100)   
	     	{  
	      		run(1.5*base,0.5*base);    
	     	}
		}	
	}
}

void line_small_2(int base){
	//��������������ֹͣ 
	while (analog(3)<W&&analog(4)<W&&analog(5)<W&&analog(6)<W)
	{	display_str(4,1,"small_2");
		 if (base>0){
	     	if(analog(4)<100&&analog(5)<100)  
	     	{
	        	run(base,base);   
	     	}
	     	else if(analog(4)>100&&analog(5)<100) 
	     	{ 
	      		run(0.9*base,1.1*base);   
	     	}
	     	else if(analog(4)<100&&analog(5)>100)   
	     	{ 
	      		run(1.1*base,0.9*base);    
	     	}
	     	else if(analog(3)>100&&analog(6)<100) 
	     	{ 
	      		run(0.8*base,1.3*base);   
	     	}
	     	else if(analog(3)<100&&analog(6)>100)   
	     	{  
	      		run(1.3*base,0.8*base);    
	     	}
	     	else if(analog(2)>100&&analog(7)<100)  
	     	{  
	      		run(0.5*base,1.5*base);   
	     	}
	     	else if(analog(7)<100&&analog(2)>100)   
	     	{  
	      		run(1.5*base,0.5*base);    
	     	}
		}
	}	
}
/* *************(δ����)*************** */
//line_black_brige:����(δ����)
void line_black_brige(int base){
//	servo(1,200 );delay( 0,500);
	while(!(analog(1)>G||analog(2)>W||analog(3)>W||analog(4)>W||analog(5)>W||analog(6)>W||analog(7)>W||analog(8)>G)){
	     brline(20);
     }

     
//     servo(1,500 );delay( 0,500);
//     if(!(analog(1)>W||analog(2)>W||analog(3)>W||analog(4)>W||analog(5)>W||analog(6)>W||analog(7)>W||analog(8)>W)){
//   	 run(20,-20);
//   	 delay(0,200);
//     }
//     if(!(analog(1)>W||analog(2)>W||analog(3)>W||analog(4)>W||analog(5)>W||analog(6)>W||analog(7)>W||analog(8)>W)){
//     	 run(-20,20);
//     	 delay(0,400);
//     }
}

//run_utill:��⺯��
void run_utill(int speed, char color, char direction){
	if(color=='B'&&direction=='A'){//��ɫΪ��ɫ�ҷ���Ϊǰ��
		while(1){
			line(speed);
			if(analog(1)<B&&analog(2)<B&&analog(3)<B&&analog(4)<B&&analog(5)<B&&analog(6)<B&&analog(7)<B&&analog(8)<B){
				break;
			}
		}
	}
	else if(color=='W'&&direction=='A'){
		while(1){
			line(speed);
			if(analog(1)>G&&analog(2)>W&&analog(3)>W&&analog(4)>W&&analog(5)>W&&analog(6)>W&&analog(7)>W&&analog(8)>G){
				break;
			}
		}
	}
	else if(color=='W'&&direction=='L'){
		while(1){
			line(speed);
			if(analog(6)>W&&analog(7)>W&&analog(8)>G){
				break;
			}
		}
	}
	else if(color=='W'&&direction=='X'){
		while(1){
			line(speed);
			if(analog(4)>W&&analog(5)>W&&analog(8)>G){
				break;
			}
		}
	}
	else if(color=='W'&&direction=='R'){
		while(1){
			line(speed);
			if(analog(1)>G&&analog(2)>W&&analog(3)>W){
				break;
			}
		}
	}
	else if(color=='B'&&direction=='B'){
		while(1){
			line(speed);
			if(analog(2)<200&&analog(3)<200&&analog(4)<200&&analog(5)<200){
				break;
			}
		}
	}
}

//peng:��ײ�����С��
void peng(char color, char direction){
	while(analog(19)>0){
		line(18);
	}
	run(15,15);
	delay(1,500);
	run(0,0);
	delay(0,300);
//	run_utill(-10,color,direction);
	if(color=='W'&&direction=='A'){
		while(1){
			run(-17,-15);
			if(analog(1)>G&&analog(2)>W&&analog(3)>W&&analog(5)>W&&analog(6)>W&&analog(7)>W){
				break;
			}
		}
	}else if(color=='W'&&direction=='R'){
		while(1){
			run(-17,-15);
			if(analog(1)>G&&analog(2)>W){
				break;
			}
		}
	}else if(color=='W'&&direction=='L'){
		while(1){
			run(-17,-15);
			if(analog(6)>W&&analog(7)>W&&analog(8)>G){
				break;
			}
		}
	}
}
//�����peng2:��ײ�����С��
void peng2(char color, char direction){
	while(analog(19)<BORD){
		line(18);
	}
	run(18,18);
	delay(1,200);
	run(0,0);
	delay(0,300);
//	run_utill(-10,color,direction);
	if(color=='W'&&direction=='A'){
		while(1){
			run(-17,-15);
			if(analog(1)>G&&analog(2)>W&&analog(3)>W&&analog(5)>W&&analog(6)>W&&analog(7)>W){
				break;
			}
		}
	}else if(color=='W'&&direction=='R'){
		while(1){
			run(-17,-15);
			if(analog(1)>G&&analog(2)>W){
				break;
			}
		}
	}else if(color=='W'&&direction=='L'){
		while(1){
			run(-17,-15);
			if(analog(6)>W&&analog(7)>W&&analog(8)>G){
				break;
			}
		}
	}
}
//��ɨ����� peng3 
void peng3(char color, char direction){
	while(analog(19)<BORD){
	run(18,16);
	}
	run(0,0);
	delay(0,100); 
	while(1){
		delay(2,0);
		if(analog(21)<400&&analog(23)>400&&analog(24)>400){
			flag=5;
			break;
		}	
		else if(analog(21)>400&&analog(23)>400&&analog(24)<400){
			flag=6;
			break;
		}	
	}
	run(18,18);
	delay(1,200);
	run(0,0);
	delay(0,300);
//	run_utill(-10,color,direction);
	if(color=='W'&&direction=='A'){
		while(1){
			run(-15,-15);
			if(analog(1)>G&&analog(2)>W&&analog(3)>W&&analog(5)>W&&analog(6)>W&&analog(7)>W){
				break;
			}
		}
	}else if(color=='W'&&direction=='R'){
		while(1){
			run(-15,-15);
			if(analog(1)>G&&analog(2)>W){
				break;
			}
		}
	}else if(color=='W'&&direction=='L'){
		while(1){
			run(-15,-15);
			if(analog(6)>W&&analog(7)>W&&analog(8)>G){
				break;
			}
		}
	}
}
void door(){
}
//start:����

//��һ����
void from_0_to_1(void){
	while(1){
		if(analog(19)<BORD)
			break;
	}
	run_utill(30,'W','L');
	turn_left();
	peng('W','A');
	run(0,0);
	delay(0,150);
	run(15,15);
	delay(0,50);
	turn_right();

	run_utill(20,'B','A');
		delay(0,600);
		run(0,0);//30 //33
	while(1){
		delay(2,0);
		if(analog(21)>300&&analog(23)<300&&analog(24)<300){
			flag=1;
			break;
		}	
		else if(analog(21)<400&&analog(23)<400&&analog(24)>400){
			flag=2;
			break;
		}	
		else if(analog(21)>200&&analog(23)<300&&analog(24)>300){
			flag=3;
			break;
		}
		else if(analog(21)<300&&analog(23)>300&&analog(24)<300){
			flag=4;
			break;
		}	
	}
	run(10,10);
	delay(0,200);
	dt(380);
//	tai(23,23,0,415);//
	run(30,26);
	delay(0,100);
	run_utill(35,'W','R');
	turn_right();
	
	run_utill(25,'W','R');
	run(20,20);
	delay(0,300);
	peng('W','R');
	turn_right();

	run_utill(30,'W','R');//20
	turn_right();
	run_utill(35,'W','R');
	turn_right();
}
void start(void){
	while(1){
		if(analog(19)<BORD){
			delay(0,300);
			run(20,20);
			delay(0, 200);
			break;
		}
	}
}

void from_1_to_2(void){
	run_utill(30,'W','L');//25
	turn_left();
	while(1){
		line(20);
		if(analog(1)>G&&analog(2)>W&&analog(3)>W&&analog(4)>W&&analog(5)>W&&analog(6)>W&&analog(7)>W&&analog(8)>G){
			turn_left();
			break;
		}
	}	
}

//������ݮ�ɵĵڶ�����
void newfrom_1_to_2(void){
	if(flag==1){
		run_utill(30,'W','L');//25
		turn_left();
		while(1){
			line(20);
			if(analog(1)>G&&analog(2)>W&&analog(3)>W&&analog(4)>W&&analog(5)>W&&analog(6)>W&&analog(7)>W&&analog(8)>G){
				turn_left();
				break;
			}
		}	
	}else if(flag==2){
			run_utill(30,'W','L');
			turn_left_45();
			while(1){
				line(20);
				if(analog(5)>W&&analog(6)>W&&analog(7)>W&&analog(1)>W&&analog(2)>W&&analog(3)>W){
				flag=1;
				run_for_half_second(12,  12) ;
				dt(80);
				delay(0,320);
				run(0,0);
				delay(0,150);
				run_utill(20,'W','X');
				
				run(20,20);
				delay(0,100);
				turn_left_45();
				break;
				}
			}	
	}else if(flag==3){
		run_utill(30,'W','L');
		run_for_half_second(25,21);
		run_for_half_second(25,21);
		run_utill(30,'W','L');
		turn_left_135();
		run_utill(20,'W','X');
		run_for_half_second(20, 18);
		run_utill(20,'W','X');
		run(20,20);
		delay(0,100);
		turn_left_45();
		
			
	}else if(flag==4){
		run_utill(30,'W','L');
		run_for_half_second(25,21);
		run_for_half_second(25,21);
		run_utill(30,'W','L');
		turn_left();
		run_utill(20,'W','R');
		turn_left();
	}
}


//��������
void from_2_to_3(void){
	run_utill(35,'B','A');
	tai(23,23,0,380);//400
	run(30,30);
	delay(0,100);
	run_utill(30,'W','L');
	turn_left();
	run_utill(40,'W','A');
	peng2('W','A');
	turn_right();
	run_utill(35,'W','L');//30	
	turn_left();
	dt(80);
	peng3('W','A');
	if(flag==5){
		dt(420);
		run_utill(30,'W','L');
		peng2('W','L');
		turn_left();
		run_utill(30,'W','A');
		run(25,25);
		delay(0,100);	
	}else if(flag==6){
		turn_right();
		run_utill(30,'B','A');
		tai(23,23,0,380);//�Һ�̨//4.17 380 400
		run(25,25);
		delay(0,100);
		run_utill(30,'W','A');
		turn_right();
	}
	
}
//���Ĳ���
void from_3_to_4(void){
	run_utill(40,'W','A');
	turn_right();
	run_utill(30,'B','A');
	tai(23,21,0,380);
	while(1){
		run(16,18);
		if(analog(2)>W||analog(3)>W||analog(4)>W||analog(5)>W||analog(6)>W||analog(7)>W||analog(8)>G){
			break;
		}
	}
	//run_for_half_second(15, 14);
 //     run_for_half_second(15, 14);
//	run_for_half_second(15, 10);
	run_utill(40,'B','B');	
	line_black_brige(20);
	run_for_half_second(20,12);
	run_for_half_second(20, 12);
	run_utill(30,'B','A');
	tai(23,21,0,0);

}


//***********************�����ǲ��Ժ�����������*************************/
void mainX2(void){
	start();
	//run_utill(-10,'W','A');
	//turn_right_135();
	from_0_to_1();//();
	newfrom_1_to_2();
	from_2_to_3();
	from_3_to_4();	
}

void mainX1(void)
{ 
	
	//from_1_to_2(); 
	from_2_to_3();
	from_3_to_4();
}

void mainX3(void)
{
fzjs();
k=1;
    clear_lcd( );
  
    while(k!=0)
    {a=analog(2)+analog(3)+analog(4)+analog(5)+analog(6)+analog(7);
   display_str(4,1,"FZ  1: 1-14");
	display_str(4,17,"1:");display_int(28,17,a);display_str(69,17,"2:");display_int(93,17,fz[1]);
	display_str(4,33,"3:");display_int(28,33,fz[2]);display_str(69,33,"4:");display_int(93,33,fz[3]);
	display_str(4,49,"5:");display_int(28,49,fz[4]);display_str(69,49,"6:");display_int(93,49,fz[5]);
	display_str(4,65,"7:");display_int(28,65,fz[6]);display_str(69,65,"8:");display_int(93,65,fz[7]);
      display_str(4,81,"9:");display_int(28,81,fz[8]);display_str(69,81,"10:");display_int(93,81,fz[9]);
      display_str(4,97,"11:");display_int(28,97,fz[10]);display_str(69,97,"12:");display_int(93,97,fz[11]);
      display_str(4,113,"13:");display_int(28,113,fz[12]);display_str(69,113,"14:");display_int(93,113,fz[13]);  
      k=key(2 );
      
    }
	 k=1;
    clear_lcd( );
    while(k!=0)
    {	
    	display_str(4,1,"FZ  2: 15-28");
   display_str(4,17,"15:");display_int(28,17,fz[14]);display_str(69,17,"16:");display_int(93,17,fz[15]);
    display_str(4,33,"17:");display_int(28,33,fz[16]);display_str(69,33,"18:");display_int(93,33,fz[17]);
      display_str(4,49,"19:");display_int(28,49,fz[18]);display_str(69,49,"20:");display_int(93,49,fz[19]);
      display_str(4,65,"21:");display_int(28,65,fz[20]);display_str(69,65,"22:");display_int(93,65,fz[21]);
	display_str(4,81,"23:");display_int(28,81,fz[22]);display_str(69,81,"24:");display_int(93,81,fz[23]);
      display_str(4,97,"25:");display_int(28,97,fz[24]);display_str(69,97,"26:");display_int(93,97,fz[25]);
      display_str(4,113,"27:");display_int(28,113,fz[26]);display_str(69,113,"28:");display_int(93,113,fz[27]);
        k=key(2 );
    }	 
     k=1;
    clear_lcd( );
    while(k!=0)
    {
    
      	display_str(4,1,"HDC  1: 1-14");
     display_str(4,17,"1:");display_int(28,17,hdc[0]);display_str(69,17,"2:");display_int(93,17,hdc[1]);
     display_str(4,33,"3:");display_int(28,33,hdc[2]);display_str(69,33,"4:");display_int(93,33,hdc[3]);
      display_str(4,49,"5:");display_int(28,49,hdc[4]);display_str(69,49,"6:");display_int(93,49,hdc[5]);
	display_str(4,65,"7:");display_int(28,65,hdc[6]);display_str(69,65,"8:");display_int(93,65,hdc[7]);
      display_str(4,81,"9:");display_int(28,81,hdc[8]);display_str(69,81,"10:");display_int(93,81,hdc[9]);
      display_str(4,97,"11:");display_int(28,97,hdc[10]);display_str(69,97,"12:");display_int(93,97,hdc[11]);
      display_str(4,113,"13:");display_int(28,113,hdc[12]);display_str(69,113,"14:");display_int(93,113,hdc[13]);   
k=key( 2);  	
    }
    k=1;
    clear_lcd( );
    while(k!=0)
    {
   	display_str(4,1,"HDC  2: 15-28");
   display_str(4,17,"15:");display_int(28,17,hdc[14]);display_str(69,17,"16:");display_int(93,17,hdc[15]);
    display_str(4,33,"17:");display_int(28,33,hdc[16]);display_str(69,33,"18:");display_int(93,33,hdc[17]);
      display_str(4,49,"19:");display_int(28,49,hdc[18]);display_str(69,49,"20:");display_int(93,49,hdc[19]);
      display_str(4,65,"21:");display_int(28,65,hdc[20]);display_str(69,65,"22:");display_int(93,65,hdc[21]);
	display_str(4,81,"23:");display_int(28,81,hdc[22]);display_str(69,81,"24:");display_int(93,81,hdc[23]);
      display_str(4,97,"25:");display_int(28,97,hdc[24]);display_str(69,97,"26:");display_int(93,97,hdc[25]);
      display_str(4,113,"27:");display_int(28,113,hdc[26]);display_str(69,113,"28:");display_int(93,113,hdc[27]);
      k=key( 2);
    }  
}

void mainX4(void)
{
	run_utill(20,'B','A');

	// ����
	line_black_brige(20); 
	run_utill(20,'W','R');
	turn_right();
	run_utill(30,'B','A');
	run(60,60);
	delay(0,300);
	run(0,0);
}
void mainX5(void)
{
	
	test();

}

void mainX6(void)
{
	while(1){
		if(analog(23)<500&&analog(24)<500){
			run(10,10);//����ֱ�� 
		}
		if(analog(23)<500&&analog(24)>500){
			run(15,5);//��ת�� 
		}
		if(analog(23)>500&&analog(24)<500){
			run(5,15);//��ת�� 
		}
		if(analog(23)>500&&analog(24)>500){
			run(10,10);//����ֱ�� 
		}
	}
}

void mainX7(void)
{
//motor( 1, 30);motor(2 , 18);delay(100,0);mot_stop( );delay(0 ,500);
flag=3;
newfrom_1_to_2();
}

void mainX(void *p_arg) 
{

	
  set_name(MAINX1,"main1-test");//���ֶβ���
  set_name(MAINX2,"run");//����
  set_name(MAINX3,"main3--FZJS");//��ֵ����
  set_name(MAINX4,"main4--MDCS");//�������
   set_name(MAINX5,"main5--DJCS");//�������
    set_name(MAINX6,"main6--NONe");//�û�����
     set_name(MAINX7,"main7");//�û�����
  // .... x7
  set_digital( 1,0 );
 	 i=0; //ͨ����Զ����㷧ֵ
   servo(1,500 );servo(2,500 );servo(3,500 );servo(4,500 );servo(5,500 );servo(6,500 );
 	 while(i<28)
 	 {
 	 	hdb[i]=record_analog(i+1, 1);
 	 	hdh[i]=record_analog(i+1, 2);
			fz[i]=(hdb[i]+hdh[i])/2;
			hdc[i]=abs(hdb[i]-hdh[i]);
			i=i+1;
			}
  select_main();
}
void fzjs()//��ֵ����
 	 {int i=0;
 	 for(i=0;i<28;i++)
 	 {	hdb[i]=record_analog(i+1, 1);
 	 	hdh[i]=record_analog(i+1, 2);
			fz[i]=(hdb[i]+hdh[i])/2;
			hdc[i]=abs(hdb[i]-hdh[i]);
			}
			clear_lcd( );
}
  void mdcs()//�������
  { 
  motor( 1, 30);motor(2 , 30);delay( 4,0);mot_stop( );delay(0 ,500);//ǰ��
  motor( 1, -30);motor(2 , -30);delay( 4,0);mot_stop( );delay(0 ,500);//����
   motor( 1, -40);motor(2 , 40);delay( 3,0);mot_stop( );delay(0 ,500);//��ת
     motor( 1, 40);motor(2 , -40);delay( 3,0);//��ת
     mot_stop( );
     }
  void djcs()//�������
  {
 servo(1,880 );delay( 0,500); servo(1,500 );delay( 0,500);servo(1,200 );delay( 0,500);servo(1,500 );delay( 0,500);//����(1�Ŷ��)̧����£�200<��ֵ<880��
  delay(1 ,0);
   servo(2,980 );delay( 0,500);servo(4,900 );servo(5,100 );delay(0 ,500);delay(1 ,500);servo(2,500 );servo(4,500 );servo(5,500 );delay( 0,500);//����(2�Ŷ��)��������500<��ֵ<980��
  delay(1 ,0);
  servo(3,800 );servo(4, 800);servo(5,800 );delay(0 ,500);//ͷ������ҡ�ڣ��ֱ����°ڶ�����3/4/5�Ŷ��100<��ֵ<800��
    servo(3,200 );servo(4, 200);servo(5,200 );delay(0 ,500);//ͷ������ҡ�ڣ��ֱ����°ڶ���3/4/5�Ŷ��100<��ֵ<800��
    servo(3,800 );servo(4, 800);servo(5,800 );delay(0 ,500);//ͷ������ҡ�ڣ��ֱ����°ڶ���3/4/5�Ŷ��100<��ֵ<800��
    servo(3,200 );servo(4, 200);servo(5,200 );delay(0 ,500);//ͷ������ҡ�ڣ��ֱ����°ڶ���3/4/5�Ŷ��100<��ֵ<800��
    servo(3,500 );servo(4, 500);servo(5,500 );delay(0,500);//ͷ������ҡ�ڣ��ֱ����°ڶ���3/4/5�Ŷ��100<��ֵ<800��
  }

