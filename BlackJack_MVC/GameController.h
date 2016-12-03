#pragma once

#include "GameModel.h"

class GameController
{
	public:
	GameController(GameModel * model);
	~GameController();

	void Start();

	private:
	GameModel* model;
};

