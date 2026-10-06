#include <stdio.h>
#include <ctype.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>

enum CalcErr {
    CALC_OK = 0,
    CALC_WRONG_ARGC,
    CALC_WRONG_FORMAT,
    CALC_INVALID_OPERATOR,
    CALC_INVALID_OPERAND,
    CALC_DIV_BY_ZERO
};

int parse_int(const char *str, int *out);
int calc(int argc, char *argv[], int *result);
void print_err(enum CalcErr err);

int main(int argc, char *argv[])
{
    int res = 0;
    int err = calc(argc, argv, &res);

    if (err)
    {
        print_err((enum CalcErr)err);
        return err;
    }

    printf("res = %d\n", res);

    return 0;
}

int parse_int(const char *str, int *out)
{
    if (str[0] == '\0')
        return 0;

    char *end;
    long val = strtol(str, &end, 10);

    if (*end != '\0')
        return 0;

    if (val > INT_MAX || val < INT_MIN)
        return 0;

    *out = (int)val;
    return 1;
}

int calc(int argc, char *argv[], int *result)
{
    if (argc != 2)
        return CALC_WRONG_ARGC;

    size_t len = strlen(argv[1]);
    char *buf = (char *)calloc(len + 1, 1);
    char *a_str = (char *)calloc(len + 1, 1);
    char *b_str = (char *)calloc(len + 1, 1);
    strcpy(buf, argv[1]);

    int i = 0;
    int j = 0;

    while (buf[i] != '\0' && isspace((unsigned char)buf[i]))
        i++;

    while (buf[i] != '\0' && !isspace((unsigned char)buf[i]))
    {
        a_str[j] = buf[i];
        i++;
        j++;
    }
    a_str[j] = '\0';

    while (buf[i] != '\0' && isspace((unsigned char)buf[i]))
        i++;

    if (buf[i] == '\0')
    {
        free(buf); free(a_str); free(b_str);
        return CALC_WRONG_FORMAT;
    }

    char op = buf[i];
    i++;

    const char *operators = "+-*/%";
    if (!strchr(operators, op))
    {
        free(buf); free(a_str); free(b_str);
        return CALC_INVALID_OPERATOR;
    }

    while (buf[i] != '\0' && isspace((unsigned char)buf[i]))
        i++;

    j = 0;
    while (buf[i] != '\0' && !isspace((unsigned char)buf[i]))
    {
        b_str[j] = buf[i];
        i++;
        j++;
    }
    b_str[j] = '\0';

    while (buf[i] != '\0' && isspace((unsigned char)buf[i]))
        i++;

    if (buf[i] != '\0')
    {
        free(buf); free(a_str); free(b_str);
        return CALC_WRONG_FORMAT;
    }

    int a = 0, b = 0;
    if (!parse_int(a_str, &a) || !parse_int(b_str, &b))
    {
        free(buf);
        free(a_str);
        free(b_str);
        return CALC_INVALID_OPERAND;
    }

    free(buf); 
    free(a_str); 
    free(b_str);

    if ((op == '/' || op == '%') && b == 0)
        return CALC_DIV_BY_ZERO;

    switch (op)
    {
        case '+':
            *result = a + b;
            break;

        case '-':
            *result = a - b;
            break;

        case '*':
            *result = a * b;
            break;

        case '/':
            *result = a / b;
            break;

        case '%':
            *result = a % b;
            break;
    }

    return CALC_OK;
}

void print_err(enum CalcErr err)
{
    switch (err)
    {
        case CALC_WRONG_ARGC:
            printf("Error: wrong number of arguments\n");
            break;

        case CALC_WRONG_FORMAT:
            printf("Error: wrong format, expected \"a op b\"\n");
            break;

        case CALC_INVALID_OPERATOR:
            printf("Error: invalid operator\n");
            break;

        case CALC_INVALID_OPERAND:
            printf("Error: operands should be integers\n");
            break;

        case CALC_DIV_BY_ZERO:
            printf("Error: division by zero\n");
            break;

        default:
            break;
    }
}

