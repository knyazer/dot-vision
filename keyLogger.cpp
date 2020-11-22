#include "keyLogger.h"

void KeyLogger::addShortcut(char key, void (*action)(void))
{
	shortcuts.push_back(Shortcut(key, action));
}

void KeyLogger::update()
{
	char key = cv::waitKey(1);

	if (key > 0)
		for (auto p : shortcuts)
			if (p.key == key)
				p.action();
}
