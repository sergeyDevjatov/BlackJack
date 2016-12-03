#include "GameController.h"

#include <iostream>
#include <string>

using std::cin;
using std::string;

GameController::GameController(GameModel * model) : model(model)
{
}


GameController::~GameController()
{
}


void GameController::Start()
{
	while (true)
	{
		string text;
		cin >> text;
		if (text.compare("exit") == 0)
			break;
	}
}