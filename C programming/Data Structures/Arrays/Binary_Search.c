/*
  V0 U0 V1 U1 V2 U2 V3 U3 V4 U4
  V5 U5 V6 U6 V7 U7 V8 U8 V9 U9
  V10 U10 V11 U11 V12 U12 V13 U13
  
  V0 V1 V2 V3 V4 
  V5 V6 V7 V8 V9
  V10 V11 V12 V13
  U0 U1 U2 U3 U4
  U5 U6 U7 U8 U9 
  U10 U11 U13 
  
*/
#include <stdio.h>
#include <stdbool.h>

bool Vint(int index){
    return !(index & 0x01);
}

bool Uint(int index){
    return (index & 0x01);
}

void ArrangePicxels(int* pIndx, int Width, int Height, int* pOutx){
    int i = 0, j = 0;
    int len = Height * Width;
    
    for(i = 0; i < len; i++){
        if(Vint(i)){
            pOutx[j++] = pIndx[i];
        }
    }
  
    for(i = 0; i < len; i++){
        if(Uint(i)){
            pOutx[j++] = pIndx[i];
        }
    }  
    
}

int main() {
    
    int pIndx[18] = {1, 5, 1, 5, 1, 5, 1, 5, 1, 5, 1, 5, 1, 5, 1, 5, 1, 5};
    int Height = 3;
    int Width = 6;
    int pOutx[18];
    
    ArrangePicxels(pIndx, Width, Height, pOutx);
    
    printf("output Array: \n");
    for (int i = 0; i < 18; i++){
        printf("%d\t",pOutx[i]);
    }
    return 0;
}

/*
output Array: 
1	1	1	1	1	1	1	1	1	5	5	5	5	5	5	5	5	5
*/
