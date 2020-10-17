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
	// 初始化绘图窗口
	initgraph(WINDOWWITH, WINDOWHEIGHT);

	// 设置背景色
	setbkcolor(BLACK);

	// 用背景色清空屏幕
	cleardevice();

	// 设置绘图色为红色
	setcolor(RED);
	setfillcolor(RED);

	// 画矩形
	rectangle(100, 100, 300, 300);
	solidcircle(200, 200, 100);

	// 按任意键退出
	_getch();
	closegraph();
}

//初始化球链表
void initBallList(Node* head)
{
	DataType b;
	for (int i = 0; i < 10; ++i)
	{
		//b.c = rand() % 2;
		b.c = i % 2;
		ListInsert(head, 0, b);
	}
}

//更新球链中球的位置
void updateBallPos(Node* head)
{
	Node* p = head;
	float x = 10.0;
	float y = WINDOWHEIGHT / 2;
	while (p->next != NULL)
	{
		p = p->next;
		p->data.x = x;
		x = x + BALLRADIUS * 2;
		p->data.y = y;
	}
}

//绘制球表
void drawBallList(Node* head)
{
	Node* p;
	DataType b;
	p = head;
	while (p->next != NULL)
	{
		p = p->next;
		b = p->data;
		setcolor(ballColorTable[b.c]);
		setfillcolor(ballColorTable[b.c]);
		solidcircle(b.x, b.y, BALLRADIUS);
	}
}

//绘制碰撞球
void drawColBall(DataType* b, float x, float y)
{
	b->x = x;
	b->y = y;
	setcolor(ballColorTable[b->c]);
	setfillcolor(ballColorTable[b->c]);
	solidcircle(b->x, b->y, BALLRADIUS);
}

//球碰撞检测
bool collisionDetection(Node* head, DataType b, bool* sameColor, int* id)
{
	Node* p = head->next;
	Node* pBef = head;
	float dist = 0.0;
	int index = 0;

	while (p != NULL)
	{
		dist = (p->data.x - b.x) * (p->data.x - b.x) + (p->data.y - b.y) * (p->data.y - b.y);
		if (dist<150.0)
		{
			if (b.c == p->data.c)
			{
				(*sameColor) = TRUE;
				(*id) = index;
			}
			else if ((b.c == pBef->data.c) && (index != 0))
			{
				(*sameColor) = TRUE;
				(*id) = index - 1;
			}
			else
			{
				(*sameColor) = FALSE;
				(*id) = index;
			}
			return TRUE;
		}
		p = p->next;
		pBef = pBef->next;
		++index;
	}
	return FALSE;
}

//判断球消掉之后相邻球是否一致
int neighborSame(Node* head)
{
	int nflag = -1, ntempfalg = 0;
	Node* pBef = head->next;
	Node* p = head->next->next;
	while (p != NULL)
	{
		if (p->data.c == pBef->data.c)
		{
			nflag = ntempfalg;
			break;
		}
		++ntempfalg;
		p = p->next;
		pBef = pBef->next;
	}
	return nflag;
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
	cball.c = rand() % 2;
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
				if (head->next == NULL)
				{
					DestroyList(head);
					closegraph();
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
					return 0;
				}
				while (neighborSame(head) != (-1))
				{
					int tempflag = neighborSame(head);
					ListDelete(head, tempflag, &tempNum);
					ListDelete(head, tempflag, &tempNum);
					temp._point += 20;
					if (head->next == NULL)
					{
						DestroyList(head);
						closegraph();
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
						return 0;
					}
				}
				updateBallPos(head);
				temp._point += 10;
			}
			cball.c = rand() % 2;
			drawColBall(&cball, WINDOWWITH / 2, WINDOWHEIGHT);
			ballMoving = FALSE;
			continue;
		}
		drawBallList(head);

		//检测碰撞球是否超出范围(应该更准确)
		if (cball.x > WINDOWWITH || cball.x <0 || cball.y > WINDOWHEIGHT || cball.y < 0)
		{
			cball.c = rand() % 2;
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
		Sleep(10);
		EndBatchDraw();
	}
}