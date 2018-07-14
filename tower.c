#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

const int n = 20;
const bool _log = false;

int* a = NULL;
int* b = NULL;
int* c = NULL;

int* initialize(bool is_tower)
{
    int* array = (int*) calloc(n, sizeof(int));
    if(is_tower)
        for(int i = n-1, j = 0; i >= 0; i--, j++)
            array[j] = i + 1;
    return array;
}

void _print(int* v)
{

    printf("[");
    for(int i = 0; i < n; i++)
        if(v[i] != 0)
        {
            if(i == n - 1)
                printf("%d", v[i]);
            else
                printf("%d, ", v[i]);
        }

    printf("]\n");
}

void print()
{
    printf("\n********\n");
    _print(a);
    _print(b);
    _print(c);
}

void append(int* array, int value)
{
    for(int i = 0; i < n; i++)
        if(array[i] == 0)
        {
            array[i] = value;
            break;
        }
}

int pop(int* array)
{
    int value = 0;
    for(int i = 0; i < n; i++)
        if(array[i] == 0)
        {
            value = array[i - 1];
            array[i - 1] = 0;
            break;
        } else if(i == n - 1)
        {
            value = array[i];
            array[i] = 0;
            break;
        }
    return value;
}

void move(int n, int* source, int* target, int* auxiliary)
{
    if(n > 0)
    {
        move(n - 1, source, auxiliary, target);
        append(target, pop(source));
        if(_log) print();
        move(n - 1, auxiliary, target, source);
    }
}

int main()
{
    int t = clock();
    a = initialize(true);
    b = initialize(false);
    c = initialize(false);
    move(n, a, c, b);
    free(a);
    free(b);
    free(c);
    printf("\nC work time: %f sec.\n", ((float)t) / CLOCKS_PER_SEC);
    return 0;
}
// gcc -Wall -O2 -c tower.c -o tower.o