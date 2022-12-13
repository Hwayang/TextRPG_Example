#include "Engine/Initialize.h"

#include "MainGame/MainGame.h"

namespace Engine
{
    Game * Initialize()
    {
        return new MainGame;
    }
}