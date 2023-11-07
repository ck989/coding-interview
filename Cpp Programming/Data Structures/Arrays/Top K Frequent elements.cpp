class Solution {
    struct node{
        int num;
        int freq;
        node(int x, int y) : num(x), freq(y) {}
    };

    struct Comparenodes{
        bool operator()(node x, node y){
            return x.freq < y.freq;
        }
    };
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        int len = nums.size();
        vector<int> res;
        unordered_map<int, int> mpp;

        for(int ele:nums){
            mpp[ele]++;
        }

        priority_queue<node, vector<node>, Comparenodes> heap;
        for(auto itr:mpp){
            heap.push(node(itr.first, itr.second));
        }

        while(k--){
            node temp = heap.top();
            heap.pop();
            res.push_back(temp.num);
        }

        return res;   
    }
};

/*
https://leetcode.com/problems/top-k-frequent-elements/submissions/

https://www.youtube.com/watch?v=Wh3A29psE_Y
*/
