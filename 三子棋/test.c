#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"game.h"
void menu()
{
	printf("*****************\n");
	printf("*****1.play******\n");
	printf("*****0.exit******\n");
	printf("*****************\n");
}
void game()
{
	char board[ROW][COL];
	char ret = 0;
	init_board(board, ROW, COL);
	print_board(board, ROW, COL);
	while (1) 
	{
		player_move(board, ROW, COL);
		print_board(board, ROW, COL);
		ret=is_win(board, ROW, COL);
		if (ret != 'c')
		{
			break;
		}
		computer_move(board, ROW, COL);
		print_board(board, ROW, COL);
		if (ret != 'c')
		{
			break;
		}
		
	}
	if (ret == '#')
		printf("����ʤ��\n");
	else if (ret == '*')
		printf("���ʤ��\n");
	else if (ret == 'q')
		printf("ƽ��\n");
}
test()
{
	srand(time(NULL));
	int input;
	do
	{
		menu();
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("��Ϸ��ʼ\n");
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����\n");
			break;
		}
	} while (input != 0);
	
}
int main()
{
	test();
	return 0;
}