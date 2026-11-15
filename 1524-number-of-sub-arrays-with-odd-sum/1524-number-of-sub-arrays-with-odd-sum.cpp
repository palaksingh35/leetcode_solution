class Solution {
   
public:
    int numOfSubarrays(vector<int>& arr) {
         const int MOD = 1e9 + 7;
      int n = arr.size();
       int sum=0;
       int odd=0;
       int even=1;
       
        long long cnt=0;
        for(int i=0; i< n; i++){
                sum+=arr[i];
            if(sum % 2 ==0){
                cnt+=odd;
                even++;
            }else{
                cnt+=even;
                odd++;
            }
        }
        
         return cnt % MOD;


        
    }
};