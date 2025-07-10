#include <cs50.h>
#include <stdio.h>

void buildThing(int height);

int main(void)
{
    int height;

    while (1){
        height = get_int("Height: ");

        if (height > 0){
            buildThing(height);}
    }
}

void buildThing(int height){
    for (int i = 0; i < height; i++){
        for (int r = height - 1; r > i; r--){
            printf(" ");
        }
        for (int b = 0; b <= i; b++)
        {
            printf("%c", '#');
        }
    printf("\n");}
}
