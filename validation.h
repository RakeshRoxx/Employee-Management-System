// #include<regex.h>
#include <ctype.h>
#define TRUE 1
#define FALSE 0

// Function Signature
int validateName(char[]);
int isIdValid(int);
int isValidSalary(float);

// Function Description

int isIdValid(int id)
{
    if (id <= 0)
        return FALSE;
    if (id <= 999 && id >= 10000)
        return FALSE;
    return TRUE;
}

int validateName(char str[25])
{
    int i = 0, ch = -1;
    // len = sizeof(str)/sizeof(str[0]);
    while (i < 25 && str[i] != '\0')
    {
        ch = (int)str[i];
        if (ch == 10)
        {
            return FALSE;
        }
        if (!((ch >= 97 && ch <= 122) || (ch >= 65 && ch <= 90)))
        {
            return FALSE;
        }
        i++;
    }
    return TRUE;
}

int isValidSalary(float salary)
{
    if (salary <= 0)
        return FALSE;

    return TRUE;
}
