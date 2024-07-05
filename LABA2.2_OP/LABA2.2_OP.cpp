#include "MyEngineerClass.h"
#include "queue.h"
#include<string>

int main()
{
	system("chcp 1251");

	deque<Engineer> engineer = {};

	bool flag = true;
	int choose;

	do
	{
		cout << "\nВыбирайте № операции:\n" << "1) Ввести инженера\n"<<"2) Размер списка\n"<<"3) Вывести инженеров\n"<<"4) Удалить инженера\n"<<"5) Найти инженера\n"<<"6) Сохранить инженера\n"<<"7) Загрузить инженеров\n";
		cin >> choose;

		switch (choose)
		{
            case(1):
            {

                Engineer newEngineer;
                string Name;
                string Specialization;
                string EducationLevel;
                int Age;
                int Experience;

                cout << "Введите имя инженера: ";

                cin >> Name;
                newEngineer.setName(Name);

                cout << "Введите возраст инженера: ";

                cin >> Age;
                newEngineer.setAge(Age);

                cout << "Введите опыт инженера в годах: ";

                cin >> Experience;
                newEngineer.setExperienxe(Experience);

                cout << "Введите специальность инженера: ";

                cin >> Specialization;
                newEngineer.setSpecialization(Specialization);

                cout << "Введите уровень образования: ";

                cin >> EducationLevel;
                newEngineer.setEducationLevel(EducationLevel);

                engineer.push_back(newEngineer);

                cout << "Инженер добавлен в очередь" << endl;
            }
            case(2): 
            {
                cout << "Размер списка: "<< engineer.size() << endl;
                break;
            }
            case(3):
                for (int i = 0; i < engineer.size(); i++)
                {
                    engineer[i].Print();
                    
                }
                break;
            case(4): 
            {
                engineer.pop_back();
                cout << "Последний инженер удален" << endl;
                break;
            }     
            case(5): {
                string searchName;
                bool search = false;

                cout << "Введите имя: " << endl;
                cin >> searchName;

                for (int i = 0; i < engineer.size(); i++) {
                    if (searchName == engineer[i].getName()) {
                        engineer[i].Print();
                        search = true;
                        break;
                    }
                }

                if (!search) {
                    cout << "Инженер не найден" << endl;
                }
                break;
            }
            case(6): 
            {
                for (int i = 0; i < engineer.size(); i++)
                {
                    engineer[i].SaveToFile();
                }
                break;
            }
            case(7): 
            {
                // Загрузка данных о инженерах из файла
                Engineer tempEngineer;
                int flag = 1;
                tempEngineer.OpenFromFile(tempEngineer); // Вызов метода OpenFromFile
                engineer.push_back(tempEngineer); // Добавление загруженного инженера в очередь
                cout << "Инженеры успешно загружены из файла" << endl;
                cout << "Хотите протестировать?" << endl;
                cin >> flag;
                if(flag == 1)
                {
                    tempEngineer.Test(tempEngineer);
                    break;
                }
                else 
                {
                    break;
                }
                

            }
		}
	} while (flag);
}

