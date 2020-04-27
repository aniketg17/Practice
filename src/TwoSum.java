import java.util.HashMap;

class Solution {
    public int[] twoSum(int[] nums, int target) {
        int[] ans = new int[2];
        HashMap<Integer, Integer> values = new HashMap<Integer, Integer>();

        for (int i = 0;  i < nums.length; i++) {
            if (values.containsKey(target - nums[i])) {
                ans[0] = i;
                ans[1] = values.get(target - nums[i]);
            } else {
                values.put(nums[i], i);
            }
        }

        return ans;
    }
}