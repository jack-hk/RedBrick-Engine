#pragma once
#include <string>

class IObserver
{
public:
	virtual ~IObserver() {};
	virtual void Update() = 0;
	virtual void OnNotify(const std::string& message_from_subject) = 0;
};
