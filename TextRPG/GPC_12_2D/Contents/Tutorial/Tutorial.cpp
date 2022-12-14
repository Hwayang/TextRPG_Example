#include "Tutorial.h"

Tutorial::Tutorial()
{
	textArr.push_back("다음 지문을 보려면 N키를 누르세요.");
	textArr.push_back("이전 지문을 보려면 B키를 누르세요.");
	textArr.push_back("게임을 시작하려면 다음으로 진행하세요.");

	this->maxIndex = textArr.size();
}