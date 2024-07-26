#include <stdio.h>
#include <stdlib.h>

#define KEY 'K'      //Define XOR Decryption Key which is the same as Encryption Key

//Function to decrypt a file
void decryptFile(const char* inputFile, const char* outputFile) {
    FILE *input, *output;
    char ch;

//Open input and output files
    input = fopen(inputFile, "r");
    output = fopen(outputFile, "w");

//Check if files were opened successfully
    if (input == NULL || output == NULL) {
        fprintf(stderr, "Error opening files.\n");
        exit(1);
    }

//Read character by character from input file, XOR decrypt, and write to output file
    while ((ch = fgetc(input)) != EOF) {
        ch = ch ^ KEY;      // Perform XOR operation with decryption key
        fputc(ch, output);     //Write decrypted character to output file
    }

//Print success message
    printf("File decrypted successfully.\n");

//Close input and output files
    fclose(input);
    fclose(output);
}

//Main function
int main() {
    const char* inputFilePath = "output.txt";
    const char* outputFilePath = "decrypted.txt";

//Call the decryptFile function with input and output filepaths
    decryptFile(inputFilePath, outputFilePath);

    return 0;
}
