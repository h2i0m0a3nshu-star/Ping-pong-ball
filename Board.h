#pragma once
#include <raylib.h>

using namespace std;

class board
{
private:
	Vector2 pos;
	int vy,width, height;
	int keyup, keydown;
public:
	Rectangle collision_rect = { 0,0,0,0 };
	board(Vector2 p, int v, int w, int h,int up,int down);
	void scr_ctr();
	void draw_boards();
	void update_boards();
	
};