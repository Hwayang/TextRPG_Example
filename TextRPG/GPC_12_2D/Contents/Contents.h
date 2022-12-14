#pragma once

#include <vector>
#include <string>

class Contents
{
public:
	std::string getText(int index);
	int getMaxIndex();

protected:
	int maxIndex = 0;
	std::vector<std::string> textArr;
};