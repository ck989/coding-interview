/*
APPLE INTERVIEW:
Consider building from east to west, there are variable heights of building from east to west.
Sun is towards west. 
Write a function that returns the index of the buildings that receives sunlight.

Travrse from east to west
*/

#include <iostream>
#include <vector>

using namespace std;

int Find_max_buidling_index(vector<int> & building, int start, int end){
    
    int large1 = building[start], large2 = building[end];
    
    while(start < end){
        if(building[start] <= building[end]){
            start++;
        }else{
            end--;
        }
    }
    
    return (building[start] >= building[end])?start:end;
}

vector<int> Building_gets_Sun(vector<int> & building){
    int len = building.size();
    vector<int> index;
    
    int i = 0;
    int start = i;
    
    while(i < len){
        i = Find_max_buidling_index(building, start, len - 1);
        index.push_back(i);
        i++;
        start = i;
    }
    
    return index;
}

int main()
{
    vector<int> building = {5, 8, 2, 4, 10, 4, 8, 5};
    
    vector<int> res = Building_gets_Sun(building);
    
    for(int i:res){
        cout << i << " ";
    }
    return 0;
}

/*
4 6 7 
*/
