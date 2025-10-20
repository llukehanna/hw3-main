#ifndef LLREC_H
#define LLREC_H

// 1) Define the Node struct
struct Node {
    int val;
    Node* next;
    Node(int v, Node* n) : val(v), next(n) {}
};

// 2) Declare llpivot
void llpivot(Node*& head, Node*& smaller, Node*& larger, int pivot);

// 3) Define the templated llfilter
template <typename Comp>
Node* llfilter(Node* head, Comp pred)
{
    if (!head) return nullptr;
    head->next = llfilter(head->next, pred);
    if (pred(head->val)) {
        Node* temp = head->next;
        delete head;
        return temp;
    }
    return head;
}

#endif
