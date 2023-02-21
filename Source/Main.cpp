#include <iostream>
#include "Engine.h"

using namespace std;

int main()
{
	Engine engine = Engine(1920, 1080, false, 60);
	engine.main_loop();
	return 0;
}