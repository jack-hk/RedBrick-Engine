#pragma once
#include <vector>
#include <memory>

#include "Game.h"
#include "GameObject.h"
#include "Graphics.h"
#include "Input.h"
#include "Collision.h"

#include "BoxCollider.h"

class Scene;
class Level;
class Menu;
class Game // Deals with gameloop and common game functions.
{
public:
	static inline Graphics _graphics;
	static inline bool _isRunning;
	static inline bool _isDebugMode = true;
	static inline std::vector<Scene*> _scenes; //shared_ptr or unique_ptr
	static inline Scene* _currentScene;

	static void LoadLevel(Scene* levelToBeLoaded);
	static void UpdateLevels();

	static void Init();
	static void Run();
	static void Quit();
};