#pragma once
#include <bits/stdc++.h>
using namespace std;

struct ListNode { int val; ListNode* next; ListNode(int x=0, ListNode* n=nullptr):val(x),next(n){} };
struct TreeNode { int val; TreeNode *left, *right; TreeNode(int x=0):val(x),left(nullptr),right(nullptr){} };

ListNode* makeList(const vector<int>& v) {
    ListNode dummy; ListNode* t = &dummy;
    for (int x : v) { t->next = new ListNode(x); t = t->next; }
    return dummy.next;
}
vector<int> toVec(ListNode* h) { vector<int> r; for (; h; h = h->next) r.push_back(h->val); return r; }

class DebugTool
{
public:
    static void OnFileOpenError()
    {
        std::cout << "File Open Error";
    }
};
