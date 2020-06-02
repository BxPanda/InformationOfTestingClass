#include<string>
#include<iostream>

#pragma once
using namespace std;

class Testting
{
protected:
	int IDStudent;
	int NumberSubj;
	double Mark;
	double SpecMark;
public:
	Testting() :IDStudent(0), NumberSubj(0), Mark(0), SpecMark(0) {}
	Testting(int i,int n,double m,double sm):IDStudent(i),NumberSubj(n),Mark(m),SpecMark(sm){}
	Testting(const Testting&a):IDStudent(a.IDStudent),NumberSubj(a.NumberSubj),Mark(a.Mark),SpecMark(a.SpecMark){}
	
	int GetIDStudent()
	{
		return IDStudent;
	}
	int GetNumberSubj()
	{
		return NumberSubj;
	}
	double GetMark()
	{
		return Mark;
	}
	double GetSpecMark()
	{
		return SpecMark;
	}
	friend istream& operator>>(istream& is, Testting& a)
	{
		is >> a.IDStudent >> a.NumberSubj >> a.Mark >> a.SpecMark;
		return is;
	}
	friend ostream& operator<<(ostream& os, const Testting& a)
	{
		os << a.IDStudent << " " << a.NumberSubj << " " << a.Mark << " " << a.SpecMark << " ";
		return os;
	}

};

