# Recursive Binary Search (C++ with Vectors)

This program implements the **Binary Search Algorithm** using recursion on a C++ `vector / array`.  
It searches for a target value in a sorted vector and returns its index if found, otherwise `-1`.

---

## Algorithm

The binary search algorithm follows **divide and conquer**:

1. Set `start = 0` and `end = n - 1` where `n` is the size of the vector.
2. If `start > end` → the target does not exist → return `-1`.
3. Calculate the midpoint:

       midPoint = start + ((end - start) / 2)

   (This avoids integer overflow compared to `(start + end)/2`).

4. Compare `vec[midPoint]` with the target:
- If equal → return `midPoint`.
- If `target > vec[midPoint]` → search the right half (`midPoint + 1` to `end`).
- If `target < vec[midPoint]` → search the left half (`start` to `midPoint - 1`).
5. Repeat recursively until found or search space is empty.

---

## Dry Run Example

### Example Input:

    vec = {5, 6, 7, 8, 9, 10, 11, 12, 13}

    target = 5

### Steps:
1. **First Call:**  
   `start = 0, end = 8`  
   `midPoint = 0 + (8 - 0)/2 = 4`  
   - `vec[4] = 9`  
   - Target `5 < 9` → search left half (`0 to 3`).

2. **Second Call:**  
   `start = 0, end = 3`  
   `midPoint = 0 + (3 - 0)/2 = 1`  
   - `vec[1] = 6`  
   - Target `5 < 6` → search left half (`0 to 0`).

3. **Third Call:**  
   `start = 0, end = 0`  
   `midPoint = 0`  
   - `vec[0] = 5` Target found.

**Result:** Index = `0`

---

## Example Run

**Input (hardcoded in program):**
```cpp
vector<int> vec = {5, 6, 7, 8, 9, 10, 11, 12, 13};
int target = 7;
```
**Output:**
`2`

```cpp
target = 3;
```
**Output:**
`-1`

```cpp
target = 13;
```
**Output:**
`8`

```cpp
target = 15;
```
**Output:**
`-1`
