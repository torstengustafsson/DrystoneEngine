#pragma once

/*
* Deleter for SDL windows, renderers and textures.
* To be used as deleters for c++ smart pointers.
*/

struct sdl_deleter {
  void operator()(SDL_Window *p) const { SDL_DestroyWindow(p); }
  void operator()(SDL_Renderer *p) const { SDL_DestroyRenderer(p); }
  void operator()(SDL_Texture *p) const { SDL_DestroyTexture(p); }
};
