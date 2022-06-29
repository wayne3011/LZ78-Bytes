#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

struct word {
	unsigned char numOfPostWord = 0; // номер предыдушего повтора
	unsigned char nextSymbol = 0; // следующий символ повтора
	string wholeWord = ""; // функция изменения порядка символов на противополжный
};


void compression(string inputFile, string outFile, bool& errorInputFile, bool& errorOutFile);// функция сжатия файла
void deCompresion(string inputFile, string outFile, bool& errorInputFile, bool& errorOutFile);// функция декодирования сжатого файла
void reverse(string& reverseStr);// функция реверсии строки
void formatFile(string& dir); // форматирование введённого адреса под формат c++




int main() {

	setlocale(LC_ALL, "ru");// русская локализация

	cout << "\t/*******************************************************************************/\n";
	cout << "\t/*			А Л Г О Р И Т М   С Ж А Т И Я   L Z 7 8		       */\n";
	cout << "\t/*******************************************************************************/\n";
	
	string File = "";// путь txt файла
	string zipFile = "";// путь бинарного закодированного файла
	// кодировки ввода и вывода консоли для кириллицы
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	for (; true;) {

		cout << "\t\t\t\t\tВыберите действие: \n\t\t\t\t\t  1) СЖАТЬ ФАЙЛ\n\t\t\t\t\t 2) РАЗЖАТЬ ФАЙЛ\n";
		
	
		char select = 0;
		
		cin >> select;
		cin.get();
		if (select == 49) {// меню для сжатия
			while (true) {//меню запроса дополнительный исходных данных
				bool errorInputFile = true;// флаг ошибки потока ввода
				bool errorOutFile = true;// флаг ошибки потока вывода
				system("cls");
				cout << "\tПодсказка: чтобы не записывать путь вручную \n\tвыберите нужный файл(папку) -> правая кнопка мыши -> копировать как путь";
				cout << "\n\n Введите путь к файлу для сжатия(формат .txt): ";

				getline(cin, File);
				while (true) {
					if (File == "") {// вывод ошибки пустого пути для входного файла
						system("cls");
						cin.clear();
						cout << "\n\n\t\t\t\tПуть к файлу не может быть пустым! \n\n\t\t\t\tНажмите ENTER для продолжения";
						cin.get();
						system("cls");


						cout << "\tПодсказка: чтобы не записывать путь вручную \n\tвыберите нужный файл(папку) -> правая кнопка мыши -> копировать как путь";
						cout << "\n\n Введите путь к файлу для сжатия(формат .txt): ";
						getline(cin, File);
					}// кц Вывод ошибки пустого пути для входного файла
					else break;


				}
				formatFile(File);

				cout << "\n Выберите путь по которому хотите сохранить сжатый файл: ";
				getline(cin, zipFile);
				while (true) {// вывод ошибки пустого пути для выходного файла
					if (zipFile == "") {
						system("cls");
						cin.clear();
						cout << "\n\n\t\t\t\tПуть к файлу не может быть пустым! \n\n\t\t\t\tНажмите ENTER для продолжения";
						cin.get();
						system("cls");

						cout << "\tПодсказка: чтобы не записывать путь вручную \n\tвыберите нужный файл(папку) -> правая кнопка мыши -> копировать как путь";
						cout << "\n\n Введите путь к файлу для сжатия(формат .txt): " << File;

						cout << "\n\n Выберите путь по которому хотите сохранить сжатый файл: ";
						getline(cin, zipFile);
					}
					else break;


				}//кц вывод ошибки пустого пути для выходного файла
				formatFile(zipFile);

				string temp = "";
				cout << "\n Введите название для сжатого файла: ";
				getline(cin, temp);
				while (true) {//вывод ошибки пустого названия для выходного файла
					if (temp == "") {
						system("cls");
						cin.clear();
						cout << "\n\n\t\t\t\tПуть к файлу не может быть пустым! \n\n\t\t\t\tНажмите ENTER для продолжения";
						cin.get();
						system("cls");

						cout << "\tПодсказка: чтобы не записывать путь вручную \n\tвыберите нужный файл(папку) -> правая кнопка мыши -> копировать как путь";
						cout << "\n\n Введите путь к файлу для сжатия(формат .txt): " << File;

						cout << "\n\n Выберите путь по которому хотите сохранить сжатый файл: " << zipFile;

						cout << "\n\n Введите название для сжатого файла: ";
						getline(cin, temp);
					}
					else break;


				}//кц вывод ошибки пустого названия для выходного файла
				//собираем путь для выходного файла
				zipFile += '/';
				zipFile += temp;
				zipFile += ".bin";
				compression(File, zipFile, errorInputFile, errorOutFile);
				if (!errorInputFile) {//некорректный путь для входного файла
					cout << "\n\n\t\t\tНе удаётся найти файл для сжатия, проверьте адрес!\n\n\t\t\tНажмите ENTER для продолжения";
					cin.get();
				}
				else if (!errorOutFile) {//некорректный путь для выходного файла
					cout << "\n\n\t\t\tНе удаётся создать сжатый файл по указанному адресу\n\n\t\t\tНажмите ENTER для продолжения";
					cin.get();
				}
				else {//меню успешного завершения процесса сжатия
					system("cls");
					cout << "\n\n\t\t\t\t\t СЖАТИЕ ПРОШЛО УСПЕШНО\n\n\t\t\t\t\tНажмите ENTER для продолжения";
					cin.get();
					system("cls");
					break;
				}
			}// кц. меню запроса
		
		}//kc shztie
		else if (select == 50) {// меню разжатия
			while (true) {//меню запроса дополнительный исходных данных
				bool errorInputFile = true;// флаг ошибки потока ввода
				bool errorOutFile = true;// флаг ошибки потока вывода
				system("cls");
				cout << "\tПодсказка: чтобы не записывать путь вручную \n\tвыберите нужный файл(папку) -> правая кнопка мыши -> копировать как путь";
				cout << "\n\n Введите путь к сжатому файлу(формат .bin): ";
				getline(cin, zipFile);
				while (true) {// обработка ошибки пустого пути входного файла
					if (zipFile == "") {
						system("cls");
						cin.clear();
						cout << "\n\n\t\t\t\tПуть к сжатому файлу не может быть пустым! \n\n\t\t\t\tНажмите ENTER для продолжения";
						cin.get();
						system("cls");


						cout << "\tПодсказка: чтобы не записывать путь вручную \n\tвыберите нужный файл(папку) -> правая кнопка мыши -> копировать как путь";
						cout << "\n\n Введите путь к сжатому файлу(формат .bin): ";
						getline(cin, zipFile);
					}//кц обработка ошибки пустого пути входного файла
					else break;


				}
				formatFile(zipFile);

				cout << "\n Выберите путь по которому хотите сохранить раскодированный файл: ";
				getline(cin, File);
				while (true) {// обработка ошибки пустого пути выходного файла
					if (File == "") {
						system("cls");
						cin.clear();
						cout << "\n\n\t\t\t\tПуть к файлу не может быть пустым! \n\n\t\t\t\tНажмите ENTER для продолжения";
						cin.get();
						system("cls");

						cout << "\tПодсказка: чтобы не записывать путь вручную \n\tвыберите нужный файл(папку) -> правая кнопка мыши -> копировать как путь";
						cout << "\n\n Введите путь к сжатому файлу(формат .bin): " << zipFile;

						cout << "\n\n Выберите путь по которому хотите сохранить раскодированный файл: ";
						getline(cin, File);
					}//кц обработка ошибки пустого пути выходного файла
					else break;


				}
				formatFile(File);

				string temp = "";
				cout << "\n Введите название для раскодированного файла: ";
				getline(cin, temp);
				while (true) {//вывод ошибки пустого названия для выходного файла
					if (temp == "") {
						system("cls");
						cin.clear();
						cout << "\n\n\t\t\t\tНазвание файла не может быть пустым! \n\n\t\t\t\tНажмите ENTER для продолжения";
						cin.get();
						system("cls");

						cout << "\tПодсказка: чтобы не записывать путь вручную \n\tвыберите нужный файл(папку) -> правая кнопка мыши -> копировать как путь";
						cout << "\n\n Введите путь к сжатому файлу(формат .bin): " << zipFile;

						cout << "\n\n Выберите путь по которому хотите сохранить раскодированный файл: " << File;

						cout << "\n\n Выберите путь по которому хотите сохранить раскодированный файл: ";
						getline(cin, temp);
					}
					else break;


				}// кц вывод ошибки пустого названия для выходного файла
				//собираем путь для выходного файла
				File += '/';
				File += temp;
				File += ".txt";
				deCompresion(zipFile, File, errorInputFile, errorOutFile);
				if (!errorInputFile) {// обработка ошибки пустого пути входного файла
					cout << "\n\n\t\t\tНе удаётся найти файл для дкодирования, проверьте адрес!\n\n\t\t\tНажмите ENTER для продолжения";
					cin.get();
				}
				else if (!errorOutFile) {// обработка ошибки пустого пути выходного файла
					cout << "\n\n\t\t\tНе удаётся создать файл по указанному адресу\n\n\t\t\tНажмите ENTER для продолжения";
					cin.get();
				}
				else {//меню успешного завершения процесса разжатия
					system("cls");
					cout << "\n\n\t\t\t\t\t ФАЙЛ УСПЕШНО ДЕКОДИРОВАН\n\n\t\t\t\t\tНажмите ENTER для продолжения";
					cin.get();
					system("cls");
					break;
				}
			}//kc разжатие
		}//кц меню разжатия
		else{// ошибка недопустимого варианта ввода
			string temp = "";

			system("cls");
			cout << "\n\t\t\t\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
			cout << "\t\t\t\t!   Недопустимый вариант ввода   !\n";
			cout << "\t\t\t\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n\n\n";
			cout << "\t\t\t\t Нажмите ENTER для продолжения";
			cin.get();
			system("cls");
		}
		
		
	}
	
	return 0;
}


void compression(string inputFile, string outFile, bool& errorInputFile, bool& errorOutFile) {	// функция сжатия файла
	ifstream fin(inputFile); // проверка входного потока
	if (!fin.is_open()) {
		errorInputFile = false;
		return;
	}
	ofstream fout(outFile,ios::binary); // проверка выходного потока
	if (!fout.is_open()) {
		errorOutFile = false;
		return;
	}

	word* Dictionary = new word[256];// массив словаря
	Dictionary[0].nextSymbol = 0;
	Dictionary[0].wholeWord = "";
	Dictionary[0].numOfPostWord = 0;
	int wordMax = 0;

	string temp = "";// обрабатываемая строка
	int indOfRep = 0;// префикс повтора
	bool noRepeat = true;// флаг повтора
	char symbol = 0;// переменная считываемого символа

	while  (fin.peek() != EOF) {//читаем файл
		noRepeat = true;
		fin.read((char*)&symbol,1);// побитовое чтение
		
		temp += symbol;

		if (wordMax == 255) {//переполнение массива словаря
		
			Dictionary = new word[256]();

			Dictionary[0].nextSymbol = 0;
			Dictionary[0].wholeWord = "";
			Dictionary[0].numOfPostWord = 0;
			wordMax = 0;
			indOfRep = 0;
			fin.seekg(-((int)temp.length()), ios_base::cur);
			temp.clear();
			fin.read((char*)&symbol, 1);
			temp += symbol;

		}


		for (int k = 0; k <= wordMax; k++) {// ищем повтор в массиве
			if (temp == Dictionary[k].wholeWord) {
				noRepeat = false;
				indOfRep = k;
				break;
			}
		}

		if (noRepeat) {// если повтор не нашёлся
			wordMax++;// добавляем новое слово

			Dictionary[wordMax].numOfPostWord = indOfRep;
			fout.write((char*)&indOfRep, 1);

			Dictionary[wordMax].nextSymbol = symbol;
			fout.write((char*)&symbol, 1);
		
			Dictionary[wordMax].wholeWord = temp;

			temp = "";
			indOfRep = 0;
			noRepeat = true;
		}

	}
	if (!noRepeat) {//обрабатываем конец строки, если он не попал в словарь
		
		fout.write((char*)&indOfRep, 1);
	}
};
void deCompresion(string inputFile, string outFile, bool& errorInputFile, bool& errorOutFile) {	// функция декодирования сжатого файла

	ifstream fin(inputFile, ios::binary);
	ofstream fout(outFile);
	if (!fin.is_open()) {// проверка потока ввода
		errorInputFile = false;
		return;
	}
	if (!fout.is_open()) {// проверка потока вывода
		errorOutFile = false;
		return;
	}
	
	word* Dictionary = new word[256];// массив словаря
	Dictionary[0].nextSymbol = NULL;
	Dictionary[0].numOfPostWord = 0;
	int wordMax = 0;

	
	while (fin.peek() != EOF) {// побитовое чтение файла

		if (wordMax == 255) {// переполнение массива
			
			Dictionary = new word[256]();

			Dictionary[0].nextSymbol = NULL;
			Dictionary[0].wholeWord = "";
			Dictionary[0].numOfPostWord = 0;
			wordMax = 0;
			
		}
		// добавление нового слова в словарь
		wordMax++;
		fin.read((char*)&(Dictionary[wordMax].numOfPostWord), 1);

		// обработка последнего элемента закодированного файла
		if (fin.peek() == EOF) {// собираем закодированное слово по префиксам кодирования
			int indOfRep = Dictionary[wordMax].numOfPostWord;
			string temp = "";
			for (; true;) {
				if (Dictionary[indOfRep].numOfPostWord == 0) {
					temp += Dictionary[indOfRep].nextSymbol;
					break;
				}
				temp += Dictionary[indOfRep].nextSymbol;
				indOfRep = Dictionary[indOfRep].numOfPostWord;
			}
			reverse(temp);// меняем порядок закодированного слова в обратную сторону
			fout << temp;
			break;
		}
		
		
		fin.read((char*)&(Dictionary[wordMax].nextSymbol), 1);

		int indOfRep = wordMax;
		string temp = "";
		for (; true;) {// собираем закодированное слово по префиксам кодирования
			if (Dictionary[indOfRep].numOfPostWord == 0) {
				temp += Dictionary[indOfRep].nextSymbol;
				break;
			}
			temp += Dictionary[indOfRep].nextSymbol;
			indOfRep = Dictionary[indOfRep].numOfPostWord;
		}
		reverse(temp);// меняем порядок закодированного слова в обратную сторону
		fout << temp;
	}
	

}
void reverse(string& reverseStr) {		// функция реверсии строки
	int lengthStr = reverseStr.length();
	string temp = "";
	for (int i = 0; i < lengthStr; i++) {
		temp += reverseStr[lengthStr - 1 - i];
	}
	reverseStr = temp;
}
void formatFile(string& dir) { // форматирование введённого адреса под формат c++
	int length = dir.length();
	string result = "";
	for (int i = (dir[0] == '"' ? 1 : 0); i < (dir[length-1] == '"' ? length - 1 : length); i++) {
		result += ((dir[i] == 92) ? '/' : dir[i]);
	
	}
	dir = result;
}

