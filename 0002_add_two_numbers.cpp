#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int val) : val(val), next(NULL) {}
  ListNode(int val, ListNode* next) : val(val), next(next) {}
};

class Solution {
  public:
    Solution() {}

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      ListNode dummy(0);
      ListNode* curr = &dummy;
      int carry = 0;
      while (l1 || l2) {
        int v1 = l1 ? l1->val : 0;
        int v2 = l2 ? l2->val : 0;
        int sum = v1 + v2 + carry;
        int val;
        if (sum > 9) {
          val = sum % 10;
          carry = 1;
        } else {
          val = sum;
          carry = 0;
        }
        curr->next = new ListNode(val);
        curr = curr->next;
        l1 = l1->next;
        l2 = l2->next;
      }
      
      if (carry)
        curr->next = new ListNode(1);

      return dummy.next;
    }

};

void printList(ListNode* curr) {
  while (curr) {
    cout << curr->val << ",";
    curr = curr->next;
  }
  cout << endl;
}

int main() {
  Solution sol;
  ListNode* l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
  ListNode* l2 = new ListNode(5, new ListNode(6, new ListNode(4)));

  cout << "List1" << endl;
  printList(l1);
  cout << "List2" << endl;
  printList(l2);
  
  ListNode* l3 = sol.addTwoNumbers(l1, l2);
  cout << "List3" << endl;
  printList(l3);

  return 0; 
}

