#pragma once
#ifndef _SmartPointer_V1_H
#define _SmartPointer_V1_H

template <class T>
class SmartPtr
{
public:
	SmartPtr(T *pointer)
	{
		ptr = pointer;
	}
	~SmartPtr()
	{
		delete ptr;
	}
	
	T& operator * ()
	{
		return *ptr;
	}
private:
	T* ptr;
};

#endif // !_SmartPointer_V1_H
