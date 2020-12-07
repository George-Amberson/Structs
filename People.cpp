#include "People.h"

void read_from_file(People*& _array)// передаем ссылку на указатель(если передадим просто указатель, то он передастся по значению, и память уйдет в никуда
{

	_array = new People[5]; //выделили память на 5 элеметов
	ifstream in; // переменная для считывания из файла
	in.open("C:\\Users\\Павел Кулемин\\Desktop\\Structs\\inputfile.txt"); //открываем файл через путь к нему. Путь может быть любым, главное не забывать два слеша вместо одного
	if (!in.is_open())cout << "qw";
	for (int i = 0; i < 5; i++)
	{
		in >> _array[i].Surname >> _array[i].lifeplace >> _array[i].birthyear;
	}
	cout << "Все данные записаны." << "\n\n";
}

void output_array_data(People* _array)//функция вывода данных на экран
{
	if (_array == nullptr) throw logic_error("empty pointer"); //проверяем не передали ли нам нулевой указатель
	for (int i = 0; i < 5; i++)
	{
		cout << _array[i].Surname << " " << _array[i].lifeplace << " " << _array[i].birthyear << "\n";
	}
	cout<< endl<<endl;
}

void correction_array_data(int num,People* _array)//функция корректировки данных в нужной строке
{
	if (_array == nullptr) throw logic_error("empty pointer"); //проверяем не передали ли нам нулевой указатель
	if ((num < 1) || (num>5)) throw logic_error("Number of string out of range");//проверяем корректный ли номер строки нам передали
	cout << "Введите пожалуйста через пробел корректную фамилию, город рождения и год рождения\n"; //интуитивно проще работать с номерами от 1 до 5 чем от 0 до 4 поэтому я сделал именно так на уровне пользователя
	cin >> _array[num-1].Surname >> _array[num-1].lifeplace >> _array[num-1].birthyear; //считываем новые данные
	cout << "Все отредактировано\n\n";
}
double middle_age(People* _array)// функция подсчета среднего возраста
{
	if (_array == nullptr) throw logic_error("empty pointer");//проверяем не передали ли нам нулевой указатель
	time_t rw=time(0);// переменная нужная для работы функции localtime, сама по себе не нужна.
	double middle_age = (localtime(&rw)->tm_year+1900)*5;//функция localtime возвращает число годов прошелших с 1900. На 5 умнажаем чтобы сразу из этого произведения вычитать года и потом поделить на 5
	for (int i = 0; i < 5; i++) middle_age -= _array[i].birthyear;
	return (middle_age / 5);
}
int output_into_file_array_data(People* _array, string& output)//функция вывода в заданный файл
{
	if (_array == nullptr) throw logic_error("empty pointer");
	if (output.empty())throw logic_error("way is empty");//проверяем что нам не передали пустое имя/пустую строку
	
	ofstream out(output);//создаем перменную для вывода в файл
	for (int i = 0; i < 5; i++)
	{
		out << _array[i].Surname << " " << _array[i].lifeplace << " " << _array[i].birthyear << "\n";
	}
	cout << "Все данные корректно записаны. Работа программы завершена.\n";
	return 2;
}