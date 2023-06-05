#include <stdio.h>

int Check(int sum);
int win(int b[][3]);
void display(int b[][3]);

int main()
{
	int board[3][3];
	char turn = 'X'; //처음 turn을 X로 시작

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
		printf("Player %c(행 열):", turn);
		scanf_s("%d %d", &row, &column);
		printf("\n");

		if (board[row][column]) //이미 채워져있으면 다시 입력 프롬프트 실행
		{
			continue;		//코드 이전부분으로 돌아감
		}

		count++; //심볼이 입력된 횟수 증가

		if (turn == 'X') 
		{
			board[row][column] = 1;
			turn = 'O'; //턴을 바꿔줌
		}

		else
		{
			board[row][column] = -1;
			turn = 'X';
		}

		display(board);

	} while ((lose = !win(board)) && count < 9); //count가 9 미만이면 3x3 판 기준으로 다 채워지지 않은 상태

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

	return 0; //아무도 안이김
}

int win(int b[][3])
{
	
	// 가로로 세개씩 체크
	for (int i = 0; i < 3; i++)
	{
		int sum = 0; //각각 체크해야하므로 매번 초기화
		for (int j = 0; j < 3; j++)
		{
			sum += b[i][j];
		}

		if (Check(sum))
		{
			return 1;
		}
	}

	// 세로로 세개씩 체크
	for (int j = 0; j < 3; j++)
	{
		int sum = 0;
		for (int i = 0; i < 3; i++)
		{
			sum += b[i][j];
		}
		if (Check(sum)) return 1;
	}
	// 대각선 체크
	int sum = 0;
	for (int i = 0; i < 3; i++)
	{
		sum += b[i][i];
	}
	if (Check(sum)) return 1;

	// 역대각선 체크
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

