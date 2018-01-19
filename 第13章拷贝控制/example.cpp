#include<string>
#include<memory>
#include<set>
using namespace std;

//拷贝控制实例

class Message {
	friend class Folder;
private:
	string contents;//msg content
	set<Folder*> folders;//msg 所在文件夹

	void add_to_Folders(const Message& msg) {
		for (auto f : msg.folders) {
			f->addMsg(this);
		}
	}

	void remove_from_Folders() {
		for (auto f : folders) {
			f->remMsg(this);
		}
	}

public:
	explicit Message(const string s = "") : contents(s){}//不允许使用隐式转换构造
	//拷贝构造函数
	Message(const Message& msg) : contents(msg.contents),folders(msg.folders){
		add_to_Folders(msg);
	}
	//拷贝赋值运算符
	Message& operator=(const Message& msg) {
		remove_from_Folders(); //先将msg从Folder中移除
		contents = msg.contents;
		folders = msg.folders;
		add_to_Folders(*this);
		return *this;
	}
	//注:若使用合成拷贝赋值运算符（不会将该对象加入folders中的每一个folder对象），
	//以及合成的析构函数（不会将对象从folders中移除），那么行为将与设计不符
	~Message() {
		remove_from_Folders();
	}

	void save(Folder& f) {
		folders.insert(&f);
		f.addMsg(this);
	}
	void remove(Folder& f) {
		folders.erase(&f);
		f.remMsg(this);
	}

	void swap(Message& one,Message& two) {
		using std::swap;
		for (auto f : one.folders) {
			f->remMsg(&one);
		}
		for (auto f : two.folders) {
			f->remMsg(&two);
		}

		swap(one.contents, two.contents);
		swap(one.folders, two.folders);
		for (auto f : one.folders) {
			f->addMsg(&one);
		}
		for (auto f : two.folders) {
			f->remMsg(&two);
		}
	}
	
	void addFolder(Folder& f) {
		folders.insert(&f);
	}
	void remFolder(Folder& f) {
		folders.erase(&f);
	}
};

class Folder {
	friend class Message;
private:
	set<Message*>  msgs;
public:
	Folder() = default;
	Folder(const Folder& f) :msgs(f.msgs) {}

	//没有指针成员，不用重载 =
	Folder& operator=(const Folder& f) {
		
		msgs = f.msgs;
		

	}

	void addMsg(Message* msg) {
		msgs.insert(msg);
	}
	void remMsg(Message* msg) {
		msgs.erase(msg);
	}


};