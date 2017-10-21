em++ -std=c++11 -O2 -Wall -I..\..\include ^
..\include\main_js.cpp ^
-s USE_SDL=2 -s USE_SDL_IMAGE=2 -s SDL2_IMAGE_FORMATS="[""png""]" -s USE_SDL_TTF=2 ^
--preload-file ..\assets ^
-o index.html
