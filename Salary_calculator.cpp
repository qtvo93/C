#include<fstream>
#include<iostream>
#include<iomanip>

using namespace std;

class employee
{
public:
	double salary, hourlyRate, taxRate, taxAmount, grossPay, netPay, otPay;
	int hours, otHours;

	int payStat;
	int employeeID;
	string firstName;
	string lastName;
	string department;

public:
	void setVariables(int empID, string fName, string lName,string depa, int stat, int rate, int hrs)
	{
		employeeID = empID;
		firstName = fName;
		lastName = lName;
		department = depa;
		payStat = stat;

		if (payStat == 1)
		{
			hourlyRate = rate;
		}
		else
		{
			salary = rate;
		}

		hours = hrs;
	}

public:
	virtual double calculateGrossPay() = 0;

	double calculateTaxAmount()
	{
		taxRate = .30;
		taxAmount = grossPay * taxRate;
		return taxAmount;
	}

	double calculateNetPay()
	{
		netPay = grossPay - taxAmount;
		return netPay;
	}

	void printData()
	{
		cout << setprecision(2) << setiosflags(ios::fixed | ios::showpoint);
		cout << firstName << setw(6) << lastName << setw(6) << employeeID << department 
			<<setw(6)<< setw(10) << hours << setw(3)
			<< otHours << setw(8) << grossPay << setw(8) << netPay << setw(8) << otPay << endl;
	}
};

class employeeSalary : public employee
{
public:
	double calculateGrossPay()
	{
		double regPay = hours * hourlyRate;
		double hourlyRate = ((salary / 52) / 40);
		if (hours > 40)
		{
			otHours = (hours - 40);
			otPay = (otHours * hourlyRate);
			grossPay = (regPay + otPay);
		}
		else if (hours <= 40)
		{
			otHours = 0; otPay = 0; grossPay = regPay;
		}

		return grossPay;
	}
};

class employeeHourly : public employee
{
public:
	double calculateGrossPay()
	{
		const double regPay = (40 * hourlyRate);

		if (hours > 40)
		{
			otHours = (hours - 40);
			otPay = (otHours * hourlyRate * 1.5);
			grossPay = (regPay + otPay);
		}
		else
		{
			otHours = 0;
			otPay = 0;
			grossPay = regPay;
		} 

		return grossPay;
	}
};

int main()
{
	int employeeCounter = 0;
	int totalEmployeeCount = 0;

	string fName, lName, department;
	int empID = 0, stat = 0, rate = 0, hrs = 0;

	cout << "enter # of employees you want to process:  ";
	cin >> totalEmployeeCount;

	employee* employee[100];

	while (employeeCounter < totalEmployeeCount)
	{
		cout << "Is employee " << employeeCounter + 1 << 
			" hourly or salary? (enter 1 for hourly / 2 for salary):";
		cin >> stat;

		if (stat == 1)
		{
			

			cout << "Enter employee's ID: ";
			cin >> empID;
			cout << "Enter employee's first name: ";
			cin >> fName;
			cout << "Enter employee's last name: ";
			cin >> lName;
			cout << "Enter employee's department: ";
			cin >> department;
			cout << "Enter employee's hourly wage: ";
			cin >> rate;
			cout << "Enter employee's hours for this week: ";
			cin >> hrs;

			employee[employeeCounter] = new employeeHourly();
			employee[employeeCounter]->setVariables(empID, fName, lName, depa, stat, rate, hrs);
			employee[employeeCounter]->calculateGrossPay();
			employee[employeeCounter]->calculateTaxAmount();
			employee[employeeCounter]->calculateNetPay();
			cout << endl << endl;
			employeeCounter++;
		}
		else
		{
			
			cout << "Enter employee's ID: ";
			cin >> empID;
			cout << "Enter employee's first name: ";
			cin >> fName;
			cout << "Enter employee's last name: ";
			cin >> lName;
			cout << "Enter employee's department: ";
			cin >> department;
			cout << "Enter employee's hourly wage: ";
			cin >> rate;
			cout << "Enter employee's hours for this week: ";
			cin >> hrs;
			employee[employeeCounter] = new employeeHourly();
			employee[employeeCounter]->setVariables(empID, fName,depa, lName, stat,
				rate, hrs);
			employee[employeeCounter]->calculateGrossPay();
			employee[employeeCounter]->calculateTaxAmount();
			employee[employeeCounter]->calculateNetPay();
			cout << endl << endl;
			employeeCounter++;
		}
	}

	cout << "-----------------------------------------\n";

	for (int i = 0; i < employeeCounter; ++i)
	{
		employee[i]->printData();
	}

	cout << "-----------------------------------------\n";

	return 0;