
#include "llrec_test_utils.h"

#include <iostream>
#include <algorithm>


Node * makeList(std::vector<int> const & content)
{
	Node * head = nullptr;
	Node * tail = nullptr;

	for(auto v : content)
	{
		if(head == nullptr) {
			head = new Node(v,nullptr);
			tail = head;
		}
		else {
			tail->next = new Node(v,nullptr);
			tail = tail->next;
		}

	}
	return head;
}


testing::AssertionResult checkContent(Node* list, std::vector<int> const & content)
{
	size_t cnt = 0;
	Node* temp = list;
	while(temp != nullptr) {
		cnt++;
		temp = temp->next;
	}
  
  	if(cnt != content.size()){
    	return testing::AssertionFailure() << "Expected list of size " << content.size() << " but actual list size is " << cnt;
  	}
	for(size_t ei = 0; ei != content.size(); ei++, list=list->next ) {
    	if(content[ei] != list->val){
      		return testing::AssertionFailure() << "Data mismatch: expected " << content[ei] << " / actual " << list->val;
    	}
  	}
  	return testing::AssertionSuccess();
}

testing::AssertionResult compareLists(Node* list1, Node* list2)
{
	size_t cnt1 = 0;
	Node* temp1 = list1;
	while(temp1 != nullptr) {
		cnt1++;
		temp1 = temp1->next;
	}

	size_t cnt2 = 0;
	Node* temp2 = list2;
	while(temp2 != nullptr) {
		cnt2++;
		temp2 = temp2->next;
	}
  
  	if(cnt1 != cnt2){
    	return testing::AssertionFailure() << "llrec and llfilter returned different sized lists";
  	}
	while(list1 != nullptr) {
    	if(list1->val != list2->val){
      		return testing::AssertionFailure() << "Data mismatch: " << list1->val << " / actual " << list2->val;
    	}
		list1 = list1->next;
		list2 = list2->next;
  	}
  	return testing::AssertionSuccess();
}


void deleteList(Node * list)
{
	Node * currElement = list;

	while(currElement != nullptr)
	{
		Node * nextElement = currElement->next;
		delete currElement;
		currElement = nextElement;
	}
}
