#include<cstddef>
#include<iostream>
#include<vector>
#include"function.h"

namespace oj
{
	Iter::~Iter(){}
}

int main()
{
  freopen("input.txt","r",stdin);

	using namespace std;
	size_t N;
	cin>>N;
	vector<oj::Node> vec(N);
	for(size_t i(0);i!=vec.size();++i)
	{
		oj::Node::value_type order;
		cin>>order;//下一個節點的位置
		cin>>vec[order].val;//下個節點的值
		vec[i].next=&vec[0]+order;//這個節點指向下個的位置
		vec[order].prev=&vec[0]+i;//下個節點指回這個節點的位置
	}
	size_t H;
	cin>>H;
	vec[H].prev=vec[H].prev->next=NULL;
	oj::Iter *iter(new oj::Bidirect_iter(&vec[H]));	//iter is current position
	size_t iter_pos(0);
	for(unsigned short I;cin>>I;)
	{
		switch(I)
		{
		case 0:
		{
			size_t P;
			cin>>P;
			oj::Bidirect_iter dis(&vec[H]);
			for(size_t i(0);i!=P;++i)
			{
				oj::Bidirect_iter next(NULL);
				dis.next(next);
				dis.assign(next);
			}
			if(iter_pos<P)
				cout<<iter->distance(dis)<<endl;
			else
				cout<<dis.distance(*iter)<<endl;
			break;
		}
		case 1:
			cin>>iter->get_val();
			break;
		case 2:
		{
			oj::Bidirect_iter next(NULL);
			iter->next(next);
			iter->assign(next);
			++iter_pos;
			break;
		}
		case 3:
		{
			oj::Bidirect_iter prev(NULL);
			iter->prev(prev);
			iter->assign(prev);
			--iter_pos;
			break;
		}
		}
	}
	delete iter;
	iter=new oj::Random_iter(&vec.front());
	while(iter->get()!=(&vec.back()+1))	//(vec.data()+vec.size())
	{
		cout<<iter->get_val()<<' ';
		oj::Random_iter next(NULL);
		iter->next(next);
		iter->assign(next);
	}
	cout<<endl;
	iter->assign(oj::Random_iter(&vec.front()));
	for(oj::Random_iter begin(&vec.front());iter->get()!=(&vec.back()+1);)	//(vec.data()+vec.size())
	{
		cout<<begin.distance(*iter)<<' ';
		oj::Random_iter next(NULL);
		iter->next(next);
		iter->assign(next);
	}
	cout<<endl;
	delete iter;
}
