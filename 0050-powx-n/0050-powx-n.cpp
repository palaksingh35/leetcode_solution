class Solution {
public:
    
        double power(double a,int b){
            if(b== 0){
                return 1;
            }
            if(b==1){
                return a;
            }
            double ans=power(a,b/2);
            // check if b is even
            if(b %2 ==0){
                return ans*ans;
            }else{
                return a* ans*ans;
            }
        }
        double myPow(double x, int n) {

        long long N = n;

        if (N < 0) {
            return 1 / power(x, -N);
        }

        return power(x, N);
        
    }
};