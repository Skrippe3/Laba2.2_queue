#pragma once

#include<iostream>
#include<string>
#include <fstream>
#include "queue.h"

using namespace std;

class Engineer {
private:
	string name;
	string specialization;
	string educationLevel;
	int age;
	int experience;
public:
	void setName(string newName);
	void setSpecialization(string newSpecialization);
	void setEducationLevel(string newEducationLevel);
	void setAge(int newAge);
	void setExperienxe(int newExperienxe);

	void Print();

	void SaveToFile();

	void OpenFromFile(Engineer& engineer);

	void Test(Engineer& engineer);

	string getName();
	string getSpecialization();
	string getEducationLevel();
	int getAge();
	int getExperienxe();

	/*Engineer()   // Конструктор по умолчанию
	{
		name = "empty";
		specialization = "empty";
		educationLevel = "empty";
		age = 0;
		experience = 0;
	}
	Engineer(string name, string specialization, string educationLevel, int age, int experience) // Конструктор с параметрами
	{
		this->name = name;
		this->specialization = specialization;
		this->educationLevel = educationLevel;
		this->age = age;
		this->experience = experience;
	}*/
};
