#include<iostream>
#include<string>
#include<memory>
#include<vector>
using namespace std;

//��Ϊ��ֵ���࣬��ָͨ��
class HasPtr {
public:
	HasPtr() = default;
	HasPtr(string& s) : ps( new string(s)), i(0) {}
	HasPtr(const HasPtr& m) : ps(new string(*m.ps)),i(m.i){}
	//������ֵ�����
	HasPtr& operator=(const HasPtr& hp) {
		//�迼�ǵ��Ը�ֵ�����
		//auto tmpPtr = hp.ps;//����дtmpPtr��hp.ps��ֵַ��ͬ
		auto tmpPtr2 = new string(*hp.ps);//����дtmpPtr2��hp.ps�ڴ��ַ��ͬ������ַ�ϵ�ֵͬ
		delete ps;//�ͷ�ԭ��psռ�õ��ڴ�
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

//��Ϊ��ֵ���࣬����ָ��
class StrBlob {
	//StrBlob() = default;
	StrBlob() : data(make_shared<vector<string>>()) {}
	StrBlob(const StrBlob& sb) : data(sb.data) {}
	StrBlob& operator=(const StrBlob& sb) {
		data = sb.data;
		return *this;
	}
	//������Ҫ��������������ָ����Զ��ͷ�
private:
	shared_ptr<vector<string>> data;
};


void main() {
	string s = "2323";
	string* s = new string(s);
}