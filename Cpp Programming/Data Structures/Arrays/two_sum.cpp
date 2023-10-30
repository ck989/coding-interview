#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> TwoSum(vector<int>& nums, int target){
    map<int, int> mpp;
    int len = nums.size();
    
    for(int i = 0; i < len; i++){
        int num = nums[i];
        int diff = target - num;
        if(mpp.find(diff) != mpp.end()){
            return {mpp[diff], i};
        }
        
        mpp[num] = i;
    }
    
    return  {-1, -1};
}

int main()
{
    vector<int> num = {2, 7, 11, 5};
    int target = 9;
    
    vector<int> res_vec = TwoSum(num, target);
    for(auto element : res_vec){
        cout << element << " " ;
    }
    
    return 0;
}

/*
0 1 
*/
