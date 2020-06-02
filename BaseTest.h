#include<string>
#include<iostream>
#pragma once
using namespace std;

class BaseTest
{
protected:
	int Number;
	string Subject;
	double MaxMark;
public:
	BaseTest():Number(0),Subject("none"),MaxMark(0){}
	BaseTest(int n,string s,double mm):Number(n),Subject(s),MaxMark(mm){}
	BaseTest(const BaseTest&a):Number(a.Number),Subject(a.Subject),MaxMark(a.MaxMark){}

	int GetNumber()
	{
		return Number;
	}
	string GetSubject()
	{
		return Subject;
	}
	double GetMaxMark()
	{
		return MaxMark;
	}
	friend istream& operator>>(istream& is, BaseTest& a)
	{
		is >> a.Number;
		is >> a.Subject;
		is >> a.MaxMark;
		return is;
	}
	friend ostream& operator<<(ostream& os, const BaseTest& a)
	{
		os << a.Number << " " << a.Subject << " " << a.MaxMark << " ";
		return os;
	}
};

class SpecTest:public BaseTest
{
	double MaxMarkSpec;
public:
	SpecTest() :BaseTest(), MaxMarkSpec(0) {}
	SpecTest(int n, string s, double mm,double mms):BaseTest(n,s,mm),MaxMarkSpec(mms){}
	SpecTest(const SpecTest&a):BaseTest(a),MaxMarkSpec(a.MaxMarkSpec){}

	double GetMaxMarkSpec()
	{
		return MaxMarkSpec;
	}
	friend istream& operator>>(istream& is, SpecTest& a)
	{
		is >> (BaseTest&)a >> a.MaxMarkSpec;
		return is;
	}
	friend ostream& operator<<(ostream& os, SpecTest& a)
	{
		os << (BaseTest&)a << a.MaxMarkSpec << " ";
		return os;
	}

};



