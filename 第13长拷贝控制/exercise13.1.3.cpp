#include<string>
#include<iostream>
using namespace std;
//13.12 �����������ô���
static int i = 0;
class Sales_data {
private:
	string book;
public:
	//Sales_data() = default;//�ñ������ϳ�Ĭ�Ϲ��캯������ʹ���������캯��
	Sales_data() {}
	Sales_data(const string& s) : book(s) {}
	Sales_data(const Sales_data& sd) : book(sd.book) {
		
	}
	//����ֵ���������������޸ĳ�Ա
	const string isbn() const {
		return book;
	}

	~Sales_data() {
		i++;//��¼
		cout << "�� " << i << " �ε�������������" << endl;
	}

};

bool fcn(const Sales_data* trans, Sales_data accum) {
	Sales_data item1(*trans);
	Sales_data item2(accum);
	//return item1.isbn() != item2.isbn();
	return true;
}

void main() {
	Sales_data one;
	Sales_data two;
	fcn(&one, two);
	system("pause");
}

//���������й��ƽ�����5������
//�ں���fcn�� ����3�Σ��ֱ��� accum,item1,item2����trans������
//������ʱ  ����2�Σ�one��two


