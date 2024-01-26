#pragma once
#include <iostream>
#include <list>

#include "Game.h"

class Collision;
class BoxCollider : public Component
{
public:
    BoxCollider(Collision &subject, GameObject* gameobject, Vector2D offset = Vector2D(0, 0));
    BoxCollider(Collision &subject, GameObject* gameobject, Vector2D newSize, Vector2D offset = Vector2D(0, 0));
    virtual ~BoxCollider();

    void Update() override;
    void OnNotify(const std::string& message_from_subject) override;

    //debug ----
    void RemoveMeFromTheList();
    void PrintInfo();

    // -----
private:
    std::string _messageFromSubject;
    Collision &_subject;
    static int static_number_;
    int _number;

    SDL_Rect _body = SDL_Rect(0, 0, 0, 0);
    Vector2D _colliderSize = Vector2D(0, 0);
    Vector2D _colliderOffset = Vector2D(0, 0);
};