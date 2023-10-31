/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <pthread.h>

#define BUFF_SIZE 5

char buff[BUFF_SIZE];
int in = 0, out = 0;

//declare two sempahores for producing and consuming
int semaphore1 = BUFF_SIZE;
int semaphore2 = 0;

//custome implementation of wait and post APIs
void wait(int* sem){
    while(*sem <= 0); //geneally semaphore should
                      //prempt, but here it is just busywait
    
    if(*sem > 0){
        (*sem)--;
    }
}

void post(int* sem){
    (*sem)++;
}

void* producer(void* arg){
    
    while(1){
        for(int i = 0; i < 6; i++){
            wait(&semaphore1); //waits until consmed
            buff[in] = i;
            in = (in + 1)%BUFF_SIZE;
            printf("Produced %d\n", i);
            post(&semaphore2); //posts after producing
        }
    }
}

void* consumer(void* arg){
    int item;
    while(1){
        for(int i = 0; i < 6; i++){
            wait(&semaphore2); //waits until produced
            item = buff[out];
            out = (out + 1)%BUFF_SIZE;
            printf("Consumed %d\n", item);
            post(&semaphore1); //post after consuming
        }
    }  
}

int main()
{
    pthread_t producer_thread, consumer_thread;
    
    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_create(&consumer_thread, NULL, consumer, NULL);
    
    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);
    
    return 0;
}


