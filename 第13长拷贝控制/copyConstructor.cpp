#include<iostream>
#include<string>
using namespace std;

class Sales_data {
public:
	//��ʾ����������������Զ�Ϊ��ϳɵĿ������캯��
	Sales_data(const Sales_data& s) : bookNo(s.bookNo),units_sold(s.units_sold){

	}

	Sales_data(string no, int sold) : bookNo(no), units_sold(sold) {}
private:
	string bookNo;//�� ���ͳ�Ա
	int units_sold = 0;//��ͨ����
};




void main() {
	Sales_data sd1("123",90);
	Sales_data sd2 = sd1;//��ʱ�ͻ������Ŀ������캯�����п�����ʼ��
	



	system("pause");
}