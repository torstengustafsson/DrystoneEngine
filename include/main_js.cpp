#include <emscripten.h>

void main_loop() {

}

int main(){

	emscripten_set_main_loop(main_loop, 60, 1);
	
	return 0;
}
