# Dutch National Flag — Sort Colors (LC 75)

**Link:** https://leetcode.com/problems/sort-colors/
**Difficulty:** Medium
**Date:** April 6, 2026

---

## Problem Summary
Given an array with only 0s, 1s, and 2s, sort it in-place in one pass without using library sort.

---

## Pattern
Three Pointers — Dutch National Flag (variation of Two Pointers)

---

## Key Insight
Maintain three regions simultaneously:
```
[...0s...][...1s...][unseen][...2s...]
          ^l        ^m      ^r
```
- Everything left of `l` is 0
- Everything between `l` and `m` is 1
- Everything right of `r` is 2
- `m` to `r` is unseen/unprocessed

---

## Rules (the only 3 things to remember)
```
nums[m] == 0 → swap with l, move BOTH l++ and m++
nums[m] == 2 → swap with r, move ONLY r-- (don't move m!)
nums[m] == 1 → just move m++
```

### Why don't we move m when swapping a 2?
When you swap `nums[m]` with `nums[r]`, what comes back to position `m` is **unknown** — it hasn't been scanned yet. So you must check `m` again.

### Why do we move m when swapping a 0?
When you swap `nums[m]` with `nums[l]`, what comes back is always a **1** — because the region between `l` and `m` only contains 1s (already processed). So it's safe to move `m` forward.

---

## Solution
```cpp
void sortColors(vector<int>& nums) {
    int l = 0, m = 0, r = nums.size() - 1;
    while (m <= r) {
        if (nums[m] == 0) {
            swap(nums[m++], nums[l++]);
        } else if (nums[m] == 2) {
            swap(nums[m], nums[r--]);
        } else {
            m++;
        }
    }
}
```

---

## Dry Run
```
Input: [2, 0, 2, 1, 1, 0]
l=0, m=0, r=5

m=0: nums[m]=2 → swap(nums[0],nums[5]) → [0,0,2,1,1,2], r=4
m=0: nums[m]=0 → swap(nums[0],nums[0]) → [0,0,2,1,1,2], l=1, m=1
m=1: nums[m]=0 → swap(nums[1],nums[1]) → [0,0,2,1,1,2], l=2, m=2
m=2: nums[m]=2 → swap(nums[2],nums[4]) → [0,0,1,1,2,2], r=3
m=2: nums[m]=1 → m=3
m=3: nums[m]=1 → m=4
m=4 > r=3 → stop

Output: [0,0,1,1,2,2] ✅
```

---

## Complexity
| | |
|---|---|
| Time | O(n) — single pass |
| Space | O(1) — in-place |

---

## Mistakes I Made
- Used midpoint formula `m = l + (r-l)/2` — wrong, m is a scanner not a midpoint
- Used wrong loop condition `l<=m || r>=m` — correct is `m <= r`
- Used `if/if/else` instead of `if/else if/else` — caused double swaps
- Moved `m` after swapping a 2 — wrong, element swapped back is unknown

---

## Pattern Recognition
When to think Dutch National Flag:
- Array has exactly **3 distinct values**
- Asked to sort **in-place**
- Asked for **one pass**
- Asked for **O(1) space**

---

## Similar Problems
| Problem | How it relates |
|---------|---------------|
| Sort Array By Parity (LC 905) | 2-way partition, same idea |
| Partition Array (LC 86) | partition around pivot |
| Wiggle Sort II (LC 324) | harder variant |