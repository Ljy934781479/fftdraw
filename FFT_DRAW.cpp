// FFT_DRAW.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#define WORK_PATH L"d:\\CodeWork\\1.bmp"

#include"myDefine.h"
#include <iostream>
#include "_ClassHpp/fftAnalysis.hpp"

int main()
{
	CReadBmp p;
	p.readFile(L"d:\\CodeWork\\1.bmp");
	p.binaryzation(RED,WHITE,0.7);
	p.setOutline(RED, WHITE, BLUE);
	p.creatOutlineList();
	CFFT c(p.getList(), p.getListSize());
	c.work(p.getWidth(),p.getHigh());
	return 0;
}