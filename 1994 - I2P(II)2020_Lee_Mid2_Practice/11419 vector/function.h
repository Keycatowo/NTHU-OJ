#ifndef FUNCTION_H
#define FUNCTION_H
#include<cstddef>
#include<new>
#include<string>

extern int main();

namespace oj
{
	//this is only for OJ
	//do not design class like this (this is a very bad coding style)
	class Employee
	{
		friend struct God;
		friend int ::main();
		static unsigned ID_;	//start from 0
		const std::string name_;
		const unsigned id_;
		Employee(const std::string &name);	//constructor (only God can construct Employee)
	public:
		Employee(const Employee &);
	};

	typedef Employee data_t;

	class Vector
	{
	public:
		typedef std::size_t size_type;
		typedef Employee value_type;
		typedef value_type &reference;
		typedef const value_type &const_reference;
		typedef value_type *pointer;
		typedef const value_type *const_pointer;
	private:
		friend void swap(Vector &,Vector &);
		pointer begin_;	//begin of array
		pointer end_;	//end of array
		pointer last_;	//end of current size
	public:
		Vector();

		inline size_type capacity() const
		{
			return end_-begin_;
		}
		inline size_type size() const
		{
			return last_-begin_;
		}
		inline reference operator[](const size_type pos)
		{
			return begin_[pos];
		}
		inline const_reference operator[](const size_type pos) const
		{
			return begin_[pos];
		}
		
		void erase(size_type pos);
		void push_back(const_reference val);
		void reserve(size_type new_capacity);
		
		~Vector();
	};

	struct God;
	void add_employee(Vector &vec,const std::string &name);
	void print(const Vector &vec);
	void quit(Vector &vec,unsigned id);
	void quit(Vector &vec,const std::string &name);

	void swap(Vector &,Vector &);	//you don't have to pay attention on this
}

//you don't have to pay attention on these 4 functions
void* operator new(std::size_t count);
void* operator new[](std::size_t count);
void operator delete(void *p) noexcept;
void operator delete[](void *p) noexcept;

#endif