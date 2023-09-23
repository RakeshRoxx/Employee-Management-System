typedef struct Date
{
    int day, month, year;
} Date;

typedef struct Employee
{
    int empId;
    char empFirstName[25];
    char empMiddleName[25];
    char empLastName[25];
    double basicSalary;
    double DA;
    double TA;
    double HRA;
    Date hireDate;
} Employee;