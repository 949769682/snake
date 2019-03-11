#include "pch.h"
#include <iostream>
#include<conio.h>
#include<windows.h>
#include<time.h>
#define random(x,y) (rand()%28-1)

using namespace std;
const char *graph[30][30];
char ch = 'w';
typedef struct snakes
{
	int x;
	int y;
	struct snakes *next;
}snake;
snake *head, *tail;
void Delete_tail()
{
	graph[tail->y][tail->x] = "　";

}
void Finish()
{
	system("cls");
	cout << "\n\n\n\n\n\n\n\n\t\t\t\t\t游戏结束！";
	_getch();
}
void Paint_snake()
{


	graph[head->y][head->x] = "■";
	graph[tail->y][tail->x] = "■";
}
void Update_snake()
{
	snake *flag;
	srand((unsigned)time(NULL));
	Delete_tail();
	flag = tail;
	while (flag->next != NULL)
	{
		flag->x = flag->next->x;
		flag->y = flag->next->y;
		flag = flag->next;
	}

}
void Create_food()
{
	int x, y;
	loop:
	x = random(1, 28);
	y = random(1, 28);
	snake *flag;
	flag = tail;
	while(flag!=NULL)
	{
		if (x == flag->x&&y == flag->y)
			goto loop;
		else
			flag = flag->next;
	}
	graph[y][x] = "★";
}
void Create_head(int x,int y)
{
	snake *flag;
	flag = (snake*)malloc(sizeof(snakes));
	flag->x = x;
	flag->y = y;
	flag->next = NULL;
	head->next = flag;
	head = flag;
	graph[head->y][head->x] = "■";
	Create_food();
}

void Move()
{
	
	if (_kbhit() != 0)
	{
		ch = _getch();
	}
	switch (ch)
	{
	case 'w':
			if (graph[head->y - 1][head->x] == "　")
			{
				Update_snake();
				head->y -= 1;
				Paint_snake();
				break;
			}
			if (graph[head->y - 1][head->x] == "★")
			{
				Create_head(head->x, head->y - 1);
				
				Update_snake();
				break;
			}
			if (graph[head->y-1][head->x] == "■")
				Finish();break;
	case 's':
			if (graph[head->y + 1][head->x] == "　")
			{
				Update_snake();
				head->y += 1;
				Paint_snake();
				break;
			}
			 if (graph[head->y + 1][head->x] == "★")
			 {
				 Create_head(head->x, head->y + 1);
			
				 Update_snake();
				 break;
			 }
			 if (graph[head->y + 1][head->x] == "■")
				 Finish();break;
	case 'a':
			if (graph[head->y][head->x - 1] == "　")
			{
				Update_snake();
				head->x -= 1;
				Paint_snake();
				break;
			}
			if (graph[head->y][head->x - 1] == "★")
			{
				Create_head(head->x - 1, head->y);
			
				Update_snake();
				break;
			}
			if (graph[head->y][head->x - 1] == "■")
				Finish();break;
	case 'd':
		if (graph[head->y][head->x + 1] == "　")
		{
			Update_snake();
			head->x += 1;
			Paint_snake();
			break;
		}
		if (graph[head->y][head->x + 1] == "★")
		{
			Create_head(head->x + 1, head->y);
			
			Update_snake();
			break;
		}
		if (graph[head->y][head->x + 1] == "■")
			Finish();break;
	default:break;
	}

}

void Create_graph()
{
	for (int i = 0;i < 30;i++)
		for (int j = 0;j < 30;j++)
		{
			const char *p;
			if (i == 0 || i == 29 || j == 0 || j == 29)
				p = "■";
			else
				p = "　";
			graph[i][j] = p;
		}
}
void Cout_graph()
{
	for (int i = 0;i < 30;i++)
	{
		for (int j = 0;j < 30;j++)
		{
			cout << graph[i][j];
		}
		cout << "\n";
	}
}
int main()
{
	int speed;
	head = (snake*)malloc(sizeof(snakes));
	tail = (snake*)malloc(sizeof(snakes));
	tail->x = 16;
	tail->y = 15;
	head->x = 15;
	head->y = 15;
	tail->next = head;
	head->next = NULL;
	cout << "请输入蛇的爬行速度(ms)：";
	cin >> speed;
	system("cls");

	Create_graph();
	Paint_snake();
	Cout_graph();
	Create_food();
	
	while (1) 
	{
		
		Move();
		Cout_graph();
		Sleep(speed);
		system("cls");
	
	}


}

