#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>
#include <algorithm>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * Constructs an m-ary heap.
   * @param m ary-ness (must be >=2)
   * @param c Comparator functor.
   */
  Heap(int m=2, PComparator c = PComparator());
  ~Heap();

  void push(const T& item);
  T const & top() const;
  void pop();
  bool empty() const;
  size_t size() const;

private:
  std::vector<T> data;
  int m;
  PComparator comp;
};

template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c) : data(), m(m), comp(c) {
    if(m < 2) {
        throw std::invalid_argument("Heap arity must be at least 2");
    }
}

template <typename T, typename PComparator>
Heap<T,PComparator>::~Heap() {
    // Nothing to do; vector cleans up automatically.
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item) {
    data.push_back(item);
    int index = data.size() - 1;
    // Sift-up
    while(index > 0) {
        int parent = (index - 1) / m;
        if(comp(data[index], data[parent])) {
            std::swap(data[index], data[parent]);
            index = parent;
        } else {
            break;
        }
    }
}

template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const {
    if(empty()){
        throw std::underflow_error("Heap is empty");
    }
    return data[0];
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::pop() {
    if(empty()){
        throw std::underflow_error("Heap is empty");
    }
    // Replace the root with the last element and remove the last element.
    data[0] = data.back();
    data.pop_back();
    int index = 0;
    int n = data.size();
    // Sift-down
    while(true) {
        int best = index;
        // Check all m children.
        for (int i = 1; i <= m; i++) {
            int child = m * index + i;
            if(child < n && comp(data[child], data[best])) {
                best = child;
            }
        }
        if(best == index) break;
        std::swap(data[index], data[best]);
        index = best;
    }
}

template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const {
    return data.empty();
}

template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const {
    return data.size();
}

#endif
