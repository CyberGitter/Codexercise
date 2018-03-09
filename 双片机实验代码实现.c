
uint16 data counter=0;
uint16 data second=0;
uint16 data minute=0;
uint16 data hour=0;
uint16 data setdisp=0;
uint16 data sethour=0;
uint16 data setminute=0;
uint16 data ampm=10;
uint16 data setampm=10;
uint16 data runcounter=0;   //读秒
uint16 data setrun=0;
uint16 data runhour=0;
uint16 data runminute=0;
uint16 data runsecond=0;
uint16 data runms=0;         //ms位
uint16 data c4counter=0;    //倒计时
uint16 data setc4=0;        //setc4为0是正常显示计时时间
uint16 data c4hour=0;
uint16 data c4minute=0;
uint16 data c4second=0;
uint16 data c4ms=0;
void intT0() interrupt 1 //T0 定时中断处理函数
{
	TH0 = -4000/256;  //定时器中断时间间隔 2ms
	TL0 = -4000%256;
	counter++;                        //在任何情况下，这里的计时都不停止
	if (counter==500)
	{
		counter=0;
		second++;
		if (second==60)
		{
			second=0;
			minute++;
			if (minute==60)
			{
				minute=0;
				hour++;
				if (hour==12)
				{
					hour=0;
					if (ampm==10) ampm=16;
					else ampm=10;
				}
			}
		}
	}
	if (setrun==1)                     //秒表开始读秒，显示
	{
		runcounter++;
		if (runcounter==5)
		{
			runcounter=0;
			runms++;
			if (runms==100)
			{
				runms=0;
				runsecond++;
				if (runsecond==60)
				{
					runsecond=0;
					runminute++;
					if (runminute==60)
					{
						runminute=0;
						runhour++;
					}
				}
			}
		}
		led[0]=runms%10;
		led[1]=runms/10;
		led[2]=runsecond%10;
		led[3]=runsecond/10;
		led[4]=runminute%10;
		led[5]=runminute/10;
		led[6]=runhour%10;
		led[7]=runhour/10;
	}

	if (setrun==2)                       //秒表读秒停止时的显示
	{
		led[0]=runms%10;
		led[1]=runms/10;
		led[2]=runsecond%10;
		led[3]=runsecond/10;
		led[4]=runminute%10;
		led[5]=runminute/10;
		led[6]=runhour%10;
		led[7]=runhour/10;
	}
	if (setc4==1&&setrun==0)           //设置倒计时起始值时的显示
	{
		led[0]=c4ms%10;
		led[1]=c4ms/10;
		led[2]=c4second%10;
		led[3]=c4second/10;
		led[4]=c4minute%10;
		led[5]=c4minute/10;
		led[6]=c4hour%10;
		led[7]=c4hour/10;
	}
	if (setc4==2&&setrun==0)          //开始倒计时！！！
	{
		c4counter++;
		if (c4counter==5)
		{
			c4counter=0;
			c4ms--;
			if (c4ms==-1)
			{
				c4ms=99;
				c4second--;
				if (c4second==-1)
				{
					c4second=59;
					c4minute--;
					if (c4minute==-1)
					{
						c4minute=59;
						c4hour--;
						if (c4hour==-1)
						{led[0]=8;led[1]=8;led[2]=8;led[3]=8;led[4]=8;led[5]=8;led[6]=8;led[7]=8;}
					}
				}
			}
			if (c4hour!=-1)
			{
				led[0]=c4ms%10;
				led[1]=c4ms/10;
				led[2]=c4second%10;
				led[3]=c4second/10;
				led[4]=c4minute%10;
				led[5]=c4minute/10;
				led[6]=c4minute%10;
				led[7]=c4minute/10;
			}
		}
	}
	if (setdisp==1&&setrun==0&&setc4==0)         //设置时间模式的显示
	{
		led[0]=17;
		led[1]=17;
		led[2]=setminute%10;
		led[3]=setminute/10;
		led[4]=sethour%10;
		led[5]=sethour/10;
		led[6]=setampm;
	}

	if (setdisp==0&&setrun==0&&setc4==0)          //此为最平常的功能：计时显示
	{
		led[0]=second%10;
		led[1]=second/10;
		led[2]=minute%10;
		led[3]=minute/10;
		led[4]=hour%10;
		led[5]=hour/10;
		led[6]=ampm;
		if (minute==0&&second==0&&counter==0) led[7]=8;
		if (minute==0&&second==0&&counter==125) led[7]=17; 
		if (minute==0&&second==0&&counter==250) led[7]=8;
		if (minute==0&&second==0&&counter==375) led[7]=17;
		if (minute==0&&second==1&&counter==0) led[7]=8;
		if (minute==0&&second==1&&counter==125) led[7]=17;
		if (minute==0&&second==1&&counter==250) led[7]=8;
		if (minute==0&&second==1&&counter==375) led[7]=17;
		if (minute==0&&second==2&&counter==0) led[7]=8;
		if (minute==0&&second==2&&counter==125) led[7]=17;
		if (minute==0&&second==2&&counter==250) led[7]=8;
		if (minute==0&&second==2&&counter==375) led[7]=17;
		if (minute==0&&second==3&&counter==0) led[7]=8;
		if (minute==0&&second==3&&counter==125) led[7]=17;
		if (minute==0&&second==3&&counter==250) led[7]=8;
		if (minute==0&&second==3&&counter==375) led[7]=17;
		if (minute==0&&second==4&&counter==0) led[7]=8;
		if (minute==0&&second==4&&counter==125) led[7]=17;
		if (minute==0&&second==4&&counter==250) led[7]=8;
		if (minute==0&&second==4&&counter==375) led[7]=17;
		if (ampm==setampm&&hour==sethour&&minute==setminute&&second==0&&counter==0) led[7]=8;
		if (ampm==setampm&&hour==sethour&&minute==setminute&&second==0&&counter==125) led[7]=17; 
		if (ampm==setampm&&hour==sethour&&minute==setminute&&second==0&&counter==250) led[7]=8;
		if (ampm==setampm&&hour==sethour&&minute==setminute&&second==0&&counter==375) led[7]=17;
		if (ampm==setampm&&hour==sethour&&minute==setminute&&second==1&&counter==0) led[7]=8;
		if (ampm==setampm&&hour==sethour&&minute==setminute&&second==1&&counter==125) led[7]=17;
		if (ampm==setampm&&hour==sethour&&minute==setminute&&second==1&&counter==250) led[7]=8;
		if (ampm==setampm&&hour==sethour&&minute==setminute&&second==1&&counter==375) led[7]=17;
		if (ampm==setampm&&hour==sethour&&minute==setminute&&second==2&&counter==0) led[7]=8;
		if (ampm==setampm&&hour==sethour&&minute==setminute&&second==2&&counter==125) led[7]=17;
		if (ampm==setampm&&hour==sethour&&minute==setminute&&second==2&&counter==250) led[7]=8;
		if (ampm==setampm&&hour==sethour&&minute==setminute&&second==2&&counter==375) led[7]=17;
		if (ampm==setampm&&hour==sethour&&minute==setminute&&second==3&&counter==0) led[7]=8;
		if (ampm==setampm&&hour==sethour&&minute==setminute&&second==3&&counter==125) led[7]=17;
		if (ampm==setampm&&hour==sethour&&minute==setminute&&second==3&&counter==250) led[7]=8;
		if (ampm==setampm&&hour==sethour&&minute==setminute&&second==3&&counter==375) led[7]=17;
		if (ampm==setampm&&hour==sethour&&minute==setminute&&second==4&&counter==0) led[7]=8;
		if (ampm==setampm&&hour==sethour&&minute==setminute&&second==4&&counter==125) led[7]=17;
		if (ampm==setampm&&hour==sethour&&minute==setminute&&second==4&&counter==250) led[7]=8;
		if (ampm==setampm&&hour==sethour&&minute==setminute&&second==4&&counter==375) led[7]=17;
	}
	leddisp();  //每次定时中断显示更新一次
	if(control_readkey == 1)  //每两次定时中断扫描一次键盘
	{
		readkey();
	}
	control_readkey = !control_readkey;
}

void main(void)
{
	TMOD = 0x01;    //
	TH0 = -4000/256;  //定时器中断时间间隔 2ms
	TL0 = -4000%256;
	TCON = 0x10;
	ET0 = 1;
	EA = 1;
	initial_lcd();//初始化液晶
	while(1)
	{
		if(getkey == 1)  //判断是否获得有效按键
		{
			getkey = 0;
			switch(keynum) //判断键值，对不同键值采取相应的用户定义处理方式
			{
				case 0x0f:              //设置分钟定时值，步进减
					if (setminute==0) setminute=59;
					else setminute--;
					break;
				case 0x0e:    //设置分钟定时值，步进加
					if (setminute==59) setminute=0;
					else setminute++;
					break;
				case 0x0d:              //设置时钟定时值，步进减
					if (sethour==0) 
					{
						sethour=11;
						if (setampm==10) setampm=16;
						else setampm=10;    
					}     
					else sethour--;
					break;
				case 0x0c:    //设置时钟定时值，步进加
					if (sethour==11) 
					{
						sethour=0;
						if (setampm==10) setampm=16;
						else setampm=10;
					}    
					else sethour++;
					break;
				case 0x0b:  //当按下第二行左起第四列按键时 ，进入定时设置显示模式，再次按下则退出
					if (setdisp==0) setdisp=1;
					else setdisp=0;
					break;
				case 0x0a:                      //调整分钟，仅步进减
					if (minute==0) minute=59;
					else minute--;
					break;
				case 0x09:                           //调整分钟，仅步进加
					if (minute==59) minute=0;
					else minute++;
					break;
				case 0x08:                       //调整时钟，仅步进加
					if (hour==11) 
					{
						hour=0;
						if (ampm==10) ampm=16;
						else ampm=10;
					}
					else hour++;
					break;
				case 0x00:             //按上排左一键进入读秒模式，精确到10ms。再按此键，停止并显示当前读秒值。再按此键退回计时显示模式
					if (setrun==2) setrun=0;  //setrun的初始值为0
					else setrun++;
					if (setrun==1) {runcounter=0;runhour=0;runminute=0;runsecond=0;runms=0;}
					if (setrun==0) led[7]=17;
					break;
				case 0x01:
					if (setc4==2) setc4=0;   //setc4的初始值为0
					else setc4++;
					if (setc4==1) {c4counter=0;c4hour=0;c4minute=0;c4second=0;c4ms=0;}
					if (setc4==0) led[7]=17;
					break;
				case 0x02:                 //设置定时小时，步进加
					if (c4hour==99) c4hour=0;
					else c4hour++;
					break;
				case 0x03:                 //设置定时小时，步进减
					if (c4hour==0) c4hour=99;
					else c4hour--;
					break;
				case 0x04:                //设置定时分钟，步进加
					if (c4minute==59) c4minute=0;
					else c4minute++;
					break;
				case 0x05:               //设置定时分钟，步进减
					if (c4minute==0) c4minute=59;
					else c4minute--;
					break;
				case 0x06:              //设置定时秒钟，步进加
					if (c4second==59) c4second=0;
					else c4second++;
					break;
				case 0x07:            //设置定时秒钟，步进减
					if (c4second==0) c4second=59;
					else c4second--;
					break;
				default:
					led[0] = keynum;  //当按下其他按键时，全部数码管显示按键值
					led[1] = keynum;
					led[2] = keynum;
					led[3] = keynum;
					led[4] = keynum;
					led[5] = keynum;
					led[6] = keynum;
					led[7] = keynum;
					break;
			}
		}
	}
}
