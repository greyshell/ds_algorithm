# Problems on Heap


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
    