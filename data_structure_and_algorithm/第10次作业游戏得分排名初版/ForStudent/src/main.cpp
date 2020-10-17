#include <iostream>
#include <fstream>
#include "AllSort.h" 
#include "ball.h"
#include <graphics.h>
#include <conio.h>
#include <time.h>
extern "C"
{
#include "LinkList.h"
}
#include <math.h>
#include <crtdbg.h>//add this header file to detect memory leaks

#define WINDOWWITH 600
#define WINDOWHEIGHT 600

COLORREF ballColorTable[] = { BLUE, GREEN, RED, YELLOW, MAGENTA, BROWN };

//绘图函数示例
void drawExample(void)
{
}

//初始化球链表
void initBallList(Node* head)
{
}

//更新球链中球的位置
void updateBallPos(Node* head)
{
}

//绘制球表
void drawBallList(Node* head)
{
}

//绘制碰撞球
void drawColBall(DataType* b, float x, float y)
{
}

//球碰撞检测
bool collisionDetection(Node* head, DataType b, bool* sameColor, int* id)
{
}


int main() 
{
	//输入
	ifstream infile;
	infile.open("游戏排名.txt");
	int AllNum = 0;
	infile >> AllNum;
	//临时变量存输入
	GamePoint temp;
	vector<GamePoint> sv;
	for (int i = 0; i < AllNum; ++i)
	{
		infile >> temp._idx;
		infile >> temp._point;
		sv.push_back(temp);
	}
	infile.close();

	//中间操作
	cout << "请输入你的名字：(十个字符以内)" << endl;
	cin >> temp._idx;
	temp._point = 0;
	//////////////套用之前///////////////
	// 初始化绘图窗口
	initgraph(WINDOWWITH, WINDOWHEIGHT);
	setbkcolor(BLACK);
	cleardevice();

	//初始化球链
	Node* head = NULL;
	CreateEmptyList(&head);
	initBallList(head);
	updateBallPos(head);
	drawBallList(head);

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
				DestroyList(head);
				closegraph();

				//////////结束了////////////
				sv.push_back(temp);
				++AllNum;
				cout << "你的游戏得分是(击中一球得10分)：" << temp._point << endl;

				//输出
				ofstream outfile;
				outfile.open("新游戏排名.txt");
				outfile << AllNum << endl;
				ChooseSort(sv, AllNum);
				for (int i = 0; i < AllNum; ++i)
				{
					outfile << sv[i]._idx << endl;
					outfile << sv[i]._point << endl;
				}
				outfile.close();
				if (!_CrtDumpMemoryLeaks())
				{
					printf("100!\n");
				}
				system("PAUSE");
				return 0;	// 按鼠标右键退出程序
			}
		}

		//定时更新球链、碰撞球
		cleardevice();
		int id;
		bool sameColor;
		bool collision = collisionDetection(head, cball, &sameColor, &id);
		if (collision)
		{
			if (!sameColor)
			{
				ListInsert(head, id, cball);
				updateBallPos(head);
			}
			else
			{
				DataType tempNum;
				ListDelete(head, id, &tempNum);
				updateBallPos(head);
				temp._point += 10;
			}
			cball.c = rand() % 6;
			drawColBall(&cball, WINDOWWITH / 2, WINDOWHEIGHT);
			ballMoving = FALSE;
			continue;
		}
		drawBallList(head);

		//检测碰撞球是否超出范围(应该更准确)
		if (cball.x > WINDOWWITH || cball.x <0 || cball.y > WINDOWHEIGHT || cball.y < 0)
		{
			cball.c = rand() % 6;
			drawColBall(&cball, WINDOWWITH / 2, WINDOWHEIGHT);
			ballMoving = FALSE;
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
		Sleep(40);
		//FlushBatchDraw();
	}


}