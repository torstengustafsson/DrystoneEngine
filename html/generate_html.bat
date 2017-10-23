em++ -std=c++11 -O2 -Wall -I..\include ^
-s USE_SDL=2 -s USE_SDL_IMAGE=2 -s SDL2_IMAGE_FORMATS="[""png""]" -s USE_SDL_TTF=2 ^
..\include\main_js.cpp ^
..\include\core\src\Game.cpp ^
..\include\core\src\GameController.cpp ^
..\include\core\src\GameEngine.cpp ^
..\include\core\src\GameRenderer.cpp ^
..\include\core\src\RandomGenerator.cpp ^
..\include\datastructures\src\Vector.cpp ^
..\include\input\src\InputHandler.cpp ^
..\include\input\src\InputCommands.cpp ^
..\include\world\src\Camera.cpp ^
..\include\world\src\GameObject.cpp ^
..\include\world\src\Player.cpp ^
--preload-file ..\assets ^
-o index.html
