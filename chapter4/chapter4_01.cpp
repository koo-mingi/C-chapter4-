#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int arr[100][100], cnt, k;
ifstream fin("in.txt");
ofstream fout("out.txt"); //현재 프로젝트가 존재하는 위치에 저장.

void print() {
	for (int i = 0; i < k + 1; i++) {
		for (int j = 0; j < k + 1; j++) {
			fout << setw(5) << arr[i][j];
		}
		fout << endl;
	}
}

void main() {

	fin >> k; // 파일로부터 입력을 받는다. 즉, 파일의 내용을 읽는다.
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < k; j++) {
			arr[i][j] = ++cnt;
			arr[i][k] += arr[i][j];
			arr[k][j] += arr[i][j];
			arr[k][k] += cnt;
		}
	}
	print();
}




