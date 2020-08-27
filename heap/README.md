# Problems on Heap


##### Find k largest elements in an array
```
Solution 1: 
- build the max heap from that array -> O(n)
- pop out the max element k times
- time complexity:  O(k*log(n)), effective when k << n
- space complexity: O(1)

Solution 2:
- use non comparison based sorting like counting sort if the elements are integer
- time complexity: O(n)
- space complexity: O(n) -> for auxiliary array

Solution 3:
- create a min heap of size k
- iterate the array element and insert into the heap
- before insertion, check if the heap is full, then pop the min element then insert
- in this approach, when we finish scanning nth element, by that time, we'll be already discarded
 (n - k) min elements and the heap contains the top k min element from the last => which are
  basically k largest elements.
- time complexity: O(n*log(k)), effective when k tends to n
- space complexity: O(k)
```
    