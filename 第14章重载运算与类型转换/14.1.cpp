#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::stable_sort;
//14.1 重载运算，要求左侧就是该类型
         // 内置类型,要求左侧运算对象，是该类型 或 可以转换为该类型


//14.8.1 lambda
class ShorterString {
public:
	bool operator()(const string &s1, const string &s2)  const {
		return s1.size() < s2.size();
	}
};


void main() {
	string s = "world";
	string t = s + "!";
	int i = 1;
	double x = 2.0 + i;
	

	//lambda
	vector<string>  vs = { "abc","ab","djfk" };
	stable_sort(vs.begin(), vs.end(), ShorterString());

	system("pause");
}