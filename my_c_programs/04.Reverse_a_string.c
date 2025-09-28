// ==========Reverse_a_String.c=========== //

// includes
#include <stdio.h>
#include <stdlib.h>

// functions declarations
size_t len(const char *v);
void reverse_string_v(const char *v);

// main aka progrms entry point
int main()
{
    const char *c = "Ktashwin2534@gmail.com ";
    printf("%zu\n", len(c));
    reverse_string_v(c);
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

void reverse_string_v(const char *v)
{
    size_t len_ = len(v);
    char c[len_ + 1];
    for (size_t i = 0; i < len_; i++)
    {
        c[i] = v[len_ - i - 1];
    }
    c[len_] = '\0';
    printf("Original :%s\nReversed :%s\n", v, c);
}