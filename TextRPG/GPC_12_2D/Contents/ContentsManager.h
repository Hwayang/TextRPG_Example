#pragma once

#include <vector>
#include <map>
#include <string>

#include "../Engine/Rendering.h"
#include "Contents.h"

class Contents;
class Tutorial;

class ContentsManager
{
public:
	ContentsManager();

	Contents& Select();
	bool changeIndex(Contents& target);
	void update();

private:
	std::map<int, Contents*> list;
	Engine::Rendering::Text::Component targetText;
	Contents thisContents;

	int contentsCount = 0;
	int maxContents = 0;
};