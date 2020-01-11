#include "game.h"

int main()
{
	int gameData[N][N];  //游戏数据
	int key;    //用户输入的按键

	//初始化游戏
	initGame(gameData);

	//显示游戏
	showGame(gameData);

	while (1)
	{
		key = getInput();//获取用户输入
		switch (key)
		{
		case UP: moveUp(gameData); break;
		case DOWN: moveDown(gameData); break;
		case LEFT: moveLeft(gameData); break;
		case RIGHT: moveRight(gameData); break;
		case EXIT: exitGame(); break;
		case OTHER: showGame(gameData);
		}
		showGame(gameData);//每操作一次更新一次结果
		if (checkGameWin(maxScore(gameData)) == 1)
		{
			while (1)
			{
				printf("You Win!(按'q'退出游戏)\n");
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
				printf("Game Over!(按'q'退出游戏)\n");
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
