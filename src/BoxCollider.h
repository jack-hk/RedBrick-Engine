#pragma once
#include <iostream>
#include <list>

#include "ISubject.h"

class BoxCollider : public ISubject
{
public:
    virtual ~BoxCollider();
    void Attach(IObserver* observer) override;
    void Detach(IObserver* observer) override;
    void Notify() override;

    void CreateMessage(std::string message = "Empty");
    void HowManyObserver();
private:
    std::list<IObserver*> list_observer_;
    std::string message_;
};