#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_INPUT_SIZE 1024

bool running = true; 

void printprompt() {

    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("\n%s >  ", cwd);
    }
    else {
        printf("\n >  ");
    }

    return;
}

void eval() {
    
    char input[MAX_INPUT_SIZE];
    char inputcopy[MAX_INPUT_SIZE];
    
    if (fgets(input, sizeof(input), stdin) == NULL) {
        return;
    }

    input[strcspn(input, "\r\n")] = '\0';
    strcpy(inputcopy, input);
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

    else if (strcmp(inputTkn, "print") == 0 || strcmp(inputTkn, "write") == 0) {
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

    else if (strcmp(inputTkn, "clear") == 0 || strcmp(inputTkn, "c") == 0) {
        system("cls");
    }

    else if (strcmp(inputTkn, "cd") == 0) {
        char *hedef_klasor = strtok(NULL, " ");
        if (hedef_klasor == NULL) {
            system("cd");
        } 
        else {
            if (chdir(hedef_klasor) != 0) {
                perror("Error: "); 
            }
        }
    }
    else if (strcmp(inputTkn, "cd..") == 0) {
        if (chdir("..") != 0) {
            perror("cd error");
        }
    }

    else {
        int result = system(inputcopy);
        
        if (result == -1) {
            printf("Error");
        }
    }

    if (running == true) {
        printprompt();

        return;
    }
}

int main(void) {
    
    printf("  =============================\n  ==== A Shell Made From C ==== \n  =============================\n");
    printprompt();
    while(running == true) {
        eval(); 
    }
    
    return 0;
}