#include<stdio.h>
#include<iostream>

using namespace std;


//运算符重载
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

	//如果一个函数的返回值类型是类类型对象的情况下，优先考虑返回引用，不能引用，就值返回
	//有个前提：能够返回引用的情况下
	//+进行了重载
	//只能进行值返回，因为 + 的使用不会改变左右值的内容
	Date operator+(int days)
	{
		Date temp(*this);     //保存了_day
		temp._day += days;
		return temp;    
		//返回对象就是this
	}

	//==  重载
	bool operator==(const Date& d)  //当前对象的年  =  d 对象的年
	{
		return _year == d._year  &&  
			_month == d._month  &&
			_day == d._day;
	}

	//!=   重载
	bool operator!=(const Date& d)
	{
		return !(*this == d);
	}


	////=（赋值运算符）重载，没有返回值
	//void operator=(const Date& d){
	//	_year = d._year;
	//	_month = d._month;
	//	_day = d._day;
	//}


	//=（赋值运算符）重载，没有返回值
	//if  判断是不是给自己赋值
	//给引用参数 效率高，
	//const 不用修改有操作数的内容
	Date& operator=(const Date& d) {
		if (this != &d) {
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return* this;  //返回函数对象比函数生命周期长 所以可以进行引用返回
	}


	//前置++
	//++d1
	Date& operator++(){
		_day += 1;
		return *this;   //返回当前对象，引用返回
	}

	//后置++
	//d1++
	//加 int 实现函数重载
	Date operator++(int){
		Date temp(*this);
		_day += 1;
		return temp;   //返回函数栈里面的对象，就是值返回   //int  固定的
	}



//const修饰成员函数
	//实际修饰该成员函数隐含的this指针
	void PrintDate()const {
		cout << _year << "-" << _month << "-" << _day << endl;
	}

	//const Date * const this：this所指向的内容不能改




private:
	int _year;
	int _month;
	mutable int _day;


	//const修饰成员函数
	//const Date * const this：this所指向的内容不能改
	//实际修饰该成员函数隐含的this指针
	void PrintDate()const {
		this->_day += 1;   //被mutable修饰了，所以可以修改
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
	a = b = c;  //重载之后这样也可以

	Date d1(2019, 5, 16);
	Date d2;
	Date d3;
// = 运算符重载测试
	//调用没有返回值的重载：
		//d3 = d2 = d1;   //这样就是错的
		////因为赋值过程是：从右往左依次来做，

		//d2.operator=(d1);
		//d3.operator=(上条语句的结果，因为没有返回值所以是错的)

	//调用返回值的重载
		d3 = d2 = d1;   //这样就是对的


// + 运算符重载测试
	//Date类   不重载加号用不了
	d2 = d1 + 1;  //重载之后成功
	d2 = d1;   //也可以赋值成功


// == 运算符重载测试
	if (d1 == d2){
		cout << "d1==d2" << endl;
	}
	else{
		cout << "错" << endl;
	}


//++运算符重载测试
	d2 = d1++;  //d1赋值结束，+1  
	d2 = ++d1;   //d1 +1 结束，赋值  

//问： const对象可以调用非const成员函数吗？
	const Date d1(2019, 5, 16);
	d1.PrintDate();  //错的

	void PrintDate() {
		//改成员函数是可以修改当前对象成员的
		cout << _year << "-" << _month << "-" << _day << endl;
	}

	//但是：这是不可以被修改的，就是会有矛盾
	const Date d1(2019, 5, 16);



//问：非const对象可以调用const成员函数吗？
	Date d1(2019, 5, 16);
	d1.PrintDate();  //对的

	void PrintDate() const{
		//改成员函数是不可以修改当前对象成员的
		cout << _year << "-" << _month << "-" << _day << endl;
	}

	//但是：这是可以被不修改的，所以就可以
	Date d1(2019, 5, 16);



//问：const成员函数内可以调用其它的非const成员函数吗？
	void PrintDate()const {   //错的
		 PrintDate();  
	}
	//因为 PrintDate() 会修改成员变量，void PrintDate()const 不能修改，就是矛盾，有问题


	void PrintDate() const{
		//改成员函数是不可以修改当前对象成员的
		cout << _year << "-" << _month << "-" << _day << endl;
	}
	void PrintDate() {
		//改成员函数是可以修改当前对象成员的
		cout << _year << "-" << _month << "-" << _day << endl;
	}




//问：非const成员函数内可以调用其它的const成员函数吗？
	void PrintDate() {   //错的
		PrintDate() const;
	}
	//因为 PrintDate() 会修改成员变量，void PrintDate()const 不能修改，但是也是成员函数，只是只读。
	//只读的放在可读可写的里面就是安全的


	void PrintDate() const{
		//改成员函数是不可以修改当前对象成员的
		cout << _year << "-" << _month << "-" << _day << endl;
	}
	void PrintDate() {
		//改成员函数是可以修改当前对象成员的
		cout << _year << "-" << _month << "-" << _day << endl;
	}






	system("pause");
	return 0;
}


