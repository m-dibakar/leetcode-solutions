# LC 78 — Subsets

**Difficulty:** Medium
**Topic:** Recursion · Backtracking · Bit Manipulation
**Date:** 17 March 2026 · Day 76 🔥

---

## Problem

Given an integer array `nums` of unique elements, return all possible subsets (the power set). The solution must not contain duplicate subsets.

```
Input:  nums = [1, 2, 3]
Output: [[], [1], [2], [1,2], [3], [1,3], [2,3], [1,2,3]]
```

---

## Key Insight

For `n` elements, there are exactly **2ⁿ subsets** — at each element you make a binary choice: include it or don't. Both approaches exploit this same idea, just differently.

---

## Approach 1 — Recursion

### Idea

Pick the last element, then recurse twice:
- **Yes branch** — add it to the current subset
- **No branch** — skip it

When the array is empty, the current subset is complete — push it to results.

### Decision Tree (`[1,2,3]`)

```
solve([1,2,3], [])
├── include 3 → solve([1,2], [3])
│   ├── include 2 → solve([1], [3,2])
│   │   ├── include 1 → solve([], [3,2,1]) ✓
│   │   └── exclude 1 → solve([], [3,2])   ✓
│   └── exclude 2 → solve([1], [3])
│       ├── include 1 → solve([], [3,1])   ✓
│       └── exclude 1 → solve([], [3])     ✓
└── exclude 3 → solve([1,2], [])
    └── ...                                ✓ (4 more)
```

### Code

```cpp
void solve(vector<int> nums, vector<vector<int>>& res, vector<int> subset) {
    if (nums.empty()) {
        res.push_back(subset);
        return;
    }
    int n = nums.back();
    nums.pop_back();

    subset.push_back(n);       // include
    solve(nums, res, subset);

    subset.pop_back();         // exclude
    solve(nums, res, subset);
}
```

### ⚠️ Bugs to avoid

| Bug | Symptom | Fix |
|-----|---------|-----|
| Pass `nums` by reference | "No" branch sees already-mutated array | Pass by **value** |
| Init subset as `vector<int> subset(1)` | Every subset has a spurious leading `0` | Use `vector<int> subset` (empty) |

### Complexity

| | |
|---|---|
| Time | O(n · 2ⁿ) |
| Space | O(n · 2ⁿ) + O(n) call stack |

---

## Approach 2 — Bit Manipulation

### Idea

Iterate every integer `mask` from `0` to `2ⁿ - 1`. Read its binary representation — if bit `i` is set, include `nums[i]` in the subset.

```
n = 3 → masks 0..7

mask  binary  subset
  0    000     []
  1    001     [1]
  2    010     [2]
  3    011     [1, 2]
  4    100     [3]
  5    101     [1, 3]
  6    110     [2, 3]
  7    111     [1, 2, 3]
```

### How `mask & (1 << i)` works

```
mask = 6  →  1 1 0
                     i=2  110 & 100 = 1  → include nums[2] = 3
                     i=1  110 & 010 = 1  → include nums[1] = 2
                     i=0  110 & 001 = 0  → skip    nums[0] = 1
Result: [2, 3] ✓
```

### Code

```cpp
vector<vector<int>> subsets(vector<int>& nums) {
    int n = nums.size();
    int total = 1 << n;          // 2^n
    vector<vector<int>> res;

    for (int mask = 0; mask < total; mask++) {
        vector<int> subset;
        for (int i = 0; i < n; i++)
            if (mask & (1 << i))
                subset.push_back(nums[i]);
        res.push_back(subset);
    }
    return res;
}
```

### Complexity

| | |
|---|---|
| Time | O(n · 2ⁿ) |
| Space | O(n · 2ⁿ) — no recursion stack |

---

## Comparison

| | Recursive | Bit Manipulation |
|---|---|---|
| Time | O(n · 2ⁿ) | O(n · 2ⁿ) |
| Space | O(n · 2ⁿ) + O(n) stack | O(n · 2ⁿ) |
| Runtime (LC) | 3 ms | 0 ms |
| Memory (LC) | 16.3 MB | 9.9 MB |
| Output order | Largest-first | Natural binary order |
| Readability | Intuitive for tree thinking | Elegant, concise |

Both produce valid answers — LC accepts any order.

---

## Takeaway

> The power set is just every possible combination of binary choices. Once you see that, both approaches fall out naturally — the recursion makes the choices explicit, and the bitmask encodes them implicitly.