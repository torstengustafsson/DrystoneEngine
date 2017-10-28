#include <emscripten.h>
#include "core/inc/Game.h"

Game theGame;

void main_loop() {
    theGame.frame();
}

int main(){

	emscripten_set_main_loop(main_loop, 60, 1);
	
	return 0;
}
