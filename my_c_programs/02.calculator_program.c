// 02.calculator_program.c

#include <stdio.h>

// fucntion declarations
void calculator();
int stringlength(const char *v);
int int_or_float(const char *v);
int convert_to_int(const char *v);
double convert_to_float(const char *v);
float f_add(float a, float b);
float f_mul(float a, float b);
float f_div(float a, float b);
float f_sub(float a, float b);
int add(int a, int b);
int mul(int a, int b);
int sub(int a, int b);
int div(int a, int b);

int main()
{
    calculator();
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

float f_add(float a, float b)
{
    return a + b;
}
int add(int a, int b)
{
    return a + b;
}
float f_sub(float a, float b)
{
    return a - b;
}
int sub(int a, int b)
{
    return a - b;
}
float f_mul(float a, float b)
{
    return a * b;
}
int mul(int a, int b)
{
    return a * b;
}
float f_div(float a, float b)
{
    return a / b;
}
int div(int a, int b)
{
    return a / b;
}

void calculator()
{
    char op;
    char a[100];
    char b[100];
    int i_a;
    int i_b;
    float f_a;
    float f_b;
    float (*func_f)(float, float);
    int (*func_i)(int, int);

    printf("Enter the Operation you want to perform (+,-,/,*) :");
    scanf(" %c", &op);

    printf("Enter the Number A :");
    scanf(" %99s", a);

    printf("Enter the Number B :");
    scanf(" %99s", b);

    if (int_or_float(a) && int_or_float(b))
    {
        printf("I am inside a if block\n");
        i_a = convert_to_int(a);
        i_b = convert_to_int(b);
        switch (op)
        {
        case '+':
            func_i = add;
            break;
        case '-':
            func_i = sub;
            break;
        case '*':
            func_i = mul;
            break;
        case '/':
            if (i_b == 0)
            {
                printf("<Error!> division by zero");
                return;
            }
            func_i = div;
            break;
        }
        int result = func_i(i_a, i_b);
        printf("Result : %d", result);
    }
    else
    {
        printf("i am inside else block\n");
        f_a = convert_to_float(a);
        f_b = convert_to_float(b);
        switch (op)
        {
        case '+':
            func_f = f_add;
            break;
        case '-':
            func_f = f_sub;
            break;
        case '*':
            func_f = f_mul;
            break;
        case '/':
            if (f_b == 0.0)
            {
                printf("<Error! division by zero!>");
                return;
            }
            func_f = f_div;
            break;
        }
        float result = func_f(f_a, f_b);
        printf("Result :%f", result);
    }
}