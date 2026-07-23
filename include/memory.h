#ifndef MEMORY_H
#define MEMORY_H

#define MAX_MEMORIES 100
#define MEMORY_CONTENT_SIZE 50

typedef struct{
    int id;
    char category[20];
    char subject[MEMORY_CONTENT_SIZE];
    char predicate[MEMORY_CONTENT_SIZE];
    char object[MEMORY_CONTENT_SIZE];
} Memory;

typedef struct{
        int id;
        const char *category;
        const char *subject;
        const char *predicate;
        const char *object;
    } SampleData;

void initMemory(Memory memories[], int size);
void loadSampleMemory(Memory memories[], int *count);
void createMemory(Memory memories[], int *count);
void showMemory(const Memory memories[], int count);
int findMemoryById(const Memory memories[], int count, int id);

#endif