#include<iostream>
#include<fstream>
#include<iterator>
#include<algorithm>
#include<numeric>
#include<vector>
#include"Applicant.h"
#include"BaseTest.h"
#include"Testting.h"

using namespace std;

template <typename T>
void Read(vector<T>& v, string path)
{
	ifstream ifs(path);
	copy(istream_iterator<T>(ifs), istream_iterator<T>(), back_inserter(v));
}

void Task1(vector<Applicant>&a,vector<Testting>&t,vector<SpecTest>&s,vector<BaseTest>&b)
{
	vector<Testting>tests_for_one;
	for (auto el : a)
	{
		auto count = count_if(t.begin(), t.end(), [&el](Testting& t) {return el.GetID() == t.GetIDStudent(); });
		tests_for_one.resize(count);
		copy_if(t.begin(), t.end(), tests_for_one.begin(), [&el](Testting& e) {return el.GetID() == e.GetIDStudent(); });
		cout << "Marks of " << el.GetName()<<" "<<el.GetSurname() << " : " << endl << endl;
		for (auto ell : tests_for_one)
		{
			auto it1 = find_if(s.begin(), s.end(), [&ell](SpecTest& s) {return ell.GetNumberSubj() == s.GetNumber(); });
			if (it1 != s.end())
			{

				cout << "Subject : " << (*it1).GetSubject() << endl;
				cout << "Base part :" << ell.GetMark() << endl;
				cout << "Special part : " << ell.GetSpecMark() << endl;
				cout << "Mark : " << (ell.GetMark() + ell.GetSpecMark()) << endl << endl;
			}
			else
			{
				auto it2 = find_if(b.begin(), b.end(), [&ell](BaseTest& b) {return ell.GetNumberSubj() == b.GetNumber(); });
				cout << "Subject : " << (*it2).GetSubject() << endl;
				cout << "General mark  : " << ell.GetMark()<< endl << endl;

			}
		}
		cout << "-----------------------------------------------------------------------------------------------" << endl;
		tests_for_one.clear();
	}
}

void Task2(vector<Applicant>& a, vector<Testting>& t, vector<SpecTest>& s, vector<BaseTest>& b)
{
	vector<Testting>temp_tests;
	cout << "-------------------------------------Rating for base tests-------------------------------------" << endl << endl;
	for (auto el : b)
	{
		auto count = count_if(t.begin(), t.end(), [&el](Testting& t) {return el.GetNumber() == t.GetNumberSubj(); });
		temp_tests.resize(count);
		copy_if(t.begin(), t.end(), temp_tests.begin(), [&el](Testting&t) {return el.GetNumber() == t.GetNumberSubj(); });
		cout << el.GetSubject() << " : " << endl << endl;
		for (auto ell : temp_tests)
		{
			auto it1 = find_if(a.begin(), a.end(), [&ell](Applicant& a) {return ell.GetIDStudent() == a.GetID(); });
			auto it2 = find_if(b.begin(), b.end(), [&ell](BaseTest& b) {return ell.GetNumberSubj() == b.GetNumber(); });
			cout << (*it1).GetName() << " " << (*it1).GetSurname() << ",test number " << (*it2).GetNumber() << " : " << ((ell.GetMark() / (*it2).GetMaxMark()) * 100) << "%" << endl;
		}
		cout << "-----------------------------------------------------------------------------------------------" << endl;
		temp_tests.clear();
	}
	cout << "-------------------------------------Rating for special tests----------------------------------" << endl << endl;
	for (auto el : s)
	{
		auto count = count_if(t.begin(), t.end(), [&el](Testting& t) {return el.GetNumber() == t.GetNumberSubj(); });
		temp_tests.resize(count);
		copy_if(t.begin(), t.end(), temp_tests.begin(), [&el](Testting& t) {return el.GetNumber() == t.GetNumberSubj(); });
		cout << el.GetSubject() << " : " << endl << endl;
		for (auto ell : temp_tests)
		{
			auto it1 = find_if(a.begin(), a.end(), [&ell](Applicant& a) {return ell.GetIDStudent() == a.GetID(); });
			auto it2 = find_if(s.begin(), s.end(), [&ell](SpecTest& s) {return ell.GetNumberSubj() == s.GetNumber(); });
			double base = (ell.GetMark() / (*it2).GetMaxMark()) * 100;
			double special = (ell.GetSpecMark() / (*it2).GetMaxMarkSpec()) * 100;
			cout << (*it1).GetName() << " " << (*it1).GetSurname() << ",test number " << (*it2).GetNumber() << " : " << (base + special) / 2 << "%" << endl;
		}
		cout << "-----------------------------------------------------------------------------------------------" << endl;
		temp_tests.clear();
	}
}
void Task3(vector<Applicant>& a, vector<Testting>& t, vector<SpecTest>& s, vector<BaseTest>& b)
{
	vector<int>tests_numbers;
	int temp = 1000;
	while (temp != 0)
	{
		cout << "Enter test number , to stop enter 0 : ";
		cin >> temp;
		tests_numbers.push_back(temp);
	}
	cout << endl << endl;
	vector<Testting>temp_tests;
	for (auto el : tests_numbers)
	{
		auto count = count_if(t.begin(), t.end(), [&el](Testting& t) {return el == t.GetNumberSubj(); });
		temp_tests.resize(count);
		copy_if(t.begin(), t.end(), temp_tests.begin(), [&el](Testting& t) {return el == t.GetNumberSubj(); });
		for (auto ell : temp_tests)
		{
			auto it1 = find_if(s.begin(), s.end(), [&ell](SpecTest& s) {return ell.GetNumberSubj() == s.GetNumber(); });
			double sum = 0;
			if (it1 != s.end())
			{
				sum = accumulate(temp_tests.begin(), temp_tests.end(), 0.0, [&ell,&el,&it1](double a, Testting b)
					{
						if (el == ell.GetNumberSubj())
						{
							return a + (((b.GetMark() / (*it1).GetMaxMark()) + (b.GetSpecMark() / (*it1).GetMaxMarkSpec())) / 2);
						}
						else
						{
							return a;
						}
					});
			}
			else
			{
				auto it2 = find_if(b.begin(), b.end(), [&ell](BaseTest& b) {return ell.GetNumberSubj() == b.GetNumber(); });
				sum = accumulate(temp_tests.begin(), temp_tests.end(), 0.0, [&el,&ell,&it2](double a ,Testting b) 
					{
						if (el == ell.GetNumberSubj())
						{
							return a + (b.GetMark() / (*it2).GetMaxMark());
						}
						else
						{
							return a;
						}
					});
			}
			cout << "Total rating of students for test number " << el << " = " << (sum / count)*100 << "%" << endl;
		}
		temp_tests.clear();
	}
}
// Task 3 working , but not perfect
int main()
{
	vector<Applicant>a1;
	vector<BaseTest>b1;
	vector<SpecTest>s1;
	vector<Testting>t1;

	Read(a1, "Applicant.txt");
	Read(b1, "Base.txt");
	Read(s1, "Spec.txt");
	Read(t1, "Tests.txt");

	Task1(a1, t1, s1,b1);
	Task2(a1, t1, s1, b1);
	Task3(a1, t1, s1, b1);



	return 0;
}