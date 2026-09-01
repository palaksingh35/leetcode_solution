class Solution {
public:
    int maxArea(vector<int>& height) {
    
        int water;
        int ans=0;
        int i=0;
        int j=height.size()-1;
       
        while(i<j){
               water = min(height[i], height[j]) * (j - i); 
            if(height[i]< height[j]){
                i++;
            }else{
                j--;
            }
            ans= max(water,ans);
            }
        

        
        
        return ans;
    }
};