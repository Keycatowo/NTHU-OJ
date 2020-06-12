#include <bits/stdc++.h>
#include "function.h"

namespace oj{

Node::Node()
  : prev(nullptr),next(nullptr){};

Iter::Iter(data_t *begin)
  : p_(begin){};

Bidirect_iter::Bidirect_iter(data_t *begin)
  : Iter(begin){};
  //�~�өI�s�����O�غc�l
Random_iter::Random_iter(data_t *begin)
  : Iter(begin){};
  //�~�өI�s�����O�غc�l

std::ptrdiff_t Random_iter::distance_(const Iter &begin,
                                      const Iter &end) const
{
  // �p��Z���A�Ϋ��Юt�Ȩ������
  return std::abs(begin.get() - end.get());
}

void Random_iter::next_(Iter &des) const
{
  //�]���n�ק�A�ҥH��call by reference
  //des�O�@��Iter��reference
  des.assign(Random_iter(get()+1));
  //�ק�des��random acess ���U�@�Ӧ�m
  //�����o�ثe��m�A+1 (�]�������ONode���ЩҥH�i�H�����B��
}

void Random_iter::prev_(Iter &des) const
{
  des.assign(Random_iter(get()-1));
}

std::ptrdiff_t Bidirect_iter::distance_(const Iter &begin,
                                        const Iter &end) const
{
  //Iter�S��copy constructor �ҥH�����U�ӥ�for loop
  //���recursion�I�s
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
