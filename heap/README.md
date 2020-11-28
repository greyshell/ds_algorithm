# note on heap

Q) find k largest elements in an array

solution_01:
- create a min heap of size k
- insert each array elements into the the heap
- after inserting an element, check if the heap overflows then pop an item to maintain the size
- time complexity: O(n*log(k)), works faster when k > n/2
- space complexity: O(k)

solution_02:
- build the max heap from that array -> O(n)
- pop the elements k times
- time complexity:  O(n + k*log(n)), works faster when k <= n/2
- space complexity: O(1)

---
Q) merge k sorted linked list

solution_01:
- create a min heap of size k.
- pick the first element from each linked list and push into the heap.
- when the heap is full, pop the item.
- pick the next item from the same array and push it into the heap

solution_02:
- if all linkedlist elements are integer then combine all those lists and use counting sort -> O(n)
- for non-integer elements: quick sort -> O(n*log(n))

---