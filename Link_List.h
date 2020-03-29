#ifndef _LINK_LIST_V_0_1_H_
#define _LINK_LIST_V_0_1_H_

#include <functional>
#include <iostream>

template <typename T>
class LinkList {
 private:
  struct Node {
   T data;
   Node *next;
  };

  Node *first;
 public:
  LinkList() : first(nullptr) {}
  ~LinkList() {}

  void insert(T data) {
    Node *N = new Node();
    N->data = data;
    N->next = first;
    first = N;
  }

  void traversal(std::function<void(T)> visit) {
    for (Node *N = first; N->next != nullptr; N = N->next) {
      visit(N->data);
    }
  }

  class iterator {
    Node *node;

   public:
    explicit iterator(Node *node) : node(node) {}
    iterator &operator++() {
      node = node->next;
      return *this;
    }
    iterator operator++(int) {
      iterator retval = *this;
      ++(*this);
      return retval;
    }
    bool operator==(iterator other) const { return node == other.node; }
    bool operator!=(iterator other) const { return !(*this == other); }
    T operator*() const { return node->data; }
  };
  iterator begin() { return iterator(first); }
  iterator end() { return iterator(nullptr); }
};

#endif
