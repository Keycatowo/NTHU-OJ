#ifndef FUNCTION_H
#define FUNCTION_H
#include<cstddef>
#include<iosfwd>
#include<new>

namespace oj
{
	class List
	{
		friend std::ostream& operator<<(std::ostream &,const List &);
	public:
		typedef std::size_t size_type;
		typedef int value_type;
		typedef const value_type &const_reference;
		typedef value_type *pointer;
		typedef const value_type *const_pointer;
	private:
		struct Node
		{
			Node *next;
			Node *prev;
			value_type data;
		};
		Node *begin_;
	public:
		List();
		~List();

		void push_back(const_reference val);
		void remove(const_reference val);
	};

	std::ostream& operator<<(std::ostream &,const List &);
}

//you don't have to pay attention on these 4 functions
void* operator new(std::size_t count);
void* operator new[](std::size_t count);
void operator delete(void *p) noexcept;
void operator delete[](void *p) noexcept;

#endif
