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


void func(Sales_data sd) {

}

Sales_data func2(Sales_data& sd) {
	return sd;
}

void main() {
	Sales_data sd1("123",90);
	Sales_data sd2 = sd1;//��ʱ�ͻ������Ŀ������캯�����п�����ʼ��
	
	func(sd1);//��Ϊ�βΣ������ô��뺯��ͬ����

	//�����ÿ��Խ���Ϊ�ο������캯�����봫�� �������ͣ��������β��������ѭ��

	func2(sd2);//��Ϊ����ֵʱҲ��
	
}