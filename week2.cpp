#include<iostream>
#include<string>
#include<iomanip>

using namespace std;
#define max 30
struct record
{
	string name;
	float paid;
};

float Facility_Cost(int NoP,float & CostCoach,float & CostMeal,float & CostTh);
int Coach_Capacity(float cost);
void Outing_Record(record outing[max], int num);
void Profit(float earned);
float PaidByPeople(record outing[max], int Nop);

int main()
{
	record outing[max] = {};
	int TotalPeople, NoSenCit, NoCarer,CoachCapacity;
	float CostPerPerson,CostTotal, CostMeal, CostCoach, CostTh, NewCostTotal,Paid,earned;
	const int MinSeniorCitizen = 10, MaxSeniorCitizen = 36;
	bool loop;
	do {
		cout 
			<< "How many Senior Citizen are coming for outing (Min=10 and Max=36) : ";
		cin >> NoSenCit;
		loop = (NoSenCit >= MinSeniorCitizen && NoSenCit <= MaxSeniorCitizen);
		if (!loop)
			cout << "Invalid Input....";
	} while (!loop);
	//decide no of carers
	if (NoSenCit <= 24)
		NoCarer = 2;
	else
		NoCarer = 3;
	cout << endl
		 << "Your Total carers Would be "
		 << NoCarer;
	//Total people
	TotalPeople = NoSenCit + NoCarer;
	cout << endl
		 << "The total number of people (Including carers) going on Outing will be : "
		 << TotalPeople;
	//cost
	CostTotal=Facility_Cost(TotalPeople, CostCoach, CostMeal, CostTh);
	cout << endl
		<< "Cost for a coach for " << TotalPeople << " will be : "
		<< CostCoach << "$" << endl
		<< "Cost for meal per person for " << TotalPeople << " will be : "
		<< CostMeal << "$" << endl
		<< "Cost for theater tickets for " << TotalPeople << " will be : "
		<< CostTh << "$" << endl
		<< "\nTotal cost for meal for " << TotalPeople << " will be : "
		<< CostMeal * TotalPeople << "$" << endl
		<< "Total cost for theater Tickets for " << TotalPeople << " will be : "
		<< CostTh * TotalPeople << "$" << endl
		<< "\nTOTAL COST : " << CostTotal<< "$"
		<< endl;
	// payable cost
	CostPerPerson = CostTotal / NoSenCit;
	cout << endl
		<< "Total Senior Citizen : " << NoSenCit
		<< endl
		<< "Cost per each senior citizen : " << CostPerPerson << "$"
		<< endl
		<< "Total Carers : " << NoCarer
		<< endl
		<< "Cost per Carer : 0$"
		<< endl;
	// TASK 2
	cout << endl
		<< "Enter The names of senior citizens going on outing and "
		<< "the amount paid by each."
		<< endl
		<< "Payable Amount by each: " << CostPerPerson 
		<< endl;
	for (int i = 0; i < TotalPeople; i++)
	{
		if (i < NoSenCit)
		{
			cout
				<< "Enter the name of the Senior Citizen Sr." << i + 1 << ":";
			getline(cin >> ws, outing[i].name);
			cout
				<< "Enter the amount paid by " << outing[i].name << " Sr." << i + 1 << " : ";
			cin >> outing[i].paid;
		}
		else
		{
			cout << endl
				<< "Enter the name of the Carer Sr." << i + 1 << ":";
			getline(cin >> ws, outing[i].name);
			cout
				<< "The amount paid by Carer" << outing[i].name << " Sr." << i + 1 << " : 0$";
		}
 	}
	// Coach capacity
	CoachCapacity = Coach_Capacity(CostCoach);
	int availableSpace = abs(TotalPeople - CoachCapacity);
	char choice;
	cout << endl
		<< "The overall Coach capacity is : " << CoachCapacity
		<< endl
		<< "Space Available for more people : " << availableSpace 
		<< endl;
	if (availableSpace == 0)
		cout << "No morer people can be added";
	else
	{
		cout << "Do you want to add more people (press Y for yes or any other key to continue) : ";
		cin >> choice;
		choice=tolower(choice);
	}
	if (choice == 'y')
	{
		cout << endl
			<< "Enter The names of new people going on outing and "
			<< "the amount paid by each."
			<< endl
			<< "Payable Amount by each: " << CostPerPerson
			<< endl;
		int NewPeople = 0;
		for (int i = TotalPeople; i < CoachCapacity && choice == 'y'; i++)
		{

			cout << endl
				<< "Enter the name of the Person Sr." << i + 1 << ":";
			getline(cin >> ws, outing[i].name);
			cout
				<< "Enter the amount paid by " << outing[i].name << " Sr." << i + 1 << " : ";
			cin >> outing[i].paid;
			NewPeople++;
			cout << endl 
				<< "Do you want to add more people (press Y for yes or any other key to exit) : ";
			cin >> choice;
			choice = tolower(choice);
			cout << endl;
		}
		CostTotal = CostTotal + (NewPeople * CostPerPerson);
	    TotalPeople=NewPeople+TotalPeople;
		cout << "New Amount of people : " << TotalPeople;
		Outing_Record(outing, TotalPeople);
		cout << endl <<
			"After adding more people The Total Cost: " << CostTotal;

	}
	else
	{
		cout << endl
			<< "No new people are added."
			<< endl;
		Outing_Record(outing, TotalPeople);
		cout 
			<< "Total money collected : " << CostTotal
			<< endl;
	}
	
	Paid=PaidByPeople(outing, TotalPeople);
	cout << endl << "Money Paid by people : " << Paid;
	earned = Paid - CostTotal;
	Profit(earned);
	return 0;
}


void Profit(float earned)
{
	cout << endl;
	if (earned == 0)
		cout << "No profit made :/";
	else if (earned < 0)
		cout << "Lost " << earned << "$ :(";
	else if (earned > 0)
		cout << "Made " << earned << "$ :)";
}

float PaidByPeople(record outing[max],int Nop)
{
	float add=0;
	for (int i = 0; i < Nop; i++)
	{
		add = add + outing[i].paid;
	}
	return add;
}



int Coach_Capacity(float cost)
{
	if (cost == 150)
		return 16;
	else if (cost == 190)
		return 26;
	else if (cost == 225)
		return 39;
}
float Facility_Cost(int Num, float& CostCoach, float& CostMeal, float& CostTheater)
{
	if (Num >= 12 && Num <= 16)
	{
		CostCoach = 150;
		CostMeal = 14.00;
		CostTheater = 21.00;
	}
	else if (Num >= 17 && Num <= 26)
	{
		CostCoach = 190;
		CostMeal = 13.50;
		CostTheater = 20.00;
	}
	else if (Num >= 27 && Num <= 39)
	{
		CostCoach = 225;
		CostMeal = 13.00;
		CostTheater = 19.00;
	}
	return  (CostCoach + (CostMeal * Num) + (CostTheater * Num));
}
void Outing_Record(record outing[max], int num)
{
	cout << endl
		<< left << setw(4) << "Sr."
		<< left << setw(15) << "Person Name"
		<< left << setw(7) << "Paid"
		<< endl;
	for (int i = 0; i < num; i++)
	{
		cout << left << setw(4) << i + 1 << " ";
		cout << left << setw(15) << outing[i].name << " ";
		cout << left << setw(7) << outing[i].paid << " ";
		cout << endl;
	}
}