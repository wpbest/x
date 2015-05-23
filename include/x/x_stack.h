#pragma once

#include "x/x_types.h"
#include "x/x_exports.h"

namespace x
{
	template < class T >
	class X_API x_Stack
	{
	private:
		struct Node
		{
			T value;
			Node *next;
		};

		Node *m_top;

	public:
		x_Stack();
		virtual ~x_Stack();
		void push(T);
		void pop(T &);
		x_Bool isEmpty();
	};

}
