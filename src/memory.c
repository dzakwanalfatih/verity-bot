#include <stdio.h>
#include <string.h>
#include "memory.h"

void initMemory(Memory memories[], int size){
    for(int i = 0; i < size; i++){
        memories[i].id = 0;
        memories[i].category[0] = '\0';
        memories[i].subject[0] = '\0';
        memories[i].predicate[0] = '\0';
        memories[i].object[0] = '\0';
    }
}

void showMemory(const Memory memories[], int count){

    //char input[50];
    if(count == 0){
        printf("No memory avaiable\n");
        return;
    }
    printf("Verity Memory\n");
    printf("---------------------\n");

    for(int i = 0; i < count; i++){
        printf("%d.[%s] %s %s %s\n",
            memories[i].id,
            memories[i].category,
            memories[i].subject,
            memories[i].predicate,
            memories[i].object
        );
    }
}

int findMemoryById(const Memory memories[], int count, int id){
    for(int i = 0; i < count; i++){
        if(memories[i].id == id){
            return i;
        }
    }
    //printf("Sorry, the memory on id %d doesn't exist\n", id);
    return -1;
}
void loadSampleMemory(Memory memories[], int *count){
    SampleData sampleData[3] = {
        {1, "PERSONAL", "User", "name", "Dzakwan"},
        {2, "PERSONAL", "I", "love", "code"},
        {3, "KNOWLEDGE", "Tiger", "eat", "meat"}
    };
    int length = sizeof(sampleData) / sizeof(sampleData[0]);

    for (int i = 0; i < length; i++){
        memories[i].id = sampleData[i].id;
        snprintf(memories[i].category,  sizeof(memories[i].category),   "%s", sampleData[i].category);
        snprintf(memories[i].subject,   sizeof(memories[i].subject),    "%s", sampleData[i].subject);
        snprintf(memories[i].predicate, sizeof(memories[i].predicate),  "%s", sampleData[i].predicate);
        snprintf(memories[i].object,    sizeof(memories[i].object),     "%s", sampleData[i].object);
    }
    *count = length;
}