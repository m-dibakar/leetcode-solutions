// 141. Linked List Cycle

#include<iostream>
using namespace std;

class ListNode{
    public:
        int val;
        ListNode* next;

        ListNode(int val) {
            this->val = val;
            next = nullptr;
        }
};

class List{
    public:
        ListNode* head; 
        ListNode* tail;
    
        List() {
            head = tail = nullptr;
        }

        void push_back(int val) {
            ListNode* newNode = new ListNode(val);

            if(head == nullptr) {
                head = tail = newNode;
            }else{
                tail->next = newNode;
                tail = newNode;
            }
        }
        void pop_back() {
            if(tail == nullptr) return;
            ListNode* temp = head;
            while(temp->next != tail) {
                temp = temp->next;
            }
            temp->next = nullptr;
            delete tail;
            tail = temp;
        }
        void print() {
            ListNode* temp = head;
            while (temp != nullptr)
            {
               cout<<temp->val<<"->";
               temp = temp->next;
            }
            cout<<"NULL"<<endl;
        }
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL) return false;
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast!= NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    List ll;
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    // ll.tail->next = ll.head;
    Solution s;
    cout<<s.hasCycle(ll.head)<<endl;
    return 0;
}