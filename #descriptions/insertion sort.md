 ## insertion sort
```bash
insertionSort(A, N)
  for i = 1 to N-1
    v = A[i]
    j = i - 1
    while j >= 0 && A[j] > v
      A[j+1] = A[j]
      j--
    A[j+1] = v
```
