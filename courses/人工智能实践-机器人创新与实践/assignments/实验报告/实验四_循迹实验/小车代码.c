#include <includes.h>
int CHGCi;
//�趨������
#define hd0 analog(1) //��ǰ
#define hd1 analog(2)
#define hd2 analog(3)
#define hd3 analog(4)
#define hd4 analog(5)
#define hd5 analog(6)
#define hd6 analog(7)
#define hd7 analog(8) //��ǰ
#define hdz analog(17) //����
#define hdy analog(18) //����
#define hdy analog(19) //ǰ����-1
#define hdy analog(20) //ǰ����-2
#define cz1 digital(1)
#define cz2 digital(2)
#define cz3 digital(3)
#define W 290 //��ɫ
#define B 100 //��ɫ
#define DJ_FLAT 670

void fzjs(void); //��ֵ����
void fzxs(void); //��ֵ��ʾ
void mdcs(void); //�������
void djcs(void); //�������
void run(int n, int p); //���趨�ٶ���ʻ
void line(int base); //��ͨѲ��
void turn_left(void); //Ѳ��ֱ�У�����·����ת
void turn_right(void); //Ѳ��ֱ�У�����·����ת
int detect_left_turn(void); //���ڼ���Ƿ�����ת��·�ڲ������ת�ĺ���
int detect_right_turn(void); //���ڼ���Ƿ�����ת��·�ڲ������ת�ĺ���
int detect_wall(void); //���ڼ���Ƿ���ǽ���ڼ�⵽ǽ����˵ĺ���
int detect_tai(void); //���ڼ���Ƿ�����̨�Ӳ����̨�϶����ĺ���
int detect_tai1(void); //���ڼ���Ƿ�����̨�Ӳ����̨�϶����ĺ���
void left(int speed); //�����ת�����ĺ���
void right(int speed); //�����ת�����ĺ���
void hit_wall(int speed); //Ѳ��ֱ�У�����ǽײ��ȥ֮�����
void go_tai(int speed); //Ѳ��ֱ�У�����̨����̨��ɶ������ͷ��̨
void go_tai1(int speed);
void motion(void); //����Ķ���
int try_door(int speed); //Ѳ��ֱ�в����Դ��ţ�����ǹ��ŵ�����˵�ͷ�����������ͨ��������ֵΪ�Ƿ�ɹ�ͨ��
int detect_door(void); //���ڼ���Ƿ��й��ŵ��ţ�����о���ɵ�ͷ�����ĺ���
void turn_around(void); //ԭ��ת180�ȵĺ���
void turn_around_open_loop(void); //����ת180��
void line_timing(int speed, long interval); //��speed�ٶ�Ѳ��ֱ��interval������˳�ִ�к������ĺ�����������ʵ��һ��·�ϵı�����ʻ��
void left_135(int speed); //Ѳ�ߵ�ֱ��·����ת135�ȵĺ���
void turn_left_135(void); //���135��ת�䶯���ĺ���
int detect_left_turn_135(void); //����Ƿ���ֱ��·�ڲ��ڼ�⵽��ִ��135����ת�ĺ���
void line_bridge(int base); //������Ѳ�ߵĺ���
void go_end(int speed); //Ѳ��ֱ�У��ִ��յ�ĺ���
int detect_end(void); //���ڼ���Ƿ����յ㲢�����ض����ĺ���
void target_degree(int degree, int speed, int threshold);
int hdb[28], hdh[28], fz[28], hdc[28]; //hdb[28]��ɫ�Ҷ�ֵ��hdh[28]�̵�̺�Ҷ�ֵ��fz[28]��ֵ��hdc[28]�ҶȸߵͲ�ֵ��
int i, v = 0, k = 0, znz = 0, z = 0, d = 34, b = 0;

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
 
void mainX4(void) {
    // ʻ�³�ʼ̨��
	run(20,20);
	delay(0,500);
    // ��ת������
	left(25);
	hit_wall(30);
    while (analog(7)<W || analog(2)<W) {
        run(-30, -30);
    }
    delay(0,100);
    right(20);
    // ����Ѱ��
	go_tai(20);
	delay(3,0);
    turn_around();
    run(20,20);
    delay(1,700);
	right(20);
    // ��������
    hit_wall(20);
    while (analog(1)<W || analog(2)<W) {
        run(-20, -20);
    }
    delay(0,100);
    right(20);
    // �ȸ�����ʻ��Ȼ����ͨ������·
    line_timing(40,2000);
    line_timing(20,1400);
	right(20);
	run(20,20);
	delay(1,500);
	right(20);
	run(20,20);
	delay(1,500);
	left(25);
    run(20,20);
    delay(1,500);
    // ����ɳ��
    // ���Ե�һ����
    if (try_door(20)){
        left(20);
        goto next_route; // �Ѿ������������������goto������������������
    }
    else{
        left_135(20);
    }

    // ���Եڶ�����
    if (try_door(20)){
        // ��ǰ��Ȼ����ת135
        // ת135��
        while(1){   // ��Ѳ�߾���һ��������
            line(20);
            if (analog(8) > W || analog(7) > W || analog(6) > W) break;
        }
        delay(0,200);
        line_timing(20, 1400);
        while(1){
            line(20);
            if (analog(8) > W){
                run(20,20);
                delay(0,800);
                turn_left_135();
                break;
            }
        }
        goto next_route;
    }
    else{
        while(1){
            line(40);
            if (analog(8) > W){
                run(20,20);
                delay(0,800);
                turn_left_135();
                break;
            }
        }
    }

    // ���ǰ�����Ų��������ĸ���һ���ǿ��ģ�ֱ����ת����ͨ�������
    left(40);
    left(40);
    goto next_route;

    // ǰ���²�
    next_route:
    go_tai(40);
    turn_around();
    left(40);
    
    // ǰ������
    run(0,0); delay(0,200);
    hit_wall(40);
   // while (analog(7)<W || analog(2)<W) {
      //  run(-40, -40);
    //}
    run(-20,-20);
    delay(0,800);
    delay(0,100);
    right(20);
    line_timing(20, 1600);
    left(20);
    // ǰ������
    hit_wall(40);
    //turn_around_open_loop();
    turn_around_open_loop();
    // ǰ�����層
    go_tai1(20);
    
    while (analog(7)<W || analog(2)<W) {
        run(-20, -20);
    }
    run(0,0);
    delay(0,500);

    // ǰ������
    left(40);
    run(20,20);
    delay(1,500);
    right(40);
    go_tai(40);
    turn_around();

    // ǰ����˳��
    right(40);
    right(40);
    go_tai(40);
    turn_around();

    // ǰ�����ţ����������ٽ�������
    line_timing(40, 500);
    line_timing(60, 500);
    line_timing(80, 1700);
    line_timing(60, 500);
    line_timing(40, 500);
    while(1){
        line(40);
        if (analog(1)<B&&analog(2)<B&&analog(3)<B&&analog(4)<B&&analog(5)<B&&analog(6)<B&&analog(7)<B&&analog(8)<B){
            break;
        }
    }
    delay(0,600);    
    while(1){
        if (analog(4)>100 || analog(5)>100){
            break;
        }
    	line_bridge(30);
    }
    run(30,30);
    delay(1,000);
    
    // ǰ���յ�
    go_end(40);
}


void mainX6(void) {
    while(1)
{
if(analog(23)>600&&analog(24)>600) { motor(1, 11); motor(2, 11); }
else if(analog(24)>600&&analog(23)<100) { motor(1, 12); motor(2, 5); }
else if(analog(23)>600&&analog(24)<100) { motor(1, 6); motor(2, 14); }
}
}
void mainX7(void){
//启动
int left=0;
while(1){
// if(analog(17==0&&left>=90000)){
// int time=2000;
// while(time--){
// run(-15,10);
// }
// }
if(left>=90000&&( analog(23)>400&&analog(24)<400 )){
run(0,0);
run(-11,7);
left++;
}
else if(analog(23)>400&&analog(24)<400){
run(0,0);
run(7,15);
left++;
}
else if(left<95000&&analog(23)<400&&analog(24)>400){
run(0,0);
run(15,7);
left++;
}
else if(analog(23)>400&&analog(24)>400){
run(10,10);
left++;
}else if( left>=95000&& (analog(23)>400&&analog(24)>400) ){
run(0,0);
run(5,5);
left++;
}
else if(left>110000)
{
left=0;
}
}
}

void line_timing(int speed, long interval){
    long start_millis;
    start_millis = mseconds();
    while (mseconds() - start_millis <= interval){
        line(speed);
    }
    run(0,0);
    delay(0,100);
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
        // ���ǰ���ϣ��������ϰ�˵�����Ų�����return 0
        if (detect_door()){
            // ������ȥ���Ա��
            run(-20,-20);
            delay(0,800);
            run(15,-15);
		    delay(2,100);
            return 0;
        }
        // ������ϣ��������ϰ�˵���Ѿ����������ˣ�˵�����ſ�ͨ��return 1
        if (cz2){
            return 1;
        }
    }
}

int detect_door(){
    if(analog(19)<300){
        return 1;
    }
    return 0;
}

int detect_left_turn_135(void) {
    if (analog(6) > W && analog(7) > W && analog(8) > W) {
        run(20, 20);
        delay(0,300);
        turn_left_135();
        return 1;
    }
    return 0;
}

int detect_left_turn(void) {
    if (analog(6) > W && analog(7) > W && analog(8) > W) {
        run(20, 20);
        delay(0, 400);
        turn_left();
        return 1;
    }
    return 0;
}

int detect_right_turn(void) {
	if ( analog(2) > W && analog(3) > W) {
		run(20, 20);
		delay(0, 400);
		turn_right();
		return 1;
	}
	return 0;
}

void turn_around(void) {
    run(25, -25);
    delay(0,700);
    //while (analog(4)<W && analog(3)<W){
        //run(25, -25);
    //}
    run(0, 0);
}

void turn_around_open_loop(void){
    run(15, -15);
    delay(1, 500);
    run(0,0);
    delay(0,150);
}

int detect_wall(void){
	if( (analog(1)>200 || analog(2)>200 || analog(3)>200 || analog(4)>200 || analog(5)>200 || analog(6)>200 || analog(7)>200 || analog(8)>200)){//wt
		run(20,20);
		delay(3,500);
		run(-20,-20);
		delay(0,400);
		return 1;
	}
	return 0;
}
// go_tai1��Ѳ��ֱ��ײǽ��ײ��������ֹͣѲ�ߣ�����������˶�����
void go_tai1(int speed) {
    while(1){
        line(speed);
        
        if (detect_tai1()){
            run(0, 0);      // ȷ��ͣ��
            delay(0, 200);
            break;
        }
        
        // ��ѡ���ӳ�ʱ��������ֹ������
        // if (mseconds() > some_start_time + 10000) break;
    }
}



//motion:�������
void motion(void){
    servo(2,690);
    delay(1,000);
    servo(2,400);
    delay(1,000);
}

int detect_tai(void){
	if(analog(1)<B&&analog(2)<B&&analog(3)<B&&analog(4)<B&&analog(5)<B&&analog(6)<B&&analog(7)<B&&analog(8)<B){
		run(30,30);
		delay(0,500);
		run(0,0);
		return 1;
	}
	return 0;
}

int detect_tai1(void){
    // ֻ��**ǰ�����������ͬʱ�����ϰ�**����ײǽ
    if(analog(1) > 250 && analog(2) > 250 && analog(3) > 200){  
        run(20, 20);      // ����һ��ײʵ
        delay(0, 400);
        run(0, 0);
        return 1;
    }
    return 0;
}


void mainX5(void) {
    djcs();
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

void line_bridge(int base) {
    if (analog(4) < 40 && analog(5) < 40) {
        run(base, base);
    } else if (analog(4) > 40 && analog(5) < 40) {
        run(0.9 * base, 1.1 * base);
    } else if (analog(4) < 40 && analog(5) > 40) {
        run(1.1 * base, 0.9 * base);
    } else if (analog(3) > 40 && analog(6) < 40) {
        run(0.8 * base, 1.3 * base);
    } else if (analog(3) < 40 && analog(6) > 40) {
        run(1.3 * base, 0.8 * base);
    } else if (analog(2) > 40 && analog(7) < 40) {
        run(0.5 * base, 1.5 * base);
    } else if (analog(7) > 40 && analog(2) < 40) {
        run(1.5 * base, 0.5 * base);
    } 
}

void turn_left(void) {
    run(0, 0);
    motor(1, -30);
    motor(2, 30);
    delay(0, 310); // ��ת	
}

void turn_left_135(void){
    run(0, 0);
    delay(1, 0);
    motor(1, -30);
    motor(2, 30);
    delay(0, 350); // ��ת 135��
}

void turn_right(void) {
    run(0, 0);
    motor(1, 30);
    motor(2, -30);
    delay(0, 285); // ��ת	
}

void mainX6(void) {

}
void mainX7(void) {

}
void mainX(void * p_arg) {
    set_name(MAINX1, "main1--SJCS"); //���������ݲ���
    set_name(MAINX2, "main2--SJDQ"); //ģ�⴫�������ݶ�ȡ
    set_name(MAINX3, "main3--FZJS"); //��ֵ����
    set_name(MAINX4, "main4--MDCS"); //�������
    set_name(MAINX5, "main5--DJCS"); //�������
    set_name(MAINX6, "main6"); //�û�����
    set_name(MAINX7, "main7"); //�û�����
    // .... x7
    set_digital(1, 0);
    i = 0; //ͨ����Զ����㷧ֵ
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
void fzjs() //��ֵ����
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

// ����ָ����ת��ָ�����򣬲�����compass��bug��û����
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

void djcs() //�������
{
    servo(2,570);
}