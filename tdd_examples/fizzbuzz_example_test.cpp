/**
 * Write a function that receives and prints a passed in number.
 * For multiples of 3 print "Fizz".
 * For mulitples of 5 print "Buzz"
 * For multiples of both 3 and 5 print "FizzBuzz"
 */
#include <string>

namespace fizzbuzz {

bool IsMultiple(const int value, const int base) { return (value % base == 0); }

std::string FizzBuzz(int value) {
  if (IsMultiple(value, 3) && IsMultiple(value, 5)) return "FizzBuzz";
  if (IsMultiple(value, 3)) return "Fizz";
  if (IsMultiple(value, 5)) return "Buzz";
  return std::to_string(value);
}

}  // namespace fizzbuzz

// TEST---------------------------------------------------------------------------------------------------------------|

#include "gtest/gtest.h"  // Contains both gmock and gtest

// Unnamed namespace limits access of class,variable,function and objects to the file in which it is defined.
namespace {

using namespace fizzbuzz;

// Test utility function
void IsFizzBuzz(int value, std::string expected_result) {
  std::string result = FizzBuzz(value);
  ASSERT_STREQ(expected_result.c_str(), result.c_str());
}

/**
 * No need for main function as it is included in gtest.
 * The TEST macro defines an individual test for a particular test case.
 * Tests from the same test  cases will be grouped together in the execution output.
 * Test case and test names should be valid C++ identifiers and should not use the wildcard "_"
 */
TEST(FizzBuzzTest, Given1_ThenPrint1) { IsFizzBuzz(1, "1"); }

TEST(FizzBuzzTest, Given2_ThenPrint2) { IsFizzBuzz(2, "2"); }

TEST(FizzBuzzTest, Given3_ThenPrintFizz) { IsFizzBuzz(3, "Fizz"); }

TEST(FizzBuzzTest, Given5_ThenPrintBuzz) { IsFizzBuzz(5, "Buzz"); }

TEST(FizzBuzzTest, Given6_ThenPrintBuzz) { IsFizzBuzz(6, "Fizz"); }

TEST(FizzBuzzTest, Given10_ThenPrintBuzz) { IsFizzBuzz(10, "Buzz"); }

TEST(FizzBuzzTest, Given15_ThenPrintFizzBuzz) { IsFizzBuzz(15, "FizzBuzz"); }

}  // namespace
