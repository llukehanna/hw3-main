#include "llrec.h"

// Helper function that appends each node to the correct list
// without losing order.
namespace {
  void pivotHelper(
    Node* curr,
    int pivot,
    Node*& smallHead, Node*& smallTail,
    Node*& largeHead, Node*& largeTail
  )
  {
    if (!curr) return;

    Node* nxt = curr->next;
    curr->next = nullptr;

    if (curr->val <= pivot) {
      if (!smallHead) {
        smallHead = curr;
        smallTail = curr;
      } else {
        smallTail->next = curr;
        smallTail = curr;
      }
    } else {
      if (!largeHead) {
        largeHead = curr;
        largeTail = curr;
      } else {
        largeTail->next = curr;
        largeTail = curr;
      }
    }
    pivotHelper(nxt, pivot, smallHead, smallTail, largeHead, largeTail);
  }
}

void llpivot(Node*& head, Node*& smaller, Node*& larger, int pivot)
{
  smaller = nullptr;
  Node* smallTail = nullptr;
  larger = nullptr;
  Node* largeTail = nullptr;

  // Recur through the list and build smaller/larger
  pivotHelper(head, pivot, smaller, smallTail, larger, largeTail);

  // The original list is now split, so set head to nullptr
  head = nullptr;
}
