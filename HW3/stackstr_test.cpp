
#include "stackstr.h"

#include <iostream>

#include "gtest/gtest.h"



class StackStrTest : public testing::Test {

protected:

	// You can remove any or all of the following functions if its body is empty.



	StackStrTest() {

		// You can do set-up work for each test here.

	}



	virtual ~StackStrTest() {

		// You can do clean-up work that doesn't throw exceptions here.		

	}



	// If the constructor and destructor are not enough for setting up

	// and cleaning up each test, you can define the following methods:

	virtual void SetUp() {

		// Code here will be called immediately after the constructor (right

		// before each test).

	}



	virtual void TearDown() {



		// Code here will be called immediately after each test (right

		// before the destructor).

	}



	// Objects declared here can be used by all tests in the test case.

    StackStr stack;

};



TEST_F(StackStrTest, empty)

{

    EXPECT_TRUE(stack.empty());

    stack.push("one");

    EXPECT_FALSE(stack.empty());

}



TEST_F(StackStrTest, push)

{

    stack.push("one");

    stack.push("hi");

    EXPECT_EQ("hi",stack.top());

    EXPECT_EQ(2, stack.size());

    

    stack.push("bye");

    EXPECT_EQ("bye", stack.top());

    EXPECT_NE(2, stack.size());

}






TEST_F(StackStrTest, top)

{

    EXPECT_TRUE(stack.empty());

    stack.push("one");

    stack.push("hi");

    EXPECT_EQ("hi", stack.top());

    
    EXPECT_EQ(2, stack.size());

    stack.push("bye");

     EXPECT_NE("hi", stack.top());
    
  

}



TEST_F(StackStrTest, pop)

{

    stack.push("one");

    stack.push("hi");

    stack.push("bye");



    EXPECT_EQ(3, stack.size());

    EXPECT_EQ("bye", stack.top());

    stack.pop();

    EXPECT_EQ(2, stack.size());

    EXPECT_EQ("hi", stack.top());

    stack.pop();

    EXPECT_EQ(1, stack.size());

    EXPECT_EQ("one", stack.top());

    stack.pop();

    EXPECT_TRUE(stack.empty());

    EXPECT_EQ(0, stack.size());

}


