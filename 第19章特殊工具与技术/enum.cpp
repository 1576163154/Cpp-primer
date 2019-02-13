#include<iostream>
using std::cout;
using std::endl;
//有限定作用域的enum 类型
enum class color {
	yellow = 1,
	blue,
	green
};

//不限定作用域
enum fruit {orange,grape,apple};

//制定enum 数据类型,限定为整型，默认为int
enum animal : short {
	tiger = 2,
	lion = 5,
	elephant =8,
};

enum planet : unsigned int;//前置声明需要制定类型
enum class element;//限定作用域，不需要，默认为int

//定义部分
enum planet unsigned int{
	solar = 3,
	jupiter,
	moon,
};
void main() {

	color c = color::blue;//需通过 color::blue 获取blue 
	fruit f = orange;//不需要
	int a = orange;
	cout << a << endl;
	system("pause");
}