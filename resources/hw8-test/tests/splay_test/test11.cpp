#include "splay_gtest_header.h"

TEST_F(SplayTest, Test11_FindZigZig)
{
	using Key = int;
	using Value = double;
	InsSeq<Key, Value> ins{
		std::make_pair(2, 2.0),
		std::make_pair(1, 1.0),
		std::make_pair(3, 3.0),
	};
	std::pair<Key, Value> exp(1, 1.0);

	NodeSeq<Key, Value> seq{
		NodeValidation<Key, Value>{1, 1.0, false, true},
		NodeValidation<Key, Value>{2, 2.0, false, true},
		NodeValidation<Key, Value>{3, 3.0, false, false},
	};

	InheritedSplay<Key, Value> bst;
	InsertInTree(bst, ins);
	CheckFind(bst, exp.first, &exp.second);
	TreeStructureCheck(bst.getRoot(), seq);
}