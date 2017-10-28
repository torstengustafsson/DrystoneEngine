#pragma once

#include <time.h>

/*
* A simple random number generator.
* Returns a new random value every time Random::next() is called.
*/

class Random {
public:
  static unsigned long int next();

private:
  static unsigned long int randIndex;
};