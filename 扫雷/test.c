#include"game.h"
void menu()
{
	printf("**************\n");
	printf("*欢迎登入游戏*\n");
	printf("*  请选择->  *\n");
	printf("* 1:开始游戏 *\n");
	printf("* 0:退出游戏 *\n");
	printf("**************\n");
}

void game()
{
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	InitBoard(mine, ROWS, COLS,'0');
	InitBoard(show, ROWS, COLS,'*');
	DisplayBoard(show, ROW, COL,'*');
}

int main()
{
	int n;
	do
	{
		menu();
		printf("请选择:");
		scanf_s("%d", &n);
		switch (n)
		{
		case (1):
			printf("开始游戏\n");
			game();
			break;
		case (0):
			printf("退出游戏\n");
			break;
		default:
			break;

		}
	} while (n);
}