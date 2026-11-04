#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include <utility>
#include <algorithm>
#include <functional>
#include <stdexcept>

// In-place heapify helper func (0 index) default min-heap (less<T>)
template <typename T, typename Compare = std::less<T>>
void heapifyDown(std::vector<T>& arr, size_t n, size_t i, Compare comp = Compare()) {
  size_t parent = i;
  size_t left = parent*2+1;
  size_t right = parent*2+2;
  size_t target = parent;
  if (left < n && comp(arr[left], arr[target])) target = left;
  if (right < n && comp(arr[right], arr[target])) target = right;

  if (target != parent) {
    std::swap(arr[parent], arr[target]);
    heapifyDown(arr, n, target, comp);
  }
}


#endif // HEAP_H