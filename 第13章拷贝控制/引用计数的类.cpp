#include<iostream>
#include<string>
using namespace std;

//行为像引用的类
class HasPtr {
private:
	string* ps;
	int i;
	unsigned int* use;
public:
	HasPtr(string* str = new string()) : ps (str),i(0),use((unsigned int)(1)){}//带一个可选参数的构造函数
	HasPtr(const HasPtr& hp) : ps(hp.ps), i(hp.i), use(hp.use) {
		++(*use);
	}
	//流程，先析构左边，再拷贝
	HasPtr& operator=(const HasPtr& hp)  {
		 //处理自赋值
		
		++(*hp.use);//防止被delete，先递增引用计数
		if (--(*use) == 0) {
			delete use;
			delete ps;
			//注： ++*(hp.use)为左值（变量，可进行赋值,修改）
			//			(*hp.use)++ 为右值（表达式，临时）
		}
		ps = hp.ps;
		use = hp.use;
		i = hp.i;
		return *this;
		
	}

	// 析构一个对象时，递减一次引用计数
	~HasPtr() {
		--(*use);
		if (*use == 0) {
			delete ps;
			delete use;
		}
	}
};