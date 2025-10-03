class Solution {
public:

    bool isAlphaNumeric(char c)
    {
        if(c>='A' && c<='Z' || c>='a' && c<='z' || c>='0' && c<='9')
        return true;
        else
        return false;
    }

    bool isPalindrome(string s) {

        int low = 0, high = s.size() - 1;

        while(low<high)
        {

            while(low<high && !isAlphaNumeric(s[low]))
            {
                low++;
            }
            while(low<high && !isAlphaNumeric(s[high]))
            {
                high--;
            }

            if(s[low]>='A' && s[low]<='Z')
            {
                s[low]=s[low]+32;
            }
            if(s[high]>='A' && s[high]<='Z')
            {
                s[high]=s[high]+32;
            }

            if(s[low]!=s[high])
            {
                return false;
            }

            low++;
            high--;

        }

        return true;

    }
};