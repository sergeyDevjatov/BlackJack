#pragma once

#include "Observer.h"
#include "GameModel.h"

class GameView: public Observer
{
public:
	GameView(GameModel* model);
	~GameView();

protected:

	static void PrintCard(const Card& card);
	static void PrintHand(const Hand& hand);
	void PrintGameInfo() const;
	void Update() const;
};

