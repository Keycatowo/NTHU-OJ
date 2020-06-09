#include<bits/stdc++.h>
using namespace std;


class Cat{
public:
  enum class Level{
  elder,
  nursy,
  kitty,
  warrior,
  apprentice,
  medicent,
  deputy,
  leader,
  };

  friend istream& operator>>(istream&is,Cat& cat){
    string tmp_level;
    is>>cat.name>>tmp_level>>cat.age;
    if(tmp_level == "elder")
      cat.order = Level::elder;
    else if (tmp_level == "nursy")
      cat.order = Level::nursy;
    else if (tmp_level == "kitty")
      cat.order = Level::kitty;
    else if (tmp_level == "warrior")
      cat.order = Level::warrior;
    else if (tmp_level == "apprentice")
      cat.order = Level::apprentice;
    else if (tmp_level == "medicent")
      cat.order = Level::medicent;
    else if (tmp_level == "deputy")
      cat.order = Level::deputy;
    else if (tmp_level == "leader")
      cat.order = Level::leader;
    return is;
  }

  friend ostream& operator<<(ostream&os,const Cat& cat){
    os<<cat.name<<"\n";
    return os;
  }

  bool operator<(const Cat& rhs){
    // compare order first
    if(this->order != rhs.order)
      return this->order < rhs.order;
    // compare age
    if(this->age != rhs.age){
      if(this->order == Level::apprentice)
        return this->age < rhs.age;
      else
        return this->age > rhs.age;
    }
    // same age , compare name
    return this->name < rhs.name;
  }

  string name;
  Level order;
  int age;

};



int main(){
  freopen("input_11490.txt","r",stdin);
  int N,M;
  vector<Cat> cats;
  while(cin>>N>>M){
    // input
    for (int i=0;i<N;i++){
      Cat new_cat;
      cin>>new_cat;
      cats.push_back(new_cat);
    }
    // sort
    sort(cats.begin(),cats.end());
    // output
    for(int i=0;i<N&&i<M;i++){
      cout<<cats[i];
    }
    // reset
    cats.clear();
  }
  return 0;
}
