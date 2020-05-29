/**
 * Unit Test Isolation with Dummies, Fakes, Stubs, Spies and Mocks:
 *
 * Test doubles are:
 *   - Almost all code depends (i.e. collaborates) with other parts of the system
 *   - Those other parts of the system are not always easy to replicate in the unit
 *     test environment or would make tests slow if used directly
 *   - Test doubles are objects that are used in unit tests as replacements to the real
 *     production system collaborators
 *
 * Types of test doubles:
 *  1. Dummy - Objects that can be passed around as necessary but do not have any type
 *             of test implementation and should never be used
 *  2. Fake - These object generally have a simplified functional implementation of a
 *            particulat interface that is adequate for testing but not for production
 *  3. Stub - These objects provide implementations with canned answers that are suitable
 *            for the test
 *  4. Spies - These objects provide implementations that recored the values that were passed
 *             in so they can be used by the test
 *  5. Mocks - These objects are pre-programmed to expect specific calls and parameters
 *             and can throw exceptions when necessary
 */
#include <vector>

#include "gtest/gtest.h"

namespace {

class MyInterface {};
class DBInterface {};

/**
 * Dummy example
 * Dummy objects expect to never be used and will generally throw an exception if one
 * of their methods is actually called.
 */
class MyDummy : public MyInterface {
 public:
  void SomeFunction() { throw "I shouldn't be called!"; }
};

/**
 * Stub example
 * Stubs are different thatn dummy test doubles in that they do expect to be called
 * and return canned data.
 */
class MyStub : public MyInterface {
 public:
  int SomeFunction() { return 0; }
};

/**
 * Fake example
 * Fake objects provide what is usually a simplified implementation of an interface
 * that is functional but not appropriate for production (i.e. an in memory database)
 */
class MyTestDB : public DBInterface {
 public:
  void PushData(int data) { data_items.push_back(data); }

 protected:
  std::vector<int> data_items;
};

/**
 * Spy example
 * Spy objects save the parameters that were passed into them so they can be analyzed
 * by the test
 */
class MySpy : public DBInterface {
 public:
  void SomeFunction(int param) { saved_param = param; }

 protected:
  int saved_param;
};

/**
 * Mock example
 * Mock objects are the most interlligent test double. They are setup with expectations
 * on how they will be called and will throw exceptions when those expectations are not met.
 */
class MyMock : public DBInterface {
 public:
  void SomeFunction(int param) {
    if (param != 1) throw "I shouldn't be called!";
  }

 protected:
  int saved_param;
};

}  // namespace
