#include <stdio.h>

int main()
{
    int x;

    long long fact = 1;

    printf("Enter value of x: ");
    scanf("%d", &x);

    while (x >= 1)
    {
        fact = fact * x;
        x--;
    }

    printf("\nFactorial of x is: %llu", fact);
}