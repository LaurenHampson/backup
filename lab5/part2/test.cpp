#include "arraylist.h"
#include "gtest/gtest.h"

class ArrayListTest : public testing::Test {
protected:
	// You can remove any or all of the following functions if its body is empty.

	ArrayListTest() {
		// You can do set-up work for each test here.
	}

	virtual ~ArrayListTest() {
		// You can do clean-up work that doesn't throw exceptions here.		
	}

	// If the constructor and destructor are not enough for setting up
	// and cleaning up each test, you can define the following methods:
	virtual void SetUp() {
		// Code here will be called immediately after the constructor (right
		// before each test).
		list.add(1);
		list.add(2);
		list.add(3);
	}

	virtual void TearDown() {
		// Code here will be called immediately after each test (right
		// before the destructor).
	}

	// Objects declared here can be used by all tests in the test case.
	ArrayList list;
};

TEST_F(ArrayListTest, GetNominal) {
	// Exepct 0th element to be 1, 1st elemnt to be 2, etc.
	EXPECT_EQ(3, list.size());

	for (int i = 0 ; i < 3; i++) {
		EXPECT_EQ(i + 1, list.get(i));
	}

	EXPECT_EQ(0, list.get(-1));
}

TEST_F(ArrayListTest, AddNominal) {
	// ...
	int size = list.size();
	list.add(4);
	EXPECT_EQ (size+1, list.size());
	list.add(5);
	EXPECT_EQ (size+2, list.size());
		EXPECT_EQ(1, list.get(0));
	list.add(6);
	EXPECT_EQ(size+ 3, list.size());

	list.insert(2, 4);
	EXPECT_EQ(1, list.get(0));

	//insert will insert at an invalid position

	
}

TEST_F(ArrayListTest, RemoveNominal) {
	int size = list.size();
	list.remove(2);
	EXPECT_NE(size, list.size());

	// Does not change the siize of the array list when removed

	// ...
}


TEST_F(ArrayListTest, SetOffNominal) {
	// ...
}
