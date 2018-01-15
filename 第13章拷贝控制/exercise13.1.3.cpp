#include<string>
#include<iostream>
using namespace std;
//13.12 析构函数调用次数
static int i = 0;
class Sales_data {
private:
	string book;
public:
	//Sales_data() = default;//让编译器合成默认构造函数，即使有其他构造函数
	Sales_data() {}
	Sales_data(const string& s) : book(s) {}
	Sales_data(const Sales_data& sd) : book(sd.book) {
		
	}
	//返回值常量，函数不能修改成员
	const string isbn() const {
		return book;
	}

	~Sales_data() {
		i++;//记录
		cout << "第 " << i << " 次调用析构函数！" << endl;
	}

};

bool fcn(const Sales_data* trans, Sales_data accum) {
	Sales_data item1(*trans);
	Sales_data item2(accum);
	//return item1.isbn() != item2.isbn();
	return true;
}

void main() {
	Sales_data one;
	Sales_data two;
	fcn(&one, two);
	system("pause");
}

//整个程序中共计进行了5次析构
//在函数fcn中 析构3次，分别是 accum,item1,item2对象，trans是引用
//最后结束时  析构2次，one，two


