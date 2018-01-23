#include "core/util/UuidGenerator.h"

namespace util {

unsigned long long UuidGenerator::next = 0;

Uuid UuidGenerator::newUUID() {
  return next++;
}

} // namespace util
