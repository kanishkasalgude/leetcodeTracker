#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        int min_price = budget+1;
        int max_factor = 0;

        for(const auto& item:items){
            min_price = min(min_price, item[1]);
            max_factor = max(max_factor, item[0]);
        } 

        vector<int>free_copies(n,0);

        if(max_factor<=200000){
            vector<int>freq(max_factor+1,0);

            for(const auto& item:items) freq[item[0]]++;

            vector<int> mult_count(max_factor+1,0);

            for(int f=1;f<=max_factor;f++){
                if(freq[f] == 0) continue;
                for(int m=f;m<=max_factor;m+=f){
                    mult_count[f] += freq[m];
                } 
            }
            for(int i=0;i<n;i++){
                free_copies[i] = mult_count[items[i][0]]-1;
            }
        }else{
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(i!=j && items[j][0] % items[i][0] == 0){
                        free_copies[i]++;
                    }
                }
            }
        }

        vector<int> dp(budget+1,0);
        for(int i=0;i<n;i++){
            int price = items[i][1];
            int val = 1+free_copies[i];
            if(price>budget) continue;

            for(int c=budget;c>=price;c--){
                dp[c] = max(dp[c], dp[c-price]+val);
            }
        }

        int ans = 0;
        for(int c=0;c<=budget;c++){
            int extra = (min_price<=budget)?(budget-c)/min_price:0;
            ans = max(ans,dp[c]+extra);
        }
        return ans;
    }
};
