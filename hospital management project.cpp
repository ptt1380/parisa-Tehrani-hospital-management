// hospital management project.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<string>
#include<iomanip>
#include<conio.h>
#include<vector>
#include<fstream>
using namespace std;
void reportMenu();
void entryMenu();
void intro();
 

class Person
{

protected:
	string firstname, lastname, phone, address;
	int age;

public:
	Person();
	Person(string, string, string, string, int );
	void setFirstname(string);
	void setLastname(string);
	void setPhone(string);
	void setAddress(string);
	void setAge(int);
	string getFirstname() const;
	string getLastname() const;
	string getPhone()const;
	string getAddress()const;
	int getAge()const;
	void report() const;
};

class Doctor: public Person
{
private:
	string doctor_code;
	string patient_Id;
	string proficiency;
public:
	Doctor();
	Doctor(string, string, string, string, int, string, string, string);
	void setDoctorCode(string);
	void setPatientId(string);
	void setProficiency(string);
	string getDoctorCode() const;
	string getPatientId() const;
	string getProficiency() const;
	void report() const;
};

class Patient : public Person
{
private:
	string disease;
	string patient_Id;
	string doctor_name;
	string doctor_code;
public:
	Patient();
	Patient(string, string, string, string, int, string, string, string , string );
	void setPatientId(string);
	void setDisease(string);
	void setDoctorName(string);
	void setDoctorCode(string);
	string getPatientId() const;
	string getDisease() const;
	string getDoctorName() const;
	string getDoctorCode() const;
	void report() const;
	 
};

int main()
{
	intro();
	int c;
	do
	{
		system("cls");
		cout << "\n\n\n\tMAIN MENU";
		cout << "\n\n\t1=REPORT MENU";
		cout << "\n\n\t2=ENTRY/EDIT MENU";
		cout << "\n\n\t3=EXIT";
		cout << "\n\n\tplease choose a section(1-3): ";
		cin >> c;
		system("cls");

		switch (c)
		{
		case 1: reportMenu();  break;
		case 2: entryMenu(); break;
		case 3:break;
		default:cout << "you should enter a number between(1-3)\n\nplease try again!\n\n";break;
		}
	} while (c!=3);
 
    return 0;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++methods of person's class++++++++++++++++++++++++++++++++++++++++++

Person::Person(){}

Person::Person(string firstname, string lastname, string phone, string address, int age)
{
	this->firstname = firstname;
	this->lastname = lastname;
	this->phone = phone;
	this->address = address;
	this->age = age;
}

void Person::setFirstname(string firstname)
{
	this->firstname = firstname;
}

void Person::setLastname(string lastname)
{
	this->lastname = lastname;
}

void Person::setPhone(string phone)
{
	this->phone = phone;
}

void Person::setAddress(string address)
{
	this->address = address;
}

void Person::setAge(int age)
{
	this->age = age;
}

string Person::getFirstname() const
{
	return firstname;
}

string Person::getLastname() const
{
	return lastname;
}

string Person::getPhone()const
{
	return phone;
}

string Person::getAddress()const
{
	return address;
}

int Person::getAge()const
{
	return age;
}

void Person::report() const
{
	cout << firstname << setw(6) << " " << lastname << setw(10) << address << setw(4) << phone << setw(4) << age << endl;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++methods of patient's class+++++++++++++++++++++++++++++++++++++++++++++++

Patient::Patient(){}

Patient::Patient(string firstname, string lastname, string phone, string address, int age, string patient_Id, string disease, string doctor_name , string doctor_code): Person(firstname,lastname,phone,address,age)
{
	this->patient_Id = patient_Id;
	this->disease = disease;
	this->doctor_name = doctor_name;
	this->doctor_code = doctor_code;
}

void Patient::setPatientId(string patient_Id)
{
	this->patient_Id = patient_Id;
}

void Patient::setDoctorName(string doctor_name)
{
	this->doctor_name = doctor_name;
}

void Patient::setDoctorCode(string doctor_code)
{
	this->doctor_code = doctor_code;
}

void Patient::setDisease(string disease)
{
	this->disease = disease;
}

string Patient::getDisease() const { return disease; }

string Patient::getDoctorName() const { return doctor_name; }

string Patient::getPatientId() const { return patient_Id; }

string Patient::getDoctorCode() const { return doctor_code; }

void Patient::report() const
{
	cout << firstname << setw(6) << " " << lastname << setw(10) << address << setw(4) << phone << setw(4) << age << setw(4) << patient_Id << setw(4) << disease << setw(4) << doctor_name<<setw(4)<<doctor_code<< endl;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++methods of doctor's class+++++++++++++++++++++++++++++++++++++++++

Doctor::Doctor(){}

Doctor::Doctor(string firstname, string lastname, string phone, string address, int age, string doctor_code, string proficiency, string patient_Id) : Person(firstname, lastname, phone, address, age)
{
	this->doctor_code = doctor_code;
	this->patient_Id = patient_Id;
	this->proficiency = proficiency;
}

void Doctor::setDoctorCode(string doctor_code)
{
	this->doctor_code = doctor_code;
}

void Doctor::setPatientId(string patient_Id)
{
	this->patient_Id = patient_Id;
}

void Doctor::setProficiency (string proficiency)
{
	this->proficiency = proficiency;
}

string Doctor::getDoctorCode() const { return doctor_code; }

string Doctor::getProficiency() const { return proficiency; }

string Doctor::getPatientId() const { return patient_Id; }

void Doctor::report() const
{
	cout << firstname << setw(10) << "  " << lastname << setw(4) << "  " << address << setw(4) << "  " << phone << setw(4) << "  " << age << setw(4) << "  " << patient_Id << setw(4) << "  " << proficiency << setw(4) << "  " << doctor_code << endl;
}

//+++++++++++++++++++++++++++++++++++++++++++++++Patient++++++++++++++++++++++++++++++++++++++++++++++++++++

vector<Patient>listP, listP2;
vector<Doctor>listD, listD2;
fstream Patient_Info;
fstream Doctor_Info;

void  write_Patient_Info()
{
	string firstname, lastname, phone, address, disease, patient_Id, doctor_name, doctor_code;
	int age;
	cout << "firstname: ";
	cin >> firstname;
	cout << "lastname: ";
	cin >> lastname;
	cout << "phone number: ";
	cin >> phone;
	cout << "address: ";
	cin >> address;
	cout << "age: ";
	cin >> age;
	cout << "disease: ";
	cin >> disease;
	cout << "doctor's name:";
	cin >> doctor_name;
	cout << "patient's Id:";
	cin >> patient_Id;
	cout << "doctor's code:";
	cin >> doctor_code;
	listP.push_back(Patient(firstname, lastname, phone, address, age, patient_Id, disease, doctor_name, doctor_code));
	Patient_Info.open("Patient.csv", ios::app);
	Patient_Info << firstname + "," + lastname + "," + phone + "," + address + "," + to_string(age) + "," + patient_Id + "," + disease + "," + doctor_name+","<<doctor_code << endl;
	Patient_Info.close();
}

void displayAllpa()
{
	system("cls");
	cout << "\n\n\t\t information of patients\n\n";
	cout << "=========================================================================================================================\n\n";
	cout << "firstname      lastname          address    phone    age    paient Id    disease    doctor's name    doctor's code\n\n";
	cout << "=========================================================================================================================\n\n";
	for (int i = 0; i < listP.size() ; i++)
	{
		listP[i].report();
	}

	cout << "\n\n number of patients= " << listP.size() << endl;
}

void displayOnePa(string codePa )
{
	system("cls");
	cout << "\n\n\t\t information of patients\n\n";
	cout << "=========================================================================================================================\n\n";
	cout << "firstname      lastname          address    phone    age    paient Id    disease    doctor's name    doctor's code\n\n";
	cout << "=========================================================================================================================\n\n";
	for (int i = 0; i < listP.size(); i++)
	{
		if(listP[i].getPatientId()==codePa)
		listP[i].report();
	}
}

void  modify_Patient_Info()
{
	string firstname, lastname, phone, address, disease, patient_Id, doctor_name,doctor_code;
	int age;
	string id;
	cout << "enetr the patient Id :";
	cin >> id;
	for (int i = 0; i < listP.size(); i++)
	{
		if (listP[i].getPatientId() == id)
		{
			int s;
			 
				cout << "which one do you want to modify?" << endl;
				cout << "1-firstname" << endl;
				cout << "2-lastname" << endl;
				cout << "3-phone" << endl;
				cout << "4-address" << endl;
				cout << "5-disease" << endl;
				cout << "6-patient Id" << endl;
				cout << "7-doctor's name" << endl;
				cout << "8=doctor's code" << endl;
				cout << "9=doctor's age" << endl;
				cout << "section: ";
				cin >> s;
				switch (s)
				{
				case 1:cout << "enetr firstname: "; cin >> firstname; listP[i].setFirstname(firstname);break;
				case 2:cout << "enetr lastname: "; cin >> lastname; listP[i].setLastname(lastname);break;
				case 3:cout << "enetr phone: "; cin >> phone; listP[i].setPhone(phone);break;
				case 4:cout << "enetr address: "; cin >> address; listP[i].setAddress(address);break;
				case 5:cout << "enetr disease: "; cin >> disease; listP[i].setDisease(disease);break;
				case 6:cout << "enetr patient Id: "; cin >> patient_Id; listP[i].setPatientId(patient_Id);break;
				case 7:cout << "enetr doctor's name: "; cin >> doctor_name; listP[i].setDoctorName(doctor_name);break;
				case 8:cout << "enter doctor's code: "; cin >> doctor_code; listP[i].setDoctorCode(doctor_code); break;
				case 9:cout << "enter doctor's age: "; cin >> age; listD[i].setAge(age);break;
				default: break;
				}
		}
	}

}

void deleteAllPa() { listP.clear(); }

void deleteOnePa(string id)
{
	for (int i = 0; i < listP.size(); i++)
	{
		if (listP[i].getPatientId() != id)
			listP2.push_back(listP[i]);
	}
	listP = listP2;
	vector<Patient>().swap(listP2);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++Doctor+++++++++++++++++++++++++++++++++++++++++++++++++++

void  write_Doctor_Info()
{
	string firstname, lastname, phone, address, proficiency, patient_Id, doctor_code;
	int age;
	cout << "firstname: ";
	cin >> firstname;
	cout << "lastname: ";
	cin >> lastname;
	cout << "phone number: ";
	cin >> phone;
	cout << "address: ";
	cin >> address;
	cout << "age: ";
	cin >> age;
	cout << "proficiency: ";
	cin >> proficiency;
	cout << "doctor's code:";
	cin >> doctor_code;
	cout << "patient's Id:";
	cin >> patient_Id;
	listD.push_back(Doctor(firstname, lastname, phone, address, age, doctor_code, proficiency, patient_Id));
	Doctor_Info.open("Doctor.csv", ios::app);
	Doctor_Info << firstname + "," + lastname + "," + phone + "," + address + "," + to_string(age) + "," + patient_Id + "," + proficiency + "," + doctor_code << endl;
	Doctor_Info.close();
}

void displayAllDoc()
{
	system("cls");
	cout << "\n\n\t\t information of Doctors\n\n";
	cout << "==========================================================================================================\n\n";
	cout << "firstname"<<setw(10)<<"  "<<"lastname"<<setw(4)<< "  " << "address"<<setw(4)<< "  " << "phone"<<setw(4)<< "  " << "age"<<setw(4) << "  " << "paient Id"<< setw(4)<< "  " << "proficiency"<< setw(4)<< "  " << "doctor's code\n\n";
	cout << "==========================================================================================================\n\n";
	for (int i = 0; i < listD.size(); i++)
	{
		listD[i].report();
	}

	cout << "\n\n number of doctors= " << listD.size() << endl;
}

void displayOneDoc(string codeDoc)
{
	system("cls");
	cout << "\n\n\t\t information of patients\n\n";
	cout << "=========================================================================================================\n\n";
	cout << "firstname      lastname          address    phone    age    paient Id    proficiency    doctor's code\n\n";
	cout << "=========================================================================================================\n\n";
	for (int i = 0; i < listD.size(); i++)
	{
		if (listD[i].getDoctorCode() == codeDoc)
			listD[i].report();
	}
}

void  modify_Doctor_Info()
{
	string firstname, lastname, phone, address, proficiency, patient_Id, doctor_code;
	int age;
	string id;
	cout << "enetr the doctor Id :";
	cin >> id;
	for (int i = 0; i < listD.size(); i++)
	{
		if (listD[i].getDoctorCode() == id)
		{
			int s;

			cout << "which one do you want to modify?" << endl;
			cout << "1-firstname" << endl;
			cout << "2-lastname" << endl;
			cout << "3-phone" << endl;
			cout << "4-address" << endl;
			cout << "5-proficiency" << endl;
			cout << "6-patient Id" << endl;
			cout << "7-doctor's code" << endl;
			cout << "8=age" << endl;
			cout << "section: ";
			cin >> s;
			switch (s)
			{
			case 1:cout << "enetr firstname: "; cin >> firstname; listD[i].setFirstname(firstname);break;
			case 2:cout << "enetr lastname: "; cin >> lastname; listD[i].setLastname(lastname);break;
			case 3:cout << "enetr phone: "; cin >> phone; listD[i].setPhone(phone);break;
			case 4:cout << "enetr address: "; cin >> address; listD[i].setAddress(address);break;
			case 5:cout << "enetr proficiency: "; cin >> proficiency; listD[i].setProficiency(proficiency);break;
			case 6:cout << "enetr patient Id: "; cin >> patient_Id; listD[i].setPatientId(patient_Id);break;
			case 7:cout << "enetr doctor's code: "; cin >> doctor_code; listD[i].setDoctorCode(doctor_code);break;
			case 8:cout << "enetr doctor's age: "; cin >> age; listD[i].setAge(age);break;
			default: break;
			}
		}
	}

}

void deleteAllDoc() { listD.clear(); }

void deleteOneDoc(string id)
{
	for (int i = 0; i < listD.size(); i++)
	{
		if (listD[i].getDoctorCode()!= id)
			listD2.push_back(listD[i]);
	}
	listD = listD2;
	vector<Doctor>().swap(listD2);
}

void patients_List()
{
	system("cls");
	string code;
	cout << "enter doctor's code: ";
	cin >> code;
	cout << "firstname  lastname  disease\n\n";
	for (int i = 0; i < listP.size(); i++)
	{
		if (listP[i].getDoctorCode() == code)
			cout << listP[i].getFirstname() << "  " << listP[i].getLastname() << "  " << listP[i].getDisease() << "\n\n";
	}
}
//++++++++++++++++++++++++++++++++++++++++++++++++++Menu++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void intro() 
{
	system("cls");
	cout << "\n\n\n\t\t Hospital Management System";
	cout << "\n\n\t\t ADVANCED C++ PROJECT";
	cout << "\n\n\t\t MADE BY : Parisa Tinaye tehrani";
	cout << "\n\n\t\t SCHOOL: QOM UNIVERSITY";
	cin.get();
}

void reportMenu()
{
	int a, e, f;
	string id;
	system("cls");
	cout << "\n\n\n\tREPORT MENU";
	cout << "\n\n\n\t1=REPORTS";
	cout << "\n\n\n\t2=BACK TO THE MAIN MENU";
	cout << "\n\n\n\tenter your choice(1-2):";
	cin >> a;

	switch (a)
	{
	case 1:
		system("cls");
		cout << "\n\n\n\tREPORTS MENU";
		cout << "\n\n\t1=Patient Reports";
		cout << "\n\n\t2=Doctor Reports";
		cout << "\n\n\n\tenter your choice(1-2):";

		cin >> e;

		switch (e)
		{
		case 1:
			system("cls");
			cout << "\n\n\t1=All Patients' Reports";
			cout << "\n\n\t2=Patient's Report";
			cout << "\n\n\t3=Show Patients' list";
			cout << "\n\n\n\tenter your choice(1-3):";
			cin >> f;
			switch (f)
			{
			case 1:displayAllpa(); _getch(); break;
			case 2:cout << "enter id of the patient: "; cin >> id; displayOnePa(id); _getch(); break;
			case 3: patients_List(); _getch(); break;
			default:
				break;
			}
			break;
		case 2:
			system("cls");
			cout << "\n\n\t1=All Doctors' Reports";
			cout << "\n\n\t2=Doctor's Report";
			cout << "\n\n\n\tenter your choice(1-2):";
			cin >> f;
			switch (f)
			{
			case 1:displayAllDoc(); _getch(); break;
			case 2:cout << "enter id of the Doctor: "; cin >> id; displayOneDoc(id); _getch(); break;
			default:
				break;
			}
			break;
		default:
			break;
		}
		break;
	case 2:break;
	default:
		break;
	}

}

void entryMenu()
{
	int a;
	string num;
	char choice;
	system("cls");
	cout << "\n\n\n\tENTRY MENU";
	cout << "\n\\n\n\t1=ENTRY MENU PATIENT";
	cout << "\n\\n\n\t2=ENTRY MENU DOCTOR";
	cout << "\n\\n\n\t3=BACK TO THE MAIN MENU";
	cout << "\n\\n\n\tplease enter your choice(1-3):";
	
	cin >> a;
	
	switch (a)
	{
	case 1:
		system("cls");
		cout << "\n\n\n\tENTRY MENU PATIENT";
		cout << "\n\\n\n\t1=CREATE PATIENT RECORD";
		cout << "\n\\n\n\t2=MODIFY PATIENT RECORD";
		cout << "\n\\n\n\t3=DELETE PATIENT RECORD";
		cout << "\n\\n\n\t4=DELETE PATIENT RECORDS";
		cout << "\n\\n\n\t5=BACK TO THE MAIN MENU";
		cout << "\n\\n\n\tplease enter your choice(1-5):";
		cin >> a;
		switch (a)
		{
		case 1:
			do
			{
				write_Patient_Info();
				cout << "\n patient record has been created";

				system("cls");
				cout << "Do you want to insert new record of patient?(Y|N)";
				cin >> choice;
				system("cls");
			} while (choice == 'y' || choice == 'Y');
			break;
		case 2:modify_Patient_Info(); break;
		case 3:cout << "enter id of the patient: "; cin >> num; deleteOnePa(num); break;
		case 4:deleteAllPa(); break;
		case 5:break;
		default:
			cout << "you should enter a number between(1-5)\n\ntry again!";
			break;
		}
		break;
	case 2: 
		system("cls");
		cout << "\n\n\n\tENTRY MENU DOCTOR";
		cout << "\n\\n\n\t1=CREATE DOCTOR RECORD";
		cout << "\n\\n\n\t2=MODIFY DOCTOR RECORD";
		cout << "\n\\n\n\t3=DELETE DOCTOR RECORD";
		cout << "\n\\n\n\t4=DELETE DOCTOR RECORDS";
		cout << "\n\\n\n\t5=BACK TO THE MAIN MENU";
		cout << "\n\\n\n\tplease enter your choice(1-5):";
		cin >> a;
		switch (a)
		{
		case 1:
			do
			{
				write_Doctor_Info();
				cout << "\n Doctor record has been created";

				system("cls");
				cout << "Do you want to insert new record of Doctor?(Y|N)";
				cin >> choice;
				system("cls");
			} while (choice == 'y' || choice == 'Y');
			break;
		case 2:modify_Doctor_Info(); break;
		case 3:cout << "enter id of the Doctor: "; cin >> num; deleteOneDoc(num); break;
		case 4:deleteAllDoc(); break;
		case 5:break;
		default:
			cout << "you should enter a number between(1-5)\n\ntry again!";
			break;
		}
	case 3:break;

	default:
		break;
	}
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++