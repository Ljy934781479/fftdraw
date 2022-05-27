// FFT_DRAW.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#define WORK_PATH L"d:\\CodeWork\\1.bmp"

#include"myDefine.h"
#include "_ClassHpp/fftAnalysis.hpp"
#include <iostream>
#include<tchar.h>

int _tmain(int argc, _TCHAR* argv[])
{
	if (argc != 4)
	{
		cout << "*仅以此尝试对公式的理解,只是自己写代码做图,并没有做动画效果,可能以后会用QT做.*" << endl;
		cout << "参数: s, n, k. " << endl;
		cout << "s:图片源." << endl;
		cout << "n:程序会将图片二值化, 每个像素RGB转HSV，对于h分量小于n的改为白色,否则红色." << endl;
		cout << "k:周转圆的频率会从[-k,k]取值,越大越逼近原图像但也耗时更久." << endl;
		return 0;
	}
	CReadBmp p;
	p.readFile(argv[1]);
	p.binaryzation(RED,WHITE,_wtof(argv[2]));
	p.save24bit("d:\\CodeWork\\二值化结果.bmp");
	p.setOutline(RED, WHITE, BLUE);
	p.creatOutlineList();
	CFFT c(p.getList(), p.getListSize(),_wtoi(argv[3]));
	c.work(p.getWidth(),p.getHigh());
	cout << "完成." << endl;
	cout << "输出目录是我写死了:D:\\CodeWork" << endl;
	return 0;
}