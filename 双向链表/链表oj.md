链表oj

### 链表分割

现有一链表的头指针 ListNode* **pHead**，给一定值x，编写一段代码将所有小于x的结点排在其余结点之前，且不能改变原来的数据顺序，返回重新排列后的链表的头指针。

小于尾插到一个链表

大于等于插到另一个列表

最后再链接起来

lesshead/lesstail

greaterhead/greatertail

两个链表尾插

```c
class Partition {
public:
    ListNode* partition(ListNode* pHead, int x) {
       struct ListNode* gGuard, * gTail, * lGuard, * lTail;
	gGuard = gTail = (struct ListNode*)malloc(sizeof(struct ListNode));
	lGuard = lTail = (struct ListNode*)malloc(sizeof(struct ListNode));
	gTail-> next = lTail->next = NULL;
	struct ListNode* cur = pHead;
	while (cur)
	{
		if (cur->val < x)
		{
			lTail->next = cur;
			lTail = lTail->next;
		}
		else
		{
			gTail->next = cur;
			gTail = gTail->next;
		}
		cur=cur->next;
	}
	lTail->next = gGuard->next;
    gTail->next=NULL;
	pHead = lGuard->next;
	free(gGuard);
	free(lGuard);
	return pHead;
    }
};
```



对于一个链表，请设计一个时间复杂度为O(n),额外空间复杂度为O(1)的算法，判断其是否为回文结构。

给定一个链表的头指针**A**，请返回一个bool值，代表其是否为回文结构。保证链表长度小于等于900。

测试样例：1->2->2->1

```c++
返回：true
```

```c
class PalindromeList {
public:
struct ListNode* middleNode(struct ListNode* head){
    struct ListNode*fast=head;
    struct ListNode*slow=head;
    while(fast&&fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
struct ListNode* reverseNode(struct ListNode* head){
  if (head == NULL)
    {
        return NULL;
    }
    struct ListNode* n1;
    struct ListNode* n2;
    struct ListNode* n3;
    n1 = NULL;
    n2 = head;
    n3 = n2->next;
    while (n2)
    {
        n2->next = n1;
        n1 = n2;
        n2 = n3;
        if (n3)
        {
            n3 = n3->next;
        }
    }
    return n1;
}
    bool chkPalindrome(ListNode* head) {
        struct ListNode*mid=middleNode(head);
        struct ListNode*rhead=reverseNode(head);
        while(head&&rhead)
        {
            if(head->val!=rhead->val)
            {
                return false;
            }
            head=head->next;
            rhead=rhead->next;
        }
        return true;


    }
};
```

返回交点

```c
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode* tailA = headA, * tailB = headB;
	int lenA = 1, lenB = 1;
	while (tailA->next)
	{
		tailA = tailA->next;
		++lenA;
	}
	while (tailB->next)
	{
		tailB = tailB->next;
		++lenB;
	}
	if (tailA != tailB)
	{
		return NULL;
	}
	int gap = abs(lenA - lenB);
	struct ListNode* longList = headA, *shortList = headB;
	if (lenA < lenB)
	{
		longList = headB;
		shortList = headA;
	}
	while (gap--)
	{
		longList = longList->next;
	}
	while (longList != shortList)
	{
		longList = longList->next;
		shortList = shortList->next;
	}
	return longList;
}
```

### 判断链表是否存在环

给你一个链表的头节点 head ，判断链表中是否有环。

如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 为了表示给定链表中的环，评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。注意：pos 不作为参数进行传递 。仅仅是为了标识链表的实际情况。

如果链表中存在环 ，则返回 true 。 否则，返回 false 
链接：https://leetcode.cn/problems/linked-list-cycle



快慢指针



```c
bool hasCycle(struct ListNode* head) {
	struct ListNode* slow, * fast;
	slow = fast = head;
	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
		{
			return true;
		}

	}
	return false;
}
```

为什么fast走2步？

每次距离缩小1。若>=3可能会错过，fast和slow之间的节点数为奇数，则追不上。

