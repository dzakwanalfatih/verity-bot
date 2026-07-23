#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include "memory.h"
#include "colorForText.h"

// HELP MODE
void helpMode(){
    printf(PURPLE"======================================\n");
    printf(BLUE"You can type anything to Verity\n");
    printf("This is available commands you can input:\n");
    printf(LIBLUE"'help' : Open this help Window\n");
    printf("'about': About this code\n");
    printf("'exit' : Exiting the code.\n");
    printf(PURPLE"======================================\n"RESET);
}
// ABOUT MODE
void aboutMode(){
    printf(PURPLE"======================================\n");
    printf(GREEN"This code is made for learning C by creating a chat bot,\n");
    printf(PURPLE"======================================\n"RESET);
}

int main(){
    char input[50];
    int countCMDInput = 0;

    Memory memories[MAX_MEMORIES];
    int length = 0;

    initMemory(memories, MAX_MEMORIES);

    loadSampleMemory(memories, &length);

    int memoryCount;
      
    while(1){
        
        printf("Verity> ");
        fgets(input, sizeof(input), stdin); // input can take more than 1 word
        input[strcspn(input, "\n")] = 0; // remove newline
        countCMDInput++;

        if(strcmp(input, "help") == 0)
        {
           helpMode();
        }
        else if(strcmp(input, "about") == 0) {
           aboutMode();
        }
        else if(strcmp(input, "exit") == 0){
            break;
        }
        else if(strcmp(input, "") == 0){
            printf(YELLOW"You Entered: ");
            printf(PURPLE"Nothing?\n"RESET);
        }
        
        else if(strcmp(input, "show memory") == 0){
            showMemory(memories, length);
        }

        else if(strcmp(input, "find memory") == 0){
            int findId = 0;
            printf("Insert number for memory you want to see\n");
            printf("you have %d memories:\n", length);
            printf("Input > ");
            scanf("%d", &findId);
            getchar();
            int idx = findMemoryById(memories, length, findId);

            if(idx >= 0){
                printf("Found: [%s] %s %s %s\n",
                memories[idx].category,
                memories[idx].subject,
                memories[idx].predicate,
                memories[idx].object
                );
            }
        }
        else{
        printf(YELLOW"You Entered: %s\n"RESET, input);}
    }
    printf(YELLOW"Total Input to Verity: %d\n"RESET, countCMDInput);
    printf(RED"Closing the command..."RESET);

    return 0;
}