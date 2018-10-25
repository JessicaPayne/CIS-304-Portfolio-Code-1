// Chapter 6, Programming Challenge 15: Overloaded Hospital WITHOUT FUNCTIONS
/* Additional instructions to accompany the Overloaded Hospital function program
Read all the instructions below before starting.

Create a program that will do the following :

1.	Create and call: a void function, with a reference parameter, that asks the user
for input and  returns 'I' or 'O' to indicate in-patient or out-patient.
The following is not a function :
If a patient was in-patient, allow the user to input the following data
a. Number of days spent in the hospital
b. The daily rate
c. Hospital medication charges
d. Charges for hospital services(lab tests, etc)
If the patient is out-patient, allow the user to input the following data
a. Charges for hospital services(lab tests, etc)
b. Hospital medication charges
2.	Create a value - returning function named patientCharges that receives all the
charges for in-patient data, calculates the charges and returns only the
totalCharges to main()
3.	Create another value - returning function named patientCharges  that receives
all the charges for out-patient data, calculates the charges and returns only
the totalCharges to main().
4.	After getting the status of the patient, and the charges, call the appropriate
function, sending the needed variables to it, depending on whether the status
of the patient was in-patient or out-patient.
// Chapter 6, Programming Challenge 15: Overloaded Hospital WITHOUT FUNCTIONS
5.  Create a VOID function named printTotalcharges to print out the total charges
6.	Do not accept any negative numbers for any data.
*/
#include <iostream>
#include <iomanip>
using namespace std;

// FUNCTION PROTOTYPES
void getPatientType(char&patientType);
double patientCharges(int days, double roomRate, double medication, double services);
double patientCharges(double medication, double services);
void printTotal(double&totalCharges);


int main()
{
	char patientType;	 // I=in-patient, O=out-patient
	int days;			 // The number of days of stay
	double roomRate;     // The daily room rate
	double medication;   // Total medication charges
	double services;	 // Total for tests and other services
	double totalCharges; // Total of all charges

						 /** START OF getPatientType;  I or O. ********************************
						 CUT AND PASTE THIS TO THE NEW FUNCTION DEFINITION AND REPLACE WITH A FUNCTION
						 CALL THAT STORES THE RESULT IN patientType **/

	getPatientType(patientType);

	// Get input for in-patients
	if (patientType == 'I' || patientType == 'i')
	{
		// Get the number of days.
		cout << "Number of days in the hospital: ";
		cin >> days;

		// Validate number of days.
		while (days < 0)
		{
			cout << "Days in hospital must be zero or more. "
				<< "Please re-enter: ";
			cin >> days;
		}

		// Get the daily room rate.
		cout << "Daily room rate: $";
		cin >> roomRate;

		// Validate room rate.
		while (roomRate < 0)
		{
			cout << "Room rate must be zero or more. "
				<< "Please re-enter: $";
			cin >> roomRate;
		}
	}

	// Get medication charges.
	cout << "Medication charges: $";
	cin >> medication;

	// Validate medication.
	while (medication < 0)
	{
		cout << "Medication charges must be zero or more. "
			<< "Please re-enter: $";
		cin >> medication;
	}

	// Get lab fees and other service charges.
	cout << "Lab fees and other service charges: $";
	cin >> services;
	// Validate input.
	while (services < 0)
	{
		cout << "These charges must be zero or more. "
			<< "Please re-enter: $";
		cin >> services;
	}

	// REPLACE THE CALCULATIONS WITH THE CALL TO THE CORRECT patientCharges FUNCTION 
	// TO RETURN total charges
	if (patientType == 'I')
		//REPLACE WITH FUNCTION CALL TO patientCharges TO STORE total charges HERE
		totalCharges = patientCharges(days, roomRate, medication, services);
	else
		//REPLACE WITH FUNCTION CALL TO patientCharges TO STORE total charges HERE
		totalCharges = patientCharges(medication, services);

	/* REPLACE THE DISPLAY RESULTS SECTION WITH A FUNCTION CALL to PRINT PATIENT BILL*/
	printTotal(totalCharges);


	return 0;
}

//*****FUNCTION DEFINITIONS SHOULD GO HERE ***************/

/*********************************************************
The getPatientType function is a void function, with
reference parameter that asks the user for input and returns
'I' or 'O' to indicate in - patient or out - patient.
*********************************************************/
void getPatientType(char&patientType)
{
	cout << "This program will compute patient hospital charges.\n"
		<< "What was the patient type?\n"
		<< "In-patient or Out-patient? (I or O) ";
	cin >> patientType;

	// Validate the patient type.
	while (patientType != 'I' && patientType != 'i' &&
		patientType != 'O' && patientType != 'o')
	{
		cout << "Please enter I or O: ";
		cin >> patientType;
	}

	// Convert lowercase to uppercase.
	if (patientType == 'i')
		patientType = 'I';
	else if (patientType == 'o')
		patientType = 'O';
}
	/************END OF getPatientType  *****************************/


/*********************************************************
The patientCharges function is a value-returning function,
that receives all the charges for in-patient data, calculates the
charges and returns only the total charges to main()
*********************************************************/
double patientCharges(int days, double roomRate, double medication, double services)
{
	return days*roomRate + medication + services;
}

/*********************************************************
The patientCharges function is another OVERLOADED value-returning function
that receives all the charges for out-patient data, calculates
the charges and returns only the total charges to main().
*********************************************************/
double patientCharges(double medication, double services)
{
	return medication + services;
}
/*********************************************
Create a VOID function named printTotalcharges to print out the total charges
*******************************************************/
void printTotal(double&totalCharges)
{
	cout << fixed << showpoint << setprecision(2);
	cout << "\nThe total charges are $" << totalCharges << endl << endl;
}