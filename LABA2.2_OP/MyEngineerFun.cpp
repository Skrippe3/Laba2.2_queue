#include "MyEngineerClass.h"

void Engineer::setName(string newName) {
	name = newName;
}
void Engineer::setSpecialization(string newSpecialization) {
	specialization = newSpecialization;
}
void Engineer::setEducationLevel(string newEducationLevel) {
	educationLevel = newEducationLevel;
}
void Engineer::setAge(int newAge) {
	age = newAge;
}
void Engineer::setExperienxe(int newExperienxe) {
	experience = newExperienxe;
}

string Engineer::getName() { return name; }
string Engineer::getSpecialization() { return specialization; }
string Engineer::getEducationLevel() { return educationLevel; }
int Engineer::getAge() { return age; }
int Engineer::getExperienxe() { return experience; }

void Engineer::Print() {
	cout << "///////////////////////// ///////////////////////// /////////////////////////" << endl;
	cout << getName() << endl;
	cout << getAge() << endl;
	cout << getSpecialization() << endl;
	cout << getEducationLevel() << endl;
	cout << getExperienxe() << endl;
}

void Engineer::SaveToFile()
{
	ofstream Fout("EngineerData.txt", ios::app);
	if (!Fout.is_open())
		cout << "\n���� �� ��������" << endl;
	else {
		Fout << getName() << endl;
		Fout << getAge() << endl;
		Fout << getSpecialization() << endl;
		Fout << getEducationLevel() << endl;
		Fout << getExperienxe() << endl;
	};
	Fout.close();
	cout << "������ ������ �������." << endl;
};

void Engineer::OpenFromFile(Engineer& engineer)
{
	ifstream Fin("EngineerData.txt");
	if (!Fin.is_open())
		cout << "\n���� �� ��������" << endl;
	else {
		string line;
		Engineer temp;

		while (getline(Fin, line))
		{

			getline(Fin, line);
			temp.setName(line);

			getline(Fin, line);
			temp.setSpecialization(line);

			getline(Fin, line);
			temp.setEducationLevel(line);

			Fin >> age;
			Fin.ignore();
			temp.setAge(age);

			Fin >> experience;
			Fin.ignore();
			temp.setExperienxe(experience);

			//engineer.push_back(temp);
		}
	}
	Fin.close();
	//cout << "������ ������ �������." << endl;
};


void Engineer::Test(Engineer& engineer) {

	Engineer buffer;
	buffer.OpenFromFile(engineer); // ���� � ���������� ��� ��������� � ��������� ��������� ������

	if (buffer.getName() == getName() &&
		buffer.getAge() == getAge() &&
		buffer.getSpecialization() == getSpecialization() &&
		buffer.getEducationLevel() == getEducationLevel() &&
		buffer.getExperienxe() == getExperienxe())
	{
		cout << "������������ ������ �������. ������ ���." << endl;
	}
	else {
		cout << "���� �� ������������� ��������� ��������: " << endl;
		if (!(buffer.getName() == getName()))
		{
			cout << "���������� ������ ���� �����: " << buffer.getName() << endl;
		}
		if (!(buffer.getAge() == getAge()))
		{
			cout << "���������� ������ ���� �������: " << buffer.getAge() << endl;
		}
		if (!(buffer.getSpecialization() == getSpecialization()))
		{
			cout << "���������� ������ ���� �������������: " << buffer.getSpecialization() << endl;
		}
		if (!(buffer.getEducationLevel() == getEducationLevel()))
		{
			cout << "���������� ������ ���� �����������: " << buffer.getEducationLevel() << endl;
		}
		if (!(buffer.getExperienxe() == getExperienxe()))
		{
			cout << "���������� ������ ���� ����: " << buffer.getExperienxe() << endl;
		}
	}
}
