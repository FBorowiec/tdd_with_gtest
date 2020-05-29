/**
 * Test fixtures:
 *   - Allows for common setup and teardown between tests
 *   - Test Fixtures are classes derived from ::testing::Test
 *   - Each test fixture  can implement virtual SetUp and TearDown functions,
 *     which will be called between each test
 *   - Tests that are using a test fixture use teh TEST_F macro rather than TEST
 *     and pass in the test fixture class name and the test name
 *     (i.e. TEST_F(TestFixtureClassName, TestName))
 *
 * Constructor/Destructor vs SetUp/TearDown:
 *   - Can use test fixtures constructor/destructor instead fo SetUp/TearDown
 *     since new instance is created for each test
 *   - Constructor/Destructor is preferable as it allows for const member variables
 *     and automatic calls to base class constructors
 *   - SetUp/TearDown functions may still be necessary if you may throw and exception
 *     during cleanup as this leads to undefined behavior in destructors
 */
#include <string>

#include "gtest/gtest.h"

namespace {

class TestFixtureExample : public ::testing::Test {
 public:
  TestFixtureExample() {}
  void SetUp() override {}
  void TearDown() override {}
};

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

// Test names must be unique
TEST_F(TestFixtureExample, BasicComparisonAsserts) {
  ASSERT_TRUE(1 == 1);   // Passes!
  ASSERT_FALSE(1 == 2);  // Passes!
  EXPECT_TRUE(1 == 2);   // FAILS - won't stop the test
  EXPECT_FALSE(1 == 1);  // FAILS!
}

TEST_F(TestFixtureExample, BinaryComparisonAsserts) {
  ASSERT_EQ(1, 1);  // Passes!
  ASSERT_NE(1, 2);  // Passes!
  ASSERT_LT(1, 2);  // Passes!
  ASSERT_LE(1, 1);  // Passes!
  ASSERT_GT(2, 1);  // Passes!
  ASSERT_GE(2, 2);  // Passes!
}

TEST_F(TestFixtureExample, StringComparisonAsserts) {
  ASSERT_EQ(std::string("1"), std::string("1"));  // Passes!
  ASSERT_NE(std::string("a"), std::string("b"));  // Passes!
  ASSERT_STREQ("a", "a");                         // Passes!
  ASSERT_STRNE("a", "b");                         // Passes!
  ASSERT_STRCASEEQ("A", "a");                     // Passes!
  ASSERT_STRCASENE("A", "b");                     // Passes!
}

TEST_F(TestFixtureExample, FloatingPointValuesComparisonAsserts) {
  ASSERT_FLOAT_EQ(1.0001f, 1.0001f);   // Passes!
  ASSERT_DOUBLE_EQ(1.0001f, 1.0001f);  // Passes!
  ASSERT_NEAR(1.0001, 1.0001, .0001);  // Passes!
  EXPECT_NEAR(1.0001, 1.0003, .0001);  // FAILS!
}

}  // namespace
