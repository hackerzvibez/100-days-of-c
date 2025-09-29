//=======panlindrome.c========

// includes
#include <stdio.h>
#include <stdbool.h>
// defines
// function declaration
size_t str_len(const char *v);
bool palindrome(const char *V);
void check_palindrome_or_not();

// global vaiables
const bool (*func_for_palindrome)(const char *) = palindrome;

// main
int main()
{
    check_palindrome_or_not();
    return 0;
}

// function definition
size_t str_len(const char *v) // this function is to find the length of the string
{
    size_t len = 0;
    while (v[len] != '\0')
    {
        len++;
    }
    return len;
}

bool palindrome(const char *v) // this function is to find the given sequence of string is plaindrome or not
{
    size_t len = str_len(v);
    size_t left = 0;
    size_t right = len - 1;
    if (len < 2)
        return false;
    while (left < right)
    {
        if (v[left] != v[right])
        {
            return false; // returns false(0) if it is a not a palindrome ...
        }
        left++;
        right--;
    }
    return true; // returns true(1) if it is a palindrome ...
}

void check_palindrome_or_not() // this function is to keep the main function clean ... it also to make the program bit more act like a terminal in the case of asking for input ...as long as the user doesn't give any empty string or 0 it will continue to ask for input
{
    while (true)
    {
        char c[50];
        printf("Enter the word to check it is palindrome or not (press \"0 or space\" and enter to quit) :");
        if (!fgets(c, sizeof c, stdin))
        {
            fprintf(stderr, "<Error!> Reading input...");
            continue;
        }
        size_t len = str_len(c);
        if (len > 0 && c[len - 1] == '\n')
        {
            c[len - 1] = '\0';
        }
        if (c[0] == '\0' || (c[0] == '0' && c[1] == '\0') || (c[0] == ' ' && c[1] == '\0'))
        {
            return;
        }
        if (func_for_palindrome(c))
        {
            printf("<True> %s is a palindrome ...\n", c);
        }
        else
        {
            printf("<False> %s is not a palindrome...\n", c);
        }
    }
}