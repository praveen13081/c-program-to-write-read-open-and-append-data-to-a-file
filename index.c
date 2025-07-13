#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void createFile(const char *filename) {
    FILE *fp = fopen(filename, "w"); // Create or overwrite
    if (fp == NULL) {
        printf("Error creating file!\n");
        return;
    }
    printf("File '%s' created successfully.\n", filename);
    fclose(fp);
}

void writeFile(const char *filename) {
    FILE *fp = fopen(filename, "w"); // Overwrite
    if (fp == NULL) {
        printf("Error opening file for writing!\n");
        return;
    }

    char data[1024];
    printf("Enter text to write (end with ENTER): ");
    fgets(data, sizeof(data), stdin);
    data[strcspn(data, "\n")] = '\0';  // Remove newline

    fputs(data, fp);
    fputs("\n", fp);  // Optional: Add newline to file
    printf("Data written to '%s'.\n", filename);
    fclose(fp);
}

void appendFile(const char *filename) {
    FILE *fp = fopen(filename, "a"); // Append
    if (fp == NULL) {
        printf("Error opening file for appending!\n");
        return;
    }

    char data[1024];
    printf("Enter text to append (end with ENTER): ");
    fgets(data, sizeof(data), stdin);
    data[strcspn(data, "\n")] = '\0';  // Remove newline

    fputs(data, fp);
    fputs("\n", fp);  // Optional: Add newline
    printf("Data appended to '%s'.\n", filename);
    fclose(fp);
}

void readFile(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file for reading!\n");
        return;
    }

    char ch;
    printf("Contents of '%s':\n", filename);
    while ((ch = fgetc(fp)) != EOF) {
        putchar(ch);
    }
    fclose(fp);
}

int main() {
    char filename[100];
    int choice;

    printf("Enter the filename: ");
    scanf("%s", filename);
    getchar(); // Clear newline left in buffer

    while (1) {
        printf("\n====== File Operations Menu ======\n");
        printf("1. Create File\n");
        printf("2. Write to File\n");
        printf("3. Append to File\n");
        printf("4. Read from File\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // Clear invalid input
            continue;
        }
        getchar(); // Clear newline from input buffer

        switch (choice) {
            case 1:
                createFile(filename);
                break;
            case 2:
                writeFile(filename);
                break;
            case 3:
                appendFile(filename);
                break;
            case 4:
                readFile(filename);
                break;
            case 5:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
