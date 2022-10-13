#include <iostream>
#include "Tetris.h"
#include <conio.h>

using namespace std;


int main()
{

	Tetris t;

	drawWindow();
	hideCursor();

	char kb = 's';
	//接收键盘输入



	while (1)
	{


		t.show();

		if (_kbhit())
			kb = _getch();
		else
			kb = 's';

		

		switch (kb)
		{
		case 'q':	
			gameOver();
			break;


		default:
			if (!t.move(kb) && t.isUnMove())
			{
				t.read();
				t = Tetris();
				//放下新方块后才会满行
				
				if (t.isGameOver())
					gameOver();
				//重新生成方块后才会判定是否结束

				t.clearLine();
			}
			break;
		}


		Sleep(100);
		

	}


	return 0;
}