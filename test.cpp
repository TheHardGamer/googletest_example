#include <gtest/gtest.h>
#include "LibCode.hpp"
#include <iostream>

using namespace std;

/*ASSERT_EQ, ASSERT_NE[not equal], ASSERT_LT[<], ASSERT_LE[<=]
ASSERT_GT,GE[>,>=],
ASSERT_STREQ(x,y)[Compare strings]*/

//TEST($testsuitename, name of the individual test)
//testsuitename = collection of related tests
TEST(TestSuiteSample, MyTest)
{
	int summ = sum(1,2);
	/*ASSERT_EQ is fatal assertion
	EXPECT_EQ can be used as non-fatal assertion instead */
	ASSERT_EQ(3, summ);
}

TEST(TestPositiveTest, PositveTest)
{
	//Arrange
	vector<int> inputVector{1,2,-3,-4,-5,6,-7,8};
	
	//Act
	int count = countPositive(inputVector);
	
	//Assert
	ASSERT_EQ(4, count);
}

TEST(TestUpperTest, UpperTestC)
{
	char inputStr[] = "hello";
	toUpperC(inputStr);
	/*ASSERT_STREQ for C-Strings*/
	ASSERT_STREQ("HELLO", inputStr);
}

TEST(TestUpperTest, UpperTestCpp)
{
	string inputStr = "hello";
	string output = toUpperCpp(inputStr);
	/*ASSERT_EQ for Cpp-Strings*/
	ASSERT_EQ("HELLO", output);
}

int main()
{
	testing::InitGoogleTest();
	return RUN_ALL_TESTS();
}
