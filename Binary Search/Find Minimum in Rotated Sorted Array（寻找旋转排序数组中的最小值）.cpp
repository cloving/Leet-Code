/* Find Minimum in Rotated Sorted Array（寻找旋转排序数组中的最小值） */

class Solution {
public:
  int findMin(vector<int>& nums) {
    int left = 0, right = nums.size() - 1;
    if (nums[left] > nums[right]) {
      while (left != right - 1) {
        int mid = left + (right - left ) / 2;
        if (nums[mid] > nums[left]) {
          left = mid;
        } else {
          right = mid;
        }
      }
    }
    return min(nums[left], nums[right]);
  }
};

