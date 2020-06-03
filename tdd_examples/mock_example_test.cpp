/**
 * Google Test Mock:
 *  - provides an easy way for automatically creating any double types at runtime
 *  - provides a fast means for creating mocking expectations for your tests
 *  - it is much more efficient than implementing custom mock object of your own creation
 *  - not using it and creating mock objects from scratch is tedious and error-prone
 *
 * Google Mock Workflow:
 *  1. Creates Mock Classes derived from the interface classes that the mock is replacing
 *  2. In the Mock Class the MOCK_METHODn Google Mock macro to specify what methods will be mocked
 *  3. Create an instance of your mock class in your test
 *  4. Then specify the expectations for the test
 *
 * Google Mock Expectations:
 *  - Expectations are defined in the test using the EXPECT_CALL macro
 *  - EXPECT_CALL is passing in the mock object and function the expectation is being set for
 *    Example: EXPECT_CALL(MyMockObj, Get());
 *
 * Specifying Parameters with Matchers:
 *  - For functions that are passed parameters Google Mock needs to know what values are expected
 *  - This is done with Matchers. Matchers allow you to specify that a parameter is any value,
 *    equal to a specific value, or typical mathematical relationships such as greater than, less than etc.
 *    Examples:
 *     & EXPECT_CALL(MyMockObj, SetData(_));
 *     & EXPECT_CALL(MyMockObj, SetData(100));
 *     & EXPECT_CALL(MyMockObj, SetData( Ge(100) ));  // parameter passed to SetData must be greater than 100
 *     & EXPECT_CALL(MyMockObj, SetData( NotNull(my_obj) ));
 *
 * Specifying how many times it will be called:
 *  - This can be achieved using the "Times" clause
 *  - It can be exact of a built-in expression such as "AtLeast" or "AtMost"
 *    Example: EXPECT_CALL(MyMockObj, GetData()).Times(2);
 *
 * Actions - telling Google Mock what should happen:
 *  - Actions are specified after the "Times" clause and are things like return values and throwing exceptions
 *  - WillOnce - specifies an action that will be done on one call to the function
 *  - WillRepeatedly - specifies an action that is done on many calls to the function
 *    Examples:
 *     & EXPECT_CALL(MyMockObj, GetData()).WillOnce(Return(1));
 *     & EXPECT_CALL(MyMockObj, GetData()).WillRepeatedly(Return(1));
 *     & EXPECT_CALL(MyMockObj, GetData()).WillOnce(Return(1))
 *                                        .WillOnce(Return(2))
 *                                        .WillOnce(Return(3));
 *     & EXPECT_CALL(MyMockObj, GetData()).Times(4)
 *                                        .WillRepeatedly(Return(1))
 */
#include <iostream>
#include <memory>

#include "gmock/gmock.h"  // important to include gmock as well as gtest
#include "gtest/gtest.h"

class QeueInterface {
 public:
  virtual ~QeueInterface() {}
  virtual void enqeue(int data) = 0;
  virtual int deqeue() = 0;
};

class DataHolder {
 public:
  DataHolder(std::unique_ptr<QeueInterface> qeue) : qeue(std::move(qeue)) {}
  void AddData(int data) { qeue->enqeue(data); }
  int GetData() { return qeue->deqeue(); }

 protected:
  std::unique_ptr<QeueInterface> qeue;
};

namespace {

class MockQeue : public QeueInterface {
 public:
  // MOCK_METHODn : The n number stands for the amount of arguments passed
  MOCK_METHOD0(deqeue, int());
  MOCK_METHOD1(enqeue, void(int data));
};

TEST(GMockTests, CanInstantiateDataHolder) {
  std::unique_ptr<MockQeue> MyMockObj(new MockQeue);
  DataHolder dh(std::move(MyMockObj));
}

TEST(GMockTests, CanAddData) {
  std::unique_ptr<MockQeue> MyMockObj(new MockQeue);

  /**
   * Data holder uses a raw pointer but we still need access to the MyMockObj!
   * So prior to moving it to the DataHolder let's make a raw pointer to the MockQeue
   */
  MockQeue* rawMockQeue = MyMockObj.get();

  DataHolder dh(std::move(MyMockObj));

  EXPECT_CALL(*rawMockQeue, enqeue(::testing::_));
  dh.AddData(1);
}

TEST(GMockTests, CanAddAndGetData) {
  std::unique_ptr<MockQeue> MyMockObj(new MockQeue);
  MockQeue* rawMockQeue = MyMockObj.get();

  DataHolder dh(std::move(MyMockObj));

  EXPECT_CALL(*rawMockQeue, enqeue(1));
  EXPECT_CALL(*rawMockQeue, deqeue()).WillOnce(::testing::Return(1));

  dh.AddData(1);
  int data = dh.GetData();
  ASSERT_EQ(data, 1);
}

}  // namespace
