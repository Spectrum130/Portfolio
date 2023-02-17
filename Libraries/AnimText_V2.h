#pragma once
#ifndef _ANIMTEXT_V2_H
#define _ANIMTEXT_V2_H

#include <string>
#include <synchapi.h>

// Instructions:
//
// Inside the classes use: 
// Anim::AnimText ObjectName = Anim::AnimText(delay);
// Or
// Anim::AnimText ObjectName;
//
// Outside of classes, use the previous or:
// Anim::AnimText ObjectName(delay);
//
// Use: 
// ObjectName << "Message";   
// Or
// ObjectName.Print("Message");
//

// Developed by ForMig
namespace Anim
{
	// Developed by ForMig
	class AnimText
	{
	public:

		// Default delay 45ms
		AnimText()
		{
			_delaySleep = 45;
		}

		// Delay in ms
		AnimText(short delay)
			:_delaySleep(delay)
		{
		}

		// Animated output
		void Print(std::string message)
		{
			for (short i = 0; i < message.length(); ++i) {
				std::cout << message[i];
				Sleep(_delaySleep);
			}
		}

		//Time in ms
		void setDelay(short time)
		{
			_delaySleep = time;
		}

		short getDelay()
		{
			return _delaySleep;
		}

		void EndLine()
		{
			Sleep(_delaySleep);
			std::cout << "\n";
		}

		friend void operator << (AnimText& out, const char str[]);
		friend void operator << (AnimText& out, std::string message);
		friend void operator >> (AnimText& out, short delay);

	private:
		short _delaySleep;
	};


	// Animated output
	void operator << (AnimText& out, const char message[])
	{
		unsigned int length = strlen(message);
		
		for (short i = 0; i < length; ++i) {
			
			std::cout << message[i];
			Sleep(out.getDelay());
		}
	}

	// Animated output
	void operator << (AnimText& out, std::string message)
	{
		out.Print(message);
	}


	// Setup delay in ms
	void operator >> (AnimText& out, short delay)
	{
		out.setDelay(delay);
	}


}



#endif // !_ANIMTEXT_V1_H