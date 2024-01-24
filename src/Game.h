#pragma once
#include <vector>

#include "Graphics.h"

class Scene;
class Game // Deals with gameloop and common game functions.
{
public:
	static inline Graphics _graphics;
	static inline bool _isRunning;
	static inline bool _isDebugMode = true;
	static inline std::vector<Scene*> _scenes;
	static inline Scene* _currentScene;

	static void Init();
	static void Quit();

	static void UpdateLevels();
};