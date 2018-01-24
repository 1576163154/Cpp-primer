#include<string>
#include<utility>
#include<memory>
#include<initializer_list>
#include<algorithm>
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
		if (elements != nullptr) {
			for (auto p = first_free; p != elements; ) {
				p--;
				alloc.destroy(p);//从后往前依次销毁对象
				
			}
			//另外一种方式
			//for_each(elements, first_free, [](string& s) {alloc.destroy(&s); });
			alloc.deallocate(elements,cap - elements);//之后释放内存
		}

		
	}

	void reallocate(){
		auto newCap = size() > 0 ? 2 * size() : 1;
		auto newData = alloc.allocate(newCap);
		auto dest = newData;
		auto elem = elements;

		for (size_t i = 0; i != size(); ++i) {
			alloc.construct(dest, std::move(*elem));//std::move不拷贝string，而是让dest接管
			dest++;
			elem++;
		}
		free();
		elements = newData;
		first_free = dest;
		cap = elements + newCap;
	}

	//拷贝一份vector<string>
	//return {begin,end}
	pair<string*, string*> alloc_n_copy(const string* first, const string* first_free) {
		auto begin = alloc.allocate(first_free - first);//分配first_free - first 个 string 所需空间，并返回首地址
		auto end = std::uninitialized_copy(first, first_free, begin);//将first ~ first_free 范围内内容 拷贝到begin
		return{ begin,end};
	}

	void chk_n_alloc() {
		if (size() == capacity()) {
			reallocate();
		}
	}

public:
	//StrVec() = default;
	StrVec() : elements(nullptr),first_free(nullptr),cap(nullptr){}

	StrVec(std::initializer_list<string> l) {
		auto newData = alloc_n_copy(l.begin(), l.end());
		elements = newData.first;
		first_free = newData.second;
		cap = newData.second;
	}

	///////////////////////////拷贝控制成员
	//像值行为
	StrVec(const StrVec& sv)  {
		auto newData = alloc_n_copy(sv.elements, sv.first_free);
		elements = newData.first;
		first_free  = newData.second;
		cap = newData.second;
	}
	StrVec& operator=(const StrVec& sv) {
		auto data = alloc_n_copy(sv.elements, sv.first_free);
		free();


	

		elements = data.first;
		first_free = data.second;
		cap = data.second;
		return *this;
	}

	//析构
	~StrVec() {
		free();

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
	
	//设置容量
	void reserve(size_t n) {
		if (n > capacity()) {
			int newCap = n;
			auto newData = alloc.allocate(newCap);
			auto oldEle = elements;
			auto dest = newData;
			for (size_t i = 0; i < size(); i++) {
				alloc.construct(dest, std::move(*oldEle));
				dest++;
				oldEle++;
			}

			free();
			elements = newData;
			first_free = dest;
			cap = elements + newCap;
		}
	}
};