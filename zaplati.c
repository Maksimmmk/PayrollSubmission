#include <stdio.h>

#define TAX_RATE 0.10

struct Employee
{
    char name[50];
    float hourlyRate;
    int hoursWorked;
};

float calculateGross(float rate, int hours)
{
    return rate * hours;
}

float calculateTax(float gross)
{
    return gross * TAX_RATE;
}

float calculateNet(float gross, float tax)
{
    return gross - tax;
}

void addEmployee()
{
    struct Employee emp;
    FILE* file = fopen("employees.txt", "a");

    if (file == NULL)
    {
        printf("Error opening file.\n");
        return;
    }

    printf("Employee name: ");
    scanf("%s", emp.name);

    printf("Hourly rate: ");
    scanf("%f", &emp.hourlyRate);

    printf("Hours worked: ");
    scanf("%d", &emp.hoursWorked);

    float gross = calculateGross(emp.hourlyRate, emp.hoursWorked);
    float tax = calculateTax(gross);
    float net = calculateNet(gross, tax);

    fprintf(file, "%s %.2f %d %.2f %.2f %.2f\n",
        emp.name, emp.hourlyRate, emp.hoursWorked,
        gross, tax, net);

    fclose(file);

    printf("Employee added successfully!\n");
}

void showEmployees()
{
    FILE* file = fopen("employees.txt", "r");

    if (file == NULL)
    {
        printf("No employees found.\n");
        return;
    }

    char name[50];
    float rate, gross, tax, net;
    int hours;

    printf("\n--- Employees ---\n");

    while (fscanf(file, "%s %f %d %f %f %f",
        name, &rate, &hours,
        &gross, &tax, &net) != EOF)
    {
        printf("Name: %s\n", name);
        printf("Gross Salary: %.2f\n", gross);
        printf("Tax: %.2f\n", tax);
        printf("Net Salary: %.2f\n\n", net);
    }

    fclose(file);
}

int main()
{
    int choice;

    do
    {
        printf("\n--- Payroll Management System ---\n");
        printf("1. Add employee\n");
        printf("2. Show all employees\n");
        printf("3. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            addEmployee();
        }
        else if (choice == 2)
        {
            showEmployees();
        }
    } while (choice != 3);

    return 0;
}