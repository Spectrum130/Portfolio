#pragma once
#ifndef _ANIMTEXT_V1_H
#define _ANIMTEXT_V1_H

#include <string>
#include <Windows.h>

// Instructions:
//
// Inside the classes use: 
// AnimText ObjectName = AnimText(delay);
// Or
// AnimText ObjectName;
//
// Outside of classes, use the previous or:
// AnimText ObjectName(delay);

class AnimText
{
public:

	// Default 45ms
	AnimText()
	{
		_delaySleep = 45;
	}

	// Time in ms
	AnimText(short delay)
		:_delaySleep(delay)
	{
	}

	void Print(std::string message)
	{
		for (short i = 0; i < message.length(); i++) {
			std::cout << message[i];
			Sleep(_delaySleep);
		}
	}

	//Time in ms
	void SetDelay(short time)
	{
		_delaySleep = time;
	}

private:
	short _delaySleep;
};

#endif // !_ANIMTEXT_V1_H