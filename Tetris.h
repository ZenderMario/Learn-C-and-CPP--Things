#pragma once

#include <iostream>
#include <Windows.h>
#include <time.h>
#include <vector>


////////////////////////////////////////////////////////////////////////


const int window_width = 15;
const int window_height = 30;
//���ڴ��ڲ���

const short shape_width = 2;
const short shape_height = 1;
//�������
const int rwindow_width = window_width * shape_width;
const int rwindow_height = window_height * shape_height;
//���Ӵ��ڲ���
//��ռ�ÿ��Ϊ2

struct Block
{
	bool block[5][5];
};
//����ÿ��������Ϣ

const Block Shape[7] =
{
	{ 0,0,1,0,0,  0,0,1,0,0,  0,0,1,0,0,  0,0,1,0,0,  0,0,0,0,0   },//����
	{ 0,0,0,0,0,  0,1,1,0,0,  0,1,1,0,0,  0,0,0,0,0,  0,0,0,0,0   },//����
	{ 0,0,0,0,0,  0,0,1,0,0,  0,0,1,0,0,  0,0,1,1,0,  0,0,0,0,0   },//L
	{ 0,0,0,0,0,  0,0,1,0,0,  0,0,1,0,0,  0,1,1,0,0,  0,0,0,0,0   },//��L
	{ 0,0,0,0,0,  0,1,1,0,0,  0,0,1,1,0,  0,0,0,0,0,  0,0,0,0,0   },//z
	{ 0,0,0,0,0,  0,0,1,1,0,  0,1,1,0,0,  0,0,0,0,0,  0,0,0,0,0   },//��z
	{ 0,0,0,0,0,  0,0,1,0,0,  0,1,1,1,0,  0,0,0,0,0,  0,0,0,0,0   } //t

};

////////////////////////////////////////////////////////////////////////

void drawWindow();
//���ô��ڴ�С
//��������

void gotoXY(short x, short y);
//�ƶ����

void hideCursor();//���ع��

void gameOver();




////////////////////////////////////////////////////////////////////////



class Tetris
{
public:
	bool window[window_height][window_width];
	//ÿ��windowֵ����һ������
	//�����С *2

	Block block;

	int m_x;
	int m_y;
	//���ķ�������

	int pm_x;
	int pm_y;
	//�°���֮ǰ����
	//������ʾ����λ��

	
	bool unmove;
	//�������ƶ�
	//�ж��������ƻ�������

	bool r_show;
	//������ʾ����ķ���
	//�Ѿ�����

	bool is_retate;
	//����Ƿ���ת
	//��ת�󷽿�ı�,������Ҫԭ����

	bool gameover;

	std::vector<int> l;
	//��������



	bool isMove(const Block &b,const int & x, const int & y);

	Block retate();

public:

	Tetris();
	//��ʼ���������

	const Tetris & operator=(const Tetris & t);

	bool move(char kb);
	//ͨ��kbֵ�ж��Ƿ����ƶ�

	void show();
	//��ʾ�����ƶ��Ķ���˹����

	bool clearLine();
	//���ĳһ��(��Ϊ��

	void read();
	//��ȡ�������ƶ��ķ���

	bool isUnMove() { return unmove; }
	//���������Ƿ�������׹

	bool isGameOver() { return gameover; }

};

////////////////////////////////////////////////////////////////////////

Tetris::Tetris()
{
	srand(unsigned(time(NULL)));

	block = Shape[rand() % 7];

	if (((rwindow_width - 5 - 1) / 2) % 2 == 0)
		m_x = (rwindow_width - 5 - 1) / 2;
	else
		m_x = (rwindow_width - 5 - 1) / 2 + 1;

	
	m_y = 3;

	pm_x = m_x;
	pm_y = m_y;

	for (int line = 0; line < window_height; line++)
		for (int col = 0; col < window_width; col++)
		{
			if (line == 0 || line == window_height - 1 || col == 0 || col == window_width - 1)
				window[line][col] = 1;
			else
				window[line][col] = 0;
		}
	//��ǽ�ĵط�

	r_show = false;
	//��ʼ״̬��������

	unmove = false;

	is_retate = false;

	
}

const Tetris& Tetris::operator=(const Tetris& t)
{
	pm_x = m_x = (rwindow_width - 5 - 1) / 2;
	pm_y = m_y = 3;
	srand(unsigned(time(NULL)));

	block = Shape[rand() % 7];

	r_show = false;

	if (!move('s'))
		gameover = true;
	else
		gameover = false;

	return t;
}

void Tetris::show()
{
	using std::cout;

	if (r_show)
	{
		for (int line = 1; line < window_height - 1; line += 1)
			for (int col = 1; col < window_width - 1; col += 1)
			{
				gotoXY(col * shape_width, line * shape_height);

				if (window[line][col])
					cout << "��";
				else
					cout << "  ";

				r_show = false;
			}
	}

	if( is_retate)
	{
		for (int line = 0; line < 5; line++)
			for (int col = 0; col < 5; col++)
			{
				if (block.block[4-col][line])
				{
					gotoXY(pm_x + (col - 2) * shape_width, pm_y + (line - 2) * shape_height);
					cout << "  ";
				}

			}
		//��ת֮�����
		is_retate = false;
	}
	else
	{
		for (int line = 0; line < 5; line++)
			for (int col = 0; col < 5; col++)
			{
				if (block.block[line][col])
				{
					gotoXY(pm_x + (col - 2) * shape_width, pm_y + (line - 2) * shape_height);
					cout << "  ";
				}

			}
	}



		pm_x = m_x;
		pm_y = m_y;
	//���֮ǰ��ʾ

	for (int line = 0; line < 5; line++)
	{
		for (int col = 0; col < 5; col++)
		{
			if (block.block[line][col])
			{
				gotoXY(pm_x + (col - 2) * shape_width, pm_y + (line - 2) * shape_height);
				cout << "��";
			}
		}
	}


	
}


Block Tetris::retate()
{
	Block temp = {};
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			temp.block[i][j] = block.block[j][4 - i];

	return temp;
}

bool Tetris::isMove(const Block& b, const int& x, const int& y)
{
	for (int line = 0; line < 5; line++)
		for (int col = 0; col < 5; col++)
			if ((window[y / shape_height -2 + line][x / shape_width - 2 + col] && b.block[line][col]))
				return false;


	return true;
}

bool Tetris::move(char kb)
{
	int tm_x = m_x;
	int tm_y = m_y;
	//��ʱ����,����һ����ʱblock

	bool ret = true;

	switch (kb)
	{
	case 'w':
		if (isMove(retate(), m_x, m_y))
		{
			block = retate();
			is_retate = true;
		}
		else
			ret = false;
		
		break;
	case 's':
		tm_y += shape_height;
		if (isMove(block, tm_x, tm_y))
			m_y += shape_height;
		else
		{
			ret = false;
			unmove = true;
		}
		break;
	case 'a':
		tm_x -= shape_width;
		if (isMove(block, tm_x, tm_y))
			m_x -= shape_width;
		else
			ret = false;
		break;
	case 'd':
		tm_x += shape_width;
		if (isMove(block, tm_x, tm_y))
			m_x += shape_width;
		else
			ret = false;
		break;

	}
	//���ϼ���ת�豣֤Ѱת���ص�
	//�����������Ҷ�Ҫ��֤���ص����˶�����ǽ

	return ret;
}

bool Tetris::clearLine()
{
	
	l.push_back(0);
	//������һ��
	
	for (int line = 1; line < window_height - 1; line++)
	{
		int col = 1;
		for (; col < window_width - 1; col++)
			if (!window[line][col])
				break;

		if(col == window_width - 1)//�����һ��
		l.push_back(line);
	}
	//�洢�����к�


	int spaceline = 0;
	//����������

	for (int i = l.size() - 1, spaceline = l[i]; i > 0; i--) //l�������зָ�ɸ�������
	{

		if (l[i] - l[i - 1] == 1)//���������ǿ��в��øı�
			continue;

		for (int line = l[i]; line > l[i - 1]; line--)
		{
			for (int col = 1; col < window_width - 1; col++)
				window[spaceline][col] = window[line - 1][col];

			spaceline--;
		}
	}



	for (int col = 0; col < window_width; col++)
		window[0][col] = 0;
	//��������һ������

	for (int i = 0; i < l.size(); i++)
		l.pop_back();


	r_show = true;



	return true;
}

void Tetris::read()
{
	for (int line = 0; line < 5; line++)
		for (int col = 0; col < 5; col++)
			if ( !window[m_y / shape_height - 2 + line][m_x / shape_width - 2 + col] && block.block[line][col])
			window[m_y / shape_height - 2 + line][m_x / shape_width - 2 + col] = block.block[line][col];

	r_show = true;
	unmove = false;
}


void drawWindow()
{
	char sys[30];
	sprintf_s(sys, "mode con lines=%d cols=%d", rwindow_height,rwindow_width);

	system(sys);
	//���ô��ڴ�С

	using std::cout;

	for (int line = 0; line < rwindow_height; line += shape_height)
		for (int col = 0; col < rwindow_width; col += shape_width)
		{
			if (line == 0 || line == rwindow_height - shape_height  || col == 0 || col == rwindow_width - shape_width )
			{
				gotoXY(col, line);
				cout << "��";
			}
			
		}


}

void gotoXY(short x, short y) 
{
	COORD coord = { x, y };
	//COORD��Windows API�ж����һ�ֽṹ�����ͣ���ʾ����̨��Ļ�ϵ����ꡣ
	//��������Ƕ�����COORD���͵ı���coord�������β�x��y���г�ʼ����


	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	//GetStdHandle(STD_OUTPUT_HANDLE); ��ȡ����̨������
	//Ȼ����SetConsoleCursorPosition���ÿ���̨(cmd)���λ��
}

void hideCursor()//���ع��
{
	HANDLE h_GAME = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor_info;
	GetConsoleCursorInfo(h_GAME, &cursor_info);
	cursor_info.bVisible = false;
	SetConsoleCursorInfo(h_GAME, &cursor_info);
}


void gameOver()
{
		gotoXY(0, 0);
		for (int line = 0; line < rwindow_height; line += shape_height)
			for (int col = 0; col < rwindow_width; col += shape_width)
			{
				std::cout << "��";
				Sleep(10);
			}
		//������з���
		exit(EXIT_SUCCESS);
}