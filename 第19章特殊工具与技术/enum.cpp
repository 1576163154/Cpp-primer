#include<iostream>
using std::cout;
using std::endl;
//���޶��������enum ����
enum class color {
	yellow = 1,
	blue,
	green
};

//���޶�������
enum fruit {orange,grape,apple};

//�ƶ�enum ��������,�޶�Ϊ���ͣ�Ĭ��Ϊint
enum animal : short {
	tiger = 2,
	lion = 5,
	elephant =8,
};

enum planet : unsigned int;//ǰ��������Ҫ�ƶ�����
enum class element;//�޶������򣬲���Ҫ��Ĭ��Ϊint

//���岿��
enum planet unsigned int{
	solar = 3,
	jupiter,
	moon,
};
void main() {

	color c = color::blue;//��ͨ�� color::blue ��ȡblue 
	fruit f = orange;//����Ҫ
	int a = orange;
	cout << a << endl;
	system("pause");
}