#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>  //����ͷ�ļ�
using namespace std;


//auto�ؼ���
int a = 10;
auto b = a;  //int 
auto* p = a;  //int 
auto& ra = &a;   //int   ����
auto c = 'a';   //char
//auto d = TestAuto();  	//��ģ���������������	

int x = 10;
auto a = &x;
auto* b = &x;
auto& c = x;

cout << typeid(a).name() << endl;    //typeid(a).name()����������͵����ֵķ���
cout << typeid(b).name() << endl;
cout << typeid(c).name() << endl;



int main(){
	int* p = NULL;
	int* pp = nullptr;
	cout << typeid(pp).name << endl;  //����ǣ�int *
	cout << typeid(nullptr).name << endl;   //����ǣ�std::nullptr_t
}





//�����Ĵ�С
//��С�ǣ�1
//���ࣺ1�ֽ�
class A{

};


//��С�ǣ�1
//��Ա������1�ֽ�
class B{
public:
	void fun()
	{
		int a = 10;
	}
};


//��С�ǣ�16
class C{
public:
	void fun()
	{
		int a = 10;
	}
private:
	char c;  //1
	int a;   //������ 4 �ı�����ʼ��ǰ 4 ����char
	double d;   //ǰ��ռ�� 8 ��   //8+8=16
	//��Ա������� 8 = Ĭ�϶����� 8��ȡ 8 �ı��� =16
};


//��С��24
class D{
public:
	void fun()
	{
		int a = 10;
	}
private:
	char c;     //1
	double d;   //���� 8 �ı�����ǰ�˸���char  
	int a;	    //ǰ 16 �����ˣ�16 ���� 4 �ı���   //8+8+4=20
	//��Ա������� 8 = Ĭ�϶����� 8��ȡ 8 �ı���=24

};


//��С�ǣ�16
class E{
public:
	void fun()
	{
		int a = 10;
	}
private:
	double d;   //8
	char c;     //1
	int a;      //���� 4 �ı�����ʼ��ǰ 8+4(char���ĸ�) ������    //8+4+4=16
	//��Ա������� 8 = Ĭ�϶����� 8��ȡ 8 �ı���=16

};


//��С�ǣ�32
class F{
public:
	void fun()
	{
		int a = 10;
	}
private:
	double d;   //8
	char c;     //1
	int a;      //���� 4 �ı�����ʼ��ǰ 8+4(char���ĸ�) ������    //8+4+4=16
	//��Ա������� 8 = Ĭ�϶����� 8��ȡ 8 �ı���=16

	class BB{
	public:
		char c;
		double d;
	};
	//��ʱ����16����Ϊֻ�Ƕ��壬F�໹������BB

	//���������һ������ BB bb����ų�ΪF����BB
	BB bb;  //���Ǵ�С = 32
	//F���С16   BB��С 16�ֽ�   ֮��=32
	//��Ա������� 8 = Ĭ�϶����� 8��ȡ 8 �ı���=32
};

int main(){
	cout << "A:" << sizeof(A) << endl;  //����ǣ�1
	cout << "B: " << sizeof(B) << endl;	//����ǣ�1
	cout << "C:" << sizeof(C) << endl;	//����ǣ�16
	cout << "D:" << sizeof(D) << endl;	//����ǣ�24
	cout << "E:" << sizeof(E) << endl;	//����ǣ�16
	cout << "F:" << sizeof(F) << endl;	//����ǣ�32
}
//�漰�ڴ��������  VSĬ�϶��� 8 �ֽ�
//char		 һ���ֽ�
//int		 �ĸ��ֽ�
//double	 �˸��ֽ�
//VSĬ�϶�������8
