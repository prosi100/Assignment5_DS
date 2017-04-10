#include <iostream>
#include <string>
#include "ListNode.h"
#include <stdexcept>
#include <cstdio>

using namespace std;

template <class T>
class DLinkedList{

	private:
		ListNode<T> *front;
		ListNode<T> *back;
		int size;
		template <class U> friend class GenQueue;

	public:
		DLinkedList();
		~DLinkedList();
		bool isEmpty() const;
		void insertFront(const T& d);
		void insertBack (const T& d);
		void printList();
		int getSize();
		T getFront() const;
		T getBack() const;
		T removeFront();
		T removeBack();
		T smallestValue();
		T largestValue();
		int positionOfValue(T value);
		T getDataAtPosition(int pos);
		void setDataAtPosition(int pos, T newData);
		void sortedInsert(T newData);
		T sumList();
};

template <typename T>
DLinkedList<T>::DLinkedList()
{
	size =0;
	front = new ListNode<T>();
	back = new ListNode<T>();
	front->next = back;
	back->prev = front;
}

template <typename T>
DLinkedList<T>::~DLinkedList()
{
	while(!isEmpty())
	{
		removeFront();
	}
	delete front;
	delete back;
}

template <typename T>
int DLinkedList<T>::getSize()
{
	return size;
}

template <typename T>
bool DLinkedList<T>::isEmpty() const
{
	return (front->next==back);
}

template <typename T>
void DLinkedList<T>::insertFront(const T& d)
{
	++size;	
	ListNode<T> *node = new ListNode<T>(d);
	
	if (size==1)
	{		
		back->prev = node;
		node->next = back;		
	}
	else
	{
		node->next = front->next;
		front->next->prev = node;
	}
	node->prev = front;
	front->next = node;	
}

template <typename T>
void DLinkedList<T>::insertBack (const T& d)
{
	++size;
	ListNode<T> *node = new ListNode<T>(d);
	if (size ==1)
	{
		front->next=node;
		node->prev = front;
	}
	else
	{
		node->prev = back->prev;
		back->prev->next = node;
	}
	node->next = back;
	back->prev = node;
}

template <typename T>
T DLinkedList<T>::getFront() const
{
	return front->next->data;
}

template <typename T>
T DLinkedList<T>::getBack() const
{
	return back->prev->data;
}
	
template <typename T>
T DLinkedList<T>::removeFront()
{
	if(size==0)
	{
		throw std::invalid_argument("Cannot remove from empty queue");
	}
	--size;
	ListNode<T> *temp = front->next;
	T tempData = temp->data;
	temp->next->prev = front;
	front->next = temp->next;
	temp->next=NULL;
	temp->prev = NULL;
	delete temp;
	return tempData;
	
}
		
template <typename T>
T DLinkedList<T>::removeBack() 
{
	if(size==0)
	{
		throw std::invalid_argument("Cannot remove from empty queue");
	}
	--size;
	ListNode<T> *temp = back->prev;
	T tempData = temp->data;
	temp->prev->next = back;
	back->prev = temp->prev;
	temp->prev=NULL;
	temp->next = NULL;
	delete temp;
	return tempData;		
}

template <typename T>
void DLinkedList<T>::printList()
{
	ListNode<T> *temp = front;	
	while(temp->next!=back)
	{
		cout<<temp->next->data<<" ";
		temp = temp->next;		
	}	
	cout<<endl;
}

template <typename T>
T DLinkedList<T>::smallestValue()
{
	ListNode<T> *temp = front;
	T theData = temp->next->data;	
	while(temp->next!=back)
	{
		if(temp->next->data<theData)
		{
			theData = temp->next->data;
		}
		temp = temp->next;		
	}	
	return theData;
}

template <typename T>
T DLinkedList<T>::largestValue()
{
	ListNode<T> *temp = front;
	T theData = temp->next->data;
	while(temp->next!=back)
	{
		if(temp->next->data>theData)
		{
			theData = temp->next->data;
		}
		temp = temp->next;
	}
	return theData;
}

template <typename T>
int DLinkedList<T>::positionOfValue(T value)//0 onward
{
	ListNode<T> *temp = front;
	int count = 0;	
	while(temp->next!=back)
	{
		if(temp->next->data==value)
		{
			return count;
		}
		count++;
		temp = temp->next;		
	}	
	return -1;	
}

template <typename T>
T DLinkedList<T>::getDataAtPosition(int pos)
{
	if (pos>size-1)
	{
		//throw error
	}
	ListNode<T> *temp = front;
	int count = 0;
	while(count<pos)
	{
		temp=temp->next;
		count++;
	}
	return temp->next->data;
}

template <typename T>
void DLinkedList<T>::setDataAtPosition(int pos, T newData)
{
	if (pos>size-1)
	{
		//throw error
	}
	ListNode<T> *temp = front;
	int count = 0;
	while (count<pos)
	{
		temp = temp->next;
		count++;
	}
	temp->next->data = newData;
}

template <typename T>
void DLinkedList<T>::sortedInsert(T newData)
{
	if(size==0)
	{
		ListNode<T> *b = new ListNode<T>(newData);
		front->next = b;
		b->prev = front;
		b->next = back;
		back->prev = b; 
		++size;
	}
	else
	{
		ListNode<T> *a = front;
		while(a->next!=back)
		{
			if (newData>a->next->data)
			{
				a = a->next;
			}
			else
			{
				break;
			}
		}	

		ListNode<T> *c = a->next;
		ListNode<T> *b= new ListNode<T>(newData);

		a->next = b;
		b->prev = a;
		b->next = c;
		c->prev = b;
		++size;
	}
}

template <typename T>
T DLinkedList<T>::sumList()
{
	T sum;
	ListNode<T> *temp = front;	
	while(temp->next!=back)
	{
		sum +=temp->next->data;
		temp = temp->next;		
	}	
	return sum;
}

