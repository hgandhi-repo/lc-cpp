#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
  public:
    Solution() {}

    vector<int> twoSum(vector<int>& nums, int k) {
      unordered_map<int, int> sumIdx;
      for (int i = 0; i < nums.size(); i++) {
        int diff = k - nums[i];
        if (sumIdx.count(diff)) {
          return {sumIdx[diff], i};
        }
        sumIdx[nums[i]] = i;
      }
      return {};
    }
};

int main() {
  Solution sol;
  vector<int> nums = {2, 3, 4, 5, 8, 9, 10};

  vector<int> out = sol.twoSum(nums, 7);
  cout << "two sum of 7:" << out[0] << " and:" << out[1] << " values:" << nums[out[0]] << " and:" << nums[out[1]] << endl;

  return 0; 
}

