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

void saveData(char file[], Item dat[], int n) {
	ofstream fo(file);
	if (!fo.is_open()) {
		cout << "Khong mo duoc file de ghi" << endl;
		return;
	}
	string s;
	int b;
	for (int i = 0; i < n; i++) {
		while ((b = dat[i].meaning.find("\n")) > -1)
			dat[i].meaning.replace(b, 2, "|=");
		fo << dat[i].word << "\t" << dat[i].meaning << endl;
	}
	fo.flush();
	fo.close();
}

void sortBySelection(Item dat[], int n) {
	// Cai dat code Chon Truc Tiep o day
    int min;
    for (int i = 0; i < n-1; i++) {
        min = i;
        for (int j = i+1; j < n; j++)
            if (dat[j].word.compare(dat[min].word)<0) min = j;
        swap(dat[i], dat[min]);
    }
}
	// ---------------------------

void sortByInsertion(Item dat[], int n) {
	// Cai dat code Chen Truc Tiep o day
    for (int i = 1; i < n; i++) {
    Item e = dat[i]; int k;
    for (k = i-1; k>-1; k--) {
        if (dat[k].word.compare(e.word)<0) break;
            dat[k+1] = dat[k];
    }
    dat[k+1] = e;
}

	// ---------------------------
}

void sortByInterchange(Item dat[], int n) {
	// Cai dat code Doi Cho Truc Tiep o day

	// ---------------------------
}

void sortByBubble(Item dat[], int n) {
	// Cai dat code Sap xep Noi Bot o day

	// ---------------------------
}

void sortByHeap(Item dat[], int n) {
	// Cai dat code Sap xep Vun Dong o day

	// ---------------------------
}

void sortByMerge(Item dat[], int n) {
	// Cai dat code Sap xep Tron o day

	// ---------------------------
}

void sortByQuick(Item dat[], int n) {
	// Cai dat code Sap xep Nhanh o day

	// ---------------------------
}

void sortByShell(Item dat[], int n) {
	// Cai dat code Sap xep Chen Voi Buoc Nhay Giam Dan o day

	// ---------------------------
}
int getMax(Item arr[], int n){
	int Max = arr[0].word.size();
	for (int i = 0; i < n; i++) {
		if(arr[i].word.size()>Max) Max=arr[i].word.size();
	}
	return Max;
}
void countSort(Item arr[], int size, int exp){
	Item *output= new Item[size];
	int count[257] = { 0 };
	int temp;
	for (int i=0;i<size;i++){
		if(exp<arr[i].word.size()) temp = (arr[i].word)[exp];
		else temp=0;
		count[temp]++;
	}
	for (int j =1;j<257;j++){
		count[j]+=count[j-1];
	}
	for (int  k = size-1; k >=0; k--) {
		if(exp<arr[k].word.size()) temp = (arr[k].word)[exp];
		else temp=0;
		count[temp]--;
		output[count[temp]]=arr[k];
	}
	for (int l=0;l<size;l++){
		arr[l]=output[l];
	}
	delete[] output;
	delete[] count;
}
void sortByRadix(Item dat[], int n) {
	// Cai dat code Sap xep Co So o day
	int max = getMax(dat, n);
	// cout<<max<<endl;
	for (int digit = max; digit >= 0; digit--){
		countSort(dat, n, digit );
	}
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
	start = clock();
	// Goi ham sap xep
	int max=getMax(data,n);
  sortByRadix(data,n);
	// ------------------------------
	cout << "Thoi gian sap xep: " << clock() - start << "ms" << endl;
	saveData("rcomputer.txt", data, n);
	system("pause");
	return 0;
}
