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
	//���ռ�������



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
				//�����·����Ż�����
				
				if (t.isGameOver())
					gameOver();
				//�������ɷ����Ż��ж��Ƿ����

				t.clearLine();
			}
			break;
		}


		Sleep(100);
		

	}


	return 0;
}