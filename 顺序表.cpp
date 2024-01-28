#include<iostream>

using namespace std;

#define eleType int

struct SequentialList{
	eleType *elements;
	int size;
	int capacity;
};

void initializeList(SequentialList *list, int capacity){
	list->elements = new eleType[capacity];
	list->size = 0;
	list->capacity = capacity;
}

void destroyList(SequentialList *list){
	delete [] list->elements;
}

int size(SequentialList *list){
	return list->size;
}

bool isEmpty(SequentialList *list){
	return  list->size==0;
}

void insert(SequentialList *list,int index,eleType element){
	if(index<0||index>list->size){
		throw std::invalid_argument("位置错误");
	}
	if(list->size == list->capacity){
		int newCapacity = list->capacity * 2;
		eleType *newElemens = new eleType[newCapacity];
		for(int i=0;i<list->size;++i){
			newElemens[i]=list->elements[i];
		}
		delete[] list->elements;
		list->elements = newElemens;
		list->capacity = newCapacity;
	}
	for(int i =list->size;i>index;--i){
		list->elements[i]=list->elements[i-1];
	}
	list->elements[index]=element;
	list->size++;
}

void deleteElement(SequentialList *list,int index){
	if(index<0||index>=list->size){
		throw std::invalid_argument("位置错误");
	}
	for(int i = index;i<list->size;++i)
	{
		list->elements[i]=list->elements[i+1];
	}
	list->size--;
}

int findElement(SequentialList *list,eleType element){
	for(int i=0;i<list->size;++i){
		if(list->elements[i]==element)
		{
			return i ;
		}
	}
	return -1;
}

eleType getElement(SequentialList *list,int index){
	if(index<0||index>=list->size){
		throw std::invalid_argument("位置错误");
	}
	return list->elements[index];
}

void updateElement(SequentialList *list,int index,eleType value){
	if(index<0||index>=list->size){
		throw std::invalid_argument("位置错误");
	}
	list->elements[index]=value;
}

int main()
{
	SequentialList mylist;
	initializeList(&mylist, 10);
	for(int i=0;i<10;++i){
		insert(&mylist, i, i*10);
	}
	cout<<"Size: "<<size(&mylist)<<endl;
	cout<<"Is Empty:"<<isEmpty(&mylist)<<endl;
	
	for(int i=0;i<size(&mylist);++i){
		cout<<getElement(&mylist, i)<<" ";
	}
	cout<<endl;
	
	deleteElement(&mylist, 5);
	updateElement(&mylist, 1, 1314);
	
	for(int i=0;i<size(&mylist);++i){
		cout<<getElement(&mylist, i)<<" ";
	}
	cout<<endl;
	
	int idx = findElement(&mylist, 20);
	updateElement(&mylist, idx, 520);
	
	for(int i=0;i<size(&mylist);++i){
		cout<<getElement(&mylist, i)<<" ";
	}
	cout<<endl;
	
	destroyList(&mylist);
	
	return 0;
}