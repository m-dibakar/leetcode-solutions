# 56. Merge Intervals — Notes

## Pattern
**Sort + Linear Scan with `result.back()`**

---

## Key Insight
After sorting by start, any overlapping interval **must come immediately after** the current one. No need to look backwards → single pass suffices.

---

## Algorithm
1. Sort intervals by start (lexicographic sort on `vector<vector<int>>` does this automatically)
2. Seed result with `intervals[0]`
3. For each remaining interval, compare with `result.back()`:
   - **Overlap** → extend `result.back()[1]` using `max`
   - **No overlap** → push new interval to result

---

## Overlap Condition
```
intervals[i][0] <= result.back()[1]
```
Only need to check this one side because starts are already sorted.

## Merge Step
```
result.back()[1] = max(intervals[i][1], result.back()[1])
```
`max` is necessary to handle containment: `[1,10]` + `[2,5]` → `[1,10]`, not `[1,5]`

---

## Solution
```cpp
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> result;
    result.push_back(intervals[0]);
    for (int i = 1; i < intervals.size(); i++) {
        if (intervals[i][0] <= result.back()[1]) {
            result.back()[1] = max(intervals[i][1], result.back()[1]);
        } else {
            result.push_back(intervals[i]);
        }
    }
    return result;
}
```

---

## Complexity
| | |
|---|---|
| Time | O(n log n) — sort dominates; loop is O(n) |
| Space | O(n) — result array |

---

## Sorting Trick
`std::sort` on `vector<vector<int>>` sorts **lexicographically** — compares `[0]` (start) first, then `[1]` as tiebreaker. No pairs, no custom comparator needed.

---

## Edge Cases
- Contained interval: `[1,10],[2,5]` → `[1,10]` — handled by `max`
- Touching intervals: `[1,4],[4,5]` → `[1,5]` — `<=` in overlap check handles equality
- Already sorted input: works fine
- Single interval: loop doesn't execute, returns seeded result

---

## Related Problems
- **57. Insert Interval** — same `result.back()` pattern, but insert a new interval first
- **252/253. Meeting Rooms** — same sort + overlap check, different question asked
- **986. Interval List Intersections** — two-pointer variant on sorted interval lists