// odd or even c project
#include <stdio.h>
// function declaration
typedef long long int intLL;
void odd_or_even(intLL v);
void odd_or_even_user_in();

// programs entry point
int main()
{
    odd_or_even(5);
    odd_or_even_user_in();
    return 0;
}

// function definition
void odd_or_even(intLL v)
{
    if (v % 2 == 0)
    {
        printf("<EVEN>The given number '%lld' is an even number\n", v);
    }
    else
    {
        printf("<ODD>The given number '%lld' is not an even number ...Hence it is an odd number ...\n", v);
    }
}

void odd_or_even_user_in()
{
    intLL v;
    printf("Enter the number you want to check whether it is odd or even :");
    scanf(" %lld", &v);
    odd_or_even(v);
}