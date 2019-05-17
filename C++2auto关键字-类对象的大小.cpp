#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>  //万能头文件
using namespace std;


//auto关键字
int a = 10;
auto b = a;  //int 
auto* p = a;  //int 
auto& ra = &a;   //int   引用
auto c = 'a';   //char
//auto d = TestAuto();  	//错的，不能做函数参数	

int x = 10;
auto a = &x;
auto* b = &x;
auto& c = x;

cout << typeid(a).name() << endl;    //typeid(a).name()：求变量类型的名字的方法
cout << typeid(b).name() << endl;
cout << typeid(c).name() << endl;



int main(){
	int* p = NULL;
	int* pp = nullptr;
	cout << typeid(pp).name << endl;  //结果是：int *
	cout << typeid(nullptr).name << endl;   //结果是：std::nullptr_t
}





//类对象的大小
//大小是：1
//空类：1字节
class A{

};


//大小是：1
//成员函数：1字节
class B{
public:
	void fun()
	{
		int a = 10;
	}
};


//大小是：16
class C{
public:
	void fun()
	{
		int a = 10;
	}
private:
	char c;  //1
	int a;   //必须是 4 的倍数开始，前 4 个放char
	double d;   //前面占了 8 个   //8+8=16
	//成员变量最大 8 = 默认对齐数 8，取 8 的倍数 =16
};


//大小：24
class D{
public:
	void fun()
	{
		int a = 10;
	}
private:
	char c;     //1
	double d;   //必须 8 的倍数，前八个放char  
	int a;	    //前 16 个放了，16 又是 4 的倍数   //8+8+4=20
	//成员变量最大 8 = 默认对齐数 8，取 8 的倍数=24

};


//大小是：16
class E{
public:
	void fun()
	{
		int a = 10;
	}
private:
	double d;   //8
	char c;     //1
	int a;      //必须 4 的倍数开始，前 8+4(char放四个) 个放了    //8+4+4=16
	//成员变量最大 8 = 默认对齐数 8，取 8 的倍数=16

};


//大小是：32
class F{
public:
	void fun()
	{
		int a = 10;
	}
private:
	double d;   //8
	char c;     //1
	int a;      //必须 4 的倍数开始，前 8+4(char放四个) 个放了    //8+4+4=16
	//成员变量最大 8 = 默认对齐数 8，取 8 的倍数=16

	class BB{
	public:
		char c;
		double d;
	};
	//这时候还是16，因为只是定义，F类还不包含BB

	//如果创建了一个对象 BB bb，这才成为F包含BB
	BB bb;  //这是大小 = 32
	//F类大小16   BB大小 16字节   之和=32
	//成员变量最大 8 = 默认对齐数 8，取 8 的倍数=32
};

int main(){
	cout << "A:" << sizeof(A) << endl;  //结果是：1
	cout << "B: " << sizeof(B) << endl;	//结果是：1
	cout << "C:" << sizeof(C) << endl;	//结果是：16
	cout << "D:" << sizeof(D) << endl;	//结果是：24
	cout << "E:" << sizeof(E) << endl;	//结果是：16
	cout << "F:" << sizeof(F) << endl;	//结果是：32
}
//涉及内存对齐问题  VS默认对齐 8 字节
//char		 一个字节
//int		 四个字节
//double	 八个字节
//VS默认对齐数是8
