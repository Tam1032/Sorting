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

void heapify(Item *a, int k, int n) {
	int j = 2*k+1;
	while (j < n) {
		if (j + 1 < n)
		if (a[j].word<a[j + 1].word) j = j + 1;
		if (a[k].word<a[j].word) return;
		swap(a[k], a[j]);
		k = j; j = 2*k + 1;
	}
}

void buildHeap(Item *a, int n) {
  int i;
  i = n/2 - 1;
  while (i >= 0) {
    heapify(a, i, n);
    i--;
  }
}

void sortByHeap(Item dat[], int n) {
	// Cai dat code Sap xep Vun Dong o day
	buildHeap(dat, n);
	while (n > 0) {
		n = n - 1;
		swap(dat[0], dat[n]);
		heapify(dat, 0, n);
	}
	// ---------------------------
}


void merge(Item arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    Item L[n1], R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    int i = 0;
    int j = 0;
    int k = l;
    while (i < n1 && j < n2) {
        if (L[i].word.compare(R[j].word) <= 0 ) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}


void mergeSort(Item arr[],int l,int r){
    if(l>=r){
        return;//returns recursively
    }
    int m =l+ (r-l)/2;
    mergeSort(arr,l,m);
    mergeSort(arr,m+1,r);
    merge(arr,l,m,r);
}
void sortByMerge(Item dat[], int n) {
	// Cai dat code Sap xep Tron o day
	mergeSort(dat,0,n-1);
	// ---------------------------
}

int Partition(Item arr[], int low, int high){
    Item pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high ; j++)
    {
        if (arr[j].word<pivot.word)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}
void quickSort(Item a[], int left, int right) {
	if (left >= right) return;
	int partitioningIndex = Partition(a,left,right);
	quickSort(a, left, partitioningIndex-1);
	quickSort(a, partitioningIndex+1, right);
}
void sortByQuick(Item dat[], int n) {
	// Cai dat code Sap xep Nhanh o day
	quickSort(dat, 0, n-1);
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
	loadData((char*)"mcomputer.txt", data, n);
	cout << "Tong so tu vung: " << n << endl;
	cout << "Thoi gian tai du lieu: " << clock() - start << "ms" << endl;
	string word;
	start = clock();
	// Goi ham sap xep
  sortByQuick(data,n);
	// ------------------------------
	cout << "Thoi gian sap xep: " << clock() - start << "ms" << endl;
	saveData((char*)"rcomputer.txt", data, n);
	system("pause");
	return 0;
}
