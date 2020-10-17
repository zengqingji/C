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

//��ͼ����ʾ��
void drawExample(void)
{
}

//��ʼ��������
void initBallList(Node* head)
{
}

//�������������λ��
void updateBallPos(Node* head)
{
}

//�������
void drawBallList(Node* head)
{
}

//������ײ��
void drawColBall(DataType* b, float x, float y)
{
}

//����ײ���
bool collisionDetection(Node* head, DataType b, bool* sameColor, int* id)
{
}


int main() 
{
	//����
	ifstream infile;
	infile.open("��Ϸ����.txt");
	int AllNum = 0;
	infile >> AllNum;
	//��ʱ����������
	GamePoint temp;
	vector<GamePoint> sv;
	for (int i = 0; i < AllNum; ++i)
	{
		infile >> temp._idx;
		infile >> temp._point;
		sv.push_back(temp);
	}
	infile.close();

	//�м����
	cout << "������������֣�(ʮ���ַ�����)" << endl;
	cin >> temp._idx;
	temp._point = 0;
	//////////////����֮ǰ///////////////
	// ��ʼ����ͼ����
	initgraph(WINDOWWITH, WINDOWHEIGHT);
	setbkcolor(BLACK);
	cleardevice();

	//��ʼ������
	Node* head = NULL;
	CreateEmptyList(&head);
	initBallList(head);
	updateBallPos(head);
	drawBallList(head);

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
				DestroyList(head);
				closegraph();

				//////////������////////////
				sv.push_back(temp);
				++AllNum;
				cout << "�����Ϸ�÷���(����һ���10��)��" << temp._point << endl;

				//���
				ofstream outfile;
				outfile.open("����Ϸ����.txt");
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
				return 0;	// ������Ҽ��˳�����
			}
		}

		//��ʱ������������ײ��
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

		//�����ײ���Ƿ񳬳���Χ(Ӧ�ø�׼ȷ)
		if (cball.x > WINDOWWITH || cball.x <0 || cball.y > WINDOWHEIGHT || cball.y < 0)
		{
			cball.c = rand() % 6;
			drawColBall(&cball, WINDOWWITH / 2, WINDOWHEIGHT);
			ballMoving = FALSE;
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
		Sleep(40);
		//FlushBatchDraw();
	}


}