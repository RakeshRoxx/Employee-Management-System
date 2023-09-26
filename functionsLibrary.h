#include <stdio.h>
#include <string.h>
#include "employeeStructure.c"
#include "validation.h"

// Functions Signatures
void setEmployeeDetails(Employee[], int *);
void getEmployeeDetails(Employee[]);
void printEmployeeDetails(Employee);
void deleteEmployee(Employee[], int *);
void showAllEmployeeDetails(Employee[], int *);
// Function Defination

void setEmployeeDetails(Employee employee[], int *currentIndex)
{
    Employee emp;
    printf("Enter Employee Id : ");
    scanf("%d", &emp.empId);
    printf("Enter First Name of the Employee: ");
    scanf("%s", emp.empFirstName);
    while (!validateName(emp.empFirstName))
    {
        printf("Name is not valid (Special Character, Numbers, Empty and Spaces are not allowed.\n");
        printf("Enter First Name of the Employee: ");
        scanf("%s", emp.empFirstName);
    }
    printf("Enter last Name of the Employee: ");
    scanf("%s", emp.empLastName);
    while (!validateName(emp.empLastName))
    {
        printf("Name is not valid (Special Character, Numbers, Empty and Spaces are not allowed.\n");
        printf("Enter Last Name of the Employee: ");
        scanf("%s", emp.empLastName);
    }
    printf("Enter Basic Salary: ");
    scanf("%f", &emp.basicSalary);
    while (!isValidSalary(emp.basicSalary))
    {
        printf("Enter valid salary.\n");
        printf("Enter Basic Salary: ");
        scanf("%f", &emp.basicSalary);
    }
    printf("Enter the Hire Date (DD/MM/YYYY): ");
    scanf("%d/%d/%d", &emp.hireDate.day, &emp.hireDate.month, &emp.hireDate.year);
    while (!isValidDate(emp.hireDate.day, emp.hireDate.month, emp.hireDate.year))
    {
        printf("Enter a valid date.\n");
        scanf("%d/%d/%d", &emp.hireDate.day, &emp.hireDate.month, &emp.hireDate.year);
    }

    emp.DA = emp.basicSalary * .4;
    emp.TA = emp.basicSalary * .1;
    emp.HRA = emp.basicSalary * .05;

    employee[(*currentIndex)++] = emp;
    return;
}

void getEmployeeDetails(Employee employee[])
{
    int i = 0, empId;
    printf("\n\nEnter the Employee Id to show the details: ");
    scanf("%d", &empId);
    for (i = 0; i < 50; i++)
    {
        if (employee[i].empId == empId)
        {
            break;
        }
    }
    if (i >= 50)
    {
        printf("\nNo Data Found!!!");
        return;
    }
    printEmployeeDetails(employee[i]);
}

void printEmployeeDetails(Employee emp)
{
    printf("\n==========================================================\n");
    printf("\nEmployee Id: %d", emp.empId);
    printf("\nEmployee Name: %s %s", emp.empFirstName, emp.empLastName);
    printf("\nEmployee Basic Salary: %8.2f", emp.basicSalary);
    printf("\nDA = %6.2f", emp.DA);
    printf("\nTA = %6.2f", emp.TA);
    printf("\nHRA = %6.2f", emp.HRA);
    printf("\n\n==========================================================\n");
}

void deleteEmployee(Employee employee[], int *currentArrayIndexPosition)
{
    int empId, i, deleteIndex = -1;
    Employee emp;
    if ((*currentArrayIndexPosition) == 0)
    {
        printf("NO DATA IN THE TABlE!!!\n");
        return;
    }
    printf("Enter the Employee Id to delete: ");
    scanf("%d", &empId);
    for (i = 0; i < 50; i++)
    {
        emp = employee[i];
        if (emp.empId == empId)
        {
            deleteIndex = i;
            break;
        }
    }
    if (deleteIndex == -1)
    {
        printf("No Employee Found to delete??????\n");
        return;
    }
    for (i = deleteIndex; i < (*currentArrayIndexPosition) - 1 && i < 50 - 1; i++)
    {
        employee[i] = employee[i + 1];
    }
    (*currentArrayIndexPosition)--;
    printEmployeeDetails(emp);
    return;
}

void showAllEmployeeDetails(Employee employee[], int *currentArrayIndexPosition)
{
    int i;
    if (*currentArrayIndexPosition == 0)
    {
        printf("No Data Available.\n\n");
        return;
    }
    printf("Employee ID\t First Name\tLast Name\tBasic Salary\tDA\tTA\tHRA\tHire Date\n");
    for (i = 0; i < (*currentArrayIndexPosition); i++)
    {
        printf("%d\t\t%s\t\t%s\t\t%6.2f\t%6.2f\t%6.2f\t%6.2f\t\t%d/%d/%d\n", employee[i].empId, employee[i].empFirstName, employee[i].empLastName, employee[i].basicSalary, employee[i].DA, employee[i].TA, employee[i].HRA, employee[i].hireDate.day, employee[i].hireDate.month, employee[i].hireDate.year);
    }
    return;
}