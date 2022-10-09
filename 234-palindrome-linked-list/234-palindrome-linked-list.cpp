class Solution
{
public:
    bool isPalindrome(ListNode* head)
    {
        vector<int> v;
        
        ListNode* ptr=head;
        
        while(ptr!=nullptr)
        {
            v.push_back(ptr->val);
            ptr=ptr->next;
        }
       int n= v.size()-1;
        for(int i=0;i<=n/2;i++)
        {
            if(v[i]!=v[n-i])
                return false;
        }
        return true;
    }
};