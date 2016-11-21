class Solution {
public:
    int lengthOfLongestSubstring(string s) {
            int n = s.length();  
            int i = 0, j = 0;  
            int maxLen = 0;  
            bool exist[256] = { false };  
            while (j < n) {  
            if (exist[s[j]]) {  
              maxLen = max(maxLen, j-i);  
              while (s[i] != s[j]) {  
                exist[s[i]] = false;  
                i++;  
              }  
              i++;  
              j++;  
            } else {  
              exist[s[j]] = true;  
              j++;  
            }  
            }  
            maxLen = max(maxLen, n-i);  
            return maxLen;  
    }
    
    int lengthOfLongestSubstring_1(string s) {
        
        if(s.length() == 0)
        {
            return 0;
        }
        int nSublen   = 1;
        int nMaxCount = 1;
        string substr = "";
        int i = 0, j = 0;
        for(i = 0;i < s.length(); i++)
        {
            for(j = s.length() - 1; j > i; j--)
            {
                substr = s.substr(i,j - i + 1);
                if(IsRepeatEx(substr))
                {
                    nSublen = substr.length();
                    break;
                }
                
            }
            if(nMaxCount < nSublen)
            {
                nMaxCount = nSublen;
            }
        }
        return nMaxCount;
    }
    
    bool IsRepeatEx(string pp_String)
    {
        //bool bRet = true;
        int a[8];  
        memset(a, 0, sizeof(a));  
        int len = pp_String.length();  
        for(int i=0; i < len; ++i)  
        {  
        char v = (int)pp_String[i];  
        int idx = v/32, shift=v%32;  
        if(a[idx] & (1 << shift)) return false;  
        a[idx] |= (1 << shift);  
        }  
        return true;  
        //return bRet;
    }
    
    bool IsRepeat(string str)
    {
        bool bRet = true;
        int i = 0, j = 0;
        for(i = 0 ;i < str.length();i++)
        {
            for(j = i + 1; j < str.length();j++)
            {
                if(str[i] == str[j])
                {
                    bRet = false;
                    goto Exit0;
                }
            }
        }
    Exit0:
        return bRet;
    }
};
