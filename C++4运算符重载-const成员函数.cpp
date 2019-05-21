#include<stdio.h>
#include<iostream>

using namespace std;


//���������
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

	//���һ�������ķ���ֵ�����������Ͷ��������£����ȿ��Ƿ������ã��������ã���ֵ����
	//�и�ǰ�᣺�ܹ��������õ������
	//+����������
	//ֻ�ܽ���ֵ���أ���Ϊ + ��ʹ�ò���ı�����ֵ������
	Date operator+(int days)
	{
		Date temp(*this);     //������_day
		temp._day += days;
		return temp;    
		//���ض������this
	}

	//==  ����
	bool operator==(const Date& d)  //��ǰ�������  =  d �������
	{
		return _year == d._year  &&  
			_month == d._month  &&
			_day == d._day;
	}

	//!=   ����
	bool operator!=(const Date& d)
	{
		return !(*this == d);
	}


	////=����ֵ����������أ�û�з���ֵ
	//void operator=(const Date& d){
	//	_year = d._year;
	//	_month = d._month;
	//	_day = d._day;
	//}


	//=����ֵ����������أ�û�з���ֵ
	//if  �ж��ǲ��Ǹ��Լ���ֵ
	//�����ò��� Ч�ʸߣ�
	//const �����޸��в�����������
	Date& operator=(const Date& d) {
		if (this != &d) {
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return* this;  //���غ�������Ⱥ����������ڳ� ���Կ��Խ������÷���
	}


	//ǰ��++
	//++d1
	Date& operator++(){
		_day += 1;
		return *this;   //���ص�ǰ�������÷���
	}

	//����++
	//d1++
	//�� int ʵ�ֺ�������
	Date operator++(int){
		Date temp(*this);
		_day += 1;
		return temp;   //���غ���ջ����Ķ��󣬾���ֵ����   //int  �̶���
	}



//const���γ�Ա����
	//ʵ�����θó�Ա����������thisָ��
	void PrintDate()const {
		cout << _year << "-" << _month << "-" << _day << endl;
	}

	//const Date * const this��this��ָ������ݲ��ܸ�




private:
	int _year;
	int _month;
	mutable int _day;


	//const���γ�Ա����
	//const Date * const this��this��ָ������ݲ��ܸ�
	//ʵ�����θó�Ա����������thisָ��
	void PrintDate()const {
		this->_day += 1;   //��mutable�����ˣ����Կ����޸�
		cout << _year << "-" << _month << "-" << _day << endl;
	}





private:
	int _year;
	int _month;
	int _day;


};

int main(){
	int a = 1;
	int b = 2;
	int c = a + b;
	a = b = c;  //����֮������Ҳ����

	Date d1(2019, 5, 16);
	Date d2;
	Date d3;
// = ��������ز���
	//����û�з���ֵ�����أ�
		//d3 = d2 = d1;   //�������Ǵ��
		////��Ϊ��ֵ�����ǣ�������������������

		//d2.operator=(d1);
		//d3.operator=(�������Ľ������Ϊû�з���ֵ�����Ǵ��)

	//���÷���ֵ������
		d3 = d2 = d1;   //�������ǶԵ�


// + ��������ز���
	//Date��   �����ؼӺ��ò���
	d2 = d1 + 1;  //����֮��ɹ�
	d2 = d1;   //Ҳ���Ը�ֵ�ɹ�


// == ��������ز���
	if (d1 == d2){
		cout << "d1==d2" << endl;
	}
	else{
		cout << "��" << endl;
	}


//++��������ز���
	d2 = d1++;  //d1��ֵ������+1  
	d2 = ++d1;   //d1 +1 ��������ֵ  

//�ʣ� const������Ե��÷�const��Ա������
	const Date d1(2019, 5, 16);
	d1.PrintDate();  //���

	void PrintDate() {
		//�ĳ�Ա�����ǿ����޸ĵ�ǰ�����Ա��
		cout << _year << "-" << _month << "-" << _day << endl;
	}

	//���ǣ����ǲ����Ա��޸ĵģ����ǻ���ì��
	const Date d1(2019, 5, 16);



//�ʣ���const������Ե���const��Ա������
	Date d1(2019, 5, 16);
	d1.PrintDate();  //�Ե�

	void PrintDate() const{
		//�ĳ�Ա�����ǲ������޸ĵ�ǰ�����Ա��
		cout << _year << "-" << _month << "-" << _day << endl;
	}

	//���ǣ����ǿ��Ա����޸ĵģ����ԾͿ���
	Date d1(2019, 5, 16);



//�ʣ�const��Ա�����ڿ��Ե��������ķ�const��Ա������
	void PrintDate()const {   //���
		 PrintDate();  
	}
	//��Ϊ PrintDate() ���޸ĳ�Ա������void PrintDate()const �����޸ģ�����ì�ܣ�������


	void PrintDate() const{
		//�ĳ�Ա�����ǲ������޸ĵ�ǰ�����Ա��
		cout << _year << "-" << _month << "-" << _day << endl;
	}
	void PrintDate() {
		//�ĳ�Ա�����ǿ����޸ĵ�ǰ�����Ա��
		cout << _year << "-" << _month << "-" << _day << endl;
	}




//�ʣ���const��Ա�����ڿ��Ե���������const��Ա������
	void PrintDate() {   //���
		PrintDate() const;
	}
	//��Ϊ PrintDate() ���޸ĳ�Ա������void PrintDate()const �����޸ģ�����Ҳ�ǳ�Ա������ֻ��ֻ����
	//ֻ���ķ��ڿɶ���д��������ǰ�ȫ��


	void PrintDate() const{
		//�ĳ�Ա�����ǲ������޸ĵ�ǰ�����Ա��
		cout << _year << "-" << _month << "-" << _day << endl;
	}
	void PrintDate() {
		//�ĳ�Ա�����ǿ����޸ĵ�ǰ�����Ա��
		cout << _year << "-" << _month << "-" << _day << endl;
	}






	system("pause");
	return 0;
}


