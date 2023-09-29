#include "Board.h"

board::board(Vector2 p, int v, int w, int h, int up, int down)
	:
	pos(p),
	vy(v),
	width(w),
	height(h),
	keyup(up),
	keydown(down)
{

}

void board::draw_boards()
{
	DrawRectangle(int(pos.x), int(pos.y), width, height, WHITE);
}

void board::update_boards()
{
	if (IsKeyDown(keyup) && pos.y >= 20){pos.y -= vy;}
	if (IsKeyDown(keydown) && pos.y + height <= 780){pos.y += vy;}

	collision_rect.x = pos.x;
	collision_rect.y = pos.y;
	collision_rect.width = width;
	collision_rect.height = height;
}
