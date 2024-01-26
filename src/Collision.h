#pragma once

#include "ISubject.h"
#include "BoxCollider.h"

class Collision : public ISubject
{
public:
    virtual ~Collision();
    void Attach(IObserver* observer) override;
    void Detach(IObserver* observer) override;
    void Notify() override;

    void CreateMessage(std::string message = "Empty");
    void HowManyObserver();

private:
    std::list<IObserver*> _observers;
    std::string _message;
};