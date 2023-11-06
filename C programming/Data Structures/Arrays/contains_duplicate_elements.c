#define SIZE 1000000



int hash(int key) {
   int r = key % SIZE;
   return r < 0 ? r + SIZE : r; 
}

int search(int* keys, int* values, int key)
{
    int index = hash(key);
    int count = 1;
    while(values[index])
    {
        count++;
        index = (index + 1) % SIZE;

        return count;
    }
    
    return 0;
}

void insert(int *keys, int *values, int key) {
    int index = hash(key);
    while (values[index]) {
        index = (index + 1) % SIZE;
    }
    keys[index] = key;
    values[index] = 1;
}

bool containsDuplicate(int* nums, int numsSize){
    
    int i;
    int keys[SIZE];
    int values[SIZE] = {0};
    
    for(i = 0; i<numsSize; i++)
    {
        int key = nums[i];
        
        int value = search(keys,values,key);
        
        if(value > 1)
        {
            return true;
        }
        
        insert(keys, values, nums[i]);
        
    }
    

    
    return false;
    
}
