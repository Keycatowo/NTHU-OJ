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

namespace oj
{
	String::String(const std::string &str_)
		:str(str_){}

	String::String(const String &rhs)
		:str(rhs.str){}

	String& String::operator=(const String &rhs)
	{
		str=rhs.str;
		return *this;
	}

	std::ostream& operator<<(std::ostream &os,const String &str)
	{
		return os<<str.str;
	}

	std::ostream& operator<<(std::ostream &os,const Vector &vec)
	{
		for(size_t i(0);i!=vec.size();++i)
		{
			if(i)
				os<<' ';
			os<<vec[i];
		}
		return os;
	}
}

int main()
{
  freopen("input.txt","r",stdin);
	using namespace std;
	{
		monitor=true;
		oj::Vector *vec[2];
		vec[0]=new oj::Vector();
		vec[1]=new oj::Vector();
		size_t num;
		for(string command;cin>>command;)
		{
			if(command=="e")
			{
				size_t pos;
				cin>>num>>pos;
				vec[num]->erase(pos);
			}
			else if(command=="i")
			{
				size_t pos;
				string str;
				cin>>num>>pos>>str;
				vec[num]->insert(pos,str);
			}
			else if(command=="c")
			{
				cin>>num;
				cout<<vec[num]->capacity()<<endl;
			}
			else if(command=="s")
			{
				cin>>num;
				cout<<vec[num]->size()<<endl;
			}
			else if(command=="copy")
			{
				size_t num2;
				cin>>num>>num2;
				*vec[num2]=*vec[num];
			}
			else if(command=="copy_ctor")
			{
				cin>>num;
				delete vec[1-num];
				vec[1-num]=new oj::Vector(*vec[num]);
			}
			cout<<*vec[0]<<endl<<*vec[1]<<endl;
		}
		delete vec[1];
		delete vec[0];
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
	const std::size_t limited_memory_size(16384);	//byte
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
