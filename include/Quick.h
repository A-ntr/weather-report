#ifndef QUICK_H
#define QUICK_H
#include <vector>
#include <utility>
#include <functional>

// Partition helper, defaults ascending
template <typename T, typename Compare = std::less<T>>
int partition(std::vector<T>& arr, int start, int end, Compare comp = Compare()) {
    // Choose first element as pivot
    int p = start;
    T pivot = arr[start];

    for (int i = start + 1; i <= end; i++) {
        if (comp(arr[i], pivot)) {
            p++;
            std::swap(arr[i], arr[p]);
        }
    }

    std::swap(arr[start], arr[p]);
    return p;
}

template <typename T, typename Compare = std::less<T>>
void quickSort(std::vector<T>& arr, int start = 0, int end = arr.size() - 1, Compare comp = Compare()) {

    if (arr.empty()) return;
    
    if (start < end) {
        int p = partition(arr, start, end, comp);

        quickSort(arr, start, p-1, comp);
        quickSort(arr, p+1, end, comp);
    }
}

#endif // QUICK_H