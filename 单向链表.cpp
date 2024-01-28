#include<iostream>
#include <stdexcept>
using namespace std;

#define eleType int


//链表结构体
struct ListNode{
	eleType data;      //数据域
	ListNode *next;     //指针域
	
	ListNode (eleType x):data(x),next(NULL){}
};

//链表的类
class LinkedList{
	//私有
private:
	ListNode *head; // 头结点
	int size;  //链表的大小
	
	//公有
public:
	//构造函数
	LinkedList():head(NULL),size(0){}
	//析构函数
	~LinkedList();
	//插入
	void insert(int i,eleType value);
	//删除
	void remove(int i);
	//查找
	ListNode *find(eleType value);
	// 获取
	ListNode *get(int i);
	//更新
	void update(int i,eleType value);
	//打印
	void print();
};

//析构函数
LinkedList::~LinkedList(){
	ListNode *curr = head;
	while(curr !=NULL){
		ListNode *temp =curr;
		curr =curr->next;
		delete temp;
	}
}

//插入
void LinkedList::insert(int i, eleType value){
	if(i<0||i>size){
		throw std::out_of_range("异常位置");
	}
	ListNode *newNode = new ListNode(value);    //也就是调用结构体中的ListNode (eleType x):data(x),next(NULL){}
	if(i == 0){
		newNode->next = head;
		head = newNode;
	}
	else{
		ListNode *curr =head;
		for(int j=0;j<i-1;j++){
			curr = curr->next;
		}
		newNode->next = curr->next;
		curr->next = newNode;
	}
	++size;
}

//删除
void LinkedList::remove(int i){
	if(i<0||i>size){
		throw std::out_of_range("异常位置");
	}
	if(i == 0){
		ListNode *temp = head;
		head = head->next;
		delete temp;		
	}
	else{
		ListNode *curr = head;
		for(int j=0;j<i-1;j++){
			curr = curr->next;
			
		}
		ListNode *temp = curr->next;
		curr->next = temp->next;
		delete temp;
	}
	--size;
	
}

//查找
ListNode *LinkedList::find(eleType value){
	ListNode *curr = head;
	while(curr&&curr->data != value){
		curr = curr->next;
	}
	return curr;
}

//查找索引/获取
ListNode *LinkedList::get(int i){
	if(i<0||i>size){
		throw std::out_of_range("异常位置");
	}
	ListNode *curr = head;
	for(int j=0;j<i;j++){
		curr = curr->next;
	}
	return curr;
	
}

void LinkedList::update(int i , eleType value){
	get(i)->data = value;
}

void LinkedList::print(){
	ListNode *curr =head;
	while(curr){
		cout<<curr->data<<" ";
		curr = curr->next;
	}
	cout<<endl;
}


int main()
{
	LinkedList list;
	list.insert(0, 10);
	list.insert(1, 20);
	list.insert(2, 30);
	list.insert(3, 40);
	list.insert(4, 50);
	
	//打印输出
	list.print();
	
	//插入
	list.insert(3, 99);
	list.print();
	
	//删除
	list.remove(0);
	list.print();
	
	//更新
	list.update(0, 1314);
	list.print();
	
	
	return 0;
}