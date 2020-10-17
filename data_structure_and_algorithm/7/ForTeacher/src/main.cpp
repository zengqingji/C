/*! gcc -std=c89 -pedantic -Wall -g -o test2 test2.c libkdtree.a -lm */
/* Extended test program, contributed by David Underhill */
#include <iostream>
#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <graphics.h>
#include <conio.h>
#include "kdtree.h"
#include "ball.h"
#include <crtdbg.h>//add this header file to detect memory leaks

#define WINDOWWITH 600
#define WINDOWHEIGHT 600
#define DEF_NUM_PTS 10
using std::cout;
using std::endl;

COLORREF ballColorTable[] = { BLUE, GREEN, RED, YELLOW, MAGENTA, BROWN };

/* returns the distance squared between two dims-dimensional double arrays */
static float dist_sq(float *a1, float *a2, int dims);

/* get a random double between -10 and 10 */
static float rd(void);

//绘制碰撞球
void drawColBall(DataType* b, float x, float y)
{
	b->x = x;
	b->y = y;
	setcolor(ballColorTable[b->c]);
	setfillcolor(ballColorTable[b->c]);
	solidcircle(b->x, b->y, BALLRADIUS);
}

int main(int argc, char **argv) {
	//初始化绘图窗口
	initgraph(WINDOWWITH, WINDOWHEIGHT);
	setbkcolor(BLACK);
	cleardevice();
	//kdtree的初始化，球的个数
	int num_pts = DEF_NUM_PTS;
	//指向kdtree
	struct kdtree *ptree = NULL;
	//某个结点存储的值，颜色
	int *data = NULL, *pch = NULL;
	//kdtree的某个节点
	struct kdres *presults = NULL;
	//某个节点坐标，距离，参考点
	float pos[2], dist;
	float pt[2];
	//搜索节点的个数，现在是1所以不需要
	//double radius = 10;
	float posx[DEF_NUM_PTS], posy[DEF_NUM_PTS];

	if (argc > 1 && isdigit(argv[1][0])) {
		num_pts = atoi(argv[1]);
	}
	if (!(data = (int*)malloc(num_pts*sizeof(int)))) {
		perror("malloc failed");
		return 1;
	}

	srand(time(0));

	/* create a k-d tree for 2-dimensional points */
	ptree = kd_create(2);
	/* add some random nodes to the tree (assert nodes are successfully inserted) */
	//把球画出来插kdtree上
	for (int i = 0; i<num_pts; ++i) {
		data[i] = i % 6;
		posx[i] = rd(), posy[i] = rd();
		assert(0 == kd_insert2f(ptree, posx[i], posy[i], &data[i]));
		setcolor(ballColorTable[data[i]]);
		setfillcolor(ballColorTable[data[i]]);
		solidcircle(posx[i], posy[i], BALLRADIUS);
	}

	//画碰撞球
	DataType cball;
	cball.c = rand() % 6;
	drawColBall(&cball, WINDOWWITH / 2, WINDOWHEIGHT);
	float ballDirction = -1;
	float speed = 10;

	//事件循环，处理鼠标、时间事件
	MOUSEMSG m;
	bool ballMoving = FALSE;
	while (true)
	{
		BeginBatchDraw();
		// 获取一条鼠标消息
		if (MouseHit())
		{
			m = GetMouseMsg();
			switch (m.uMsg)
			{
			case WM_MOUSEMOVE:
				break;

			case WM_LBUTTONDOWN:
				//更新球的运动方向，球开始运动
				if (!ballMoving)
				{
					ballDirction = float(m.x - WINDOWWITH / 2) / float(WINDOWHEIGHT - m.y);
					ballMoving = TRUE;
				}
				break;

			case WM_RBUTTONUP:
				/* free our tree, results set, and other allocated memory */
				closegraph();
				free(data);
				kd_res_free(presults);
				kd_free(ptree);
				cout << "你已经结束游戏" << endl;
				if (!_CrtDumpMemoryLeaks())
				{
					cout << "你已经结束游戏" << endl;
				}
				system("PAUSE");
				return 0;	// 按鼠标右键退出程序
			}
		}

		//定时更新球链、碰撞球
		cleardevice();
		pt[0] = cball.x;
		pt[1] = cball.y;
		/* find points closest to the origin and within distance radius */
		//这儿有点内存泄露，不应该啊？
		presults = kd_nearestf(ptree, pt);
		/* get the data and position of the current result item */
		pch = (int*)kd_res_itemf(presults, pos);
		/* compute the distance of the current result from the pt */
		dist = dist_sq(pt, pos, 2);
		//dist = 200;
		if (dist <= 150.0)
		{
			/* print out the retrieved data */
			cout << "你已经成功碰撞，碰撞球的中心坐标和颜色分别是：" << endl;
			cout << "(" << pos[0] << "," << pos[1] << ")" << " 颜色index：" << *pch << endl;
			/* free our tree, results set, and other allocated memory */
			free(data);
			kd_res_free(presults);
			kd_free(ptree);
			closegraph();
			cout << "你已经结束游戏" << endl;
			if (!_CrtDumpMemoryLeaks())
			{
				cout << "你已经结束游戏" << endl;
			}
			system("PAUSE");
			return 0;
		}

		for (int i = 0; i<num_pts; ++i) {
			setcolor(ballColorTable[data[i]]);
			setfillcolor(ballColorTable[data[i]]);
			solidcircle(posx[i], posy[i], BALLRADIUS);
		}

		//检测碰撞球是否超出范围(应该更准确)
		if (cball.x > WINDOWWITH || cball.x <0 || cball.y > WINDOWHEIGHT || cball.y < 0)
		{
			cball.c = rand() % 6;
			drawColBall(&cball, WINDOWWITH / 2, WINDOWHEIGHT);
			ballMoving = FALSE;
			cout << "你未成功碰撞" << endl;
			continue;
		}
		//移动、绘制碰撞球
		if (ballMoving == TRUE)
		{
			drawColBall(&cball, cball.x += (speed * ballDirction), cball.y -= speed);
		}
		else
		{
			drawColBall(&cball, WINDOWWITH / 2, WINDOWHEIGHT);
		}
		Sleep(10);
		EndBatchDraw();
	}
}

static float dist_sq(float *a1, float *a2, int dims) {
	double dist_sq = 0, diff;
	while (--dims >= 0) {
		diff = (a1[dims] - a2[dims]);
		dist_sq += diff*diff;
	}
	return dist_sq;
}

static float rd(void) {
	return (float)(rand() % 500);
}
