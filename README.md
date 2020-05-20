# TDD with GoogleTest

_Examples of gootest usage for Test Driven Development_


## **MOTIVATION:**

It is necessary to have a multilayered safety net of test in place that will catch any bugs that might get introduced.
The first layer of that net should be a suite of automated unit tests.


## **Unit tests**:
* Verify the code at a level of functions and classes
* perform negative and positive test cases at the lowest level of the code
* Every line of production code should have an associated unit test to verify it's working as expected

### **Why Unit Test?**
* Software bugs hurt businesses
* Software testing catches the bugs before they get to the field
* Need several levels of safety nets
* Serves also the purpose of documenting what the code is actually doing
* Drives good object oriented design

### **Levels of Testing**:
1. Unit testing:
    * Testing at the function level
    * This is generally the lowest level of testing and most comprehensive
    * A test should be writeen for each test case for a function (all positive and negative test cases)
    * Group of tests can be combined into test suites for better organization
    * Executes in the development environment rather than the production environment
    * Execution of the tests should be automated
    * They should be ran often so they should be fast
2. Component Testing:
    * Testing at the library and compiled binary level
    * This tests extrenal interfaces of these components
3. System Testing (Integration tests):
    * Tests the external interfaces of a system which is a collection of sub-systems
4. Performance Testing:
    * Testing done at sub-system and system levels to verify timing and resource usages are acceptable

## **Test Driven Development (TDD)**:
* Is a practice of writing unit tests before writing production code
* This has the benefit of knowing that each of the new lines of code are working as soon as they're written
* It's easier to track down problems as only a small amount of code has been implemented since the execution of the last test
* It gives more confidence in changing the code as the feedback loop is very short
* All test cases shouldn't be implemented at once but rather gradually as the code evolves
* _TDD has been created by Kent Beck in the 1990's as part of the Extreme Programming software development process_

### **RED -> GREEN -> REFACTOR workflow phases**:
1. Writing a failing Unit test (RED phase)
2. Writing just enough production code to make that test pass (GREEN phase)
3. Recatoring the unit test and the produciton code to make it clean (REFACTOR phase)

### **Uncle Bob's (Robert Martin) 3 laws of TDD**:
1. Thou shall not write any production code unit you ahve written a failing unit test
2. Thou shall not write more of a unit test than is sufficient to fail, and not compiling is failing
3. Thou shall not write more production code than is sufficient to pass the currently failing unit test

## _Bibliography:_
* **Kent Beck** - _Test Driven Development: By example_
* **Robert Marting** - _Clean Code: A handbook of Agile Software Craftsmanship_

### Command example:
bazel run //tdd_examples:fizzbuzz_test