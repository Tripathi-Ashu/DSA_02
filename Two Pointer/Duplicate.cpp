#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode (int x){
        val = x;
        next = NULL;
    }
};

class Solution {
    public: 
    ListNode* deleteDuplicate(ListNode * head){
        if(head == NULL) return head;

        ListNode* current = head;

        while(current != NULL && current->next != NULL){
            if(current->val == current->next->val ){
                current->next = current->next->next ;
            }else {
                current = current->next;
            }
        }
        return head;
    }
};

// helper function to print list ;

void printList(ListNode* head){
    while(head != NULL){
        cout<< head->val <<" ";
        head = head->next;
    }
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next= new ListNode(3);

    Solution obj;
    head = obj.deleteDuplicate(head);

    cout << "Object: ";
    printList(head);

    return 0;
}
