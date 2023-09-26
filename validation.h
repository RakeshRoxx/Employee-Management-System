#include <ctype.h>
#define TRUE 1
#define FALSE 0
#define max_yr 9999
#define min_yr 1800

// Function Signature
int validateName(char[]);
int isIdValid(int);
int isValidSalary(float);
int isLeap(int);
int isValidDate(int, int, int);

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

int isLeap(int y)
{
    if (((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0))
        return TRUE;
    else
        return FALSE;
}

int isValidDate(int d, int m, int y)
{
    if (y < min_yr || y > max_yr)
        return FALSE;
    if (m < 1 || m > 12)
        return FALSE;
    if (d < 1 || d > 31)
        return FALSE;
    // Now we will check date according to month
    if (m == 2)
    {
        if (isLeap(y))
        {
            if (d <= 29)
                return TRUE;
            else
                return FALSE;
        }
        else
        {
            if (d <= 28)
                return TRUE;
            else
                return FALSE;
        }
    }
    // April, June, September and November are with 30 days
    if (m == 4 || m == 6 || m == 9 || m == 11)
        if (d <= 30)
            return TRUE;
        else
            return FALSE;
    return TRUE;
}
