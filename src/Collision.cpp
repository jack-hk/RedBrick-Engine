#include "Collision.h"

Collision::~Collision()
{
    std::cout << "Goodbye, I was the Subject.\n";
}

void Collision::Attach(IObserver* observer)
{
	_observers.push_back(observer);
}

void Collision::Detach(IObserver* observer)
{
    _observers.remove(observer);
}

void Collision::Notify()
{
    std::list<IObserver*>::iterator iterator = _observers.begin();
    HowManyObserver();
    while (iterator != _observers.end())
    {
        (*iterator)->OnNotify(_message);
        ++iterator;
    }
}

void Collision::CreateMessage(std::string message)
{
    this->_message = message;
    Notify();
}

void Collision::HowManyObserver()
{
    std::cout << "There are " << _observers.size() << " observers in the list.\n";
}
