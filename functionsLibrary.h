#include <stdio.h>
#include<string.h>
#include "employeeStructure.c"
#include "validation.h"


// Functions Signatures
void setEmployeeDetails(Employee [], int *);
void getEmployeeDetails(Employee []);
void printEmployeeDetails(Employee);
void deleteEmployee(Employee [], int *);
void showAllEmployeeDetails(Employee [], int *);
//Function Defination

void setEmployeeDetails(Employee employee[], int *currentIndex){
    Employee emp;
    printf("Enter Employee Id : ");
    scanf("%d", &emp.empId);
    printf("Enter First Name of the Employee: ");
    scanf("%s", emp.empFirstName);
    while(!validateName(emp.empFirstName)){
        printf("Name is not valid (Special Character, Number not allowed.\n");
        printf("Enter First Name of the Employee: ");
        scanf("%s", emp.empFirstName);
    }
    while ((getchar()) != '\n');
    printf("Enter Middle Name of the Employee: ");
    fgets(emp.empMiddleName, 25, stdin);
    if(strlen(emp.empMiddleName) == 1){
        emp.empMiddleName[0] = '\0';
    }
     while(!validateName(emp.empMiddleName)){
        printf("Name is not valid (Special Character, Number not allowed.\n");
        printf("Enter Middle Name of the Employee: ");
        scanf("%s", emp.empMiddleName);
    }
    printf("Enter last Name of the Employee: ");
    scanf("%s", emp.empLastName);
     while(!validateName(emp.empLastName)){
        printf("Name is not valid (Special Character, Number not allowed.\n");
        printf("Enter Last Name of the Employee: ");
        scanf("%s", emp.empLastName);
    }
    printf("Enter Basic Salary: ");
    scanf("%d", &emp.basicSalary);
    printf("Enter the Hire Date (DD/MM/YYYY): ");
    scanf("%d/%d/%d", &emp.hireDate.day, &emp.hireDate.month, &emp.hireDate.year);
    employee[(*currentIndex)++] = emp;
    return;
}

void getEmployeeDetails(Employee employee[]){
    int i = 0, empId;
    printf("\n\nEnter the Employee Id to show the details: ");
    scanf("%d", &empId);
    for(i = 0; i < 50; i++){
        if(employee[i].empId == empId){
            break;
        }
    }
    if(i >= 50){
        printf("\nNo Data Found!!!");
        return;
    }
    printEmployeeDetails(employee[i]);
}


void printEmployeeDetails(Employee emp){
    printf("\n==========================================================\n");
    printf("\nEmployee Id: %d", emp.empId);
    printf("\nEmployee Name: %s %s %s", emp.empFirstName, emp.empMiddleName, emp.empLastName);
    printf("\nEmployee Basic Salary: %.2f", emp.basicSalary);
    printf("\n\n==========================================================\n");
}

void deleteEmployee(Employee employee[], int *currentArrayIndexPosition){
    int empId, i, deleteIndex = -1;
    Employee emp;
    if((*currentArrayIndexPosition) == 0){
        printf("NO DATA IN THE TABlE!!!\n");
        return;
    }
    printf("Enter the Employee Id to delete: ");
    scanf("%d", &empId);
    for(i = 0; i < 50; i++){
        emp = employee[i];
        if(emp.empId == empId){
            deleteIndex = i;
            break;
        }
    }
    if(deleteIndex == -1) {
        printf("No Employee Found to delete??????\n");
        return;
    }
    for(i = deleteIndex; i < (*currentArrayIndexPosition) - 1 && i < 50 - 1; i++){
        employee[i] = employee[i + 1];
    }
    (*currentArrayIndexPosition)--;
    printEmployeeDetails(emp);
    return;
}


void showAllEmployeeDetails(Employee employee[], int *currentArrayIndexPosition){
    int i;
    for(i = 0; i < (*currentArrayIndexPosition); i++){
        printf("EMP ID : %d\n", employee[i].empId);
    }
    return;
}