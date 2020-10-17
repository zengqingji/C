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

//������ײ��
void drawColBall(DataType* b, float x, float y)
{
	b->x = x;
	b->y = y;
	setcolor(ballColorTable[b->c]);
	setfillcolor(ballColorTable[b->c]);
	solidcircle(b->x, b->y, BALLRADIUS);
}

int main(int argc, char **argv) {
	//��ʼ����ͼ����
	initgraph(WINDOWWITH, WINDOWHEIGHT);
	setbkcolor(BLACK);
	cleardevice();
	//kdtree�ĳ�ʼ������ĸ���
	int num_pts = DEF_NUM_PTS;
	//ָ��kdtree
	struct kdtree *ptree = NULL;
	//ĳ�����洢��ֵ����ɫ
	int *data = NULL, *pch = NULL;
	//kdtree��ĳ���ڵ�
	struct kdres *presults = NULL;
	//ĳ���ڵ����꣬���룬�ο���
	float pos[2], dist;
	float pt[2];
	//�����ڵ�ĸ�����������1���Բ���Ҫ
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
	//���򻭳�����kdtree��
	for (int i = 0; i<num_pts; ++i) {
		data[i] = i % 6;
		posx[i] = rd(), posy[i] = rd();
		assert(0 == kd_insert2f(ptree, posx[i], posy[i], &data[i]));
		setcolor(ballColorTable[data[i]]);
		setfillcolor(ballColorTable[data[i]]);
		solidcircle(posx[i], posy[i], BALLRADIUS);
	}

	//����ײ��
	DataType cball;
	cball.c = rand() % 6;
	drawColBall(&cball, WINDOWWITH / 2, WINDOWHEIGHT);
	float ballDirction = -1;
	float speed = 10;

	//�¼�ѭ����������ꡢʱ���¼�
	MOUSEMSG m;
	bool ballMoving = FALSE;
	while (true)
	{
		BeginBatchDraw();
		// ��ȡһ�������Ϣ
		if (MouseHit())
		{
			m = GetMouseMsg();
			switch (m.uMsg)
			{
			case WM_MOUSEMOVE:
				break;

			case WM_LBUTTONDOWN:
				//��������˶�������ʼ�˶�
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
				cout << "���Ѿ�������Ϸ" << endl;
				if (!_CrtDumpMemoryLeaks())
				{
					cout << "���Ѿ�������Ϸ" << endl;
				}
				system("PAUSE");
				return 0;	// ������Ҽ��˳�����
			}
		}

		//��ʱ������������ײ��
		cleardevice();
		pt[0] = cball.x;
		pt[1] = cball.y;
		/* find points closest to the origin and within distance radius */
		//����е��ڴ�й¶����Ӧ�ð���
		presults = kd_nearestf(ptree, pt);
		/* get the data and position of the current result item */
		pch = (int*)kd_res_itemf(presults, pos);
		/* compute the distance of the current result from the pt */
		dist = dist_sq(pt, pos, 2);
		//dist = 200;
		if (dist <= 150.0)
		{
			/* print out the retrieved data */
			cout << "���Ѿ��ɹ���ײ����ײ��������������ɫ�ֱ��ǣ�" << endl;
			cout << "(" << pos[0] << "," << pos[1] << ")" << " ��ɫindex��" << *pch << endl;
			/* free our tree, results set, and other allocated memory */
			free(data);
			kd_res_free(presults);
			kd_free(ptree);
			closegraph();
			cout << "���Ѿ�������Ϸ" << endl;
			if (!_CrtDumpMemoryLeaks())
			{
				cout << "���Ѿ�������Ϸ" << endl;
			}
			system("PAUSE");
			return 0;
		}

		for (int i = 0; i<num_pts; ++i) {
			setcolor(ballColorTable[data[i]]);
			setfillcolor(ballColorTable[data[i]]);
			solidcircle(posx[i], posy[i], BALLRADIUS);
		}

		//�����ײ���Ƿ񳬳���Χ(Ӧ�ø�׼ȷ)
		if (cball.x > WINDOWWITH || cball.x <0 || cball.y > WINDOWHEIGHT || cball.y < 0)
		{
			cball.c = rand() % 6;
			drawColBall(&cball, WINDOWWITH / 2, WINDOWHEIGHT);
			ballMoving = FALSE;
			cout << "��δ�ɹ���ײ" << endl;
			continue;
		}
		//�ƶ���������ײ��
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
