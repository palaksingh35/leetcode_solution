class Solution {
public:
    bool checkString(string s) {
        bool foundB=false;
        for(int i=0; i< s.size(); i++){
             if(s[i]=='b'){
               foundB=true;
             }
             if(s[i]=='a' && foundB==true){
                return false;
             }
        }
        return true;
    }
};