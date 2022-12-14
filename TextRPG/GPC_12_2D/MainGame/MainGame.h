#include "../Engine/Game.h"
//#include "../Parser/parser.h"
#include "../Contents/ContentsManager.h"

class MainGame final : public Engine::Game
{
public:
    void  Start() final override;
    void Update() final override;
    void    End() final override;

private:
    ContentsManager Cmanager;
};