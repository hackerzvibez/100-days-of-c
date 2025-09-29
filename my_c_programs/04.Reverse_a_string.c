// ==========Reverse_a_String.c=========== //

// includes
#include <stdio.h>
#include <stdlib.h>

// Global Vaiables

// functions declarations
size_t len(const char *v);
char *reverse_string_v(const char *v);
char *read_line();
void until_user_end();
// main aka progrms entry point
int main()
{
    until_user_end();
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
    if (!v)
    {
        fprintf(stderr, "<Error!> reversing string\n");
        return NULL;
    }
    size_t len_ = len(v);
    char *c = malloc(len_ + 1);
    if (!c)
    {
        fprintf(stderr, "<Error!> allocating memory\n");
        return NULL;
    }
    for (size_t i = 0; i < len_; i++)
    {
        c[i] = v[len_ - i - 1];
    }
    c[len_] = '\0';
    return c;
}

char *read_line()
{
    size_t size = 128, len_ = 0;
    char *str = malloc(size);
    if (!str)
    {
        fprintf(stderr, "<Error!> Allocating memory using malloc\n");
        return NULL;
    }
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF)
    {
        str[len_++] = (char)ch;
        if (len_ == size)
        {
            size *= 2;
            char *temp = realloc(str, size);
            if (!temp)
            {
                free(str);
                return NULL;
            }
            str = temp;
        }
    }
    str[len_] = '\0';
    return str;
}

void until_user_end()
{
    while (1)
    {
        printf("Enter the String you wanna reverse:");
        char *c = read_line();
        if (!c)
        {
            fprintf(stderr, "<Error!>Reading input\n");
            break;
        }
        if (c[0] == '\0')
        {
            free(c);
            break;
        }
        char *r = reverse_string_v(c);
        if (!r)
        {
            fprintf(stderr, "<Error!>Reversing string!\n");
            free(c);
            break;
        }
        printf("Orginal : %s\nReversed : %s\n", c, r);
        free(c);
        free(r);
    }
}