class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int countone = 0;
        int counttwo = 0;
        for(int i = 0;i< nums.size();i++)
        {
            for(int j = i + 1;j< nums.size();j++)
            {
                if(nums[i] + nums[j] == target)
                {
                    countone = i;
                    counttwo = j;
                    break;
                }
            }
        }
        vector<int> tmp;
        tmp.push_back(countone);
        tmp.push_back(counttwo);
        return tmp;
    }
};
