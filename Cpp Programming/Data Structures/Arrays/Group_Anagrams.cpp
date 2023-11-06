lass Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;

        map<map<char, int>, vector<string>> mpp;
        int len = strs.size();

        for(int i = 0; i < len; i++){
            map<char, int> temp;
            for(char c: strs[i]){
                temp[c]++;
            }

            mpp[temp].push_back(strs[i]);
        }

        for(auto itr = mpp.begin(); itr != mpp.end(); itr++){
            ans.push_back(itr->second);
        }

        return ans;
    }
};

/*
https://leetcode.com/problems/group-anagrams/description/
*/
