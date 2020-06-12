#include <bits/stdc++.h>
#include "function.h"

namespace oj{

Node::Node()
  : prev(nullptr),next(nullptr){};

Iter::Iter(data_t *begin)
  : p_(begin){};

Bidirect_iter::Bidirect_iter(data_t *begin)
  : Iter(begin){};
  //繼承呼叫父類別建構子
Random_iter::Random_iter(data_t *begin)
  : Iter(begin){};
  //繼承呼叫父類別建構子

std::ptrdiff_t Random_iter::distance_(const Iter &begin,
                                      const Iter &end) const
{
  // 計算距離，用指標差值取絕對值
  return std::abs(begin.get() - end.get());
}

void Random_iter::next_(Iter &des) const
{
  //因為要修改，所以用call by reference
  //des是一個Iter的reference
  des.assign(Random_iter(get()+1));
  //修改des成random acess 的下一個位置
  //先取得目前位置再+1 (因為類型是Node指標所以可以直接運算
}

void Random_iter::prev_(Iter &des) const
{
  des.assign(Random_iter(get()-1));
}

std::ptrdiff_t Bidirect_iter::distance_(const Iter &begin,
                                        const Iter &end) const
{
  //Iter沒有copy constructor 所以不能抓下來用for loop
  //改用recursion呼叫
  if(begin.get() == end.get())
    return 0;
  else
    return distance_(Bidirect_iter(begin.get()->next),end) + 1;
}

void Bidirect_iter::next_(Iter &des) const
{
//  des.assign(des.get().next);
  des.assign(Bidirect_iter(get()->next));
}

void Bidirect_iter::prev_(Iter &des) const
{
  des.assign(Bidirect_iter(get()->prev));
}



} //namespace oj
