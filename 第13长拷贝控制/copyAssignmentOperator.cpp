#include<string>
using namespace std;
class Foo {
public:
	//��ʾ�������壬��������Ϊ���Ǻϳɵ�Ĭ�ϸ�ֵ�����
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
	one = two;//��������ֵ����ʱ���� ������ֵ�����
	Foo three;
	three.operator=(two);//���������дΪ ����ĺ�������

}