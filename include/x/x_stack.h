#pragma once

#include "x_types.h"
#include "x/x_exports.h"

namespace x
{
	template < class T >
	class X_API Stack
	{
	private:
		struct Node
		{
			T value;
			Node *next;
		};

		Node *m_top;

	public:
		Stack();
		virtual ~Stack();
		void push(T);
		void pop(T &);
		x::x_Bool isEmpty();
	};

}
