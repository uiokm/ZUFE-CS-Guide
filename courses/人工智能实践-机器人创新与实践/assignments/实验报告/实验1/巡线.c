#include <includes.h> 

int CHGCi;
//设定传感器
#define hd0 analog(1)  //右前
#define hd1 analog(2)
#define hd2 analog(3)
#define hd3 analog(4)
#define hd4 analog(5)
#define hd5 analog(6)
#define hd6 analog(7)
#define hd7 analog(8)//左前
#define hdz analog(17) //中左
#define hdy analog(18)//中右
#define hdy analog(19)//前测障-1
#define hdy analog(20)//前测障-2
#define cz1 digital(1) 
#define cz2 digital(2)
#define cz3 digital(3)
#define W 250  //白色

void fzjs(void);//阀值计算
void fzxs(void);//阀值显示
void mdcs(void);//马达测试
void djcs (void);//舵机测试
void run(int n, int p);
void line(int base);
void turn_left(void);
void turn_right(void);


int hdb[28],hdh[28],fz[28],hdc[28];//hdb[28]白色灰度值，hdh[28]绿地毯灰度值，fz[28]阀值，hdc[28]灰度高低差值。
int i,v=0,k=0,znz=0,z=0,d=34,b=0;
//int x=50;
//int y=50:
void mainX1(void)

{ 
test();
}
void mainX2(void)
{
record();
 
}
void mainX3(void)
{
fzjs();
k=1;
    clear_lcd( );
  
    while(k!=0)
    {	
   display_str(4,1,"FZ  1: 1-14");
	display_str(4,17,"1:");display_int(28,17,fz[0]);display_str(69,17,"2:");display_int(93,17,fz[1]);
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
mdcs();

 	 
}
void mainX5(void)
{
	while(1){
		 if( analog(4)>W&&analog(5)>W )   
    		 {
         	 run(20,20);   
      	}
    		 else if(analog(4)<W&&analog(5)>W) 
     		{ 
     		 run(10,22);   
    		 }
      		else if(analog(4)>W&&analog(5)<W)   
    		 { 
      		run(22,10);    
    		 }
    }
}
void run(int m,int p)
{
	int rate = 1;
 motor(1,m * rate);
 motor(2,p * rate);
}
void line(int base)
{
     if( analog(4)>W&&analog(5)>W )   
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
     //else{
     //	 run(-20,-20);
     //	 delay(0,200);
     //	 run(0,0);
     //	 delay(0,200);
 //    }
}

void turn_left(void){
	run(0,0);
	delay(0,200);
	motor(1, -10);motor(2 , 30);delay(0,300);// 左转	
}
void turn_right(void){
	run(0,0);
	delay(0,200);
	motor( 1, 50);motor(2 , -10);delay(0,300);// 右转	
}
void mainX6(void)
{

}
void mainX7(void)
{

}	
void mainX(void *p_arg) 

{

	
  set_name(MAINX1,"main1--SJCS");//传感器数据测试
  set_name(MAINX2,"main2--SJDQ");//模拟传感器数据读取
  set_name(MAINX3,"main3--FZJS");//阀值计算
  set_name(MAINX4,"main4--MDCS");//马达测试
   set_name(MAINX5,"main5--DJCS");//舵机测试
    set_name(MAINX6,"main6");//用户程序
     set_name(MAINX7,"main7");//用户程序
  // .... x7
  set_digital( 1,0 );
 	 i=0; //通电后自动计算阀值
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
void fzjs()//阀值计算
 	 {int i=0;
 	 for(i=0;i<28;i++)
 	 {	hdb[i]=record_analog(i+1, 1);
 	 	hdh[i]=record_analog(i+1, 2);
			fz[i]=(hdb[i]+hdh[i])/2;
			hdc[i]=abs(hdb[i]-hdh[i]);
			}
			clear_lcd( );
}
  void mdcs()//马达测试
  { 
  motor( 1, 20);motor(2 , -20);delay( 4,0);mot_stop( );delay(0 ,500);//前进
  
     mot_stop( );
     }
  void djcs()//舵机测试
  {
 servo(1,880 );delay( 0,500); servo(1,500 );delay( 0,500);servo(1,200 );delay( 0,500);servo(1,500 );delay( 0,500);//大舵机(1号舵机)抬起放下（200<数值<880）
  delay(1 ,0);
   servo(2,980 );delay( 0,500);servo(4,900 );servo(5,100 );delay(0 ,500);delay(1 ,500);servo(2,500 );servo(4,500 );servo(5,500 );delay( 0,500);//大舵机(2号舵机)躺下立起（500<数值<980）
  delay(1 ,0);
  servo(3,200 );servo(4, 200);servo(5,200 );delay(0 ,500);//头部左右摇摆，手臂上下摆动。（3/4/5号舵机100<数值<800）
  }