#include<string>
#include<iostream>
#pragma once
using namespace std;

class Applicant
{
protected:
	int ID;
	string Name, Surname;
public:
	Applicant():ID(0),Name("none"),Surname("none"){}
	Applicant(int id,string n,string s):ID(id),Name(n),Surname(s){}
	Applicant(const Applicant&a):ID(a.ID),Name(a.Name),Surname(a.Surname){}

	int GetID()
	{
		return ID;
	}
	string GetName()
	{
		return Name;
	}
	string GetSurname()
	{
		return Surname;
	}

	friend istream& operator>>(istream& is, Applicant& a)
	{
		is >> a.ID;
		is >> a.Name;
		is >> a.Surname;
		return is;
	}

	friend ostream& operator<<(ostream& os, const Applicant& a)
	{
		os << a.ID << " " << a.Name << " " << a.Surname << " ";
		return os;
	}
	
};

