#include "..\inc\utils.h"

ListNode* createList(const vector<int>& arr)
{
    ListNode* res = NULL;
    size_t n = arr.size();
    if(n >= 1){
        res = new ListNode(arr[0]);
    }
    
    ListNode* resRunner = res;

    for(size_t i = 1; i < n; i++){
        resRunner->next = new ListNode(arr[i]);
        resRunner = resRunner->next;
    }
    return res;
}

void releaseList(ListNode* root)
{
    ListNode* tmpRoot = NULL;
    while(root){
        tmpRoot = root->next;
        delete root;
        root = tmpRoot;
    }
}

void printListNodes(const ListNode* root)
{
    while(root){
        printf("%d ", root->val);
        root = root->next;
    }
    printf("\n");
}