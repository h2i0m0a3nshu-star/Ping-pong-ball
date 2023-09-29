#pragma once
#include <raylib.h>

using namespace std;

class ball
{
public:
	ball(Vector2 p, Vector2 v, float r);
	Rectangle ball_collision_rect = { 0,0,0,0 };
	void draw_ball();
	void update_ball();
	void collision_response();
	void ball_player_collision();
	void ball_reset();
private:
	Vector2 pos, vel;
	float radius;
	
};
