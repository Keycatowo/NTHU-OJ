#include<algorithm>
#include<cstddef>
#include<cstdlib>
#include<ctime>
#include<iostream>
#include<new>
#include<stdexcept>
#include<string>
#include<utility>
#include"function.h"
#ifdef ONLINE_JUDGE
#include"NTHUOJLock"
#endif

namespace
{
	extern std::size_t current_memory_size;
	extern std::size_t peak_current_memory_size;
	extern bool monitor;
	extern unsigned short true_vec;
}

namespace oj
{
	Employee::Employee(const Employee &rhs)
		:name_(rhs.name_),id_(rhs.id_){}

	unsigned Employee::ID_(0);

	Vector::Vector()
		:begin_(nullptr),end_(nullptr),last_(nullptr){}
}

int main()
{
  freopen("input.txt","r",stdin);
	using namespace std;
	srand(time(nullptr));
	{
		monitor=true;
		oj::Vector vec[2];
		for(string command,name;cin>>command;)
		{
			if(command=="recruit")
			{
				cin>>name;
				add_employee(vec[true_vec],name);
				if(rand()&1)
				{
					add_employee(vec[1-true_vec],name);
					--oj::Employee::ID_;
				}
			}
			else if(command=="quit")
			{
				unsigned id;
				cin>>id;
				if(id)
				{
					cin>>id;
					if(rand()&1)
						quit(vec[1-true_vec],id);
					quit(vec[true_vec],id);
				}
				else
				{
					cin>>name;
					if(rand()&1)
						quit(vec[1-true_vec],name);
					quit(vec[true_vec],name);
				}
			}
			else if(command=="reserve")
			{
				size_t size;
				cin>>size;
				if(rand()&1)
					vec[1-true_vec].reserve(size);
				vec[true_vec].reserve(size);
			}
			else if(command=="capacity")
				cout<<vec[true_vec].capacity()<<endl;
			else if(command=="size")
				cout<<vec[true_vec].size()<<endl;
			print(vec[true_vec]);
			if(rand()&1)
			{
				oj::swap(vec[0],vec[1]);
				true_vec^=1;
			}
		}
	}
	monitor=false;
	if(current_memory_size!=0)
		cout<<"memory leak (leak "<<current_memory_size<<" byte)"<<endl;
	//cout<<"maximum memory usage "<<peak_current_memory_size<<" byte"<<endl;
#ifdef ONLINE_JUDGE
	nthuoj_unlock();
#endif
}

namespace oj
{
	void swap(Vector &lhs,Vector &rhs)
	{
		std::swap(lhs.begin_,rhs.begin_);
		std::swap(lhs.end_,rhs.end_);
		std::swap(lhs.last_,rhs.last_);
	}
}

namespace
{
	std::size_t current_memory_size(0);
	std::size_t peak_current_memory_size(0);
	bool monitor(false);
	unsigned short true_vec(0);
	const std::size_t limited_memory_size(4096);	//byte
	std::size_t memory_status_index(0);
	std::pair<void *,std::size_t> memory_status[limited_memory_size]{};

	void *for_new(const std::size_t count)
	{
		if(monitor)
		{
			const auto left_size(limited_memory_size-current_memory_size);
			if(left_size&&count<=left_size)
			{
				current_memory_size+=count;
				peak_current_memory_size=std::max(peak_current_memory_size,current_memory_size);
				if(void *p=malloc(count))
				{
					while(memory_status[memory_status_index].first)
						memory_status_index=(memory_status_index+1)%limited_memory_size;
					memory_status[memory_status_index]=std::pair<void *,std::size_t>(p,count);
					return p;
				}
			}
		}
		else
			if(void *p=malloc(count))
				return p;
		throw std::bad_alloc();
	}

	void for_delete(void *p)
	{
		if(p)
			if(monitor)
			{
				while(memory_status[memory_status_index].first!=p)
					memory_status_index=(memory_status_index+1)%limited_memory_size;
				free(p);
				current_memory_size-=memory_status[memory_status_index].second;
				memory_status[memory_status_index]=std::pair<void *,std::size_t>(nullptr,0);
			}
			else
				free(p);
	}
}

void* operator new(std::size_t count)
{
	return for_new(count);
}

void* operator new[](std::size_t count)
{
	return for_new(count);
}

void operator delete(void *p) noexcept
{
	for_delete(p);
}

void operator delete[](void *p) noexcept
{
	for_delete(p);
}
