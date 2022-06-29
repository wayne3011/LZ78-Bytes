#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

struct word {
	unsigned char numOfPostWord = 0; // ����� ����������� �������
	unsigned char nextSymbol = 0; // ��������� ������ �������
	string wholeWord = ""; // ������� ��������� ������� �������� �� ��������������
};


void compression(string inputFile, string outFile, bool& errorInputFile, bool& errorOutFile);// ������� ������ �����
void deCompresion(string inputFile, string outFile, bool& errorInputFile, bool& errorOutFile);// ������� ������������� ������� �����
void reverse(string& reverseStr);// ������� �������� ������
void formatFile(string& dir); // �������������� ��������� ������ ��� ������ c++




int main() {

	setlocale(LC_ALL, "ru");// ������� �����������

	cout << "\t/*******************************************************************************/\n";
	cout << "\t/*			� � � � � � � �   � � � � � �   L Z 7 8		       */\n";
	cout << "\t/*******************************************************************************/\n";
	
	string File = "";// ���� txt �����
	string zipFile = "";// ���� ��������� ��������������� �����
	// ��������� ����� � ������ ������� ��� ���������
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	for (; true;) {

		cout << "\t\t\t\t\t�������� ��������: \n\t\t\t\t\t  1) ����� ����\n\t\t\t\t\t 2) ������� ����\n";
		
	
		char select = 0;
		
		cin >> select;
		cin.get();
		if (select == 49) {// ���� ��� ������
			while (true) {//���� ������� �������������� �������� ������
				bool errorInputFile = true;// ���� ������ ������ �����
				bool errorOutFile = true;// ���� ������ ������ ������
				system("cls");
				cout << "\t���������: ����� �� ���������� ���� ������� \n\t�������� ������ ����(�����) -> ������ ������ ���� -> ���������� ��� ����";
				cout << "\n\n ������� ���� � ����� ��� ������(������ .txt): ";

				getline(cin, File);
				while (true) {
					if (File == "") {// ����� ������ ������� ���� ��� �������� �����
						system("cls");
						cin.clear();
						cout << "\n\n\t\t\t\t���� � ����� �� ����� ���� ������! \n\n\t\t\t\t������� ENTER ��� �����������";
						cin.get();
						system("cls");


						cout << "\t���������: ����� �� ���������� ���� ������� \n\t�������� ������ ����(�����) -> ������ ������ ���� -> ���������� ��� ����";
						cout << "\n\n ������� ���� � ����� ��� ������(������ .txt): ";
						getline(cin, File);
					}// �� ����� ������ ������� ���� ��� �������� �����
					else break;


				}
				formatFile(File);

				cout << "\n �������� ���� �� �������� ������ ��������� ������ ����: ";
				getline(cin, zipFile);
				while (true) {// ����� ������ ������� ���� ��� ��������� �����
					if (zipFile == "") {
						system("cls");
						cin.clear();
						cout << "\n\n\t\t\t\t���� � ����� �� ����� ���� ������! \n\n\t\t\t\t������� ENTER ��� �����������";
						cin.get();
						system("cls");

						cout << "\t���������: ����� �� ���������� ���� ������� \n\t�������� ������ ����(�����) -> ������ ������ ���� -> ���������� ��� ����";
						cout << "\n\n ������� ���� � ����� ��� ������(������ .txt): " << File;

						cout << "\n\n �������� ���� �� �������� ������ ��������� ������ ����: ";
						getline(cin, zipFile);
					}
					else break;


				}//�� ����� ������ ������� ���� ��� ��������� �����
				formatFile(zipFile);

				string temp = "";
				cout << "\n ������� �������� ��� ������� �����: ";
				getline(cin, temp);
				while (true) {//����� ������ ������� �������� ��� ��������� �����
					if (temp == "") {
						system("cls");
						cin.clear();
						cout << "\n\n\t\t\t\t���� � ����� �� ����� ���� ������! \n\n\t\t\t\t������� ENTER ��� �����������";
						cin.get();
						system("cls");

						cout << "\t���������: ����� �� ���������� ���� ������� \n\t�������� ������ ����(�����) -> ������ ������ ���� -> ���������� ��� ����";
						cout << "\n\n ������� ���� � ����� ��� ������(������ .txt): " << File;

						cout << "\n\n �������� ���� �� �������� ������ ��������� ������ ����: " << zipFile;

						cout << "\n\n ������� �������� ��� ������� �����: ";
						getline(cin, temp);
					}
					else break;


				}//�� ����� ������ ������� �������� ��� ��������� �����
				//�������� ���� ��� ��������� �����
				zipFile += '/';
				zipFile += temp;
				zipFile += ".bin";
				compression(File, zipFile, errorInputFile, errorOutFile);
				if (!errorInputFile) {//������������ ���� ��� �������� �����
					cout << "\n\n\t\t\t�� ������ ����� ���� ��� ������, ��������� �����!\n\n\t\t\t������� ENTER ��� �����������";
					cin.get();
				}
				else if (!errorOutFile) {//������������ ���� ��� ��������� �����
					cout << "\n\n\t\t\t�� ������ ������� ������ ���� �� ���������� ������\n\n\t\t\t������� ENTER ��� �����������";
					cin.get();
				}
				else {//���� ��������� ���������� �������� ������
					system("cls");
					cout << "\n\n\t\t\t\t\t ������ ������ �������\n\n\t\t\t\t\t������� ENTER ��� �����������";
					cin.get();
					system("cls");
					break;
				}
			}// ��. ���� �������
		
		}//kc shztie
		else if (select == 50) {// ���� ��������
			while (true) {//���� ������� �������������� �������� ������
				bool errorInputFile = true;// ���� ������ ������ �����
				bool errorOutFile = true;// ���� ������ ������ ������
				system("cls");
				cout << "\t���������: ����� �� ���������� ���� ������� \n\t�������� ������ ����(�����) -> ������ ������ ���� -> ���������� ��� ����";
				cout << "\n\n ������� ���� � ������� �����(������ .bin): ";
				getline(cin, zipFile);
				while (true) {// ��������� ������ ������� ���� �������� �����
					if (zipFile == "") {
						system("cls");
						cin.clear();
						cout << "\n\n\t\t\t\t���� � ������� ����� �� ����� ���� ������! \n\n\t\t\t\t������� ENTER ��� �����������";
						cin.get();
						system("cls");


						cout << "\t���������: ����� �� ���������� ���� ������� \n\t�������� ������ ����(�����) -> ������ ������ ���� -> ���������� ��� ����";
						cout << "\n\n ������� ���� � ������� �����(������ .bin): ";
						getline(cin, zipFile);
					}//�� ��������� ������ ������� ���� �������� �����
					else break;


				}
				formatFile(zipFile);

				cout << "\n �������� ���� �� �������� ������ ��������� ��������������� ����: ";
				getline(cin, File);
				while (true) {// ��������� ������ ������� ���� ��������� �����
					if (File == "") {
						system("cls");
						cin.clear();
						cout << "\n\n\t\t\t\t���� � ����� �� ����� ���� ������! \n\n\t\t\t\t������� ENTER ��� �����������";
						cin.get();
						system("cls");

						cout << "\t���������: ����� �� ���������� ���� ������� \n\t�������� ������ ����(�����) -> ������ ������ ���� -> ���������� ��� ����";
						cout << "\n\n ������� ���� � ������� �����(������ .bin): " << zipFile;

						cout << "\n\n �������� ���� �� �������� ������ ��������� ��������������� ����: ";
						getline(cin, File);
					}//�� ��������� ������ ������� ���� ��������� �����
					else break;


				}
				formatFile(File);

				string temp = "";
				cout << "\n ������� �������� ��� ���������������� �����: ";
				getline(cin, temp);
				while (true) {//����� ������ ������� �������� ��� ��������� �����
					if (temp == "") {
						system("cls");
						cin.clear();
						cout << "\n\n\t\t\t\t�������� ����� �� ����� ���� ������! \n\n\t\t\t\t������� ENTER ��� �����������";
						cin.get();
						system("cls");

						cout << "\t���������: ����� �� ���������� ���� ������� \n\t�������� ������ ����(�����) -> ������ ������ ���� -> ���������� ��� ����";
						cout << "\n\n ������� ���� � ������� �����(������ .bin): " << zipFile;

						cout << "\n\n �������� ���� �� �������� ������ ��������� ��������������� ����: " << File;

						cout << "\n\n �������� ���� �� �������� ������ ��������� ��������������� ����: ";
						getline(cin, temp);
					}
					else break;


				}// �� ����� ������ ������� �������� ��� ��������� �����
				//�������� ���� ��� ��������� �����
				File += '/';
				File += temp;
				File += ".txt";
				deCompresion(zipFile, File, errorInputFile, errorOutFile);
				if (!errorInputFile) {// ��������� ������ ������� ���� �������� �����
					cout << "\n\n\t\t\t�� ������ ����� ���� ��� ������������, ��������� �����!\n\n\t\t\t������� ENTER ��� �����������";
					cin.get();
				}
				else if (!errorOutFile) {// ��������� ������ ������� ���� ��������� �����
					cout << "\n\n\t\t\t�� ������ ������� ���� �� ���������� ������\n\n\t\t\t������� ENTER ��� �����������";
					cin.get();
				}
				else {//���� ��������� ���������� �������� ��������
					system("cls");
					cout << "\n\n\t\t\t\t\t ���� ������� �����������\n\n\t\t\t\t\t������� ENTER ��� �����������";
					cin.get();
					system("cls");
					break;
				}
			}//kc ��������
		}//�� ���� ��������
		else{// ������ ������������� �������� �����
			string temp = "";

			system("cls");
			cout << "\n\t\t\t\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
			cout << "\t\t\t\t!   ������������ ������� �����   !\n";
			cout << "\t\t\t\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n\n\n";
			cout << "\t\t\t\t ������� ENTER ��� �����������";
			cin.get();
			system("cls");
		}
		
		
	}
	
	return 0;
}


void compression(string inputFile, string outFile, bool& errorInputFile, bool& errorOutFile) {	// ������� ������ �����
	ifstream fin(inputFile); // �������� �������� ������
	if (!fin.is_open()) {
		errorInputFile = false;
		return;
	}
	ofstream fout(outFile,ios::binary); // �������� ��������� ������
	if (!fout.is_open()) {
		errorOutFile = false;
		return;
	}

	word* Dictionary = new word[256];// ������ �������
	Dictionary[0].nextSymbol = 0;
	Dictionary[0].wholeWord = "";
	Dictionary[0].numOfPostWord = 0;
	int wordMax = 0;

	string temp = "";// �������������� ������
	int indOfRep = 0;// ������� �������
	bool noRepeat = true;// ���� �������
	char symbol = 0;// ���������� ������������ �������

	while  (fin.peek() != EOF) {//������ ����
		noRepeat = true;
		fin.read((char*)&symbol,1);// ��������� ������
		
		temp += symbol;

		if (wordMax == 255) {//������������ ������� �������
		
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


		for (int k = 0; k <= wordMax; k++) {// ���� ������ � �������
			if (temp == Dictionary[k].wholeWord) {
				noRepeat = false;
				indOfRep = k;
				break;
			}
		}

		if (noRepeat) {// ���� ������ �� �������
			wordMax++;// ��������� ����� �����

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
	if (!noRepeat) {//������������ ����� ������, ���� �� �� ����� � �������
		
		fout.write((char*)&indOfRep, 1);
	}
};
void deCompresion(string inputFile, string outFile, bool& errorInputFile, bool& errorOutFile) {	// ������� ������������� ������� �����

	ifstream fin(inputFile, ios::binary);
	ofstream fout(outFile);
	if (!fin.is_open()) {// �������� ������ �����
		errorInputFile = false;
		return;
	}
	if (!fout.is_open()) {// �������� ������ ������
		errorOutFile = false;
		return;
	}
	
	word* Dictionary = new word[256];// ������ �������
	Dictionary[0].nextSymbol = NULL;
	Dictionary[0].numOfPostWord = 0;
	int wordMax = 0;

	
	while (fin.peek() != EOF) {// ��������� ������ �����

		if (wordMax == 255) {// ������������ �������
			
			Dictionary = new word[256]();

			Dictionary[0].nextSymbol = NULL;
			Dictionary[0].wholeWord = "";
			Dictionary[0].numOfPostWord = 0;
			wordMax = 0;
			
		}
		// ���������� ������ ����� � �������
		wordMax++;
		fin.read((char*)&(Dictionary[wordMax].numOfPostWord), 1);

		// ��������� ���������� �������� ��������������� �����
		if (fin.peek() == EOF) {// �������� �������������� ����� �� ��������� �����������
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
			reverse(temp);// ������ ������� ��������������� ����� � �������� �������
			fout << temp;
			break;
		}
		
		
		fin.read((char*)&(Dictionary[wordMax].nextSymbol), 1);

		int indOfRep = wordMax;
		string temp = "";
		for (; true;) {// �������� �������������� ����� �� ��������� �����������
			if (Dictionary[indOfRep].numOfPostWord == 0) {
				temp += Dictionary[indOfRep].nextSymbol;
				break;
			}
			temp += Dictionary[indOfRep].nextSymbol;
			indOfRep = Dictionary[indOfRep].numOfPostWord;
		}
		reverse(temp);// ������ ������� ��������������� ����� � �������� �������
		fout << temp;
	}
	

}
void reverse(string& reverseStr) {		// ������� �������� ������
	int lengthStr = reverseStr.length();
	string temp = "";
	for (int i = 0; i < lengthStr; i++) {
		temp += reverseStr[lengthStr - 1 - i];
	}
	reverseStr = temp;
}
void formatFile(string& dir) { // �������������� ��������� ������ ��� ������ c++
	int length = dir.length();
	string result = "";
	for (int i = (dir[0] == '"' ? 1 : 0); i < (dir[length-1] == '"' ? length - 1 : length); i++) {
		result += ((dir[i] == 92) ? '/' : dir[i]);
	
	}
	dir = result;
}

