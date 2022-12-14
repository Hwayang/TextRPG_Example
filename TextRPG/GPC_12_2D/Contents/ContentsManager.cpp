#include <algorithm>
#include <cassert>

#include "../Engine/Random.h"
#include "../Engine/Input.h"

#include "ContentsManager.h"

#include "Tutorial/Tutorial.h"

ContentsManager::ContentsManager()
{
	targetText.Length = { 255,255 };
	targetText.Color = { 0,0,0 };
	targetText.Location = { 0,0 };

	list.insert({0, new Tutorial});

	thisContents = *list.find(0)->second;
	targetText.Text = thisContents.getText(0).c_str();
}

Contents& ContentsManager::Select()
{
	return *list[Random::GetInt(0, maxContents)];
}

bool ContentsManager::changeIndex(Contents& target)
{
	if (Engine::Input::Get::Key::Down('N'))
	{
		if (contentsCount >= target.getMaxIndex())
		{
			return false;
		}

		targetText.Text = target.getText(contentsCount).c_str();
		++contentsCount;
		return true;
	}
	else if (Engine::Input::Get::Key::Down('B'))
	{
		if (contentsCount <= 0)
		{
			return true;
		}

		targetText.Text = target.getText(contentsCount - 1).c_str();
		--contentsCount;
		return true;
	}

	return false;
}

void ContentsManager::update()
{
	if (changeIndex(thisContents) == false)
	{
		thisContents = Select();
	}

	targetText.Render();
}