#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string name = get_string("What's your name? ");

    if (name == NULL)
    {
        return 1;
    }

    printf("hello, %s\n", name);

    return 0;
}
