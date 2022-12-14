#include "Contents.h"

std::string Contents::getText(int index)
{
	return textArr[index];
}

int Contents::getMaxIndex()
{
	return maxIndex;
}