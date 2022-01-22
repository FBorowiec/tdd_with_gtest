/**
 * Fails when a specific exception is not thrown,
 * when any exception is not thrown of when an
 * exception is thrown and non was expected.
 */
#include <stdlib.h>
#include <bitset>
#include <iostream>
#include <stdexcept>
#include <string>

#include "gtest/gtest.h"

namespace {

/**
 * Google Test Asserts perform checks that determine if a test passes of fails.
 * Two typpes:
 *  - ASSERT_* macros which abort the current test if they fail.
 *  - EXPECT_* macros which indicate a failure but do not abort the current test.
 * EXPECT_* macros should be used if possible.
 *
 * Four comparison types:
 *  - Basic - Verifies that a passed boolean expression evaluates to true or false.
 *  - Binary - Compares binary values to see if they are equal, not equal,
 *             less than, less than or equal, greater than, or greater than or equal.
 *  - String - Compares two C styles strings to see if they are equal, not equal,
 *             equal ignoring case, or not equal ignoring case
 *  - Floats/Doubles - Compares two floats or doubles to see if they are "close" to equal.
 *                     Also provides an assert for specifying the max allowed difference
 *                     between the floats
 */

void CallIt() {
  try {
    // bitset constructor throws an invalid_argument if initialized
    // with a string containing characters other than 0 and 1
    std::bitset<5> mybitset(std::string("01234"));
  } catch (const std::invalid_argument& ia) {
    throw ia;
  }
}

TEST(ExceptionsTest, ExceptionAsserts) {
  ASSERT_THROW(CallIt(), std::invalid_argument);  // Passes!
  ASSERT_ANY_THROW(CallIt());                     // Passes!
  EXPECT_NO_THROW(CallIt());                      // FAILS!
}

}  // namespace
