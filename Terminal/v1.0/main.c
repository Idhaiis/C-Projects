#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_INPUT_SIZE 1024

bool running = true; 

void eval() {
    
    char input[MAX_INPUT_SIZE];
    
    if (fgets(input, sizeof(input), stdin) == NULL) {
        return;
    }

    input[strcspn(input, "\n")] = '\0';
    char * inputTkn = strtok(input, " ");

    if (strlen(input) == 0) {
        printf(" >  ");
        return;
    }

    if (strcmp(inputTkn, "quit") == 0 || strcmp(inputTkn, "exit") == 0 || strcmp(inputTkn, "leave") == 0) {
        running = false;
        printf("Leaving Shell...");
        return;
    }

    else if (strcmp(inputTkn, "print") == 0 || strcmp(inputTkn, "write") == 0){
        char *param = strtok(NULL, " ");
        if (param == NULL) {
            printf("You missed parameters! Usage: \"print <text>\" or \"write <text>\"");
            printf("\n >  ");
            return;
        }
        printf("Your sentence is: ");
        while (param != NULL) {
            printf("%s ", param);
            param = strtok(NULL, " ");
        }
    }

    printf("\n >  ");
    return;
}

int main(void) {
    
    printf("A Shell Made From C \n >  ");
    
    while(running == true) {
        eval(); 
    }
    
    return 0;
}