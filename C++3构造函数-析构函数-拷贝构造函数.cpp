#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>  //万能头文件
using namespace std;

//构造函数
class Date {
public:
	//1.无参构造函数   
	Date()
	{}

	//2.带参构造函数    
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

//后面函数中就可以调用：
void test()
{
	Date d1;
	Date d2(2019.5.13);  //会调用代参的构造函数
}



//析构函数
class String {
public:    
	String(const char* str = "jack")    
	{ 
		_str = (char*)malloc(strlen(str) + 1);        
		strcpy(_str, str); 
	}

	~String()     //析构函数
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




//拷贝构造函数
class Date {
public:
	Date(int year = 1900, int month = 1, int day = 1)   //构造函数，全省构造
	{
		_year = year;
		_month = month;
		_day = day;
	}

	Date(const Date& d)   //引用传递   const的含义保证正确性，不会被修改
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
	Date d1;    //对象d1
	Date d2(d1);  //对象d2拷贝构造函数
	return 0;
}

int main(){


	system("pause");
	return 0;
}

