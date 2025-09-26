// 02.calculator_program.c

#include <stdio.h>

// fucntion declarations
int stringlength(const char *v);
int int_or_float(const char *v);
int convert_to_int(const char *v);
double convert_to_float(const char *v);

int main()
{
    char *v = "123.5";
    if (int_or_float(v))
    {
        printf("Int\n");
    }
    else
    {
        printf("Float\n");
    }
    printf("%.6f\n", convert_to_float("123.578945"));
    return 0;
}

// function implementations

int int_or_float(const char *v)
{
    char c = *v;
    char *null = "\0";
    char *dot = ".";
    for (int i = 0; c != *null; i++)
    {
        char temp = *(v + i);
        if (temp == *dot)
        {
            return 0; // float if its return a zero
        }
        c = *(v + i + 1);
    }
    return 1; // int if its return a one
}
int convert_to_int(const char *v)
{
    int num = 0;
    char c = *v;
    char *null = "\0";
    char *dot = ".";
    for (int i = 0; c != *null; i++)
    {
        if (c == *dot)
        {
            c = *(v + i + 1);
            continue;
        }
        int temp = *(v + i) - 48;
        num = (num * 10) + temp;
        c = *(v + i + 1);
    }
    return num;
}
double convert_to_float(const char *v)
{
    int len_of_string = stringlength(v);
    int num = convert_to_int(v);
    float result = 0.0;
    int dot_len = 0;
    char *null = "\0";
    char *dot = ".";
    char c = *v;
    for (int i = 0; c != *null; i++)
    {
        if (c == *dot)
            break;
        dot_len += 1;
        c = *(v + i + 1);
    }
    printf("%d\n%d\n", len_of_string, dot_len);
    int e = len_of_string - dot_len - 1;
    switch (e)
    {
    case 1:
        result = num * (1e-1);
        break;
    case 2:
        result = num * (1e-2);
        break;
    case 3:
        result = num * (1e-3);
        break;
    case 4:
        result = num * (1e-4);
        break;
    case 5:
        result = num * (1e-5);
        break;
    case 6:
        result = num * (1e-6);
        break;
    }
    return result;
}
int stringlength(const char *v)
{
    int count = 0;
    char c = *v;
    char *null = "\0";
    for (int i = 0; c != *null; i++)
    {
        count++;
        c = *(v + i + 1);
    }
    return count;
}