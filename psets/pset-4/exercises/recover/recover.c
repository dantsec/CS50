#include <stdio.h>
#include <stdlib.h>
// UINT8_T
#include <stdint.h>

int main(int argc, char *argv[])
{
    // HANDLING ARGS
    if(argc != 2) {
        fprintf(stderr, "Usage: ./recover [image]\n");
        return 1;
    }

    // ACCESSING FILE
    FILE* input_file = fopen(argv[1], "r");

    if(input_file == NULL) {
        fprintf(stderr, "Could not open file.\n");
        return 1;
    }

    // READING BYTES - VARIABLES
    const int BLOCK = 512;
    uint8_t BUFFER[512] = { 0 };
    char filename[8] = { 0 };
    int filename_index = 0;
    FILE* output_file = NULL;

    // SCROLLING THROUGH BLOCKS OF BYTES
    while(fread(BUFFER, BLOCK, 1, input_file)) {
        // VERIFYNG JPG DELIMITER
        if(BUFFER[0] == 0xff && BUFFER[1] == 0xd8 && BUFFER[2] == 0xff && (BUFFER[3] >= 0xe0 && BUFFER[3] <= 0xef)) {
            // CLOSE FILE IF OPENED
            if(output_file != NULL)
                fclose(output_file);

            // WRITE FILE NAME
            sprintf(filename, "%03d.jpg", filename_index);

            output_file = fopen(filename, "w+");

            filename_index++;
        }

        // FILE OPENED -> WRITE BYTES
        if(output_file != NULL)
            fwrite(BUFFER, BLOCK, 1, output_file);
    }

    // CLOSING FILES
    fclose(input_file);
    fclose(output_file);

    return 0;
}
