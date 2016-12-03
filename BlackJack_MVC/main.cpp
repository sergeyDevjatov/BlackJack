#include "GameModel.h"
#include "GameView.h"
#include "GameController.h"


int main()
{
	GameModel* model = new GameModel;
	GameView* view = new GameView(model);
	GameController* controller = new GameController(model);
	controller->Start();
}