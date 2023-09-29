#pragma once
#pragma once
#include <raylib.h>
#include <iostream>
#include <assert.h>
#include "physics.h"
#include "Ball.h"
#include "Board.h"
using namespace std;
class Game
{
public:
	Game(int width, int height, string title);
	Game(const Game& other) = delete;
	Game& operator=(const Game& other) = delete;
	bool should_close() const;
	void tick();
	~Game() noexcept;
private:
	ball ball;
	board player1;
	board player2;
	collision c;
	Rectangle border = { 20, 20, 760, 760 };
	Rectangle border_collision_rect = { 20, 20, 760, 760 };
	int player_1score = 0, player_2score = 0;
	void draw();
	void update();
};