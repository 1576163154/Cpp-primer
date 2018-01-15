#include<iostream>
#include<string>
using namespace std;

//��Ϊ�����õ���
class HasPtr {
private:
	string* ps;
	int i;
	unsigned int* use;
public:
	HasPtr(string* str = new string()) : ps (str),i(0),use((unsigned int)(1)){}//��һ����ѡ�����Ĺ��캯��
	HasPtr(const HasPtr& hp) : ps(hp.ps), i(hp.i), use(hp.use) {
		++(*use);
	}
	//���̣���������ߣ��ٿ���
	HasPtr& operator=(const HasPtr& hp)  {
		 //�����Ը�ֵ
		
		++(*hp.use);//��ֹ��delete���ȵ������ü���
		if (--(*use) == 0) {
			delete use;
			delete ps;
			//ע�� ++*(hp.use)Ϊ��ֵ���������ɽ��и�ֵ,�޸ģ�
			//			(*hp.use)++ Ϊ��ֵ�����ʽ����ʱ��
		}
		ps = hp.ps;
		use = hp.use;
		i = hp.i;
		return *this;
		
	}

	// ����һ������ʱ���ݼ�һ�����ü���
	~HasPtr() {
		--(*use);
		if (*use == 0) {
			delete ps;
			delete use;
		}
	}
};