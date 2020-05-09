class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int k) 
    {
        sort(A.begin(),A.end());
        int i=0,min=INT_MAX;
        while(i<A.size())
        {
            if(A[i]<0 and k>0) {A[i]=-A[i];k--;}
            if(A[i]<min)min=A[i];
            i++;
        }
        int sum=0;
        for(auto x:A) sum+=x;
        if(k%2==0) return sum;
        else return sum-2*min;
        
    }
};