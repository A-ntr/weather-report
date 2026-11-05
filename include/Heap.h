#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include <utility>
#include <algorithm>
#include <functional>
#include <stdexcept>

// In-place heapify helper func (0 index) default max-heap (less<T>)
template <typename T, typename Compare = std::less<T>>
void heapifyDown(std::vector<T>& arr, size_t n, size_t i, Compare comp = Compare()) {
  size_t parent = i;
  size_t left = parent*2+1;
  size_t right = parent*2+2;
  size_t target = parent;
  if (left < n && comp(arr[target], arr[left])) target = left;
  if (right < n && comp(arr[target], arr[right])) target = right;

  if (target != parent) {
    std::swap(arr[parent], arr[target]);
    heapifyDown(arr, n, target, comp);
  }
}

template <typename T, typename Compare = std::less<T>>
void heapSort(std::vector<T>& arr, Compare comp = Compare()) {
  if (arr.size() <= 1) return;
  for (int i = arr.size()/2 -1; i >= 0; --i)
    heapifyDown(arr, arr.size(), i, comp);
  for (int i = arr.size()-1; i > 0; --i) {
    std::swap(arr[0], arr[i]);
    heapifyDown(arr, i, 0, comp);
  }
}

#endif // HEAP_H