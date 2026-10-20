#include<bits/stdc++.h>
class Solution {
public:
    
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.begin(), prices.end());
        sort(discounts.begin(), discounts.end());
        int j=discounts.size()-1;
        double sum = 0;
        for(int i=prices.size()-1;i>=0;i--){
            if(j>=0){
                sum = sum + ((double)prices[i]*(100-(double)discounts[j])/100);
                j--;
            }else{
                sum = sum + prices[i];
            }
        }
        return sum;
    }
};
