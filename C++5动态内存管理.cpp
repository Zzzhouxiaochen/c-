#include<stdio.h>
#include<iostream>
#include<assert.h>
using namespace std;


class Date {
public:
	//1.�޲ι��캯��   
	Date()
	{}

	//2.���ι��캯��    
	Date(int year, int month, int day)
	{
		cout << "Date::Date(int,int,int)" << this << endl;
		_year = year;
		_month = month;
		_day = day;
	}

	//��������
	~Date() {
		cout << "Date::~Date()" << this << endl;
	}




private:
	int _year;
	int _month;
	int _day;


};

//C++�� malloc�����ù��캯��
//free ��������������
//��˶������Դһ�Ŵ��ڣ�ֻ�Ƕ��ڴ�Ŀռ�������룬�ͷŵģ��ǲ��Ե�
void TestFunc() {     //C�е��ڴ�����
	Date* pd = (Date*)malloc(sizeof(Date));
	if (nullptr == pd) {
		assert(false);
		return;
	}
	/*
	����
	*/
	free(pd);
}

int main() {
	//���󴴽�
	Date d1(2019, 5, 16);
	Date d2;
	Date d3;

	int* p1 = new int;   //����int���͵Ŀռ�    //����ǿ��ת��
	int* p2 = new int(10);   //���Գ�ʼ��  //��ʼ��10

	int array[10];    //�ʣ��������͡���int[10]   //�����õ�ʣ�µ�    //��Ԫ�����͡���int�����ͣ�
	int* p3 = new int[10];  
	int* p4 = new int[10]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };  //��ʼ��

	Date* p5=new Date (2019, 5, 16);  //�����˹��캯��   
	delete p5;

	Date* p6 = new Date[10];  //��ָ�ռ� 10��Date����Ŀռ�
	delete[] p6;

	delete p1;
	delete p2;
	delete[] p3;
	delete[] p4;



	system("pause");
	return 0;
}