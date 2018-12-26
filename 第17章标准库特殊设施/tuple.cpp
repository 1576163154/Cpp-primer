#include<iostream>
#include<tuple>
#include<string>
#include<vector>
#include<list>
using namespace std;

void main() {
	tuple<int, int, int> T_threeInt;
	tuple<string, vector<int>, list<int>, int> t("hello,tuple!", { 1,2,3,4,5 }, { 2,4,6,7 },98);

	auto aTuple = make_tuple("fjdlkajfl", 123, 0.233);
	auto one = get<0>(aTuple); //��ȡaTuple �ĵ�һ��Ԫ��
	get<1>(aTuple) = 333; //�޸�

	cout << get<1>(aTuple) << endl;

	typedef decltype(aTuple) shiftType;//��ȡ Tuple ����
	shiftType abc("djflaj",111,0.234);
	cout << get<1>(abc) << endl;

	size_t tsize = tuple_size<shiftType>::value;//��ȡ tuple ����
	cout << tsize << endl;

	tuple_element<1, shiftType>::type oneType = get<1>(abc);//��ȡtuple��ĳindex��Ա����
	cout << oneType << endl;

	//17.1.1
	tuple<int, int, int> TTI_a(10, 20, 30);
	//17.1.2
	tuple<string, vector<string>, pair<string, int>> TSVECPAIR_a("djflaj", { "afd","djfkla","djfk" }, { "abc",123 });

	system("pause");
}
