# Problems on Heap


##### Merge k Sorted linked list

```
Solution 1:
- create a min heap of size k.
- pick the first element from each linked list and push into the heap.
- when the heap is full, pop the min item.
- pick the next item from the same array and push it into the heap
```


##### Find k largest elements in an array

```
Solution 1:
- build the max heap from that array -> O(n)
- pop out the max element k times
- time complexity:  O(n + k*log(n))
- space complexity: O(1)

Solution 2:
- use non comparison based sorting like counting sort if the elements are integer
- time complexity: O(n)
- space complexity: O(n) -> for auxiliary array

Solution 3:
- create a min heap of size k
- iterate the array element and insert into the heap
- after push check if the heap overflows, then pop the item
- time complexity: O(n*log(k)), O(log(k) -> 1
- space complexity: O(k)
```
