#include<stdio.h>
#include<iostream>
#include<assert.h>
using namespace std;


class Date {
public:
	//1.无参构造函数   
	Date()
	{}

	//2.带参构造函数    
	Date(int year, int month, int day)
	{
		cout << "Date::Date(int,int,int)" << this << endl;
		_year = year;
		_month = month;
		_day = day;
	}

	//析构函数
	~Date() {
		cout << "Date::~Date()" << this << endl;
	}




private:
	int _year;
	int _month;
	int _day;


};

//C++中 malloc不调用构造函数
//free 不调用析构函数
//因此对象的资源一九存在，只是对内存的空间进行申请，释放的，是不对的
void TestFunc() {     //C中的内存申请
	Date* pd = (Date*)malloc(sizeof(Date));
	if (nullptr == pd) {
		assert(false);
		return;
	}
	/*
	……
	*/
	free(pd);
}

int main() {
	//对象创建
	Date d1(2019, 5, 16);
	Date d2;
	Date d3;

	int* p1 = new int;   //单个int类型的空间    //不用强制转换
	int* p2 = new int(10);   //可以初始化  //初始化10

	int array[10];    //问：数组类型——int[10]   //名字拿掉剩下的    //问元素类型——int（整型）
	int* p3 = new int[10];  
	int* p4 = new int[10]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };  //初始化

	Date* p5=new Date (2019, 5, 16);  //调用了构造函数   
	delete p5;

	Date* p6 = new Date[10];  //所指空间 10个Date对象的空间
	delete[] p6;

	delete p1;
	delete p2;
	delete[] p3;
	delete[] p4;



	system("pause");
	return 0;
}