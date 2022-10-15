#pragma once

#include <iostream>
#include <Windows.h>
#include <time.h>
#include <vector>


////////////////////////////////////////////////////////////////////////


const int window_width = 15;
const int window_height = 30;
//类内窗口参数

const short shape_width = 2;
const short shape_height = 1;
//方块参数
const int rwindow_width = window_width * shape_width;
const int rwindow_height = window_height * shape_height;
//可视窗口参数
//□占用宽度为2

struct Block
{
	bool block[5][5];
};
//储存每个方块信息

const Block Shape[7] =
{
	{ 0,0,1,0,0,  0,0,1,0,0,  0,0,1,0,0,  0,0,1,0,0,  0,0,0,0,0   },//长条
	{ 0,0,0,0,0,  0,1,1,0,0,  0,1,1,0,0,  0,0,0,0,0,  0,0,0,0,0   },//方块
	{ 0,0,0,0,0,  0,0,1,0,0,  0,0,1,0,0,  0,0,1,1,0,  0,0,0,0,0   },//L
	{ 0,0,0,0,0,  0,0,1,0,0,  0,0,1,0,0,  0,1,1,0,0,  0,0,0,0,0   },//反L
	{ 0,0,0,0,0,  0,1,1,0,0,  0,0,1,1,0,  0,0,0,0,0,  0,0,0,0,0   },//z
	{ 0,0,0,0,0,  0,0,1,1,0,  0,1,1,0,0,  0,0,0,0,0,  0,0,0,0,0   },//反z
	{ 0,0,0,0,0,  0,0,1,0,0,  0,1,1,1,0,  0,0,0,0,0,  0,0,0,0,0   } //t

};

////////////////////////////////////////////////////////////////////////

void drawWindow();
//设置窗口大小
//其它可视

void gotoXY(short x, short y);
//移动光标

void hideCursor();//隐藏光标

void gameOver();




////////////////////////////////////////////////////////////////////////



class Tetris
{
public:
	bool window[window_height][window_width];
	//每个window值代表一个方块
	//方块大小 *2

	Block block;

	int m_x;
	int m_y;
	//中心方块坐标

	int pm_x;
	int pm_y;
	//新按键之前坐标
	//用于显示方块位置

	
	bool unmove;
	//不能再移动
	//判断是左右移还是下落

	bool r_show;
	//重新显示上面的方块
	//已经清行

	bool is_retate;
	//检测是否旋转
	//旋转后方块改变,消除需要原方块

	bool gameover;

	std::vector<int> l;
	//保存满行



	bool isMove(const Block &b,const int & x, const int & y);

	Block retate();

public:

	Tetris();
	//初始化各项参数

	const Tetris & operator=(const Tetris & t);

	bool move(char kb);
	//通过kb值判断是否能移动

	void show();
	//显示正在移动的俄罗斯方块

	bool clearLine();
	//清除某一行(若为慢

	void read();
	//读取不能再移动的方块

	bool isUnMove() { return unmove; }
	//返回现在是否不能再下坠

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
	//画墙的地方

	r_show = false;
	//初始状态不用清行

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
					cout << "■";
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
		//旋转之后清除
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
	//清除之前显示

	for (int line = 0; line < 5; line++)
	{
		for (int col = 0; col < 5; col++)
		{
			if (block.block[line][col])
			{
				gotoXY(pm_x + (col - 2) * shape_width, pm_y + (line - 2) * shape_height);
				cout << "■";
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
	//临时坐标,构建一个临时block

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
	//向上即旋转需保证寻转后不重叠
	//向下向左向右都要保证不重叠且运动后不碰墙

	return ret;
}

bool Tetris::clearLine()
{
	
	l.push_back(0);
	//最上面一行
	
	for (int line = 1; line < window_height - 1; line++)
	{
		int col = 1;
		for (; col < window_width - 1; col++)
			if (!window[line][col])
				break;

		if(col == window_width - 1)//检查完一行
		l.push_back(line);
	}
	//存储满行行号


	int spaceline = 0;
	//最下面满行

	for (int i = l.size() - 1, spaceline = l[i]; i > 0; i--) //l容器满行分割成各个区间
	{

		if (l[i] - l[i - 1] == 1)//连着两行是空行不用改变
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
	//把最上面一层消除

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
	//设置窗口大小

	using std::cout;

	for (int line = 0; line < rwindow_height; line += shape_height)
		for (int col = 0; col < rwindow_width; col += shape_width)
		{
			if (line == 0 || line == rwindow_height - shape_height  || col == 0 || col == rwindow_width - shape_width )
			{
				gotoXY(col, line);
				cout << "■";
			}
			
		}


}

void gotoXY(short x, short y) 
{
	COORD coord = { x, y };
	//COORD是Windows API中定义的一种结构体类型，表示控制台屏幕上的坐标。
	//上面语句是定义了COORD类型的变量coord，并以形参x和y进行初始化。


	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	//GetStdHandle(STD_OUTPUT_HANDLE); 获取控制台输出句柄
	//然后用SetConsoleCursorPosition设置控制台(cmd)光标位置
}

void hideCursor()//隐藏光标
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
				std::cout << "■";
				Sleep(10);
			}
		//清除所有方块
		exit(EXIT_SUCCESS);
}