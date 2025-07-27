#include<bits/stdc++.h>
using namespace std;
int trap(vector<int>& heights){
    int n = heights.size();
    if(n== 0) return 0;

    vector<int>leftMax(n),rightMax(n);
    leftMax[0] = heights[0];
    for(int i=1;i<n;i++){
        leftMax[i] = max(leftMax[i-1],heights[i]);
    }

    rightMax[n-1]= heights[n-1];
    for(int i=n-2;i>=0;i--){
        rightMax[i] = max(rightMax[i+1],heights[i]);
    }

    int trapped =0;
    for(int i=0;i<n;i++){
        trapped += min(leftMax[i],rightMax[i])-heights[i];
    }

    return trapped;
}


// Trwo Pointer Approach
int trapUsingTwoPointer(vector<int>& heights){
    int n = heights.size();
    int left =0, right=n-1;
    int left_max=0,right_max=0;
    int trapped =0;
    while(left<right){
        if(heights[left]<heights[right]){
          if(heights[left]>= left_max){
             left_max = heights[left];
          }else{
              trapped += left_max - heights[left];
          }
          left++;
        }else{
            if(heights[right] >= right_max){
              right_max = heights[right];
            }else{
              trapped += right_max - heights[right];
            }
           right--;
        }
    }
    return trapped;
}
int main() {
    vector<int> arr = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << "Total water trapped: " << trap(arr) << endl; // Output: 6
   

    cout << "Total water trapped using two pointer : " << trapUsingTwoPointer(arr) << endl; // Output: 6
    return 0;

}