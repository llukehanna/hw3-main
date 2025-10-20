//
// Test suite for HW3 Linked List Recursion
//

#include "llrec.h"
#include "llrec_test_utils.h"
#include <vector>
#include <random_generator.h>

//====================================
// TESTS FOR OTHER LLRECURSIVE PAST PROBLEMS
//  REPLACE WITH PIVOT AND FILTER TESTS
//====================================

// Predicates for filter
struct IsEven
{
    bool operator()(int num) {
        return (num % 2) == 0;
    }
};

struct IsOdd
{
    bool operator()(int num) {
        return (num % 2) != 0;
    }
};

bool IsNeg(int v)
{ return v < 0; }

struct IsLessEquals
{
	int num2;
	IsLessEquals(int val) : num2(val){}
    bool operator()(int num1) {
        return (num1 <= num2);
    }
};

struct IsGreater
{
	int num2;
	IsGreater(int val) : num2(val){}
    bool operator()(int num1) {
        return (num1 > num2);
    }
};

/********************************************
 *    Pivot Tests
 ********************************************/

TEST(Pivot, Empty)
{
	Node* list = nullptr;
	Node* small = (Node*) &list; // set to a non-null address
	Node* large = (Node*) &list; // set to a non-null address
	llpivot(list, small, large, 42);

	EXPECT_EQ(nullptr, list);
	EXPECT_EQ(nullptr, small);
	EXPECT_EQ(nullptr, large);

}

TEST(Pivot, Size1SmallEmpty)
{
	Node* list = makeList({2});
	Node* small = (Node*) &list; // set to a non-null address
	Node* large = (Node*) &list; // set to a non-null address
	llpivot(list, small, large, 1);

	EXPECT_TRUE(checkContent(small, {}));
	EXPECT_TRUE(checkContent(large, {2}));
	EXPECT_TRUE(checkContent(list, {}));

	deleteList(small);
	deleteList(large);
}

TEST(Pivot, Size1LargeEmpty)
{
	Node* list = makeList({2});
	Node* small = (Node*) &list; // set to a non-null address
	Node* large = (Node*) &list; // set to a non-null address
	llpivot(list, small, large, 3);

	EXPECT_TRUE(checkContent(small, {2}));
	EXPECT_TRUE(checkContent(large, {}));
	EXPECT_TRUE(checkContent(list, {}));

	deleteList(small);
	deleteList(large);
}

TEST(Pivot, Size2SmallLarge)
{
	Node* list = makeList({2,4});
	Node* small = (Node*) &list; // set to a non-null address
	Node* large = (Node*) &list; // set to a non-null address
	llpivot(list, small, large, 3);

	EXPECT_TRUE(checkContent(small, {2}));
	EXPECT_TRUE(checkContent(large, {4}));
	EXPECT_TRUE(checkContent(list, {}));

	deleteList(small);
	deleteList(large);
}

TEST(Pivot, Size2LargeSmall)
{
	Node* list = makeList({4,2});
	Node* small = (Node*) &list; // set to a non-null address
	Node* large = (Node*) &list; // set to a non-null address
	llpivot(list, small, large, 3);

	EXPECT_TRUE(checkContent(small, {2}));
	EXPECT_TRUE(checkContent(large, {4}));
	EXPECT_TRUE(checkContent(list, {}));

	deleteList(small);
	deleteList(large);
}

TEST(Pivot, Size3LargeSmallLarge)
{
	Node* list = makeList({4,2,6});
	Node* small = (Node*) &list; // set to a non-null address
	Node* large = (Node*) &list; // set to a non-null address
	llpivot(list, small, large, 3);

	EXPECT_TRUE(checkContent(small, {2}));
	EXPECT_TRUE(checkContent(large, {4,6}));
	EXPECT_TRUE(checkContent(list, {}));

	deleteList(small);
	deleteList(large);
}

TEST(Pivot, Size3SmallLargeSmall)
{
	Node* list = makeList({4,8,6});
	Node* small = (Node*) &list; // set to a non-null address
	Node* large = (Node*) &list; // set to a non-null address
	llpivot(list, small, large, 7);

	EXPECT_TRUE(checkContent(small, {4,6}));
	EXPECT_TRUE(checkContent(large, {8}));
	EXPECT_TRUE(checkContent(list, {}));

	deleteList(small);
	deleteList(large);
}

TEST(Pivot, Size3LargeLargeSmall)
{
	Node* list = makeList({4,6,2});
	Node* small = (Node*) &list; // set to a non-null address
	Node* large = (Node*) &list; // set to a non-null address
	llpivot(list, small, large, 3);

	EXPECT_TRUE(checkContent(small, {2}));
	EXPECT_TRUE(checkContent(large, {4,6}));
	EXPECT_TRUE(checkContent(list, {}));

	deleteList(small);
	deleteList(large);
}


TEST(Pivot, Size6SmallThenLarge)
{
	Node* list = makeList({2,3,4,6,7,8});
	Node* small = (Node*) &list; // set to a non-null address
	Node* large = (Node*) &list; // set to a non-null address
	llpivot(list, small, large, 5);

	EXPECT_TRUE(checkContent(small, {2,3,4}));
	EXPECT_TRUE(checkContent(large, {6,7,8}));
	EXPECT_TRUE(checkContent(list, {}));

	deleteList(small);
	deleteList(large);
}

TEST(Pivot, Size6LargeThenSmall)
{
	Node* list = makeList({6,7,8,2,3,4});
	Node* small = (Node*) &list; // set to a non-null address
	Node* large = (Node*) &list; // set to a non-null address
	llpivot(list, small, large, 5);

	EXPECT_TRUE(checkContent(small, {2,3,4}));
	EXPECT_TRUE(checkContent(large, {6,7,8}));
	EXPECT_TRUE(checkContent(list, {}));

	deleteList(small);
	deleteList(large);
}

TEST(Pivot, Nominal)
{
	Node* list = makeList({2, 4, 8, 3});
	Node* small = (Node*) &list; // set to a non-null address
	Node* large = (Node*) &list; // set to a non-null address

	llpivot(list, small, large, 5);

	EXPECT_TRUE(checkContent(small, {2, 4, 3}));
	EXPECT_TRUE(checkContent(large, {8}));
	EXPECT_TRUE(checkContent(list, {}));

	deleteList(small);
	deleteList(large);
}

TEST(Pivot, SameValues)
{
	Node* list = makeList({2, 2, 2, 2});
	Node* small = (Node*) &list; // set to a non-null address
	Node* large = (Node*) &list; // set to a non-null address

	llpivot(list, small, large, 2);

	EXPECT_TRUE(checkContent(small, {2, 2, 2, 2}));
	EXPECT_TRUE(checkContent(large, {}));
	EXPECT_TRUE(checkContent(list, {}));

	deleteList(small);
	deleteList(large);
}

TEST(Pivot, NoCopySameNodeCheck)
{
	Node* list = makeList({2, 3, 4, 6});
	Node* small = (Node*) &list; // set to a non-null address
	Node* large = (Node*) &list; // set to a non-null address

	Node* temp = list;
	std::vector<Node*> originalNodes;
	while(temp != nullptr){
		originalNodes.push_back(temp);
		temp = temp->next;
	}
	llpivot(list, small, large, 5);

	EXPECT_TRUE(checkContent(small, {2, 3, 4}));
	EXPECT_TRUE(checkContent(large, {6}));
	EXPECT_TRUE(checkContent(list, {}));

	size_t i = 0;
	Node* aftertemp = small;
	while(aftertemp != nullptr){
		EXPECT_EQ(aftertemp, originalNodes[i++]);
		aftertemp = aftertemp->next;
	}
	aftertemp = large;
	while(aftertemp != nullptr){
		EXPECT_EQ(aftertemp, originalNodes[i++]);
		aftertemp = aftertemp->next;
	}
	

	deleteList(small);
	deleteList(large);
}

/********************************************
 *    Filter Tests
 ********************************************/



TEST(Filter, EmptyList)
{
	Node* list = makeList({});
	EXPECT_TRUE(checkContent(list, {}));

	list = llfilter(list, IsNeg);
	EXPECT_TRUE(checkContent(list, {}));

	deleteList(list);
}

// nF = no Filter, F = filter
TEST(Filter, Size1_F)
{
	Node* list = makeList({3});
	EXPECT_TRUE(checkContent(list, {3}));

	list = llfilter(list, IsOdd());
	EXPECT_TRUE(checkContent(list, {}));

	deleteList(list);
}

// nF = no Filter, F = filter
TEST(Filter, Size1_nF)
{
	Node* list = makeList({2});
	EXPECT_TRUE(checkContent(list, {2}));

	list = llfilter(list, IsOdd());
	EXPECT_TRUE(checkContent(list, {2}));

	deleteList(list);
}

TEST(Filter, Size2_F_nF)
{
	Node* list = makeList({2,3});
	EXPECT_TRUE(checkContent(list, {2,3}));

	list = llfilter(list, IsEven());
	EXPECT_TRUE(checkContent(list, {3}));

	deleteList(list);
}

TEST(Filter, Size2_nF_F)
{
	Node* list = makeList({3,2});

	list = llfilter(list, IsEven());
	EXPECT_TRUE(checkContent(list, {3}));

	deleteList(list);
}

TEST(Filter, Size3_nF_F_nF)
{
	Node* list = makeList({3,4,5});

	list = llfilter(list, IsEven());
	EXPECT_TRUE(checkContent(list, {3,5}));

	deleteList(list);
}

TEST(Filter, Size3_F_nF_F)
{
	Node* list = makeList({3,4,5});

	list = llfilter(list, IsOdd());
	EXPECT_TRUE(checkContent(list, {4}));

	deleteList(list);
}

TEST(Filter, SameNodeCheck)
{
	Node* list = makeList({2, 4, 6, 3});
	EXPECT_TRUE(checkContent(list, {2, 4, 6, 3}));

	Node* temp = list;
	std::vector<Node*> originalNodes;
	while(temp != nullptr){
		originalNodes.push_back(temp);
		temp = temp->next;
	}

	list = llfilter(list, IsOdd());
	EXPECT_TRUE(checkContent(list, {2, 4, 6}));

	size_t i = 0;
	Node* aftertemp = list;
	while(aftertemp != nullptr){
		EXPECT_EQ(aftertemp, originalNodes[i++]);
		aftertemp = aftertemp->next;
	}

	deleteList(list);
}

TEST(Filter, MultipleCalls)
{
	Node* list = makeList({-2, 3, 4, -10, 6, 9, -15});

	list = llfilter(list, IsNeg);
	EXPECT_TRUE(checkContent(list, {3, 4, 6, 9}));

	list = llfilter(list, IsOdd());
	EXPECT_TRUE(checkContent(list, {4, 6}));

	deleteList(list);
}




TEST(Filter, CompareWithLlrec)
{
	Node* list = makeList({2, 4, 8, 3});
	Node* small = (Node*) &list; // set to a non-null address
	Node* large = (Node*) &list; // set to a non-null address

	llpivot(list, small, large, 5);

	EXPECT_TRUE(checkContent(small, {2, 4, 3}));
	EXPECT_TRUE(checkContent(large, {8}));
	EXPECT_TRUE(checkContent(list, {}));

	list = makeList({2, 4, 8, 3});
	EXPECT_TRUE(checkContent(list, {2, 4, 8, 3}));

	IsLessEquals islessequal(5);
	list = llfilter(list, islessequal);
	EXPECT_TRUE(checkContent(list, {8}));
	EXPECT_TRUE(compareLists(large, list));

	deleteList(list);

	IsGreater isgreater(5);
	list = makeList({2, 4, 8, 3});
	list = llfilter(list, isgreater);
	EXPECT_TRUE(checkContent(list, {2, 4, 3}));
	EXPECT_TRUE(compareLists(small, list));

	deleteList(small);
	deleteList(large);
	deleteList(list);
}
