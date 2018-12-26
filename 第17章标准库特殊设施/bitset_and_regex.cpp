#include<iostream>
#include<bitset>
#include<string>
#include<regex>
using namespace std;

void main() {
	bitset<32> bs(1U);
	bitset<13> bsTwo(0xbeef);//�����ĸ�λ������
	bitset<20> bsThree(0xbeef);//ʣ�µ�λ��Ϊ 0 

	//string to binary	
	bitset<5> bsString("1100");//
	cout << bsString << endl;

	//������ʽ
	string pattern = "[^c]ei";
	pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
	regex r(pattern);
	smatch results;
	string test_str = "receipt freiend theif receive";
	if (regex_search(test_str, results, r) == true) {
		cout << results.str() << endl;
	}
	regex rTwo;
	try {
		rTwo = *( new regex("[[:alnum:]]+\\.(cpp|cxx|cc$)", regex::icase));
	}
	catch (regex_error e) {
		cout << e.what() << endl;
		cout << "code : " << e.code() << endl;
	}
	
	smatch res;
	string filename;
	while (cin >> filename) {
		bool b = regex_search(filename, res, rTwo); 
		if (b == true) {
			cout << res.str() << endl;
		}
	}


	//��ӡ������ƥ��ĵ���
	for (sregex_iterator it(test_str.begin(), test_str.end(), r), end_it; 
																								it != end_it; 
																											++it) {
		cout << it->str() << endl;
	}

	system("pause");
}