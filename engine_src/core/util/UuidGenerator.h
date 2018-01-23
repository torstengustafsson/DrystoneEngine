#pragma once

/*
* A simple Universally Unique Identifier generator. 
* (Or Globally Unique Identifier (GUID), which means the same thing)
* Generates a new unique value each time newUUID() is called.
*/

namespace util {

  typedef unsigned long long Uuid;

struct UuidGenerator {
  static Uuid newUUID();
  static Uuid next;
};

} // namespace util
