#include<iostream>
#include<string>
#include<fstream>//подключение библиотеки содержащей 
//в себе объекты и классы, для работы с файловой системой устройства
bool ststistic(std::string str);

int main() {
	setlocale(LC_ALL, "ru");
	int n;

	std::string path = "file.txt";
	
	
	//Класс ofstream для записи в файл
	/*std::ofstream out;//объявление объекта записи в файл
	out.open(path,std::ios::app);// открытие файла. Создает файл, если его не существует.

	if (out.is_open())//проверка открытия файла
	{
		std::cout << "Файл открыт для записи\n";
		std::string str;
		std::cout << "Введите строку->";
		std::getline(std::cin, str);
		out << str << '\n';//добавление записи в файл
		

	}

	else {
		std::cout << "Ошибка открытия файла\n";
		//Возможные причины ошибки при открытии файла
		//1. Не корректный путь к файлу
		//2. Нет доступа к файлу
		//3. Файл открыт другим объектом или программой
	}


	out.close();//закрытие файла
	*/

	//Класс ifstream для чтения файла
	/*std::ifstream in;
	in.open(path);

	if (in.is_open()) {
		std::cout << "Файл открыт. Содержимое файла\n";
		std::string file;


		// Посимвольное считывание
		//char sym;
		//while (in.get(sym)) {
			//file += sym;
		//}
		//std::cout << file << std::endl;

		// Пословное считывание
		//while (!in.eof()) {
			//std::string word;
			//in >> word;
			//file += word + '\n';
		//}
		//std::cout << file << std::endl;
	//}
		//else {
			//std::cout << "Ошибка открытия файла\n";
			//Возможные причины ошибки при открытии файла
			//1.Неправильный путь к файлу
			//2.Файла не существует
			//3.Нет доступа к файлу

		//Построчное считывание
		std::string str;
		while (std::getline(in,str)) {
			file += str + '\n';
		}
		std::cout << file;

	}

	in.close();
	*/
	// Удаление файла
	// remove(path.c_str()); // неудобно
	/*if (remove(path.c_str()) == 0) {
		std::cout << "Файл удален\n";
	}
	else {
		std::cout << "Ошибка удаления файла\n";
		//Возможные причины ошибок при удалении файла
		//1.Нет доступа к файлу
		//2.Файла не существует
		//3.Файл открыт в другом приложении
		//4.Неправильный путь к файлу
	}
	*/

	//Задача 1 Статистика в файл
	std::cout << "Введите строку\n";
	std::string str1;
	std::getline(std::cin, str1);
	if (ststistic(str1))
		std::cout << "Запись добавлена";
	else
		std::cout << "Ошибка";

	return 0;
}

bool ststistic(std::string str) {
	static std::ofstream out;
	out.open("stats.txt",std::ios::app);
	if (out.is_open()) {
		out << str << ' ' << str.length() << '\n';
		out.close();
		return true;
	}

	return false;
}