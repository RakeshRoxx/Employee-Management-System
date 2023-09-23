#include <stdio.h>
#include <stdlib.h>
#include "functionsLibrary.h"

int main(int argc, char *argv[])
{
    int currentArrayIndexPosition = 0, ch = 5;
    Employee employee[50];

    while (1)
    {
        printf("\n1->Add Employee Details\n2->Show Employee Details\n3->Show All Employee\n4->Delete Employee Details\n5->EXIT\n");
        printf("Enter your choice:  ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            setEmployeeDetails(employee, &currentArrayIndexPosition);
            break;
        case 2:
            getEmployeeDetails(employee);
            break;
        case 3:
            showAllEmployeeDetails(employee, &currentArrayIndexPosition);
            break;
        case 4:
            deleteEmployee(employee, &currentArrayIndexPosition);
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("wrong choice............\n");
        }
    }

    return 0;
}