class Solution {
public:
    bool checkValidString(string s) {
        int cnt1=0;
        int cnt2=0;
        for(int i=0;i < s.size();i++){
            if(s[i]=='('){
                cnt1++;
                cnt2++;
            }
            else if(s[i]==')'){
                cnt1--;
                cnt2--;
            }else{
                cnt1--;
                cnt2++;
            }
           cnt1=max(0, cnt1);
            if(cnt2 < 0){
            return false;
        }
        }
       
       return cnt1==0;
    }
};