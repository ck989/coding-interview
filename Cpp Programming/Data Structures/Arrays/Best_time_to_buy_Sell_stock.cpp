/*
Refer this youtube link:
https://www.youtube.com/watch?v=1pkOgXD63yU
*/

#define MAX_NUM(x, y) (x > y)?x:y

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        int l = 0;
        int r = 1;

        int curr_max = 0, final_max = 0;

        while (r < len){
            if(prices[l] >= prices[r]){
                l = r++;
            }else{
                curr_max = prices[r] - prices[l];
                final_max = MAX_NUM(curr_max, final_max);
                r++;
            }
        }

        return final_max;
    }
};
