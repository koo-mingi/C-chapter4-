#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

string name[5];
int sung[5][6], cnt, k,i,j,gra;
ifstream fin("in_1.txt");
ofstream fout("out_2.txt"); //���� ������Ʈ�� �����ϴ� ��ġ�� ����.
//5�� �л��� 3���� ���� �Է¹ޱ�
void input() {
	
	for (i = 0; i < 5; i++) {
		fin>>name[i];
		for (j = 0; j < 3; j++) {
			fin >> sung[i][j];
		}
	}
}

//������ �հ�� ���
void process() {

	for (i = 0; i < 5; i++) {
		for (j = 0; j < 3; j++) {
			sung[i][3] += sung[i][j];
		}
		sung[i][4] = sung[i][3] / 3;
		//cout << sung[i][3] << "  "<<sung[i][4]<<endl;
	}

}

//����
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

//��¹��� �̿��ؼ� �ð�ȭ
void visual() {
	gra = sung[i][4] / 10;
	fout << setw(7);
	for (k = 0; k < gra; k++) {
		fout << "��";
	}
}


//���
void print() {
	fout << setw(6) <<"�̸�"<< setw(6) << "JAVA" << setw(6) << "C++" << setw(7) << "Python"
		<< setw(6) << "����" << setw(6) << "���" << setw(6) << "����" << setw(10) << "�׷���" << endl;
	for (i = 0; i < 5; i++) {
		//�̸� ���
		fout << setw(6) << name[i];

		//���� ���
		for (j = 0; j < 6; j++) {
			fout << setw(6) << sung[i][j];
		}
		visual();
		fout << endl;
	}
}



//����
int main(void) {
	input();
	process();
	ranking();
	print();

}

