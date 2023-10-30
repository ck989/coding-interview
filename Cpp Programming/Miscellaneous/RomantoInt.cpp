#include <iostream>
#include <unordered_map>

using namespace std;

/*
Refer to this Youtube: https://www.youtube.com/watch?v=Ydho2JPTI3Y
*/
int RomanToInt(string& s){
    unordered_map<char, int> mpp{
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000},
    };
    
    int val = 0;
    
    for(int i = 0; i < s.size(); i++){
        if(mpp[s[i]] < mpp[s[i + 1]]){
            val -= mpp[s[i]];
        }else{
            val += mpp[s[i]];
        }
    }
    
    return val;
}

int main()
{
    string str = "DXCVI";
    
    int num = RomanToInt(str);
    
    cout << num << endl;
    return 0;
}

/*
596
*/
