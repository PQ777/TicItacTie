#include <stdio.h>

int Check(int sum);
int win(int b[][3]);
void display(int b[][3]);

int main()
{
	int board[3][3];
	char turn = 'X'; //ó�� turn�� X�� ����

	int row = 0, column = 0;
	int count = 0;
	int lose = 0;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			board[i][j] = 0;
		}
	}
		

	count = 0;
	display(board);

	do
	{
		printf("Player %c(�� ��):", turn);
		scanf_s("%d %d", &row, &column);
		printf("\n");

		if (board[row][column]) //�̹� ä���������� �ٽ� �Է� ������Ʈ ����
		{
			continue;		//�ڵ� �����κ����� ���ư�
		}

		count++; //�ɺ��� �Էµ� Ƚ�� ����

		if (turn == 'X') 
		{
			board[row][column] = 1;
			turn = 'O'; //���� �ٲ���
		}

		else
		{
			board[row][column] = -1;
			turn = 'X';
		}

		display(board);

	} while ((lose = !win(board)) && count < 9); //count�� 9 �̸��̸� 3x3 �� �������� �� ä������ ���� ����

	if (lose && count == 9)
		printf("Nobody wins!\n");
}


void display(int b[][3])
{
	char ch;

	printf("    0 1 2\n");
	printf("   ------\n");

	for (int i = 0; i < 3; i++)
	{
		printf("%d |", i);
		for (int j = 0; j < 3; j++)
		{
			if (b[i][j] == 1)
			{
				ch = 'X';
			}
			else if (b[i][j] == -1)
			{
				ch = 'O';
			}
			else
			{
				ch = ' ';
			}
			printf(" %c", ch);
		}
		printf("\n");
	}
}

int Check(int sum)
{
	if (sum == 3)
	{
		printf("Player X wins!\n");
		return 1;
	}
	else if (sum == -3)
	{
		printf("Player O wins!\n");
		return 1;
	}

	return 0; //�ƹ��� ���̱�
}

int win(int b[][3])
{
	
	// ���η� ������ üũ
	for (int i = 0; i < 3; i++)
	{
		int sum = 0; //���� üũ�ؾ��ϹǷ� �Ź� �ʱ�ȭ
		for (int j = 0; j < 3; j++)
		{
			sum += b[i][j];
		}

		if (Check(sum))
		{
			return 1;
		}
	}

	// ���η� ������ üũ
	for (int j = 0; j < 3; j++)
	{
		int sum = 0;
		for (int i = 0; i < 3; i++)
		{
			sum += b[i][j];
		}
		if (Check(sum)) return 1;
	}
	// �밢�� üũ
	int sum = 0;
	for (int i = 0; i < 3; i++)
	{
		sum += b[i][i];
	}
	if (Check(sum)) return 1;

	// ���밢�� üũ
	sum = 0;
	for (int i = 0; i < 3; i++)
	{
		sum += b[i][3 - 1 - i];
	}
	if (Check(sum))
	{
		return 1;
	}
	return 0;
}

