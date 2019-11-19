#include "stdafx.h"

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x = 0) : val(x), next(NULL) {}
    
};
/***************** Class Template ******************
class ListNode
{
public:
    ListNode(int x)
    {
        val = x;
        next = NULL;
    }
    ~ListNode()
    {
        val = 0;
        next = NULL;
    }

private:
    int val;
    ListNode *next;
};
****************************************************/
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode result(0), *p = &result;
        int flag = 0;

        while (l1 || l2 || flag)
        {
            int tmp= 0;
            if (l1 != NULL) tmp += l1->val;
            if (l2 != NULL) tmp += l2->val;
            tmp += flag;

            flag = tmp / 10;
            tmp %= 10;

            ListNode *next = new ListNode(tmp);

            p->next = next;
            p = p->next;
            l1 = (l1 ? l1->next : NULL);
            l2 = (l2 ? l2->next : NULL);
        }

        return result.next;
    }
};

ListNode *stringToListNode(string input)
{
    //Generate list from the input
    vector<int> list = stringToIntegerVector(input);

    //Now convert that list into linked list
    ListNode *dummyRoot = new ListNode(0);
    ListNode *ptr = dummyRoot;
    for (int item : list)
    {
        ptr->next = new ListNode(item);
        ptr = ptr->next;
    }
    
    ptr = dummyRoot->next;
    delete dummyRoot;
    return ptr;
}

string listNodeToString(ListNode *node)
{
    if (node == NULL)
    {
        return "[]";
    }

    string result;
    while (node)
    {
        result += to_string(node->val) + ",";
        node = node->next;
    }

    return "[" + result.substr(0, result.length()-1) + "]";
}

int main02()
{
    string line;
    cout << "Please input first list []: ";
    while (getline(cin, line) && !line.empty())
    {
        ListNode *l1 = stringToListNode(line);
        cout << "Input second list []: ";
        getline(cin, line);
        ListNode *l2 = stringToListNode(line);
    
        ListNode *ret = Solution().addTwoNumbers(l1, l2);

        string out = listNodeToString(ret);
        cout << "Result: " + out << endl;
    }

    return 0;
}

