#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include"doctest.h"
#include"math.hpp"

TEST_CASE("Test the multiplication function")
{
  CHECK(square(0) == 0);
  CHECK(square(1) == 1);
  CHECK(square(2) == 4);
  CHECK(square(3) == 9);
  CHECK(square(4) == 16);
  CHECK(square(10) == 100);
  CHECK_FALSE(square(9) == 18);
}


