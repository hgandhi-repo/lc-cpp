#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
  public:
    Solution() {}
  
  int lengthOfLongestSubstring(string s) {
    int charCnt[128] = {};

    int start = 0;
    int res = 0;
    for (int end = 0; end < s.length(); end++) {
      char ec = s[end];
      charCnt[ec]++;
      
      // roll the window
      while(charCnt[ec] > 1) {
        charCnt[s[start]]--;
        start++;
      }
      res = max(res, end - start + 1);
    }
    return res;
  }
};

int main() {
  Solution sol;

  string s1 = "abcabcbb";
  string s2 = "bbbbb";
  string s3 = "pwwkew";

  cout << "longest substring for s1 is of length:" << sol.lengthOfLongestSubstring(s1) << endl;
  cout << "longest substring for s2 is of length:" << sol.lengthOfLongestSubstring(s2) << endl;
  cout << "longest substring for s3 is of length:" << sol.lengthOfLongestSubstring(s3) << endl;
  return 0; 
}

