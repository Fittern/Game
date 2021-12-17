#include "GameEng/GameStart.h"
#include "Rules/RulesBuilder.h"


int main()
{
    //527, 55, 123, 77, 1638560379, 1638567804
    GameStart<RulesBuilder<0>, RuleEnd<-1>> game;
    game.StartGame();
    return 0;
}