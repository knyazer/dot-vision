#ifndef __KEY_LOGGER_DOT__
#define __KEY_LOGGER_DOT__

#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <vector>

struct Shortcut
{
public:
	Shortcut(char key, void (*action)(void))
	{
		this->key = key;
		this->action = action;
	}
	char key;
	void (*action)(void);
};

class KeyLogger
{
public:

	void addShortcut(char key, void (*action)(void));
	void update();

private:
	std::vector<Shortcut> shortcuts;
};


#endif
