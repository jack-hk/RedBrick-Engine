#include "BoxCollider.h"

BoxCollider::BoxCollider(Collision& subject, GameObject* gameObject, Vector2D offset) : _subject(subject), Component(gameObject)
{
	_body = SDL_Rect{
		(int)_gameObject->GetPosition().x + (int)offset.x,
		(int)_gameObject->GetPosition().y + (int)offset.y,
		(int)_gameObject->GetSize(),
		(int)_gameObject->GetSize()
	};
	_colliderSize.x = _body.w;
	_colliderSize.y = _body.h;
	_colliderOffset = offset;

	this->_subject.Attach(this);
	this->_number = BoxCollider::static_number_;
	if (Game::_isDebugMode) { std::cout << "Hi, I'm the Observer \"" << ++BoxCollider::static_number_ << "\".\n"; }
}

BoxCollider::BoxCollider(Collision& subject, GameObject* gameObject, Vector2D newSize, Vector2D offset) : _subject(subject), Component(gameObject)
{
	_body = SDL_Rect{
		(int)_gameObject->GetPosition().x + (int)offset.x,
		(int)_gameObject->GetPosition().y + (int)offset.y,
		(int)newSize.x,
		(int)newSize.y
	};
	_colliderSize = newSize;
	_colliderOffset = offset;

	this->_subject.Attach(this);
	this->_number = BoxCollider::static_number_;
	if (Game::_isDebugMode) { std::cout << "Hi, I'm the Observer \"" << ++BoxCollider::static_number_ << "\".\n"; }
}

BoxCollider::~BoxCollider()
{
	std::cout << "Goodbye, I was the Subject.\n";
}

void BoxCollider::Update()
{
	_body = SDL_Rect{
	(int)_gameObject->GetPosition().x + (int)_colliderOffset.x,
	(int)_gameObject->GetPosition().y + (int)_colliderOffset.y,
	(int)_colliderSize.x,
	(int)_colliderSize.y
	};
}

void BoxCollider::OnNotify(const std::string& message_from_subject)
{
	_messageFromSubject = message_from_subject;
	PrintInfo();
}

void BoxCollider::RemoveMeFromTheList()
{
	_subject.Detach(this);
	std::cout << "Observer \"" << _number << "\" removed from the list.\n";
}

void BoxCollider::PrintInfo()
{
	std::cout << "Observer \"" << this->_number << "\": a new message is available --> " << this->_messageFromSubject << "\n";
}
