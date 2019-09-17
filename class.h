#pragma once
using namespace std;
class sch {
private:
	string date[19][6];
	float num; // 시작교시
	float Lnum; // 마지막교시


public:
	explicit sch();

	void manu();

	void start();

	void memo();

	void save_sch();

	void push();

	void input(string day, string Subject, string num, string Lnum);

	void Show();

	~sch();
	
};