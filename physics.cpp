#include "physics.h"

bool collision::collision_check_x(Rectangle entity1, Rectangle entity2)
{

	if ((entity1.x <= entity2.x  ||
		(entity1.x+entity1.width) >= (entity2.x+entity2.width) )
		)
	{
		return true;
	}
	return false;
}

bool collision::collision_check_y(Rectangle entity1, Rectangle entity2)
{
	if ((entity1.y <= entity2.y 
		|| (entity1.y + entity1.height) >= (entity2.y + entity2.height))
		)
	{
		return true;
	}
	return false;
}

bool collision::left_collision_check(Rectangle ball_collision, Rectangle player_collision)
{
	if (ball_collision.x <= player_collision.x + player_collision.width && 
		ball_collision.y >= player_collision.y && 
		ball_collision.y + ball_collision.height <= player_collision.y + player_collision.height)
	{
		return true;
	}
	return false;
}

bool collision::right_collision_check(Rectangle ball_collision, Rectangle player_collision)
{
	if (ball_collision.x+ball_collision.width >= player_collision.x &&
		ball_collision.y >= player_collision.y &&
		ball_collision.y + ball_collision.height <= player_collision.y + player_collision.height)
	{
		return true;
	}
	return false;
}
