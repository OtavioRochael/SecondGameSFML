#include "Game.hpp"

int main()
{
    //Initialize random seed
    srand(static_cast<unsigned>(time(0)));

    //Initialize game object
    Game game;

    //Game looping
    while (game.RunningGame()) {
        game.Update();
        game.Render();
    }
    
    //End of application
    return 0;
}