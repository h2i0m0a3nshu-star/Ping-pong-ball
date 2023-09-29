#pragma once
#include <raylib.h>

class collision
{
public:
	bool collision_check_x(Rectangle entity1,Rectangle entity2);
	bool collision_check_y(Rectangle entity1, Rectangle entity2);
	bool left_collision_check(Rectangle ball_collision,Rectangle player_collision);
	bool right_collision_check(Rectangle ball_collision,Rectangle player_collision);
private:

};