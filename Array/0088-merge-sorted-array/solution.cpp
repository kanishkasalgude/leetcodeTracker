class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int left = 0; int right = 0; int index = 0;
        vector<int>temp = nums1;
        while(left<m && right<n){
            if(temp[left]<=nums2[right]){
                nums1[index] = temp[left];
                left++;index++;
            }else{
                nums1[index] = nums2[right];
                right++; index++;
            }
        }
        while(left<m){
            nums1[index] = temp[left];
            left++;
            index++;
        }
        while(right<n){
            nums1[index] = nums2[right];
            right++;
            index++;
        }
    }
};
