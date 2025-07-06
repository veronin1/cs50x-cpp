#include <cs50.h>
#include <stdio.h>

int get_positive_input(void);
void print_mario(int n);

int main(void)
{
    const int n = get_positive_input();
    print_mario(n);
}

int get_positive_input(void)
{
    int n;
    do
    {
        n = get_int("Integer: ");
    }
    while (n < 1 || n > 8);
    return n;
}

void print_mario(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = n; j > i + 1; j--)
        {
            printf(" ");
        }
        for (int k = 0; k < i + 1; k++)
        {
            printf("#");
        }
        printf("\n");
    }
}
