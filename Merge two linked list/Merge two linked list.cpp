#include<iostream>
using namespace std;
class ListNode {
public:
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy, * temp;
        dummy = new ListNode();
        temp = dummy;

        //when both list1 and list2 isn't empty
        while (list1 && list2) {
            if (list1->val < list2->val) {
                temp->next = list1;
                list1 = list1->next;
            }
            else {
                temp->next = list2;
                list2 = list2->next;
            }
            temp = temp->next;
        }

        // we reached at the end of one of the list
        if (list1) temp->next = list1;
        if (list2) temp->next = list2;

        return dummy->next;
    }
    void printList(ListNode *head) {
        if (head == NULL) cout << "list is empty";
        while (head) {
            cout << head->val << " ";
            head = head->next;
        }
    }
};

int main() {
    ListNode* list1=NULL;
    ListNode* list2=NULL;
    list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(3);
    list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);
    ListNode L;
    L.printList(L.mergeTwoLists(list1, list2));

}
