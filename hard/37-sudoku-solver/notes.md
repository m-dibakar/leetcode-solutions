# 37. Sudoku Solver — Notes

**Difficulty:** Hard
**Topic:** Backtracking, Bit Manipulation
**Date Solved:** 16/03/2026

---

## 🧩 Problem Summary

Fill all empty cells (`'.'`) of a 9×9 Sudoku board such that:
- Every row contains digits 1–9 exactly once
- Every column contains digits 1–9 exactly once
- Every 3×3 box contains digits 1–9 exactly once

The input is guaranteed to have exactly one valid solution.

---

## 🔵 Approach 1 — Backtracking (Brute Force)

**Runtime:** 322 ms

### Idea
Try placing digits 1–9 in each empty cell left-to-right, top-to-bottom.
For each placement, check if it's valid. If yes, recurse to the next cell.
If no digit works, backtrack and try the next digit in the previous cell.

### isSafe() Check
For a digit at `(row, col)`, scan:
- All 9 cells in that row
- All 9 cells in that column
- All 9 cells in the 3×3 box → top-left corner at `((row/3)*3, (col/3)*3)`

### Bugs I Hit
- `to_string(digit)` returns a `std::string` — comparing it with a `char` always fails. Use `'0' + digit` instead.
- `sudokuSolver` was declared `void` but had `return true` / `return false` inside — must be `bool`.
- Missing semicolon after `nextCol = 0`.

### Complexity
- **Time:** O(9^m) where m = number of empty cells
- **Space:** O(m) recursion stack

### Bottlenecks
1. `isSafe()` scans 27 cells on every single digit attempt — O(27) per check
2. Cells are always picked in fixed order — even if the next cell has 7 valid options, we still try it first

---

## 🔴 Approach 2 — Bitmask + MRV (Optimized)

**Runtime:** 2 ms

### Key Optimizations

#### 1. Bitmask for O(1) Safety Check
Maintain three arrays: `rowMask[9]`, `colMask[9]`, `boxMask[9]`.
Each is a 9-bit integer where bit `k` being set means digit `k+1` is already placed.

```
used  = rowMask[r] | colMask[c] | boxMask[(r/3)*3 + c/3]
avail = (~used) & 0x1FF   // 9-bit mask of valid digits
```

Place a digit → OR the bit in. Undo → XOR the bit out.

#### 2. MRV — Minimum Remaining Values
Instead of picking cells left-to-right, always pick the empty cell with the **fewest valid digits** first.

- A cell with 1 option → no branching at all
- A cell with 2 options → at most 2 branches
- Dramatically reduces the search tree compared to fixed order

```cpp
int options = __builtin_popcount(avail);
// pick cell with minimum options
```

#### 3. Bit Tricks for Iterating Digits
```cpp
while (avail) {
    int bit   = avail & (-avail);      // isolate lowest set bit
    avail    &= avail - 1;             // clear lowest set bit
    int digit = __builtin_ctz(bit);    // bit position = digit index
}
```

#### 4. Early Dead-End Detection
If any empty cell has 0 valid options during the MRV scan, return `false` immediately — no point recursing deeper.

### Complexity
- **Time:** O(9^m) worst case, but MRV prunes the tree so aggressively it rarely approaches this
- **Space:** O(m) recursion stack + O(1) for bitmask arrays

---

## 📈 Comparison

| | Approach 1 | Approach 2 |
|---|---|---|
| **Runtime** | 322 ms | 2 ms |
| **Safety check** | O(27) scan | O(1) bitmask |
| **Cell selection** | Fixed order | MRV (most constrained first) |
| **Dead-end detection** | On recursion | During cell selection |

---

## 💡 Key Takeaway

The backtracking algorithm is identical in both approaches.
What changed is everything *around* it — how we check validity and which cell we pick next.
