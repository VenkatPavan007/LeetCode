class Solution {
public:
    int findNthDigit(int n) 
    {
        // find number of digits of the number in which nth digit is a part of
        int base = 9, digits = 1;        
        while(true)
        {
            if(n - ((long long)base*digits)>0)
            {
                n-= base*digits;
                ++digits;
                base*=10;                
            }
            else
                break;
        }
        //cout<<digits<<endl;
        // find the number to which the nth digit belongs to
        int index = n%digits;
        if(index == 0)
            index = digits;
        int baseDigit = 1;
        for(int i=0; i<digits-1; i++)
            baseDigit*=10;
        baseDigit += (index == digits) ? ((n/digits) - 1) : n/digits;
        
        //cout<<baseDigit<<endl;
        // find the digit in the number denoted by baseDigit
        for(int i = index; i<digits; i++)
            baseDigit/=10;
        
        return baseDigit%10;
    }
};