#include "Tutorial.h"

Tutorial::Tutorial()
{
	this->maxIndex = 3;

	for (size_t i = 0; i < maxIndex; i++)
	{
		textArr.push_back(new std::string);
	}

	*textArr[0] = "���� ������ ������ NŰ�� ��������.";
	*textArr[1] = "���� ������ ������ BŰ�� ��������.";
	*textArr[2] = "������ �����Ϸ��� �������� �����ϼ���.";
}