//计算一个数的二进制里有多少位1
int main(int x){
  int countx = 0;
  while(x){
    count++;
    x = x&(x-1);
  }
  return countx;
}
//计算一个数的二进制里有多少位0
int main(int x){
  int countx = 0;
  for(int i = 0; i < 32; i++){
    countx+=x%2==0?1:0;
    x = x >> 1;
  }
  return countx;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//递归合并两个升序链表
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        //recursive method:
        if(!l1) return l2;
        if(!l2) return l1;
        ListNode* finalNode = nullptr;
        if(l1->val <= l2->val){
            finalNode = l1;
            finalNode->next = mergeTwoLists(l1->next, l2);
        }else{
            finalNode = l2;
            finalNode->next = mergeTwoLists(l1, l2->next);
        }
        return finalNode;
}
//不使用递归
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if(!l1) return l2;
    if(!l2) return l1;
    ListNode *finalNode = nullptr, *cur = nullptr;
    if(l1->val <= l2->val){
        finalNode = l1;
        cur = l1;
        l1 = l1->next;  
    }else{
        finalNode = l2;
        cur = l2;
        l2 = l2->next;  
    }
    while(l1 && l2){
        if(l1->val <= l2->val){
            cur->next = l1;
            l1 = l1->next;
        }else{
            cur->next = l2;
            l2 = l2->next;
        }
        cur = cur->next;    
    }
    if(l1) cur->next = l1;
    if(l2) cur->next = l2;
    return finalNode;
}
//寻找两链表的公共节点leetcode52
//将一个链表首尾相连，就相当于找单链表环的位置
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *slow= headB, *fast = headB;
    while(headB->next) headB = headB->next;
    headB->next = headA;
    slow = slow->next; fast = fast->next->next;
    cout << fast->val;
    while(slow != fast){
        slow = slow->next;
        fast = fast->next->next;
    }
    cout << fast -> val << endl;
    return fast;
}
//
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *slow= headA, *fast = headB;
    if(!headA || !headB) return NULL;
    while(slow!=fast){
        slow = slow?slow->next:headB;//使用slow而不是slow->next避免了没有交点的死循环
        fast = fast?fast->next:headA;
    }
    return slow;
}
//判断单链表有环
bool *detectCycle(ListNode *head) {
  if(!head) return NULL;
  ListNode *slow=head, *fast=head->next;
  while(fast && slow!=fast){
    slow = slow->next;
    fast = fast->next?fast->next->next:NULL;
  }
  return fast?false:true;
}
