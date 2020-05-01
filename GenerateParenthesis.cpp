#include<bits/stdc++.h>
class Solution {
public:
    vector<string> res;
    
    void getGeneratedParenthesis(int open, int close, int n, string &s)
    {
        if(open == close)
        {
            if(open == n)
            {
                res.push_back(s);
                return;
            }
            else
            {
                s+='(';
                getGeneratedParenthesis(open+1,close,n,s);            
                s.pop_back();
            }
        }
        
        else if(open == n)
        {
            s+=')';
            getGeneratedParenthesis(open,close+1,n,s);            
            s.pop_back();
        }
        
        else if(open > close)
        {
            // either open or close
            s += '(';
            getGeneratedParenthesis(open+1, close, n, s);
            s.pop_back();
            s+= ')';
            getGeneratedParenthesis(open, close+1, n, s);
            s.pop_back();
        }
            
            
        
    }
    vector<string> generateParenthesis(int n) 
    {
        string s = "";
        getGeneratedParenthesis(0, 0, n, s);
        return res;
    }
};