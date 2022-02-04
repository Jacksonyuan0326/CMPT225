#include"List.h"
#include"Patient.h"
#include<iostream>
using namespace std;

string checkString(const string& str)
{
	
	//check if is an address
	for (int i = 0; i < str.size(); i++)
		for (int j = 1; j < str.size(); j++)
			if (str.at(i) > 47 && str.at(i) < 58 && str.at(j) > 64)
				return "address";

	//check if the string is phone number
	for(int i = 0; i < str.size(); i++)
		if(str.at(i) == 45)
			return "phone";
	
	//check if the string is email
	for(int i = 0; i < str.size(); i++)
		if(str.at(i) == 46 || str.at(i) == 64) //judge email with "." or "@"
			return "email";
	
	//last option is name
	return "name";
}
Patient enterAPatient(string name, string address, string phone, string careCard, string email)
{
	Patient p1;
	cout << "Please enter the carecard number for patient!" << endl;
	cin >> careCard;
	cout << "Would you like to add more information for this patient? Y or N." << endl;
	string ans;
	if (ans == "N")
		return p1;
	
	else {
		cout << "Please enter your name OR TBD(To be entered)!" << endl;
		cin >> name;
		if (checkString(name) == "name" || name == "TBD")
		{
			p1.setName(name);
			cout << "Name enter correctly! Please enter your address OR TBD(To be entered)!" << endl;
			cin >> address;
			if (checkString(address) == "address" || address == "TBD") {
				p1.setAddress(address);
				cout << "Address enter correctly!Please enter your phone OR TBD(To be entered)!" << endl;
				cin >> phone;
				if (checkString(phone) == "phone" || phone == "TBD") {
					p1.setPhone(phone);
					cout << "Phone enter correctly! Please enter your email OR TBD(To be entered)!" << endl;
					cin >> email;
					if (checkString(email) == "email" || email == "TBD")
					{
						return p1;
					}
				}
			}
		}
	}
}
int main()
{
	int num;
	List list;
	Patient p;
	string name, address, phone, careCard, email;
	do {
		cout << "What can I help you? Choose from menu. Enter number" << endl; // give 6 option from different function
		cout << "1. Insert your information into the database " << endl
			<< "2. Search information in the database." << endl
			<< "3. Delete your information from the database." << endl
			<< "4. Print your information from the information." << endl
			<< "5. Modify your information in the database." << endl
			<< "6. Exit" << endl; //end of menu
		cin >> num;//need user to enter the option

		//Option 1:insert a Patient to list
		if (num == 1) {

			p = enterAPatient(name, address, phone, careCard, email);

			if (list.search(p) == NULL)
			{
				if (list.insert(p))
					cout << "The patient has been insert into the database." << endl;
			}
			else
			{
				cout << "The patient has already in the database!" << endl;
			}
		}

		//Option 2: search a patient from the list
		else if (num == 2)
		{
			cout << "Enter the patient information in order to search in the database." << endl;
			p = enterAPatient(name, address, phone, careCard, email);
			cout << "The patient : " << list.search(p) << "has been found!";
		}

		//Option 3: delete a patient from the list
		else if (num == 3)
		{
			cout << "Enter the patient information in order to delete in the database." << endl;
			p = enterAPatient(name, address, phone, careCard, email);
			if (list.remove(p))
				cout << "The patient :" << p.getCareCard() << " - " << p.getName() << "has been deleted!" << endl;
		}

		//Option 4: print the list in descending order
		else if (num == 4)
		{
			list.printList();
		}

		//Option 5: Modify the patient information in the list
		else if (num == 5);
		{
			int ans;
			cout << "Which patient you want to update?" << endl;
			cout << "Enter the patient information in order to update in the database." << endl;
			p = enterAPatient(name, address, phone, careCard, email);
			list.remove(p);
			cout << "Which part you want to update?" << endl;
			cout << "1.Name		2.Address	3.Phone		4.Email" << endl;
			cin >> ans;
			string change;
			if (ans == 1) {
				cout << "Please enter the information! " << endl;
				cin >> change;
				p.setName(change);
			}
			else if (ans == 2)
			{
				cout << "Please enter the information! " << endl;
				cin >> change;
				p.setAddress(change);
			}
			else if (ans == 3)
			{
				cout << "Please enter the information! " << endl;
				cin >> change;
				p.setPhone(change);
			}
			else if (ans == 4)
			{
				cout << "Please enter the information! " << endl;
				cin >> change;
				p.setEmail(change);
			}
			if (list.insert(p))
				cout << "The information has updated!" << endl;
		}
	}while(num != 6);//while key in 6 to exit the program



	cout << "Good bye! Have a good day!" << endl;//end of the whole program

	system("pause");
	return 0;
}