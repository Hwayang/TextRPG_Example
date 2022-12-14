#include "Tutorial.h"

Tutorial::Tutorial()
{
	this->maxIndex = 3;

	for (size_t i = 0; i < maxIndex; i++)
	{
		textArr.push_back(new std::string);
	}

	*textArr[0] = "다음 지문을 보려면 N키를 누르세요.";
	*textArr[1] = "이전 지문을 보려면 B키를 누르세요.";
	*textArr[2] = "게임을 시작하려면 다음으로 진행하세요.";
}