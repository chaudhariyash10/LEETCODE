#include <stdio.h>

int main()
{
    int x, y;

    long long ans = 1;

    printf("Enter values of x and y: ");
    scanf("%d%d", &x, &y);

    while (y >= 1)
    {
        ans = ans * x;
        y--;
    }

    printf("\nFactorial of x raised to y : %llu", ans);
}