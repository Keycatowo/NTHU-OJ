#ifndef FUNCTION_H
#define FUNCTION_H
#include<cstddef>
#include<iosfwd>
#include<new>
#include<string>

namespace oj
{
	struct String
	{
		std::string str;
		String(const std::string &);
		String(const String &);
		String& operator=(const String &);
	};

	std::ostream& operator<<(std::ostream &,const String &);

	class Vector
	{
	public:
		typedef std::size_t size_type;
		typedef String value_type;
		typedef value_type &reference;
		typedef const value_type &const_reference;
		typedef value_type *pointer;
		typedef const value_type *const_pointer;
	private:
		pointer begin_;	//begin of array
		pointer end_;	//end of array
		pointer last_;	//end of current size
	public:
		Vector();
		Vector(const Vector &);
		Vector& operator=(const Vector &);

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
		void insert(size_type pos,const_reference val);
		void reserve(size_type new_capacity);
		
		~Vector();
	};

	std::ostream& operator<<(std::ostream &,const Vector &);
}

//you don't have to pay attention on these 4 functions
void* operator new(std::size_t count);
void* operator new[](std::size_t count);
void operator delete(void *p) noexcept;
void operator delete[](void *p) noexcept;

#endif