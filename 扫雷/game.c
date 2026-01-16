#include"game.h"

void InitBoard(char board[ROWS][COLS], int rows, int cols,char set)
{
	int i;
	int j;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}

void DisplayBoard(char board[ROWS][COLS], int row, int col, char set)
{
	int i;
	int j;
	printf("-------------扫雷游戏--------------\n");
	for (j = 0; j <= col; j++)
	{
		printf("%d ",j);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}

void SetMine(char board[ROWS][COLS], int row, int col)
{
	int count = EASY_COUNT;
	while (count)
	{
		int x = rand() % col + 1;
		int y = rand() % row + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}

int get_my_count(char board[ROWS][COLS], int x, int y)
{
	return board[x - 1][y - 1] + board[x - 1][y] + board[x - 1][y + 1] 
		+ board[x][y - 1] + board[x][y + 1] 
		+ board[x + 1][y + 1] + board[x + 1][y] + board[x + 1][y - 1]
		- 8 * '0';
}

void FineMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x;
	int y;
	printf("请输入坐标->");
	scanf_s("%d%d", &x,&y);
	if (x >= 1 && x <= row && y >= 1 && y <= col)
	{
		if (mine[x][y] == '1')
		{
			printf("你被炸死了\n");
			DisplayBoard(mine, ROW, COL, '0');
		}
		else
		{
			int count = get_my_count(mine, x, y);
			show[x][y] = count + '0';//此处是转换为数字字符
			DisplayBoard(show, ROW, COL, '*');
		}
	}
	else
	{
		printf("你输入的坐标超出范围，请重新输入");
	}
}
