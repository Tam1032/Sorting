#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Item {
	string word;
	string meaning;
};

void loadData(char file[], Item dat[], int &n) {
	ifstream fi(file);
	if (!fi.is_open()) {
		cout << "Khong mo duoc file de tu dien" << endl;
		return;
	}
	string s;
	int b, e;
	n = 0;
	while(!fi.eof()) {
		getline(fi, s);
		b = s.find("\t");
		if (b < 0)
			continue;
		//s //(
		dat[n].word = s.substr(0, b);
		s = s.substr(b + 1);
		while ((b = s.find("|=")) > -1) {
			s.replace(b, 2, "\n");
		}
		dat[n].meaning = s;
		n++;
	}
	fi.close();
}

int linearSearch(string word, Item dat[], int n) {
	// Cai dat code tim kiem tuyen tinh o day

	// ---------------------------
}

int binarySearch(string word, Item dat[], int n) {
	// Cai dat code tim kiem nhi phan o day

	// ---------------------------
}

int main() {
	Item *data = new Item[13375];
	int n;
	clock_t start;
	start = clock();
	cout << "Tai du lieu tu dien" << endl;
	loadData("mcomputer.txt", data, n);
	cout << "Tong so tu vung: " << n << endl;
	cout << "Thoi gian tai du lieu: " << clock() - start << "ms" << endl;
	string word;
	while (1) {
		cout << "Nhap tu can tra (EXIT de thoat): ";
		getline(cin,word);
		if (word == "EXIT")
			break;
		start = clock();
		// Goi ham va in ket qua tim duoc

		// ------------------------------
		cout << "Thoi gian tim: " << clock() - start << "ms" << endl;
	}
	delete[] data;
	system("pause");
	return 0;
}