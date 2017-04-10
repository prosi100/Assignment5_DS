#include <iostream>
#include <string>

using namespace std;

template <class T>
class ListNode
{
	private: 
		T data;
		ListNode<T> *next;
		ListNode<T> *prev;
	public:
		ListNode();
		ListNode(const T& d);
		~ListNode();
		template <class U> friend class DLinkedList;

	
};

template <typename T>
ListNode<T>::ListNode(const T& d):data(d), next(NULL), prev(NULL){}

template <typename T>
ListNode<T>::ListNode(){}

template <typename T>
ListNode<T>::~ListNode()
{
}