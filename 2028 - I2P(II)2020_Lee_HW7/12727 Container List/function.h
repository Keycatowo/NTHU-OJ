#include <cstdint>

namespace oj {
using size_type = uint64_t;
using value_type = int32_t;
using reference = value_type &;
using difference_type = uint64_t;

struct Node {
  Node *prev, *next;
  value_type data;
  Node(value_type d = 0) : prev(nullptr), next(nullptr), data(d) {}
};

struct iterator_impl_base {
  virtual reference operator*() const = 0;
  virtual iterator_impl_base &operator++() = 0;
  virtual bool operator!=(const iterator_impl_base &) const = 0;
  virtual iterator_impl_base *clone() const = 0;
};

class list_iterator : public iterator_impl_base {
 protected:
  Node *_node;
 public:
  list_iterator() : _node(nullptr) {}
  list_iterator(Node *n) : _node(n) {}
  reference operator*() const { return _node->data; }
  iterator_impl_base *clone() const { return new list_iterator(_node); }

  iterator_impl_base &operator++();
  bool operator!=(const iterator_impl_base &) const;
};

class iterator {
 protected:
  iterator_impl_base *_p;
 public:
  iterator(iterator_impl_base *p) : _p(p->clone()) {}
  iterator(const iterator& rhs) : _p(rhs._p->clone()) {}
  ~iterator() { delete _p, _p = 0; }
  iterator operator+(difference_type offset) const {
    iterator it(_p);
    while (offset--) ++it;
    return it;
  }
  reference operator*() const { return **_p; }
  iterator &operator++() { return ++*_p, *this; }
  bool operator!=(const iterator &rhs) { return *_p != *rhs._p; }
  bool operator==(const iterator &rhs) { return !(*_p != *rhs._p); }
};

struct container_base {
  virtual size_type size() const = 0;
  virtual bool empty() const = 0;
  virtual void clear() = 0;
};

struct dynamic_size_container : container_base {
  virtual iterator begin() = 0;
  virtual iterator end() = 0;
};

struct ordered_container : dynamic_size_container {
  virtual void insert(iterator, size_type, const value_type) = 0;
  virtual void erase(iterator, iterator) = 0;
};

class list : public ordered_container {
 protected: // you have two pointers to spare :) do anything you wish
  Node *_head;
  Node *_tail;
  size_type _size;
 public:
  list();
  ~list();
  void clear();
  size_type size() const;
  bool empty() const;
  iterator begin();
  iterator end();
  void insert(iterator, size_type, const value_type);
  void erase(iterator, iterator);
};
};

