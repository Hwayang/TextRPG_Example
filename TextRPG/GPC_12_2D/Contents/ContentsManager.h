#pragma once

#include <vector>

class Contents;
class Tutorial;

class ContentsManager
{
public:
	ContentsManager();
	Contents& Select();
	void changeIndex(Contents& target);

private:
	std::vector<Contents*> list;
	int contentsCount = 0;
};