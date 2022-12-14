#include "../../Engine/Random.h"
#include "../Engine/Input.h"

#include "ContentsManager.h"
#include "Contents.h"

#include "Tutorial/Tutorial.h"

ContentsManager::ContentsManager()
{
	list.push_back(new Tutorial);
}

Contents& ContentsManager::Select()
{
	return *list[Random::GetInt()];
}

void ContentsManager::changeIndex(Contents& target)
{
	if (Engine::Input::Get::Key::Down('N'))
	{
		if()
	}
	else if (Engine::Input::Get::Key::Down('B'))
	{

	}

}