class Solution
{
public:
    string breakPalindrome(string palindrome)
    {
        int n = palindrome.size();
        if (n == 1 || n == 0) return "";
        int i = 0;
        while (i < n / 2)
        {
            if (palindrome[i] != 'a')
            {
                palindrome[i] = 'a';
                break;
            }
            i++;
        }
        if (i == n / 2)
            palindrome[n - 1] = 'b';
        return palindrome;
    }
};