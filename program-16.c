c
#include <stdio.h>

int main() {
    FILE *file;
    char data[100], readData[100];
    
    // Write to file
    printf("Enter text to write to file: ");
    fgets(data, sizeof(data), stdin);
    
    file = fopen("sample.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing!\n");
        return 1;
    }
    
    fprintf(file, "%s", data);
    fclose(file);
    printf("Data written to file successfully.\n");
    
    // Read from file
    file = fopen("sample.txt", "r");
    if (file == NULL) {
        printf("Error opening file for reading!\n");
        return 1;
    }
    
    printf("\nReading data from file:\n");
    while (fgets(readData, sizeof(readData), file) != NULL) {
        printf("%s", readData);
    }
    
    fclose(file);
    
    return 0;
}
