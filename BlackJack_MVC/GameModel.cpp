#include "GameModel.h"



GameModel::GameModel()
{
	playerHands = new list<Hand>;
	dealerHand = new Hand;
	shoe = new Shoe;
}


GameModel::~GameModel()
{
}

const list<Hand>* GameModel::GetPlayerHands() const
{
	playerHands;
}

const Hand* GameModel::GetDealerHand() const
{
	return dealerHand;
}

const Shoe* GameModel::GetShoe() const
{
	return shoe;
}