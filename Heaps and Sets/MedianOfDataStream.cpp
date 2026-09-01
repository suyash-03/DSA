#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/*
    Logic behind the problem:
    - We maintain two heaps:
        1. max_heap -> stores the lower half of numbers
        2. min_heap -> stores the upper half of numbers
    - The two heaps are always balanced so that their sizes differ by at most 1.
    - If total count is even, median = average of top elements of both heaps.
    - If total count is odd, median = top element of the larger heap.

    Example:
    stream = [5, 15, 1, 3]
    after adding 5 -> 5
    after adding 15 -> 10
    after adding 1 -> 5
    after adding 3 -> 4
*/

class MedianFinder {
public:
    priority_queue<int> max_heap; // lower half
    priority_queue<int, vector<int>, greater<int>> min_heap; // upper half

    MedianFinder() {}

    void addNum(int num) {
        if (max_heap.empty() || num <= max_heap.top()) {
            max_heap.push(num);
        } else {
            min_heap.push(num);
        }

        if (min_heap.size() > max_heap.size() + 1) {
            max_heap.push(min_heap.top());
            min_heap.pop();
        } else if (max_heap.size() > min_heap.size() + 1) {
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
    }

    double findMedian() {
        if (max_heap.size() == min_heap.size()) {
            return (max_heap.top() + min_heap.top()) / 2.0;
        }
        return max_heap.size() > min_heap.size() ? max_heap.top() : min_heap.top();
    }
};

int main() {
    MedianFinder mf;
    vector<int> nums = {5, 15, 1, 3};

    for (int x : nums) {
        mf.addNum(x);
        std::cout << "After adding " << x << ": median = " << mf.findMedian() << std::endl;
    }

    return 0;
}

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */