
#include "GameEngine.h"

using namespace sf;
using namespace std;

int main()
{
    
    unique_ptr <GameEngine> myGame = make_unique<GameEngine>();
        
    myGame->run();


}