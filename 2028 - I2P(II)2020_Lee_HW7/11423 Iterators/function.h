#ifndef FUNCTION_H
#define FUNCTION_H
#include<cstddef>

namespace oj
{
	struct Node
	{
		typedef int value_type;
		Node *next;	//for Bidirect_iter, not Random_iter
		Node *prev;	//for Bidirect_iter, not Random_iter
		value_type val;
		Node();
	};

	typedef Node data_t;

	class Iter	//simulate Iterator
	{
		//calculate the distance from begin to end
		virtual std::ptrdiff_t distance_(const Iter &begin,const Iter &end) const=0;
		//because Iter does not have copy constructor and copy assignment operator
		//I have to use a strange way to achieve next_ and prev_
		virtual void next_(Iter &des) const=0;	//store next element to des
		virtual void prev_(Iter &des) const=0;	//store previous element to des
		data_t *p_;
	public:
		Iter(data_t *begin);
		inline Iter& assign(const Iter &rhs)
		{
			p_=rhs.p_;
			return *this;
		}

		inline std::ptrdiff_t distance(const Iter &iter) const
		{
			return distance_(*this,iter);
		}

		inline data_t* get() const
		{
			return p_;
		}

		inline data_t::value_type& get_val()
		{
			return p_->val;
		}

		inline const data_t::value_type& get_val() const
		{
			return p_->val;
		}

		inline void next(Iter &iter) const
		{
			next_(iter);
		}

		inline void prev(Iter &iter) const
		{
			prev_(iter);
		}

		virtual ~Iter()=0;
	};

	class Random_iter:public Iter
	{
		std::ptrdiff_t distance_(const Iter &begin,const Iter &end) const;
		void next_(Iter &des) const;
		void prev_(Iter &des) const;
	public:
		Random_iter(data_t *begin);
	};

	class Bidirect_iter:public Iter
	{
		std::ptrdiff_t distance_(const Iter &begin,const Iter &end) const;
		void next_(Iter &des) const;
		void prev_(Iter &des) const;
	public:
		Bidirect_iter(data_t *begin);
	};
}

#endif
