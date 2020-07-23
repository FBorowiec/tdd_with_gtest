# TDD with GoogleTest

_Examples of googletest usage for Test Driven Development_

## **Motivation**

It is necessary to have a multilayered safety net of test in place that will catch any bugs that might get introduced.
The first layer of that net should be a suite of automated unit tests.

_"Making large changes without tests is like doing aerial gymnastics without a net."_ - **Michael Feathers**, unit tester and author of Working Effectively with Legacy Code

## **Unit tests**

* Verify the code at a level of functions and classes
* Perform negative and positive test cases at the lowest level of the code
* Every line of production code should have an associated unit test to verify it's working as expected

### **Why Unit Test?**

* Software bugs hurt businesses
* Software testing catches the bugs before they get to the field
* Need several levels of safety nets
* Serves also the purpose of documenting what the code is actually doing
* Drives good object oriented design

### **Levels of Testing**

1. Unit testing:
    * Testing at the function level
    * This is generally the lowest level of testing and most comprehensive
    * A test should be written for each test case for a function (all positive and negative test cases)
    * Group of tests can be combined into test suites for better organization
    * Executes in the development environment rather than the production environment
    * Execution of the tests should be automated
    * They should be ran often so they should be fast
2. Component Testing:
    * Testing at the library and compiled binary level
    * This tests external interfaces of these components
3. System Testing (Integration tests):
    * Tests the external interfaces of a system which is a collection of sub-systems
4. Performance Testing:
    * Testing done at sub-system and system levels to verify timing and resource usages are acceptable

## **Test Driven Development (TDD)**

* Is a practice of writing unit tests before writing production code
* This has the benefit of knowing that each of the new lines of code are working as soon as they're written
* It's easier to track down problems as only a small amount of code has been implemented since the execution of the last test
* It gives more confidence in changing the code as the feedback loop is very short
* All test cases shouldn't be implemented at once but rather gradually as the code evolves
* _TDD has been created by Kent Beck in the 1990's as part of the Extreme Programming software development process_

### **RED -> GREEN -> REFACTOR workflow phases**

1. Writing a failing Unit test (RED phase)
2. Writing just enough production code to make that test pass (GREEN phase)
3. Refactoring the unit test and the production code to make it clean (REFACTOR phase)

### **Uncle Bob's (Robert Martin) 3 laws of TDD**

1. Thou shall not write any production code unit you ahve written a failing unit test
2. Thou shall not write more of a unit test than is sufficient to fail, and not compiling is failing
3. Thou shall not write more production code than is sufficient to pass the currently failing unit test

## **What is Google Test?**

* It is an open-source C++ unit testing framework from Google
* Provides the ability to create Tests, Test Cases and Test Suites (Fixtures)
* Provides several types of assert macros for generating unit test failures based on boolean, binary and string comparisons

## **Command line arguments**

Many command line options available for controlling how tests are run:

* <code>--gtest_filter</code> : Regular expressions which indicate which tests should be run in the format of: TestCaseRegEx:TestRegEx
* <code>--gtest_repeat</code> : Repeats running the tests the specified number of times. Can be very helpful for ensuring you don't have any flaky tests.
* <code>--gtest_shuffle</code> : Runs the tests in a randomized order. Helps ensure no dependencies between the tests (as it shouldn't matter what order the tests are executed in)

_Example:_

<code>bazel run //path/to/unit:test -- --gtest_shuffle</code>

## **Best practices**

* Write the next simplest test case
* Do not jump into the complex test cases too quickly
* Use descriptive test names
* Test suites should name the class or function under test and the test names should describe the functionality being tested
* Keep tests fast
* Keep console output to a minimum to avoid cluttering
* Mock out any slow collaborators with test doubles that are fast
* Use code coverage tools
* Run tests multiple time and in random order

## _Bibliography_

* **Kent Beck** - _Test Driven Development: By example_
* **Robert Martin** - _Clean Code: A handbook of Agile Software Craftsmanship_
