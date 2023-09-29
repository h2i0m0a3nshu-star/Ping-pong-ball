#include "ball.h"

ball::ball(Vector2 p, Vector2 v, float r)
	:
	pos(p),
	vel(v),
	radius(r)	
{

}

void ball::draw_ball()
{
	DrawCircle(int(pos.x), int(pos.y), radius, RED);
}

void ball::update_ball()
{
	pos.x += vel.x;
	pos.y -= vel.y;
	ball_collision_rect.x = pos.x - radius;
	ball_collision_rect.y = pos.y - radius;
	ball_collision_rect.width = 2 * radius;
	ball_collision_rect.height = 2 * radius;
}

void ball::collision_response()
{
	vel.y *= -1;
}

void ball::ball_player_collision()
{
	vel.x *= -1;
}

void ball::ball_reset()
{
	pos.x = 400;
	pos.y = 400;
}
