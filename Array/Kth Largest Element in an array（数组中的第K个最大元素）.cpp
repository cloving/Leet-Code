// 第一种：直接排序
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return nums[nums.size()-k];
    }
};

// 第二种：使用优先队列
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // 优先级大的先出（数值大的优先级大）
        priority_queue<int> q(nums.begin(), nums.end());
        for (int i = 1; i <= k-1; i++) {
            q.pop();
        }
        return q.top();
    }
};

// 第三种：使用快排思想
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0, right = nums.size()-1;
        while(true) {
          int pos = partition(nums, left, right);
          if (pos == k-1) {
            return nums[pos];
          } else if (pos < k-1) {
              left = pos + 1;
          } else {
              right = pos - 1;
          }
        }
    }
    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[left], l = left+1, r = right;
        while (l <= r) {
            if (nums[l] < pivot && nums[r] > pivot) {
                swap(nums[l++], nums[r--]);
            }
            if (nums[l] >= pivot) {
                l++;
            }
            if (nums[r] <= pivot) {
                r--;
            }
        }
        swap(nums[left], nums[r]);
        return r;
    }
};
