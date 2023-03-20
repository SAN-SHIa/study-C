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

