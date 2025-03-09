#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

vector<vector<int>> matrix;
void findCombinations(vector<int>& nums, int i, int m, vector<int>& ans, int sum, int target) { 
         // m = number of elements that sum upto the target value
         // base case
         if(sum == target && m == 0) {
             matrix.push_back(ans);
             return ;
         }
         
         if(m == 2) {
             int j = i; 
   	         int k = nums.size()-1;
   	         while(j < k) {
   	         int total = nums[j] + nums[k];
      	     if(total == target - sum) {
      	         ans.push_back(nums[j]);
      	         ans.push_back(nums[k]);
      	         matrix.push_back(ans);
      	         ans.pop_back();
      	         ans.pop_back();
   			     j++;
   			     k--;
   			     while(j < k && nums[j] == nums[j-1]) j++; // Skip duplicates for j
   		         while(j < k && nums[k] == nums[k+1]) k--; // Skip duplicates for k
   			 } else if(total > target - sum) {
   			     k--;
   			 } else {
   			     j++;
   			 }
   		   }   
   		   return;
         }
         
         // choices
         for(int ch = i; ch <= nums.size() - m ; ch++){
             // make sure duplicate of i are skipped.
             if(ch > i && nums[ch] == nums[ch-1]) continue;
             ans.push_back(nums[ch]); // choose
             findCombinations(nums, ch+1, m-1, ans, sum+nums[ch], target); // move forward
             ans.pop_back(); // backtrack
         }
   		
}

int main() {
   vector<int> nums = {1, -1, -2, 1, 4, -2, -7};
   vector<int> ans;
   sort(nums.begin(), nums.end()); // sorting the array -> O(nlogn)
   findCombinations(nums, 0, 5, ans, 0, 0);
   
    for (const auto& vec : matrix) {
        cout << "[ ";
        for (int num : vec) {
            cout << num << " ";
        }
        cout << "]\n";
    }
   return 0;
}