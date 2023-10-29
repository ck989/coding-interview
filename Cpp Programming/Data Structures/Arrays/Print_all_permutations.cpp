#include <iostream>
#include <vector>

using namespace std;

//This solution prints all permutations including duplicates
/*
Refer the following youtube video: https://www.youtube.com/watch?v=f2ic2Rsc9pU&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=15
*/
void recurpermute(int index, vector<int>& nums, vector<vector<int>>& ans){
    
    if(index == nums.size()){
        ans.push_back(nums);
        return;
    }
    
    for(int i = 0; i < nums.size(); i++){
        swap(nums[index], nums[i]);
        recurpermute(index+1, nums, ans);
        swap(nums[index], nums[i]);
    }
}

vector<vector<int>> permute(vector<int>& nums){
    
    vector<vector<int>> ans;
    recurpermute(0, nums, ans);
    return ans;
}

int main()
{
    vector<int> num = {1, 2, 3};
    
    vector<vector<int>> ans = permute(num);
    for(auto& innervector : ans){
        for(int element : innervector){
            cout << element << " ";
        } 
        cout << endl;
    }

    return 0;
}

/*
output:
3 1 2 
3 2 1 
3 2 1 
1 2 3 
1 3 2 
1 3 2 
3 2 1 
3 1 2 
3 1 2 
2 1 3 
2 3 1 
2 3 1 
1 3 2 
1 2 3 
1 2 3 
2 3 1 
2 1 3 
2 1 3 
2 3 1 
2 1 3 
2 1 3 
3 1 2 
3 2 1 
3 2 1 
2 1 3 
2 3 1 
2 3 1
  */
