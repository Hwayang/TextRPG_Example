#pragma once

#include <vector>
#include <string>

class Contents
{
public:
	std::string getText(int index);

protected:
	int maxIndex = 0;
	std::vector<std::string*> textArr;
};