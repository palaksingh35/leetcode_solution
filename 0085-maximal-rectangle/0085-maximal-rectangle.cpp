class Solution {
     int largestRectangleArea(vector<int>& heights) {
        
        int n=heights.size();
        int area=0;
        vector<int>next(n);
         next=nextSmallerElement(heights);

         vector<int>prev(n);

         prev=prevSmallerElement(heights);

         for(int i=0; i< n;i++){
            int l=heights[i];
            if(next[i]==-1){
                next[i]=n;
            }
            int b= next[i]-prev[i]-1;
            
            int newArea=l*b;
            area=max(area, newArea);
         }
          return area;
     }
     vector<int> nextSmallerElement(vector<int> &arr)
{
    int n= arr.size();
    vector<int>ans(n);
    stack<int>s;
    s.push(-1);
    for(int i= n-1; i>=0;i--){
        int curr=arr[i];
        while(s.top()!=-1 && arr[s.top()]>=curr){
            s.pop();
        }
        ans[i]=s.top();
        s.push(i);
    }
    return ans;
}
vector<int> prevSmallerElement(vector<int> &arr)
{
    int n = arr.size();
    vector<int>ans(n);
    stack<int> s;
    s.push(-1);
    for(int i=0;i<n; i++){
        int curr=arr[i];
         while(s.top()!=-1 && arr[s.top()]>=curr){
            s.pop();
        }
        ans[i]=s.top();
        s.push(i);
    }
    return ans;

    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
      int n = matrix.size();
      int m = matrix[0].size();

       vector<int> heights(m, 0);
         int area=0;
        for(int i =0; i< n;i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j]=='1'){
                  heights[j]++;
                }
                else 
                    heights[j]=0;
            
            }
           int currentArea = largestRectangleArea(heights);
           area = max(area, currentArea);
        }
        return area;
    }
};