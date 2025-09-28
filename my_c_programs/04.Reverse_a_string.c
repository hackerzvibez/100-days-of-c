// ==========Reverse_a_String.c=========== //

// includes
#include <stdio.h>
#include <stdlib.h>

// Global Vaiables

// functions declarations
size_t len(const char *v);
char *reverse_string_v(const char *v);
char *read_line();

// main aka progrms entry point
int main()
{
    printf("Enter the String you wanna reverse :");
    char *in = read_line();
    if (!in)
        return 1;
    char *reversed = reverse_string_v(in);
    printf("Orginal :%s\nReversed :%s\n", in, reversed);
    free(in);
    free(reversed);
    return 0;
}

// function definition
size_t len(const char *v)
{
    size_t len = 0;
    while (v[len] != '\0')
    {
        len++;
    }
    return len;
}

char *reverse_string_v(const char *v)
{
    size_t len_ = len(v);
    char *c = malloc(len_ + 1);
    for (size_t i = 0; i < len_; i++)
    {
        c[i] = v[len_ - i - 1];
    }
    c[len_] = '\0';
    return c;
}

char *read_line()
{
    size_t size = 128;
    size_t len_ = 0;
    char *str = malloc(size);
    if (!str)
        return NULL;
    char ch;
    while ((ch = getchar()) != '\n' && ch != EOF)
    {
        str[len_++] = ch;
        if (len_ == size)
        {
            size *= 2;
            str = realloc(str, size);
            if (!str)
                return NULL;
        }
    }
    str[len_] = '\0';
    return str;
}