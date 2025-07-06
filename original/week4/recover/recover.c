#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Expect 1 argument
    if (argc != 2)
    {
        printf("Usage: ./recover <FILE>\n");
        return 1;
    }

    // Open file & null check
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }

    uint8_t buffer[512];
    FILE *output = NULL;

    int counter = 0;
    while (fread(buffer, 1, 512, input) == 512)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && buffer[3] >= 0xe0 && buffer[3] <= 0xef)
        {
            if (output != NULL)
            {
                fclose(output);
            }

            char filename[8];
            sprintf(filename, "%03i.jpg", counter++);
            output = fopen(filename, "wb");
        }

        if (output != NULL)
        {
            fwrite(buffer, 1, 512, output);
        }
    }

    if (output != NULL)
    {
        fclose(output);
    }

    fclose(input);
}
