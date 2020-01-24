
#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int n = 1, a[100], b[12] = { 0 }, c[12] = { 0 };
TCHAR s[20];
char kb;
FILE *fp;

void ifcreatdata();
void bstart();
void tatalstyle();
void substyle();
void numberstyle();
void printtxt1();
int choose();
void start();
void printtxt2();
int randf();
int judge(int k);
void luckdraw();
void printtxt3();
void temp();

int main()
{
	bstart();
	do
	{
		do
		{
			printtxt1();
		} while (choose());
		start();
		temp();
	} while (1);
}
void ifcreatdata()
{
	fp = fopen("D:\\date.dat", "rb");
	if (fp == NULL)
	{
		fp = fopen("D:\\date.dat", "wb");
		int tem[100] = { 0 };
		fwrite(tem, sizeof(int), 100, fp);
	}
	fclose(fp);
}
void bstart()
{
	ifcreatdata();
	srand((unsigned int)time(0));
	initgraph(1280, 720);
	setbkcolor(0xFFFFFF);
	cleardevice();
	settextcolor(0x000000);
}
void tatalstyle()
{
	LOGFONT f;
	gettextstyle(&f);
	f.lfHeight = 72;
	_tcscpy_s(f.lfFaceName, _T("黑体"));
	f.lfQuality = ANTIALIASED_QUALITY; 
	f.lfWeight = 1000;
	settextstyle(&f);
}
void substyle()
{
	LOGFONT f;
	gettextstyle(&f);
	f.lfHeight = 24;
	_tcscpy_s(f.lfFaceName, _T("黑体"));
	f.lfQuality = ANTIALIASED_QUALITY;
	settextstyle(&f);
}
void numberstyle()
{
	LOGFONT f;
	gettextstyle(&f);
	f.lfHeight = 48;
	_tcscpy_s(f.lfFaceName, _T("黑体"));
	f.lfQuality = ANTIALIASED_QUALITY;
	settextstyle(&f);
}
void printtxt1()
{
	tatalstyle();
	clearrectangle(400, 70, 950, 150);
	outtextxy(420, 70, _T("抽奖马上开始！"));
	substyle();
	clearrectangle(1120, 80, 1180, 120);
	_stprintf_s(s, _T("中奖人数：%d"), n);
	outtextxy(1000, 100, s);
	outtextxy(200, 90, _T("开始抽奖"));
}
int choose()
{
	kb = _getch();
	if (kb == 72)
	{
		if (n < 12) n++;
		return 1;
	}
	if (kb == 80)
	{
		if (n > 1) n--;
		return 1;
	}
	if (kb == 32)
		return 0;
	else return 1;
}
void start()
{
	fp = fopen("D:\\date.dat", "rb");
	fread(a,sizeof(int), 100, fp);
	printtxt2();
	do
	{
		do
		{
			luckdraw();
			Sleep(50);
		} while (!_kbhit());
	} while (_getch() != 32);
	fclose(fp);
}
void printtxt2()
{
	tatalstyle();
	clearrectangle(400, 70, 950, 150);
	outtextxy(550, 70, _T("抽奖中！"));
	substyle();
	outtextxy(200, 90, _T("停止抽奖"));
    numberstyle();
}
int randf()
{
	int k;
	do
	{
		k = rand()%350+501;
	} while (judge(k));
	return k;
}
int judge(int k)
{
	int i;
	for (i = 0; a[i] != 0; i++)
	{
		if (k == a[i])
			return 1;
	}
	for (i = 0; i < 12; i++)
	{
		if (k == b[i])
			break;
	}
	if (i == 12)
		return 0;
	else return 1;
}
void luckdraw() 
{
	int i;
	TCHAR num[10];
	for (i = 0; i < n; i++)
	{
		b[i] = randf();
		c[i] = b[i];
		_stprintf_s(num, _T("0250%03d"), b[i]);
		outtextxy(450 + (i % 2) * 250, 200 + (i / 2) * 80, num);
	}
	
	for (i = 0; i < n; i++)
	{
		b[i] = 0;
	}
}
void printtxt3()
{
	tatalstyle();
	clearrectangle(400, 70, 950, 150);
	outtextxy(420, 70, _T("恭喜你中奖了！"));
	substyle();
	outtextxy(200, 90, _T("再次抽奖"));
	numberstyle();
}
void temp()
{
	int i,t;
	printtxt3();
	kb = 0;	
	Sleep(500);
	for (i = 0; a[i] != 0; i++);
	for (t = 0; t<12; t++,i++)
	{
		a[i] = c[t];
	}
	fp = fopen("D:\\date.dat", "wb");
	fwrite(a, sizeof(int), 100, fp);
	fclose(fp);
	do
	{
		kb = _getch();
	} while (kb!=32);
	clearrectangle(350, 150, 1000, 700);
}