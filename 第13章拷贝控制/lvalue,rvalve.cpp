#include<vector>
#include<iostream>
#include<utility>
using namespace std;

int f() {
	return 1;
}

void main() {
	//左值引用（即常用引用类型,位于 = 运算符 左边
	int i = 42;
	int& lvi = i;//ri 为 42 的左值引用

	//右值引用（即位于 = 运算符 右边，且不能作为左值
	const int& lvi2 = i;
	//int&& rvi = i;
	int&& rvi = i * 3;
	int b = rvi;
	cout << rvi << endl;

	int&& rvi2 = 45;
	//int&& rvi3 = rvi2;一个右值引用不能绑定到另外一个右值引用
	//使用std::move来实现 右值引用 绑定到一个 右值变量
	int&& rvi4 = std::move(rvi2);

	//16.46
	vector<int> vi(100);
	int&& r1 = f();//非引用返回值作为 右值
	int& r2 = vi[0];
	//int&& r3 = vi[0]; vi[0]是左值，不能将一个左值绑定到右值
	int& r4 = vi[0];
	int&& r5 = vi[0] * f();//计算结果为右值
	system("pause");
}