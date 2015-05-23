#include "x_pch.h"

#include "x/x_stack.h"

namespace x
{
	template < class T >
	x_Stack<T>::x_Stack()
	{
		m_top = nullptr;
	}

	template < class T >
	x_Stack<T>::~x_Stack()
	{
		Node *nodePtr, *nextNode;
		nodePtr = m_top;

		while (nodePtr != nullptr)
		{
			nextNode = nodePtr->next;
			delete nodePtr;
			nodePtr = nextNode;
		}
	}

	template < class T >
	void x_Stack<T>::push(T value)
	{
		Node *newNode;
		newNode = new Node;
		newNode->value = value;

		if (isEmpty())
		{
			m_top = newNode;
			newNode->next = nullptr;
		}
		else
		{
			newNode->next = m_top;
			m_top = newNode;
		}
	}

	template < class T >
	void x_Stack<T>::pop(T &value)
	{
		if (!isEmpty())
		{
			Node *temp;
			value = m_top->value;
			temp = m_top->next;
			delete m_top;
			m_top = temp;
		}
	}

	template < class T >
	x::x_Bool x_Stack<T>::isEmpty()
	{
		x::x_Bool status;

		if (!m_top)
			status = true;
		else
			status = false;

		return status;
	}

}