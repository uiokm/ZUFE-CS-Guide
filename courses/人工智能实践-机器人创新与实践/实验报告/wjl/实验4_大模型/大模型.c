#include <includes.h>
int CHGCi;
//设定传感器
#define hd0 analog(1) //右前
#define hd1 analog(2)
#define hd2 analog(3)
#define hd3 analog(4)
#define hd4 analog(5)
#define hd5 analog(6)
#define hd6 analog(7)
#define hd7 analog(8) //左前
#define hdz analog(17) //中左
#define hdy analog(18) //中右
#define hdy analog(19) //前测障-1
#define hdy analog(20) //前测障-2
#define cz1 digital(1)
#define cz2 digital(2)
#define cz3 digital(3)
#define W 400 //白色
#define B 200 //黑色
#define DJ_FLAT 670

void fzjs(void); //阀值计算
void fzxs(void); //阀值显示
void mdcs(void); //马达测试
void djcs(void); //舵机测试
void run(int n, int p); //按设定速度行驶
void line(int base); //普通巡线
void turn_left(void); //巡线直行，遇到路口左转
void turn_right(void); //巡线直行，遇到路口右转
int detect_left_turn(void); //用于检测是否有左转弯路口并完成左转的函数
int detect_right_turn(void); //用于检测是否有右转弯路口并完成右转的函数
int detect_wall(void); //用于检测是否有墙并在检测到墙后后退的函数
int detect_tai(void); //用于检测是否上了台子并完成台上动作的函数
void left(int speed); //完成左转动作的函数
void right(int speed); //完成右转动作的函数
void hit_wall(int speed); //巡线直行，遇到墙撞上去之后后退
void go_tai(int speed); //巡线直行，遇到台子上台完成动作后掉头下台
void motion(void); //舵机的动作
int try_door(int speed); //巡线直行并尝试此门，如果是关着的则后退掉头，如果开着则通过，返回值为是否成功通过
int detect_door(void); //用于检测是否有关着的门，如果有就完成掉头动作的函数
void turn_around(void); //原地转180度的函数
void turn_around_open_loop(void); //开环转180度
void line_timing(int speed, long interval); //以speed速度巡线直行interval毫秒后退出执行后续语句的函数（可用于实现一段路上的变速行驶）
void left_135(int speed); //巡线到直角路口左转135度的函数
void turn_left_135(void); //完成135度转弯动作的函数
int detect_left_turn_135(void); //检测是否有直角路口并在检测到后执行135度左转的函数
void line_bridge(int Lbase,int Rbase); //在桥上巡线的函数
void go_end(int speed); //巡线直行，抵达终点的函数
int detect_end(void); //用于检测是否到了终点并完成相关动作的函数
void target_degree(int degree, int speed, int threshold);

int hdb[28], hdh[28], fz[28], hdc[28]; //hdb[28]白色灰度值，hdh[28]绿地毯灰度值，fz[28]阀值，hdc[28]灰度高低差值。
int i, v = 0, k = 0, znz = 0, z = 0, d = 34, b = 0,flag=0;

void left_45(int speed);
int detect_left_turn_45(void);
void turn_left_45(void);

#define EAST 76
#define WEST 254

//int x=50;
//int y=50:
void mainX1(void){
    test();
}

void mainX2(void) {
	while(1){
		
        display_str(4, 17, "1:");
        display_int(28, 17, analog(17));
        display_str(69, 34, "2:");
        display_int(93, 34, analog(18));
    }
}
void mainX3(void) {
    fzjs();
    k = 1;
    clear_lcd();

    while (k != 0) {
        display_str(4, 1, "FZ  1: 1-14");
        display_str(4, 17, "1:");
        display_int(28, 17, fz[0]);
        display_str(69, 17, "2:");
        display_int(93, 17, fz[1]);
        display_str(4, 33, "3:");
        display_int(28, 33, fz[2]);
        display_str(69, 33, "4:");
        display_int(93, 33, fz[3]);
        display_str(4, 49, "5:");
        display_int(28, 49, fz[4]);
        display_str(69, 49, "6:");
        display_int(93, 49, fz[5]);
        display_str(4, 65, "7:");
        display_int(28, 65, fz[6]);
        display_str(69, 65, "8:");
        display_int(93, 65, fz[7]);
        display_str(4, 81, "9:");
        display_int(28, 81, fz[8]);
        display_str(69, 81, "10:");
        display_int(93, 81, fz[9]);
        display_str(4, 97, "11:");
        display_int(28, 97, fz[10]);
        display_str(69, 97, "12:");
        display_int(93, 97, fz[11]);
        display_str(4, 113, "13:");
        display_int(28, 113, fz[12]);
        display_str(69, 113, "14:");
        display_int(93, 113, fz[13]);
        k = key(2);

    }
    k = 1;
    clear_lcd();
    while (k != 0) {
        display_str(4, 1, "FZ  2: 15-28");
        display_str(4, 17, "15:");
        display_int(28, 17, fz[14]);
        display_str(69, 17, "16:");
        display_int(93, 17, fz[15]);
        display_str(4, 33, "17:");
        display_int(28, 33, fz[16]);
        display_str(69, 33, "18:");
        display_int(93, 33, fz[17]);
        display_str(4, 49, "19:");
        display_int(28, 49, fz[18]);
        display_str(69, 49, "20:");
        display_int(93, 49, fz[19]);
        display_str(4, 65, "21:");
        display_int(28, 65, fz[20]);
        display_str(69, 65, "22:");
        display_int(93, 65, fz[21]);
        display_str(4, 81, "23:");
        display_int(28, 81, fz[22]);
        display_str(69, 81, "24:");
        display_int(93, 81, fz[23]);
        display_str(4, 97, "25:");
        display_int(28, 97, fz[24]);
        display_str(69, 97, "26:");
        display_int(93, 97, fz[25]);
        display_str(4, 113, "27:");
        display_int(28, 113, fz[26]);
        display_str(69, 113, "28:");
        display_int(93, 113, fz[27]);
        k = key(2);
    }
    k = 1;
    clear_lcd();
    while (k != 0) {

        display_str(4, 1, "HDC  1: 1-14");
        display_str(4, 17, "1:");
        display_int(28, 17, hdc[0]);
        display_str(69, 17, "2:");
        display_int(93, 17, hdc[1]);
        display_str(4, 33, "3:");
        display_int(28, 33, hdc[2]);
        display_str(69, 33, "4:");
        display_int(93, 33, hdc[3]);
        display_str(4, 49, "5:");
        display_int(28, 49, hdc[4]);
        display_str(69, 49, "6:");
        display_int(93, 49, hdc[5]);
        display_str(4, 65, "7:");
        display_int(28, 65, hdc[6]);
        display_str(69, 65, "8:");
        display_int(93, 65, hdc[7]);
        display_str(4, 81, "9:");
        display_int(28, 81, hdc[8]);
        display_str(69, 81, "10:");
        display_int(93, 81, hdc[9]);
        display_str(4, 97, "11:");
        display_int(28, 97, hdc[10]);
        display_str(69, 97, "12:");
        display_int(93, 97, hdc[11]);
        display_str(4, 113, "13:");
        display_int(28, 113, hdc[12]);
        display_str(69, 113, "14:");
        display_int(93, 113, hdc[13]);
        k = key(2);
    }
    k = 1;
    clear_lcd();
    while (k != 0) {
        display_str(4, 1, "HDC  2: 15-28");
        display_str(4, 17, "15:");
        display_int(28, 17, hdc[14]);
        display_str(69, 17, "16:");
        display_int(93, 17, hdc[15]);
        display_str(4, 33, "17:");
        display_int(28, 33, hdc[16]);
        display_str(69, 33, "18:");
        display_int(93, 33, hdc[17]);
        display_str(4, 49, "19:");
        display_int(28, 49, hdc[18]);
        display_str(69, 49, "20:");
        display_int(93, 49, hdc[19]);
        display_str(4, 65, "21:");
        display_int(28, 65, hdc[20]);
        display_str(69, 65, "22:");
        display_int(93, 65, hdc[21]);
        display_str(4, 81, "23:");
        display_int(28, 81, hdc[22]);
        display_str(69, 81, "24:");
        display_int(93, 81, hdc[23]);
        display_str(4, 97, "25:");
        display_int(28, 97, hdc[24]);
        display_str(69, 97, "26:");
        display_int(93, 97, hdc[25]);
        display_str(4, 113, "27:");
        display_int(28, 113, hdc[26]);
        display_str(69, 113, "28:");
        display_int(93, 113, hdc[27]);
        k = key(2);
    }
}
void mainX6(void) {
//	else if(flag==3){
    line_timing(30, 1000);
    line_timing(45, 1000);
    line_timing(60, 500);
    line_timing(45, 1000);
    line_timing(30, 3000);
}
void mainX4(void) {
//	while(1){
	//	delay(2,0);
	//	if(analog(23)>500&&analog(24)>500){
	//		flag=1;
	//		break;
	//	}	
	//	else if(analog(23)>500&&analog(24)==0){
	//2		flag=2;
		//	break;
	//	}	
	//	else if(analog(23)==0&&analog(24)>500){
	//		flag=3;
	//		break;
	//	}
	//	else if(analog(23)==0&&analog(24)==0){
	//		flag=4;
	//	break;
	//	}	
//	}
	flag=2;
    // 驶下初始台子
	run(20,20);
	delay(1,500);

    // 左转到曲靖
	left(20);
	hit_wall(20);
    while (analog(7)<W || analog(2)<W) {
        run(-20, -20);
    }
    delay(0,100);
    right(20);

    // 到达寻甸
	go_tai(20);
	run(20,20);
	delay(0,300);
	
    turn_around();
	right(20);

    // 到达昆明
    hit_wall(20);
    while (analog(1)<W || analog(2)<W) {
        run(-20, -20);
    }
    delay(0,100);
    right(20);

    // 先高速行驶，然后缓慢通过颠簸路
    line_timing(40,2000);
    line_timing(20,1400);
	right(20);
	right(20);
	
    
    // 过金沙江
 	while(1){
        	if(flag==1){
                  left(20);
                  left(20);
                  goto next_route;
            //龙街渡; 
        	}
        	else if(flag==2){
                  left_45(20);
      		line_timing(20, 5500);
              
      		left_135(20);
      		line_timing(20, 1600);
      		goto next_route;
            //巧家渡;
        	}
        	else if(flag==3){
        		line(20);
        		line_timing(20, 3600);
           		left_135(20);
        		while(1){
          	  		line(20);
            		if (analog(8) > W || analog(7) > W || analog(6) > W) 
            			break;
       	 	}
        		delay(0,200);
        		line_timing(20, 4800);
        		while(1){
            		line(20);
            		if (analog(8) > W){
                			run(20,20);
                			delay(0,800);
                			turn_left_45();
                			break;
            		}
        		}
                  goto next_route;
            //洪门渡;
        	}
        	else if(flag==4){
        	         line(20);
        	         line_timing(20, 3600);
                     left(20);
                     left(20);
                     goto next_route;
            //皎平渡;
        	}
    }

    // 前往德昌
    next_route:
    go_tai(20);
    run(20,20);
    delay(0,300);
    turn_around();
    
    left(20);
    
    // 前往沪沽
    hit_wall(20);
    while (analog(7)<W || analog(2)<W) {
        run(-20, -20);
        
    }
    delay(0,200);
    right(20);
    line_timing(20, 1600);
    
    left(20);
///11111

//拿11111
    // 前往颅骨121212537123
    hit_wall(20);
    run(-20,-20);
	delay(0,100);
//while(1){
//if(analog(24)==0&&analog(23)>100){
	 // 前往海子
    //right(20);
   // go_tai(20);
   // turn_around();
        //right(20);
            //海子线; 
          // break;
        //	}
        //	else if(analog(24)>100&&analog(23)==0){
        	//	turn_around_open_loop();
        		    // 前往大树堡
    turn_around_open_loop();
    hit_wall(30);
    while (analog(7)<W && analog(2)<W) {
        run(-25, -25);
    }
    delay(0,200);
    left(20);
    line_timing(20,3500);
   // break;
            //大树堡线;
        //	}
        	
//}

    // 前往安顺场
    right(20);
    go_tai(20);
    run(20,20);
    delay(0,300);
    turn_around();
    
	line_timing(20,700);
   // 前往泸定桥，渐渐加速再渐渐减速
    line_timing(30, 1000);
    line_timing(45, 1000);
    line_timing(60, 500);
    line_timing(45, 1000);
    line_timing(30, 5000);
    
    while(1){
        line(25);
        if (analog(1)<B&&analog(2)<B&&analog(3)<B&&analog(4)<B&&analog(5)<B&&analog(6)<B&&analog(7)<B&&analog(8)<B){
            break;
        }
    }
    delay(0,300);   
    while(1){
        if (analog(4)>200 || analog(5)>200){
            break;
        }
    	line_bridge(25,20);
    	delay(0,300);
    	
    }
    run(20,20);
    delay(0,200);
    
    // 前往终点
    go_end(30);
}

void line_timing(int speed, long interval){
    long start_millis;
    start_millis = mseconds();
    while (mseconds() - start_millis <= interval){
        line(speed);
    }
}

void left_135(int speed) {
    while(1){
        line(speed);
        if (detect_left_turn_135()){
            break;
        }
    }
}

void left(int speed) {
    while(1){
        line(speed);
        if (detect_left_turn()){
            break;
        }
    }
}

void left_45(int speed) {
    while(1){
        line(speed);
        if (detect_left_turn_45()){
            break;
        }
    }
}

void right(int speed) {
    while(1){
        line(speed);
        if (detect_right_turn()){
            break;
        }
    }
}


void hit_wall(int speed) {
    while(1){
		line(speed);
		if (detect_wall()){
			break;
		}
	}
}

void go_tai(int speed) {
    while(1){
		line(speed);
		if (detect_tai()){
			break;
		}
	}
}

void go_end(int speed) {
    while(1){
        line(speed);
        if (detect_end()){
            break;
        }
    }
}

int detect_end(void){
    if(analog(1)<B&&analog(2)<B&&analog(3)<B&&analog(4)<B&&analog(5)<B&&analog(6)<B&&analog(7)<B&&analog(8)<B){
		run(30,30);
		delay(0,780);
		run(0,0);
		return 1;
	}
	return 0;
}

int try_door(int speed) {
    while(1){
        line(speed);
        // 检查前避障，假如有障碍说明此门不开，return 0
        if (detect_door()){
            // 倒车回去尝试别的
            run(-20,-20);
            delay(0,800);
            run(15,-15);
		    delay(2,100);
            return 0;
        }
        // 检查侧避障，假如有障碍说明已经开到门里了，说明此门可通，return 1
        if (cz2){
            return 1;
        }
    }
}

int detect_door(){
    if(analog(19)<400){
        return 1;
    }
    return 0;
}

int detect_left_turn_135(void) {
    if (analog(7) > W || analog(8) > W) {
        run(20, 20);
        delay(0, 620);
        turn_left_135();
        return 1;
    }
    return 0;
}

int detect_left_turn_45(void) {
    if (analog(6) > W && analog(7) > W && analog(8) > W) {
        run(20, 20);
        delay(0, 200);
        turn_left_45();
        return 1;
    }
    return 0;
}

int detect_left_turn(void) {
    if (analog(6) > W && analog(7) > W && analog(8) > W) {
        run(20, 20);
        delay(0, 350);
        turn_left();
        return 1;
    }
    return 0;
}

int detect_right_turn(void) {
	if (analog(1) > W && analog(2) > W && analog(3) > W) {
		run(20, 20);
		delay(0, 350);
		turn_right();
		return 1;
	}
	return 0;
}

void turn_around(void) {
    run(15, -15);
    delay(2,580);
    run(0, 0);
}

void turn_around_open_loop(void){
//	while (analog(7)<W || analog(2)<W) {
    //    run(20,20);
    //}
   //delay(0,500);
    run(15, -15);
    delay(2, 200);
}

int detect_wall(void){
	if(analog(19)<400 && (analog(1)>B || analog(2)>B || analog(3)>B || analog(4)>B || analog(5)>B || analog(6)>B || analog(7)>B || analog(8)>B)){
		run(20,20);
		delay(0,300);
		run(-20,-20);
		delay(0,400);
		return 1;
	}
	return 0;
}

//motion:舵机动作
void motion(void){
    servo(2,690);
    delay(1,000);
    servo(2,400);
    delay(1,000);
}

int detect_tai(void){
	if(analog(1)<B&&analog(2)<B&&analog(3)<B&&analog(4)<B&&analog(5)<B&&analog(6)<B&&analog(7)<B&&analog(8)<B){
		run(20,20);
		delay(0,800);
		run(0,0);
		delay(0,1000);
		return 1;
	}
	return 0;
}

void mainX5(void)
{

	 // 前往海子
    go_tai(20);
    turn_around();
        right(20);
            //海子线; 


    // 前往安顺场
    right(20);
    go_tai(20);
    turn_around();
    
    line_timing(20,700);
   // 前往泸定桥，渐渐加速再渐渐减速
    line_timing(30, 667);
    line_timing(45, 667);
    line_timing(60, 2267);
    line_timing(45, 667);
    line_timing(30, 667);
    while(1){
        line(25);
        if (analog(1)<B&&analog(2)<B&&analog(3)<B&&analog(4)<B&&analog(5)<B&&analog(6)<B&&analog(7)<B&&analog(8)<B){
            break;
        }
    }
    delay(0,300);   
    while(1){
        if (analog(4)>200 || analog(5)>200){
            break;
        }
    	line_bridge(25,20);
    	
    }
    run(20,20);
    delay(1,000);
    
    // 前往终点
    go_end(30);
}
void run(int m, int p) {
    int rate = 1;
    motor(1, m * rate);
    motor(2, p * rate);
}
void line(int base) {
    if (analog(4) > W && analog(5) > W) {
        run(base, base);
    } else if (analog(4) < W && analog(5) > W) {
        run(0.9 * base, 1.1 * base);
    } else if (analog(4) > W && analog(5) < W) {
        run(1.1 * base, 0.9 * base);
    } else if (analog(3) < W && analog(6) > W) {
        run(0.8 * base, 1.3 * base);
    } else if (analog(3) > W && analog(6) < W) {
        run(1.3 * base, 0.8 * base);
    } else if (analog(2) < W && analog(7) > W) {
        run(0.5 * base, 1.5 * base);
    } else if (analog(7) < W && analog(2) > W) {
        run(1.5 * base, 0.5 * base);
    } else if (analog(1) > W && analog(8) < W) {
        run(1.5 * base, 0.4 * base);
    } else if (analog(8) > W && analog(1) < W) {
        run(0.4 * base, 1.5 * base);
    } else {
        run(base, base);
    }
}

void line_bridge(int Lbase,int Rbase) {
    if (analog(4) < 40 && analog(5) < 40) {
        run(Lbase, Rbase);
    } else if (analog(4) > 40 && analog(5) < 40) {
        run(0.8 * Lbase, 1.2 * Rbase);
    } else if (analog(4) < 40 && analog(5) > 40) {
        run(1.2 * Lbase, 0.8 * Rbase);
    } else if (analog(3) > 40 && analog(6) < 40) {
        run(0.8 * Lbase, 1.2 * Rbase);
    } else if (analog(3) < 40 && analog(6) > 40) {
        run(1.2 * Lbase, 0.8 * Rbase);
    } else if (analog(2) > 40 && analog(7) < 40) {
        run(0.8 * Lbase, 1.2 * Rbase);
    } else if (analog(7) > 40 && analog(2) < 40) {
        run(1.2 * Lbase, 0.8 * Rbase);
    } else{
    line(10);
    }
}

void turn_left(void) {
    run(0, 0);
    motor(1, -24);
    motor(2, 24);
     delay(0, 450); // 左转
}

void turn_left_135(void){
    run(0, 0);
    delay(0, 300);
    motor(1, -30);
    motor(2, 30);
    delay(0, 575); // 左转 135度
}

void turn_left_45(void){
    run(0, 0);
    delay(0, 300);
    motor(1, -30);
    motor(2, 30);
    delay(0, 250); // 左转 45度
}

void turn_right(void) {
    run(0, 0);
    motor(1, 24);
    motor(2, -24);
    delay(0, 450); // 右转	
}


void mainX7(void) {
	line_timing(20,700);
   // 前往泸定桥，渐渐加速再渐渐减速
    line_timing(30, 1000);
    line_timing(45, 1000);
    line_timing(60, 500);
    line_timing(45, 1000);
    line_timing(30, 5000);
    
    while(1){
        line(25);
        if (analog(1)<B&&analog(2)<B&&analog(3)<B&&analog(4)<B&&analog(5)<B&&analog(6)<B&&analog(7)<B&&analog(8)<B){
            break;
        }
    }
    delay(0,300);   
    while(1){
        if (analog(4)>200 || analog(5)>200){
            break;
        }
    	line_bridge(25,20);
    	delay(0,300);
    	
    }
    run(20,20);
    delay(0,200);
    
    // 前往终点
    go_end(30);
}


void mainX(void * p_arg) {
    set_name(MAINX1, "main1--SJCS"); //传感器数据测试
    set_name(MAINX2, "main2--SJDQ"); //模拟传感器数据读取
    set_name(MAINX3, "main3--FZJS"); //阀值计算
    set_name(MAINX4, "main4--MDCS"); //马达测试
    set_name(MAINX5, "main5--DJCS"); //舵机测试
    set_name(MAINX6, "main6"); //用户程序
    set_name(MAINX7, "main7"); //用户程序
    // .... x7
    set_digital(1, 0);
    i = 0; //通电后自动计算阀值
    servo(1, 500);
    servo(2, 500);
    servo(3, 500);
    servo(4, 500);
    servo(5, 500);
    servo(6, 500);
    while (i < 28) {
        hdb[i] = record_analog(i + 1, 1);
        hdh[i] = record_analog(i + 1, 2);
        fz[i] = (hdb[i] + hdh[i]) / 2;
        hdc[i] = abs(hdb[i] - hdh[i]);
        i = i + 1;
    }
    select_main();
}
void fzjs() //阀值计算
{
    int i = 0;
    for (i = 0; i < 28; i++) {
        hdb[i] = record_analog(i + 1, 1);
        hdh[i] = record_analog(i + 1, 2);
        fz[i] = (hdb[i] + hdh[i]) / 2;
        hdc[i] = abs(hdb[i] - hdh[i]);
    }
    clear_lcd();
}

// 利用指南针转到指定方向，不过这compass有bug，没用上
void target_degree(int target, int speed, int threshold)
{
    int l_bound = (target - threshold + 359) % 359;
    int r_bound = (target + threshold) % 359; 

    int now = compass();
    int delta_r = target - now;
    int delta_l = now - target;
    if (delta_r < 0) delta_r += 358;
    if (delta_l < 0) delta_l += 358;
    if (delta_l < delta_r){
        now = compass();
        if (l_bound > r_bound){
            while (!((now > l_bound) || (now < r_bound))){
                run(-speed,speed);
                now = compass();
            }
        }
        else{
            while (!((now > l_bound) && (now < r_bound))){
                run(-speed,speed);
                now = compass();
            }
        }
    }
    else{
        now = compass();
        if (l_bound > r_bound){
            while (!((now > l_bound) || (now < r_bound))){
                run(speed,-speed);
                now = compass();
            }
        }
        else{
            while (!((now > l_bound) && (now < r_bound))){
                run(speed,-speed);
                now = compass();
            }
        }
    }
    run(0,0);
}

void djcs() //舵机测试
{
    servo(2,570);
}