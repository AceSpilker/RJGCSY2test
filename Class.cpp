#include "Class.h"
#include<stdio.h>
struct DTZT
{
	int ZT;
	int DSQTYPE;
	int CSTKLC;
	int BDY;
	int flag;
}a[4];
int flag, slxl, szlc, golc, lccz[3], dth[3], i, flag1 = 0;
int js(int x, int y, int z, int g) //计算楼层差值函数
{
	int c, b, sum;
	if (a[x].ZT == 0)//此时a[x]电梯处于静止状态
	{
		if (y == z)
			return 0;
		else if (y < z)
		{
			c = z - y;
			if (y > g)
			{
				b = y - g;
			}
			else
			{
				b = g - y;
			}
			sum = c + b;
		}
		else if (y > z)
		{
			c = y - z;
			if (y > g)
			{
				b = y - g;
			}
			else
			{
				b = g - y;
			}
			sum = c + b;
		}
		return sum;
	}
}

int SL_XL_formOtoJ_AND_fromJtoO()
{
	lccz[0] = js(0, szlc, a[0].CSTKLC, golc);
	lccz[1] = js(1, szlc, a[3].CSTKLC, golc);
	if (lccz[0] < lccz[1])
	{
		//printf("离用户最近并且符合条件的电梯为：1号\n");
		a[0].CSTKLC = golc;
		return 1;
	}
	else
	{
		//printf("离用户最近并且符合条件的电梯为：4号\n");
		a[3].CSTKLC = golc;
		return 4;
	}

}
int XL_SL_fromOtoO()
{
	lccz[0] = js(0, szlc, a[0].CSTKLC, golc);
	lccz[1] = js(1, szlc, a[2].CSTKLC, golc);
	lccz[2] = js(2, szlc, a[3].CSTKLC, golc);
	if (lccz[0] < lccz[1])
	{
		if (lccz[0] < lccz[2])
		{
			//printf("离用户最近并且符合条件的电梯为：1号\n");
			a[0].CSTKLC = golc;
			return 1;
		}
		else
		{
			//printf("离用户最近并且符合条件的电梯为：4号\n");
			a[3].CSTKLC = golc;
			return 4;
		}
	}
	else
	{
		if (lccz[1] < lccz[2])
		{
			//printf("离用户最近并且符合条件的电梯为：3号\n");
			a[2].CSTKLC = golc;
			return 3;
		}
		else
		{
			//printf("离用户最近并且符合条件的电梯为：4号\n");
			a[3].CSTKLC = golc;
			return 4;
		}
	}

}

int SL_XL_fromJtoJ()
{
	lccz[0] = js(0, szlc, a[0].CSTKLC, golc);
	lccz[1] = js(1, szlc, a[1].CSTKLC, golc);
	lccz[2] = js(2, szlc, a[3].CSTKLC, golc);
	if (lccz[0] < lccz[1])
	{
		if (lccz[0] < lccz[2])
		{
			//printf("离用户最近并且符合条件的电梯为：1号\n");
			a[0].CSTKLC = golc;
			return 1;

		}
		else
		{
			//printf("离用户最近并且符合条件的电梯为：4号\n");
			a[3].CSTKLC = golc;
			return 4;
		}
	}
	else
	{
		if (lccz[1] < lccz[2])
		{
			//printf("离用户最近并且符合条件的电梯为：2号\n");
			a[1].CSTKLC = golc;
			return 2;
		}
		else
		{
			//printf("离用户最近并且符合条件的电梯为：4号\n");
			a[3].CSTKLC = golc;
			return 4;
		}
	}
}

int Class::fun(int flag,int szlc,int slxl,int golc) //接人操作
{
	a[0].ZT = 0;//三种状态：静止，上行，下行
	a[1].ZT = 0;
	a[2].ZT = 0;
	a[3].ZT = 0;
	a[0].CSTKLC = 2;//表示此时电梯停在的楼层数为1楼
	a[1].CSTKLC = 11;//表示此时电梯停在的楼层数为7楼
	a[2].CSTKLC = 8;//表示此时电梯停在的楼层数为14楼
	a[3].CSTKLC = 19;//表示此时电梯停在的楼层数为20楼
	a[0].DSQTYPE = 2;//一号电梯所有楼层都停靠
	a[1].DSQTYPE = 1;//二号电梯单号楼层都停靠
	a[2].DSQTYPE = 0;//三号电梯双号楼层都停靠
	a[3].DSQTYPE = 2;//四号电梯所有楼层都停靠
	int i;
	int flag1 = 0;
	int j = 0;
	if (flag == 1 && slxl == 1 && szlc % 2 == 0 && golc % 2 == 1)//用户需要电梯上楼在偶数层要去奇数层
		return SL_XL_formOtoJ_AND_fromJtoO();//计算上楼下楼奇数层去偶数层和偶数层去奇数层
	if (flag == 1 && slxl == 1 && szlc % 2 == 0 && golc % 2 == 0)//用户需要电梯上楼在偶数层要去偶数层
		return XL_SL_fromOtoO();//计算上楼下楼偶数层去偶数层
	if (flag == 1 && slxl == 1 && szlc % 2 == 1 && golc % 2 == 0)//用户需要电梯上楼在奇数层要去偶数层
		return SL_XL_formOtoJ_AND_fromJtoO();
	if (flag == 1 && slxl == 1 && szlc % 2 == 1 && golc % 2 == 1)//用户需要电梯上楼在奇数层要去奇数层
		return SL_XL_fromJtoJ();//计算上楼下楼奇数层去奇数层
	if (flag == 1 && slxl == 0 && szlc % 2 == 0 && golc % 2 == 1)//用户需要电梯下楼在偶数层要去奇数层
		return SL_XL_formOtoJ_AND_fromJtoO();
	if (flag == 1 && slxl == 0 && szlc % 2 == 0 && golc % 2 == 0)//用户需要电梯下楼在偶数层要去偶数层
		return XL_SL_fromOtoO();
	if (flag == 1 && slxl == 0 && szlc % 2 == 1 && golc % 2 == 0)//用户需要电梯下楼在奇数层要去偶数层
		return SL_XL_formOtoJ_AND_fromJtoO();
	if (flag == 1 && slxl == 0 && szlc % 2 == 1 && golc % 2 == 1)//用户需要电梯下楼在奇数层要去奇数层
		return SL_XL_fromJtoJ();
}