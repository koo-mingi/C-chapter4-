#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

string name[5];
int sung[5][6], cnt, k,i,j,gra;
ifstream fin("in_1.txt");
ofstream fout("out_2.txt"); //현재 프로젝트가 존재하는 위치에 저장.
//5명 학생의 3과목 성적 입력받기
void input() {
	
	for (i = 0; i < 5; i++) {
		fin>>name[i];
		for (j = 0; j < 3; j++) {
			fin >> sung[i][j];
		}
	}
}

//성적의 합계와 평균
void process() {

	for (i = 0; i < 5; i++) {
		for (j = 0; j < 3; j++) {
			sung[i][3] += sung[i][j];
		}
		sung[i][4] = sung[i][3] / 3;
		//cout << sung[i][3] << "  "<<sung[i][4]<<endl;
	}

}

//석차
void ranking() {

	for (i = 0; i < 5; i++) {
		sung[i][5] = 1;

		for (j = 0; j < 5; j++) {
			if (sung[i][4] < sung[j][4]) {
				sung[i][5]++;
			}
		}
		cout << sung[i][5]<<" "<<endl;
	}
}

//출력문을 이용해서 시각화
void visual() {
	gra = sung[i][4] / 10;
	fout << setw(7);
	for (k = 0; k < gra; k++) {
		fout << "★";
	}
}


//출력
void print() {
	fout << setw(6) <<"이름"<< setw(6) << "JAVA" << setw(6) << "C++" << setw(7) << "Python"
		<< setw(6) << "총점" << setw(6) << "평균" << setw(6) << "석차" << setw(10) << "그래프" << endl;
	for (i = 0; i < 5; i++) {
		//이름 출력
		fout << setw(6) << name[i];

		//점수 출력
		for (j = 0; j < 6; j++) {
			fout << setw(6) << sung[i][j];
		}
		visual();
		fout << endl;
	}
}



//메인
int main(void) {
	input();
	process();
	ranking();
	print();

}

