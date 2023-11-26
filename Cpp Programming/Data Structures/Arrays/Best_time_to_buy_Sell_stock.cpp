/*
Refer this youtube link:
https://www.youtube.com/watch?v=1pkOgXD63yU
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        int l = 0;
        int r = 1;

        int curr_max = 0, final_max = 0;

        while (r < len){
            if(prices[l] >= prices[r]){
                l = r;
                r++;
            }else{
                curr_max = prices[r] - prices[l];
                if(curr_max > final_max)
                    final_max = curr_max;
                r++;
            }
        }
        return final_max;
    }
};
