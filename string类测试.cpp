#include <algorithm>
#include<iostream>
#include <string>
#include  <sstream> 
using namespace std;


int main() {
	string s1;   //���ַ���
	string s2(10, '$');  //ʮ�� $
	string s3("hello world");  //hello word
	string s4("ABCD");
	string s5("ABCDEFGH");

	cout << s3.size() << endl;
	cout << s3.length() << endl; //�������ַ�������  11
	cout << s3.capacity() << endl; //��s3������
	s3.push_back('A');
	cout << s3 << endl; 

	s3.append("ABC");
	cout << s3 << endl; 

	s4.insert(2, 3, 'A');
	cout << s4 << endl; 

	s4.insert(2,"ABC");
	s4.insert(2, "ABC", 1);
	s4.insert(2, "ABC", 1, 1);
	s4.insert(2, "ABC", 1, string::npos);
	s4.insert(++s4.begin(), 2, 'a');
	string str1("abc");
	s4.insert(s4.begin(), str1.begin(), str1.end());
	s4.erase(2);
	s4.erase(2,1);
	s4.clear();  //���
	s5.replace(2, 4, "abcd");
	if (s4.empty()) {
		printf("%d", 1);
		}
	s4.assign("ABC", 1, 1);
	s4.assign(5,'A');
	reverse(s4.begin(), s4.end());
	int n=s4.find("ABC");
	int n = s4.find("B",1);
	int n = s4.rfind("ABC");
	printf("%d", n);
	cout << s4 << endl; 

	s3.clear();  //���
	string s14(s3); //s4 �� s3һ��
	istringstream zxc("5200.1314");    //�������iss,ͬʱ��ʼ��Ϊ  
	//��ʵ���ǣ�    istringstream zxc;    zxc.str("123.5");                 

	double num;

	zxc >> num;               //ͨ������iss.operator >>(num), ��"123.5"תΪ����,������bool���ͱ���
	cout << num << endl;

	string str = "520.1";

	double num;

	istringstream(str) >> num;
	cout << num << endl;


	ostringstream zxc;
	zxc << 520.1;                   //�൱�ڵ���: oss.str("123.5");
	string str = zxc.str();
	cout << str << endl;

	system("pause");
	return 0;
}