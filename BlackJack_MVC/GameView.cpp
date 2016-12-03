#include "GameView.h"
#include <iostream>
#include <iomanip>

using std::cout;
using std::endl;
using std::left;
using std::setw;

GameView::GameView(GameModel * model)
{
	Attach(model);
	model->Add(this);
}

GameView::~GameView()
{
}

void GameView::PrintCard(const Card& card)
{
	switch (card.GetValue())
	{
		case Card::Value::Ace:
			cout << 'A';
			break;
		case Card::Value::King:
			cout << 'K';
			break;
		case Card::Value::Queen:
			cout << 'Q';
			break;
		case Card::Value::Jack:
			cout << 'J';
			break;
		default:
			cout << static_cast<int>(card.GetValue());
			break;
	}

	/* from 3 ♥♦♣♠ to 6 */
	switch (card.GetSuit())
	{
		case Card::Suit::Spades:
			std::cout << char(6);
			break;
		case Card::Suit::Clubs:
			std::cout << char(5);
			break;
		case Card::Suit::Hearts:
			std::cout << char(3);
			break;
		case Card::Suit::Diamonds:
			std::cout << char(4);
			break;
	}
}

void GameView::PrintHand(const Hand& hand)
{
	for (Hand::const_iterator it = hand.cbegin(); it != hand.cend(); ++it)
		PrintCard(*it);
}

void GameView::PrintGameInfo() const
{
	GameModel* model = static_cast<GameModel*>(observable);

	std::left(cout);

	cout << std::setw(10);
	cout << "Колоды:";
	for (auto& deckCount : model->GetShoe()->GetSeparatelyCounts())
		cout << '[' << deckCount << "] ";
	cout << endl;

	cout << std::setw(10) << "Дилер:" << (PrintHand(*model->GetDealerHand()), endl);

	cout << std::setw(10);
	cout << "Вы:";
	const list<Hand>* playerHands = model->GetPlayerHands();
	for (list<Hand>::const_iterator it = playerHands->begin(); it != playerHands->end(); ++it)
	{
		if (it != playerHands->begin())
			cout << std::setw(10);
		PrintHand(*it);
	}
	cout << endl;
}

void GameView::Update() const
{
	PrintGameInfo();
}
