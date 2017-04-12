#include <iostream>
#include <string>

using namespace std;

template <typename E>
class GenStack
{
	enum {DEF_CAP = 1000};
	public:
		GenStack(int cap = DEF_CAP);
		~GenStack();
		void push(const E& e) throw(invalid_argument);
		E& pop() throw(invalid_argument);
		bool isEmpty() const;
		bool isFull() const;
		int getSize() const;
		const E& peek() const throw(invalid_argument);

	private:
		E* StackArray;
		int top;
		int capacity;
};

template<typename E> GenStack<E>::GenStack(int cap)
:StackArray(new E[cap]), capacity(cap), top(-1)
{}
template <typename E> GenStack<E>::~GenStack()
{
	delete[] StackArray;
	cout << "Object deleted" << endl;
}
template <typename E> int GenStack<E>::getSize() const
{
	return (top+1);
}
template <typename E> bool GenStack<E>::isEmpty() const
{
	return (top<0);
}
template <typename E> const E& GenStack<E>::peek() const throw(invalid_argument)
{
	if (isEmpty())
		throw std::invalid_argument("The top of the stack is empty");
	else
		return StackArray[top];
}
template <typename E> void GenStack<E>::push(const E& e) throw(invalid_argument)
{
	if (getSize() == capacity)
		throw std::invalid_argument("Push to full stack");
	else
		StackArray[++top] = e;
}
template <typename E> E& GenStack<E>::pop() throw(invalid_argument)
{
	if (isEmpty())
		throw std::invalid_argument("Pop from empty stack");
	else 
	{
		E& temp = StackArray[top];
		--top;
		return temp;
	}
}
template <typename E> bool GenStack<E>::isFull() const
{
	return (top>=capacity);
}