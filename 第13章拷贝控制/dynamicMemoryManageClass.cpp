#include<string>
#include<utility>
#include<memory>
using std::string;
using std::pair;
using std::allocator;
class StrVec {


private:
	string* elements;
	string* first_free;
	string* cap;

	static allocator<string> alloc;
	
	void free(){
	}

	void reallocate(){

	}

	pair<string*, string*> alloc_n_copy(const string* first, const string* first_free) {

	}

	void chk_n_alloc() {
		if (size() == capacity()) {
			reallocate();
		}
	}

public:
	//StrVec() = default;
	StrVec() : elements(nullptr),first_free(nullptr),cap(nullptr){}

	///////////////////////////拷贝控制成员
	//像值行为
	StrVec(const StrVec& sv) : elements(new string(*sv.elements)),first_free(new string(*sv.first_free)),cap(new string(*sv.cap)){}
	StrVec& operator=(const StrVec& sv) {
		//处理自赋值
		auto ele = new string(*sv.elements);
		auto free = new string(*sv.first_free);
		auto end = new string(*sv.cap);

		//释放原有内存
		delete elements;
		delete first_free;
		delete cap;

		elements = ele;
		first_free = free;
		cap = end;
	}

	//析构
	~StrVec() {
		delete elements;
		delete first_free;
		delete cap;

	}

	/////////////////////////其他方法
	void push_back(const string& str) {
		chk_n_alloc();//检查
		alloc.construct(first_free, str);//创建
		first_free++;//更新

	}
	//const 修饰无法修改对象
	size_t size() const {
		//string* s = new string("jfdkjf");
		//first_free = s;
		return first_free - elements;
	}

	size_t capacity() const {
		return cap - elements;
	}
		
};