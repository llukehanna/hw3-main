//
// Auto-checker for HW1 Teams
//

#ifndef CS104_HW3_TEST_SUITE_LLREC_TEST_UTILS_H
#define CS104_HW3_TEST_SUITE_LLREC_TEST_UTILS_H

#include <llrec.h>

#include <gtest/gtest.h>

#include <vector>
#include <limits>
#include <cstdlib>

// Utility functions for testing LLRecursive Pivot and Filter


// build a list from the given vector of content
Node * makeList(std::vector<int> const & content);

// check that a list has the given values, even if they're in a different order
// NOTE: runs in O(nlogn), is able to handle duplicate values properly
testing::AssertionResult checkContent(Node * list, std::vector<int> const & content);

//compare results returned drom llrec and llfilter for same condition
testing::AssertionResult compareLists(Node* list1, Node* list2);

// delete a list that was created by makeList()
void deleteList(Node * list);

// Returns a vector without Nodes
template <typename Comp>
std::vector<int> filterValues(const std::vector<int>& content, Comp c)
{
  std::vector<int> vec;
  for(auto v : content) {
      // If it doesn't meet the criteria, keep it by adding it to new vec
      if(!c(v)){
          vec.push_back(v);
      }
  }
  return vec;

}

template <typename Comp>
struct UnaryComp {
    int val_;
    Comp c_;
    UnaryComp(int v, Comp c) : val_(v), c_(c) {}
    bool operator()(int num) {
        return c_(num, val_);
    }
};



#endif //CS104_HW3_TEST_SUITE_LLREC_TEST_UTILS_H
