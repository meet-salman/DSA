# Euclidean Algorithm (GCD Finder)

This program implements the **Euclidean Algorithm** to compute the Greatest Common Divisor (GCD) of two integers.

---

## Algorithm

The **Euclidean Algorithm** works on the principle that:

`gcd(a, b) = gcd(b, a % b), where a ≥ b`


- If `b = 0`, then `gcd(a, 0) = a`.
- Otherwise, repeatedly replace `(a, b)` with `(b, a % b)` until `b = 0`.

### Steps:
1. Take two integers `a` and `b` as input.
2. Convert both values to positive using `abs()` (since GCD is always non-negative).
3. Apply recursion:
   - If `b != 0`, calculate remainder `rem = a % b`.
   - Set `a = b` and `b = rem`.
   - Repeat the process.
4. When `b = 0`, return `a` as the GCD.
5. Print the result.

---

## Dry Run Example

### Example Input:

`a = 48, b = 18`


### Steps:
1. **First call:**  
   `euclidean_algo(48, 18)`  
   - `rem = 48 % 18 = 12`  
   - Recurse with `(18, 12)`

2. **Second call:**  
   `euclidean_algo(18, 12)`  
   - `rem = 18 % 12 = 6`  
   - Recurse with `(12, 6)`

3. **Third call:**  
   `euclidean_algo(12, 6)`  
   - `rem = 12 % 6 = 0`  
   - Recurse with `(6, 0)`

4. **Fourth call:**  
   `euclidean_algo(6, 0)`  
   - Since `b = 0`, return `6`.

   **Final Answer = 6**

---

## Example Run

**Input:**

`48 18`


**Output:**

`6`


