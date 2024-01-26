#include "BoxCollider.h"

BoxCollider::~BoxCollider()
{
    std::cout << "Goodbye, I was the Subject.\n";
}

void BoxCollider::Attach(IObserver* observer)
{
    list_observer_.push_back(observer);
}

void BoxCollider::Detach(IObserver* observer)
{
    list_observer_.remove(observer);
}

void BoxCollider::Notify()
{
    std::list<IObserver*>::iterator iterator = list_observer_.begin();
    HowManyObserver();
    while (iterator != list_observer_.end())
    {
        (*iterator)->Update(message_);
        ++iterator;
    }
}

void BoxCollider::CreateMessage(std::string message)
{
    this->message_ = message;
    Notify();
}

void BoxCollider::HowManyObserver()
{
    std::cout << "There are " << list_observer_.size() << " observers in the list.\n";
}
