typedef struct Date
{
    int day, month, year;
} Date;

typedef struct Employee
{
    int empId;
    char empFirstName[25];
    char empLastName[25];
    float basicSalary;
    float DA;
    float TA;
    float HRA;
    Date hireDate;
} Employee;