# Description

Learning Data Structure and Algorithm in `C` and `python`.

### Learning Tracker

- https://www.notion.so/greyshell/

### `C` Reference Materials

1. Chekuri Srikanth Varma
    - https://interviewprep.appliedcourse.com/course/2/Interview-Preparation-Course
    - https://gate.appliedcourse.com/course/6/data-structures-and-algorithms => till Stack is free
2. Ravindrababu Ravula
    - https://ravindrababuravula.com/interviewpreperation.php
3. Abdul Bari
    - https://www.udemy.com/course/datastructurescncpp/learn/lecture/13319372
    - https://www.youtube.com/watch?v=0IAPZzGSbME&list=PLDN4rrl48XKpZkf03iYFl-O29szjTrs_O
    - Reference `Book`: Data Structures and Algorithms made easy by Narasimha Karumanchi
4. Dr. Naveen Garg - IITD
    - https://www.youtube.com/watch?v=zWg7U0OEAoE&list=PLBF3763AF2E1C572F
    - Reference `Book`: Coreman
5. Clément Mihailescu / AlgoExpert
    - https://www.algoexpert.io/questions
6. Benyam Ephrem
    - https://codinginterviewclass.com/courses/enrolled/633601
7. Algorithm Part 1 and 2 offered by Princeton University
    - https://www.coursera.org/learn/algorithms-part1/home/welcome
    - https://www.coursera.org/learn/algorithms-part2#syllabus
    - Reference `Book`: Algorithms in C by Robert Sedgewick
    - https://algs4.cs.princeton.edu/home/
8. Algorithms Specialization offered by Standford University
    - https://www.coursera.org/specializations/algorithms
9. Leetcode Theory | Exercise 
    - https://leetcode.com/explore/learn/
    - https://leetcode.com/problemset/all/
10. geeksforgeeks.org
    - https://www.geeksforgeeks.org/fundamentals-of-algorithms/
    - https://www.geeksforgeeks.org/heap-data-structure/
11. `Book`: Modern C by Jens Gustedt
12. `Book`: C, the complete reference by Herbert Schildt
13. `Book`: The C Programming Language by Brian Kernighan and Dennis Ritchie

### `python` Reference Materials

1. Grokking Algorithms by Aditya Y Bhargava
2. Problem Solving with Algorithms and Data Structures Using Python by By Brad Miller and David
 Ranum => downloaded
3. Python Data Structures and Algorithms by Benjamin Baka (Author) => safari book
4. Data Structures and Algorithms in Python by magnus => downloaded
5. Data Structures and Algorithms Using Python by Rance D => downloaded
6. http://interactivepython.org/runestone/static/pythonds/index.html by Brad Miller => online
7. https://www.tutorialspoint.com/python/python_algorithm_design.htm => online, downloaded
8. http://nptel.ac.in/courses/106106145/

## Git Workflow

- Check the last commit made from which system. 
```bash
git show --summary
```

- If the last commit was made from different system then we need to
sync the local repo with remote.
```
git pull --rebase

# Sometimes we need to force pull to overwrite local files:
git fetch --all && git reset --hard origin/master && git pull origin master
```

- Update the local repo and push the code into remote branch.
```bash
git commit -am "<system_name>: message" && git push
``` 
