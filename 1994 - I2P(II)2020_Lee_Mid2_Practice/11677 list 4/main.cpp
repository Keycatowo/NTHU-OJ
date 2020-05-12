#include<algorithm>
#include<cstddef>
#include<cstdlib>
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
}

int main()
{
  freopen("input.txt","r",stdin);
	using namespace std;
	{
		monitor=true;
		oj::List lst;
		for(string command;cin>>command;)
			if(command=="push_back")
			{
				oj::List::value_type val;
				cin>>val;
				lst.push_back(val);
			}
			else
				if(command=="remove")
				{
					oj::List::value_type val;
					cin>>val;
					lst.remove(val);
				}
				else
					if(command=="show")
						cout<<lst<<endl;
	}
	monitor=false;
	if(current_memory_size!=0)
		cout<<"memory leak (leak "<<current_memory_size<<" byte)"<<endl;
	//cout<<"maximum memory usage "<<peak_current_memory_size<<" byte"<<endl;
#ifdef ONLINE_JUDGE
	nthuoj_unlock();
#endif
}

namespace
{
	std::size_t current_memory_size(0);
	std::size_t peak_current_memory_size(0);
	bool monitor(false);
	const std::size_t limited_memory_size(2048);	//byte
	std::size_t memory_status_index(0);
	std::pair<void *,std::size_t> memory_status[limited_memory_size]{};

	void* for_new(const std::size_t count)
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
