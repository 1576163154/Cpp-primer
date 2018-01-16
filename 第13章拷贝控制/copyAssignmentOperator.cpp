#include<string>
using namespace std;
class Foo {
public:
	//显示声明定义，编译器会为我们合成的默认赋值运算符
	Foo(int o, string n) : one(o),name(n){

	}
	Foo() {}
	Foo& operator=(const Foo& f) {
		one = f.one;
		name = f.name;
		return *this;
	}
private:
	int one;
	string name;
};

void main() {
	Foo one, two(2, "lala");
	one = two;//两个对象赋值操作时调用 拷贝赋值运算符
	Foo three;
	three.operator=(two);//上述代码可写为 纯粹的函数调用

}