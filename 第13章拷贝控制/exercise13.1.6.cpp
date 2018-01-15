#include<iostream>
#include<string>
using namespace std;
class Employee {
private:
	int i = num;
	string name;
public:
	static int num;//declaration
	Employee() = default;
	Employee(string n) : name(n), i(num) {
		num++;
	}
};

int Employee::num = 1;//definition
void main() {
	Employee one("Tom");
	Employee two("Ann");
	cout << one.num << endl;
	cout << two.num << endl;
}