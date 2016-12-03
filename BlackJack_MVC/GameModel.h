#pragma once

#include "Observer.h"
#include "Hand.h"
#include "Shoe.h"
#include <string>
#include <list>

using std::string;
using std::list;

class GameModel : public Observable
{
public:
	GameModel();
	~GameModel();

	const list<Hand>* GetPlayerHands() const;
	const Hand* GetDealerHand() const;
	const Shoe* GetShoe() const;

private:
	
	list<Hand>* playerHands;
	Hand* dealerHand;
	Shoe* shoe;

};

