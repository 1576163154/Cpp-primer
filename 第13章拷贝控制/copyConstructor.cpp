#include<iostream>
#include<string>
using namespace std;

class Sales_data {
public:
	//显示声明定义编译器会自动为类合成的拷贝构造函数
	Sales_data(const Sales_data& s) : bookNo(s.bookNo),units_sold(s.units_sold){

	}

	Sales_data(string no, int sold) : bookNo(no), units_sold(sold) {}
private:
	string bookNo;//类 类型成员
	int units_sold = 0;//普通类型
};


void func(Sales_data sd) {

}

Sales_data func2(Sales_data& sd) {
	return sd;
}

void main() {
	Sales_data sd1("123",90);
	Sales_data sd2 = sd1;//此时就会调用类的拷贝构造函数进行拷贝初始化
	
	func(sd1);//作为形参（非引用传入函数同样会

	//这正好可以解释为何拷贝构造函数必须传入 引用类型，若传入形参则进入死循环

	func2(sd2);//作为返回值时也会
	
}