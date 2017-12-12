#include "linalg/Mat3.h"
#include "linalg/Vec3.h"
#include "linalg/Quaternion.h"
#include "core/inc/Log.h"

#define str std::to_string

namespace linalg {

Mat3::Mat3()
  : m{ 1, 0, 0,
       0, 1, 0,
       0, 0, 1 } {
}

Mat3::Mat3(float f1, float f2, float f3,
           float f4, float f5, float f6,
           float f7, float f8, float f9)
  : m{ f1, f2, f3,
       f4, f5, f6,
       f7, f8, f9 } {
}

Mat3::Mat3(float f)
  : m{ f, f, f,
       f, f, f,
       f, f, f } {
}

void Mat3::print() const {
  std::string output = "{ " + str(m[0]) + ", " + str(m[1]) + ", " + str(m[2])  + ", "  + ",\n" +
                       "  " + str(m[3]) + ", " + str(m[4]) + ", " + str(m[5])  + ", "  + ",\n" +
                       "  " + str(m[6]) + ", " + str(m[7]) + ", " + str(m[8]) + ", " + " }\n";
  log(output);
}

} // namespace linalg
