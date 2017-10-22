#include "core/inc/RandomGenerator.h"

unsigned long int Random::randIndex = 0;

unsigned long int Random::next() {
  randIndex = (randIndex * 500041 + time(NULL)) % 542081;
  return randIndex;
}
