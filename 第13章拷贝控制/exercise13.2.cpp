#include<iostream>
#include<string>
#include<memory>
#include<vector>
using namespace std;

//行为像值的类，普通指针
class HasPtr {
public:
	HasPtr() = default;
	HasPtr(string& s) : ps( new string(s)), i(0) {}
	HasPtr(const HasPtr& m) : ps(new string(*m.ps)),i(m.i){}
	//拷贝赋值运算符
	HasPtr& operator=(const HasPtr& hp) {
		//需考虑到自赋值的情况
		//auto tmpPtr = hp.ps;//这样写tmpPtr和hp.ps地址值相同
		auto tmpPtr2 = new string(*hp.ps);//这样写tmpPtr2与hp.ps内存地址不同，但地址上的值同
		delete ps;//释放原先ps占用的内存
		ps = tmpPtr2;
		i = hp.i;
		return *this;

	}
	~HasPtr() {
		delete ps;
	}
private:
	string* ps;
	int i;
};

//行为像值的类，智能指针
class StrBlob {
	//StrBlob() = default;
	StrBlob() : data(make_shared<vector<string>>()) {}
	StrBlob(const StrBlob& sb) : data(sb.data) {}
	StrBlob& operator=(const StrBlob& sb) {
		data = sb.data;
		return *this;
	}
	//不再需要析构函数，智能指针会自动释放
private:
	shared_ptr<vector<string>> data;
};


void main() {
	string s = "2323";
	string* s = new string(s);
}