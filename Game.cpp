#include "Game.h"

Game::Game(int width, int height, string title)
	:
	ball({400,400},{5,4},20),
	player1({20,20},5,30,150,KEY_W,KEY_S),
	player2({ 750,20 },5,30,150,KEY_UP,KEY_DOWN)
{
	assert(!IsWindowReady());
	InitWindow(width, height, title.c_str());
	SetTargetFPS(60);
}


bool Game::should_close() const
{

	return WindowShouldClose();
}

void Game::tick()
{
	BeginDrawing();
	update();
	draw();
	EndDrawing();
}

Game::~Game()
{
	assert(IsWindowReady());
	CloseWindow();
}

void Game::draw()
{
	ClearBackground(BLACK);
	DrawRectangleLines(int(border.x),int(border.y),int(border.width),int(border.height), BLUE);
	ball.draw_ball();
	player1.draw_boards();
	player2.draw_boards();
	DrawText(TextFormat(" Score : %i",player_1score), 10, 10, 20, GREEN);
	DrawText(TextFormat(" Score : %i",player_2score), 700, 10, 20, GREEN);
}

void Game::update()
{
	ball.update_ball();
	player1.update_boards();
	player2.update_boards();
	if (c.collision_check_x(ball.ball_collision_rect,border_collision_rect))
	{
		if (ball.ball_collision_rect.x <= 20)
		{
			player_2score += 1;
		}
		else
		{
			player_1score += 1;
		}
		ball.ball_reset();
	}
	if (c.collision_check_y(ball.ball_collision_rect,border_collision_rect))
	{
		ball.collision_response();
	}
	if (c.right_collision_check(ball.ball_collision_rect, player2.collision_rect))
	{
		ball.ball_player_collision();
	}
	if (c.left_collision_check(ball.ball_collision_rect, player1.collision_rect))
	{
		ball.ball_player_collision();
	}

}


