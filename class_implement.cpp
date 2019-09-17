#include "header.h"

sch::sch() {
	int Ck = 1;
	int ab = 1;

	date[0][0] = " ";
	for (int k = 1; k < 19; k++)
	{
		if (ab != 0)
		{
			this->date[k][0] = to_string(Ck) + 'A';
			ab = 0;
		}
		else
		{
			this->date[k][0] = to_string(Ck)+'B';
			ab = 1;
			Ck++;
		}
	}

	date[0][1] = "������";
	date[0][2] = "ȭ����";
	date[0][3] = "������";
	date[0][4] = "�����";
	date[0][5] = "�ݿ���";
}

void sch::manu() {
	cout << "1: �Է�" << endl;
	cout << "2: ���" << endl;
	cout << "3: ������" << endl;
	cout << "4: ����� �ð�ǥ" << endl;
	cout << "q: ������" << endl;
}

void sch::start() {
	int ch = 5;
	char cp;
	manu();
	while (ch == 5) {
		if (kbhit()) {
			cp = getch();
			switch (cp) {
			case '1':
				system("cls");
				push();
				system("pause");
				system("cls");
				manu();
				break;
			case '2':
				system("cls");
				Show();
				system("pause");
				system("cls");
				manu();
				break;
			case '3':
				system("cls");
				memo();
				system("pause");
				system("cls");
				manu();
				break;
			case '4':
				system("cls");
				save_sch();
				system("pause");
				system("cls");
				manu();
				break;
			case 'q':
			case 'Q':
				ch = 4;
				break;
			default:;
			}
		}
	}
}

void sch::memo() {
	ifstream is;
	string buf;
	is.open("d:\\20141250\\C++\\data.txt");
	while (getline(is, buf)) {
		cout << buf << endl;
	}
	is.close();
}

void sch::save_sch() {
	ifstream is;
	string buf;
	is.open("d:\\20141250\\C++\\sch.txt");
	while (getline(is, buf)) {
		cout << buf << endl;
	}
	is.close();
}

void sch::push() {
	string day;
	string sub;
	string FT;
	string LT;
	string temp;
	string buf;
	int count = 0;
	ifstream is;
//	is.exceptions(is.failbit | is.badbit);
	is.open("d:\\20141250\\C++\\data.txt");

	while (getline(is, temp)) {
		stringstream tok(temp);
		while (tok >> buf) {
			if (count == 0) {
				if (buf == "#") {
					break;
				}
				else {
					day = buf;
					count++;
				}
			}
			else if (count == 1) {
				sub = buf;
				count++;
			}
			else if (count == 2) {
				FT = buf;
				count++;
			}
			else if (count == 3) {
				if (FT == LT) {
					LT = "";
					input(day, sub, FT, LT);
					count = 0;
				}
				else {
					LT = buf;
					input(day, sub, FT, LT);
					count = 0;
				}
			}
		}
	}

	is.close();
}

void sch::input(string day, string Subject, string num, string Lnum) {
	int find_Ftime = 0;
	int find_Ltime = 0;
	int find_day = 0;
	for (int k = 1; k < 6; k++)
	{
		if (!this->date[0][k].find(day)) {
			find_day = k;
		}
	}
	for (int k = 1; k < 19; k++)
	{
		if (!this->date[k][0].find(num)) {
			find_Ftime = k;
		}
	}
	for (int k = 1; k < 19; k++)
	{
		if (!this->date[k][0].find(Lnum)) {
			find_Ltime = k;
		}
	}

	for (int k = find_Ftime; k <= find_Ltime; k++)
	{
		if (!date[k][find_day].empty() && date[k][find_day] != Subject) {
			cout << date[0][find_day] << "�� �����: " << Subject << " ������ ��Ĩ�ϴ�. data������ Ȯ���ϼ���. " << endl;
			return;
		}
		else {
		}
	}
	for (int k = find_Ftime; k <= find_Ltime; k++)
	{
		date[k][find_day] = Subject;
	}



}


void sch::Show() {
	ofstream os;
	os.open("d:\\20141250\\C++\\sch.txt");
	cout << this->date[0][0] << "     ";
	os << this->date[0][0] << "     ";
	for (int k = 1; k < 6; k++)
	{
		cout <<"��  " << this->date[0][k] << "  ��";
		os << "��  " << this->date[0][k] << "  ��";
	}
	cout << "\n�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�";
	cout << endl;
	os << "\n�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�";
	os << endl;

	for (int one = 1; one < 19; one++) {
		for (int two = 0; two < 6; two++) {
			if (this->date[one][two].empty() && two != 0) {
				cout << "��          ��";
				os << "��          ��";

			}
			else {
				if (two != 0) {
					cout << "��";
					cout.width(9);
					cout.fill(' ');
					cout << this->date[one][two];
					cout.width(1);
					cout << " ��";
					os << "��";
					os.width(9);
					os.fill(' ');
					os << this->date[one][two];
					os.width(1);
					os << " ��";
				}
				else {
					cout << "   " << this->date[one][two] << " ";
					os << "   " << this->date[one][two] << " ";
				}
			}
		}
		cout << "\n�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n";
		os << "\n�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n";
	}
	os.close();
}

sch::~sch() {
	
}