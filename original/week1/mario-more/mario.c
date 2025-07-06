#include <cs50.h>
#include <stdio.h>

int get_pyramid_height(void);
void print_pyramids(int height);

int main(void)
{
    const int height = get_pyramid_height();
    print_pyramids(height);
}

int get_pyramid_height(void)
{
    int height;
    do
    {
        height = get_int("Height (1-8): ");
    }
    while (height < 1 || height > 8);
    return height;
}

void print_pyramids(int height)
{
    for (int row = 0; row < height; row++)
    {
        for (int spaces = height - row - 1; spaces > 0; spaces--)
        {
            printf(" ");
        }

        for (int left_hashes = 0; left_hashes <= row; left_hashes++)
        {
            printf("#");
        }

        printf("  ");

        for (int right_hashes = 0; right_hashes <= row; right_hashes++)
        {
            printf("#");
        }

        printf("\n");
    }
}
