﻿#include<iostream>
#include<string>
#include<memory>
#include<vector>
#include<algorithm>
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
	
	friend void swap(HasPtr&,HasPtr&);//friend 确保该方法能访问private成员

	friend bool operator<(HasPtr&, HasPtr&);//重载 < 运算符
	
	~HasPtr() {
		delete ps;
	}
private:
	string* ps;
	int i;
};

inline void swap(HasPtr& one,HasPtr& two){
	using std::swap;
	swap(one.ps,two.ps);//交换指针
	swap(one.i,two.i);
	cout << "调用自定义 swap （）" << endl;
}

inline bool operator<(HasPtr& one, HasPtr& two) {
	return *one.ps < *two.ps;
}

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
	string* ws = new string("222");

	string o = "one";
	string t = "two";
	HasPtr one(o);
	HasPtr two(t);
	


	bool flag = one < two ? true : false;
	vector<HasPtr> vHP = { HasPtr(string("one")),HasPtr(string("awo")) ,HasPtr(string("three")) ,HasPtr(string("four")) };
	using std::sort;
	sort(vHP.begin(), vHP.end());//sort 过程中，并未调用自定义swap方法
	swap(one, two);
}