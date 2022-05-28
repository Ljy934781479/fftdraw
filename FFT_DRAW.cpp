// FFT_DRAW.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#define WORK_PATH L"d:\\CodeWork\\1.bmp"

#include"myDefine.h"
#include "_ClassHpp/fftAnalysis.hpp"
#include <iostream>
#include<tchar.h>

int _tmain(int argc, _TCHAR* argv[])
{
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