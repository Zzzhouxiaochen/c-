#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>  //����ͷ�ļ�
using namespace std;

//���캯��
class Date {
public:
	//1.�޲ι��캯��   
	Date()
	{}

	//2.���ι��캯��    
	Date(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}

private:
	int _year;
	int _month;
	int _day;
};

//���溯���оͿ��Ե��ã�
void test()
{
	Date d1;
	Date d2(2019.5.13);  //����ô��εĹ��캯��
}



//��������
class String {
public:    
	String(const char* str = "jack")    
	{ 
		_str = (char*)malloc(strlen(str) + 1);        
		strcpy(_str, str); 
	}

	~String()     //��������
	{ 
		cout << "~String()" << endl;        
		free(_str); 
	} 
private:    
	char* _str;
};


class Person 
{ 
private:    
	String _name;    
	int    _age; 
};

int main() 
{ 
	Person p;    
	return 0; 
}




//�������캯��
class Date {
public:
	Date(int year = 1900, int month = 1, int day = 1)   //���캯����ȫʡ����
	{
		_year = year;
		_month = month;
		_day = day;
	}

	Date(const Date& d)   //���ô���   const�ĺ��屣֤��ȷ�ԣ����ᱻ�޸�
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1;    //����d1
	Date d2(d1);  //����d2�������캯��
	return 0;
}

int main(){


	system("pause");
	return 0;
}

