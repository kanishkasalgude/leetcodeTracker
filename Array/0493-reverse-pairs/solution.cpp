class Solution {
public:
    void merge(vector<int>& nums, int low, int mid, int high){
        int left = low;
        int right = mid+1;
        vector<int>temp;
        while(left<=mid && right<=high){
            if(nums[left]<= nums[right]){
                temp.push_back(nums[left++]);
            }else{
                temp.push_back(nums[right++]);
            }
        }
        while(left<=mid){
            temp.push_back(nums[left++]);
        }
        while(right<=high){
            temp.push_back(nums[right++]);
        }

        for(int i=0; i<temp.size(); i++){
            nums[low+i] = temp[i];
        }
    }

    int countPairs(vector<int>& nums, int low, int mid, int high){
        int cnt = 0;
        int right = mid+1;
        for(int left  = low; left<=mid; left++){
            while(right<=high && (long long)nums[left]>2LL*nums[right]){
                right++;
            }
            cnt += right-(mid+1);
        }
        return cnt;
    }

    int ms(vector<int>& nums, int low, int high){
        int cnt = 0;
        if(low>=high){
            return cnt;
        }

        int mid = (low+high)/2;
        cnt += ms(nums, low, mid);
        cnt += ms(nums, mid+1,high);
        cnt += countPairs(nums, low, mid, high);
        merge(nums, low, mid, high);
        return cnt;
    }

    int reversePairs(vector<int>& nums) {
        return ms(nums, 0, nums.size()-1);
    }
};
