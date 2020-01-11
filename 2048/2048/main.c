#include "game.h"

int main()
{
	int gameData[N][N];  //��Ϸ����
	int key;    //�û�����İ���

	//��ʼ����Ϸ
	initGame(gameData);

	//��ʾ��Ϸ
	showGame(gameData);

	while (1)
	{
		key = getInput();//��ȡ�û�����
		switch (key)
		{
		case UP: moveUp(gameData); break;
		case DOWN: moveDown(gameData); break;
		case LEFT: moveLeft(gameData); break;
		case RIGHT: moveRight(gameData); break;
		case EXIT: exitGame(); break;
		case OTHER: showGame(gameData);
		}
		showGame(gameData);//ÿ����һ�θ���һ�ν��
		if (checkGameWin(maxScore(gameData)) == 1)
		{
			while (1)
			{
				printf("You Win!(��'q'�˳���Ϸ)\n");
				key = getInput();
				//fflush(stdin);
				switch (key)
				{
				case EXIT: exitGame(); break;
				default: showGame(gameData);
				}
			}
			
		}
		if (checkGameOver(gameData))
		{
			while (1)
			{
				printf("Game Over!(��'q'�˳���Ϸ)\n");
				key = getInput();
				//fflush(stdin);
				switch (key)
				{
				case EXIT: exitGame(); break;
				default: showGame(gameData);
				}
			}
		}
	}
	return 0;
}
