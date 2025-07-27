#include <stdio.h>

void saveToFile(char *filePath) {
    FILE *filePtr = fopen(filePath, "w");
    if (!filePtr) {
        printf("Unable to create file.\n");
        return;
    }

    char inputText[1000];
    printf("Type the content to save:\n");
    fgets(inputText, sizeof(inputText), stdin);
    fputs(inputText, filePtr);
    fclose(filePtr);
    printf("Content saved successfully.\n");
}

void addToFile(char *filePath) {
    FILE *filePtr = fopen(filePath, "a");
    if (!filePtr) {
        printf("Unable to open file.\n");
        return;
    }

    char inputText[1000];
    printf("Type the content to add:\n");
    fgets(inputText, sizeof(inputText), stdin);
    fputs(inputText, filePtr);
    fclose(filePtr);
    printf("Content appended successfully.\n");
}

void displayFile(char *filePath) {
    FILE *filePtr = fopen(filePath, "r");
    if (!filePtr) {
        printf("File not available.\n");
        return;
    }

    char character;
    printf("\n--- File Output ---\n");
    while ((character = fgetc(filePtr)) != EOF) {
        putchar(character);
    }
    fclose(filePtr);
}

int main() {
    char fileName[100];
    int option;

    printf("Enter the file name: ");
    scanf("%s", fileName);
    getchar(); 
    while (1) {
        printf("\nChoose an option:\n");
        printf("1. Write File\n2. Append File\n3. Read File\n4. Exit\nEnter your choice: ");
        scanf("%d", &option);
        getchar(); 
        switch (option) {
            case 1: saveToFile(fileName); break;
            case 2: addToFile(fileName); break;
            case 3: displayFile(fileName); break;
            case 4: return 0;
            default: printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}