# 1994 - I2P(II)2020_Lee_Mid2_Practice


| State  | Number | Name                                     | tags |
| ------ | ------ | ---------------------------------------- | ---- |
| AC     | 11419  | Using your vector (Implement a vector 3) |      |
| AC     | 11438  | Implement a list 2 (back)                |      |
| hw6-AC | 11443  | 3DShape                                  |      |
| AC     | 11461  | Copy a vector (Implement a vector 7)     |      |
| hw6-AC | 11484  | Draw the Shapes                          |      |
| AC     | 11677  | Implement a list 4 (back and remove)     |      |
| AC     | 12764  | Binary Search Tree for Shapes            |      |

## 11419 Using your vector (Implement a vector 3)

### 重點
#### placement new and delete
見[浅谈 C++ 中的 new/delete 和 new[]/delete[]](https://www.cnblogs.com/hazir/p/new_and_delete.html)以及[Placement new的用法及用途](http://www.cppblog.com/kongque/archive/2010/02/20/108093.html)  
簡言之，用自訂方式在已經分配好的內存上重新建立對象，避免**反復直接操作內存**造成時間和空間上的浪費
```c++
begin_[i].~value_type(); // 用來刪除
new (begin_ + i) value_type(begin_[i + 1]); // 用來新增並初始
```
#### 用static_cast來new自訂類別
```c++
pointer new_begin_ (static_cast<pointer> (operator new[](new_capacity * sizeof(value_type))));
```
拆解一下括號
```c++
pointer new_begin_
  (
    static_cast<pointer>
    (
      operator new[]
      (
        new_capacity * sizeof(value_type) // 計算所需空間
      ) // 用operator new來取得空間
    )//包起來丟給static_cast轉型成pointer
  );// placement new
```
#### 用interface存取
因為本次作業中`Employee`類別中並沒有可以直接操作的函數，但有留一個尚未定義的friend類別`God`  
所以對於`Employee`中的內容要透過`God`來完成  
```c++
struct God{
  typedef std::size_t size_type;
  void hire(Vector &vec, const std::string &name);
  void show(const Vector &vec);
  void fire(Vector &vec,unsigned id);
  void fire(Vector &vec,const std::string &name);
};
```
實作在freiend class中完成
```c++
God boss; /// An interface to access class-Employee

// add_employee -> boss.hire()
void God::hire(Vector &vec, const std::string &name){
  vec.push_back(Employee(name));
}
// print -> boos.show()
void God::show(const Vector &vec){
  using std::cout;
  for (int i=0;i<vec.size();i++){
    cout<<vec[i].id_<<" "<<vec[i].name_<<"\n";
  }
}
// quit -> boss.fire()
void God::fire(Vector &vec, unsigned id){
  for (int i=0;i<vec.size();i++){
    if (vec[i].id_ == id){
      vec.erase(i);
      return ;
    }
  }
}
void God::fire(Vector &vec, const std::string &name){
  int i=0;
  while(i<vec.size()){
    if (vec[i].name_ == name){
      vec.erase(i); //考慮同名
    }
    else
      i++;
  }
}
```
透過介面呼叫
```c++
void add_employee(Vector &vec, const std::string &name){
  boss.hire(vec,name);
}
void print(const Vector &vec){
  boss.show(vec);
}
void quit(Vector &vec, unsigned id){
  boss.fire(vec,id);
}
void quit (Vector &vec, const std::string &name){
  boss.fire(vec,name);
}
```

## 11438 - Implement a list 2 (back)
### 重點
題目只要求對結尾進行處理，並且給定結構為**double linked list**，所以可以直接將list的head->prev設成tail  

```c++

void List::pop_back(){
  // for size 0 list
  if(begin_==nullptr)
    return;
  // for size 1 list
  if(begin_->next == begin_){
    delete begin_;
    begin_ = nullptr;
    return;
  }

  // for size 2+ list
  Node* old_tail = begin_->prev;
  Node* new_tail = old_tail->prev;
  new_tail->next = begin_;
  begin_->prev = new_tail;
  delete old_tail;
}
```
```c++
void List::push_back(const_reference val){
  // create a new node
  Node* new_node = new Node;
  new_node->data = val;

  // for size 0 list
  if(begin_==nullptr){
    begin_ = new_node;
    begin_->prev = new_node;
    begin_->next = new_node;
  }

  // for size 1+ list
  else{
    Node* old_tail = begin_->prev;
    old_tail->next = new_node;
    new_node->prev = old_tail;
    new_node->next = begin_;
    begin_->prev = new_node;
  }

}
```

## 11461  Copy a vector (Implement a vector 7)



```c++
Vector::Vector(const Vector &rhs){
  // copy constructor
  begin_ = nullptr;
  last_  = nullptr;
  end_   = nullptr;
  reserve(rhs.size());
  for(size_type i=0; i<rhs.size();i++)
    insert(i,rhs[i]);
}

Vector& Vector::operator=(const Vector &rhs){
  // important! **/
  /* deal with the case copy to itself */
  if(this==&rhs) return *this;

  // delete old vector
  for(size_type i=0;i<size();i++)
    begin_[i].~value_type();
  last_=begin_;
  reserve(rhs.size());
  // insert new vector
  for(size_type i=0;i<rhs.size();i++)
    insert(i,rhs[i]);

  return *this;
}
```

```c++
void Vector::insert(size_type pos, const_reference val){
  size_type old_size = size();
  size_type old_capacity = capacity();

  // for invalid pos case
  if(pos>old_size || pos<0)
    return;
  // for reserve memory
  if(last_==end_)
    reserve(std::max(old_capacity+1,old_capacity*3));

  /// for insert
  if(pos==old_size)
    new (begin_+old_size) value_type(val);
  else{
    new (begin_+old_size) value_type(begin_[old_size-1]);
    for (size_type i=old_size-1;i>pos;i--){
    // copy_backward
      begin_[i] = begin_[i-1];
    }
    begin_[pos] = val;
  }
  last_++;
}
```


##  11677 Implement a list 4 (back and remove)
對於刪除開頭的元素要單獨處理
```c++
void List::remove(const_reference val){
  // for size 0 list
  if(begin_==nullptr)
    return;
  // for size 1 list delete
  if(begin_->next == begin_ && begin_->data == val){
    delete begin_;
    begin_ = nullptr;
    return;
  }

  // for size 2+ list
  if(begin_->data == val){
    // for head be delete
    // delete and recursion
    Node* tmp = begin_;
    begin_ = tmp->next;
    begin_->prev = tmp->prev;
    tmp->prev->next = begin_;
    delete tmp;
    remove(val);
  }
  else{
    // case not delete head
    Node* cur = begin_;
    do{
      if(cur->data == val){
        Node* tmp = cur;
        cur = cur->next;
        cur->prev = tmp->prev;
        tmp->prev->next = cur;
        delete tmp;
      }
      else
        cur = cur->next;
    }while(cur!=begin_);
  }
}
```

## 12764

```c++
class Square : public Shape{
public:
  Square(double arg[]){
    setArea(arg);
  }

  void setArea(double arg[]) override{
    if (arg[0]<0)
      area = 0;
    else
      area = arg[0] * arg[0];
  }

  void print() override{
    using namespace std;
    cout<<"Square("<<fixed<<setprecision(2)<<area<<")\n";
  }
};




void BST::insertNode(std::string& line){
  using namespace std;
  stringstream ss;
  ss<<line;
  string shape_name;
  ss>>shape_name;

  Node* new_node = new Node;
  double arg[2];
  if(shape_name=="Circle"){
    ss>>arg[0]>>arg[1];
    new_node->data = new Circle(arg);
  }
  else{
    ss>>arg[0];
    new_node->data = new Square(arg);
  }

  if (root == nullptr){
    root = new_node;
  }
  else{

    Node** cur = &root;
    while(*cur!=nullptr){
      if (new_node->data->getArea() < (*cur)->data->getArea())
        cur = & (*cur)->left;
      else if(new_node->data->getArea() > (*cur)->data->getArea())
        cur = & (*cur)->right;
      else
        return;
    }
    *cur = new_node;

  }
}
```
