#include <stdio.h>
#include <stdlib.h>

#define KEY 'K'     // Define XOR Encryption Key

//Function to encrypt a file
void encryptFile(const char* inputFile, const char* outputFile) {
    FILE *input, *output;
    char ch;

//Open input and output files
    input = fopen(inputFile, "r");
    output = fopen(outputFile, "w");

//Check if files were opened successfully
    if (input == NULL || output == NULL) {
        fprintf(stderr, "Error opening files.\n");//whats the meaning of fprintf?
        exit(1);
    }

//Read character by character from input file, XOR encrypt, and write to output file
    while ((ch = fgetc(input)) != EOF) {
        ch = ch ^ KEY;      //Perform XOR operation with encryption key
        fputc(ch, output);     //Write encrypted character to output file
    }

//Print success message
    printf("File encrypted successfully.\n");

//Close input and output files
    fclose(input);
    fclose(output);
}

//Main function
int main() {
    const char* inputFilePath = "input.txt";
    const char* outputFilePath = "output.txt";

//Call the encryptFile function with input and output filepaths
    encryptFile(inputFilePath, outputFilePath);

    return 0;
    //final copy
}
