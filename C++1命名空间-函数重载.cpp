#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>  //万能头文件
using namespace std;
//面向对象
//面向过程
//
//C++基础：C++  Primer    C++程序设计语言   C++程序设计原理实践  




//命名空间：
// N1为命名空间的名称 
namespace N1
{ 
	// 命名空间中的内容，既可以定义变量，也可以定义函数
	int a=10; 
	int b = 20;

	int Add(int left, int right) 
	{ 
		return left + right;
	}
}
  //命名空间可以嵌套
//同一个工程中允许存在多个相同名称的命名空间 
//   编译器后会合成同一个命名空间中。 
namespace N2
{
	int a = 12;
	int b = 22;

	namespace N3
	{
		int a = 20;
		int b = 30;

		int sub(int left, int right)
		{
			return left - right;
		}
	}
}



int a = 11;  //全局变量
//
//命名空间成员使用：1.N1::  
//2.用using N1::b   后面直接用b
using N1::b;
//3.using namespace N1;  将N1中的所有成员作为全局变量直接用
int main()
{
	int a = 20;


	printf("%d", a);   //打印局部
	printf("%d", ::a);  //打印全局
	printf("%d", N1::a); //打印命名空间的
	printf("%d", N2::N3::a);  //N3中的a

	
	printf("%d", b);   //配合using N1::b  

	return 0;
}	




//函数重载
//函数重载
int Add(int left, int right)
{
	return left + right;
}

double Add(double left, double right) //类型不同
{
	return left + right;
}

int Add(double a, int b, float c)  //个数不同
{
	return a + b + c;
}

int Add(int a, float b, double c)  //顺序不同
{
	return a + b + c;
}


int main() {
	Add(10, 20); Add(10.0, 20.0); Add(10L, 20L);

	return 0;
}



//传值，传地址，传引用
void swap1(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;
}

void swap2(int& ra, int& rb)
{
	int temp = ra;
	ra = rb;
	rb = temp;
}

void swap3(int* pa, int* pb)
{
	int temp = *pa;
	*pa = *pb;
	*pb = temp;
}

int main(){
	int a = 10;
	int b = 20;
	swap1(a, b);    //传值
	swap2(a, b);   //传引用
	swap3(&a, &b);  //传地址
}