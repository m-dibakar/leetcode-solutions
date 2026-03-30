# 49. Group Anagrams

**Difficulty:** Medium  
**Pattern:** HashMap + Sorting

---

## Core Idea

Two strings are anagrams if and only if their **sorted characters are identical**.  
Use the sorted string as a key to group anagrams together in a hashmap.

- `"eat"` → sort → `"aet"`
- `"tea"` → sort → `"aet"`  
- `"tan"` → sort → `"ant"`

Same key = same group.

---

## Approach

1. For each string, create a copy and sort it → this is the key
2. Push the original string into `map[key]`
3. Collect all map values into the result vector

---

## Solution

```cpp
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> m;

    for (const auto& s : strs) {
        string key = s;
        sort(key.begin(), key.end());
        m[key].push_back(s);
    }

    vector<vector<string>> result;
    for (const auto& pair : m) {
        result.push_back(pair.second);
    }
    return result;
}
```

---

## Complexity

| | Value |
|---|---|
| Time | O(n · k log k) — n words, k = avg word length |
| Space | O(n · k) — storing all strings in the map |

---

## Key Details

- `m[key].push_back(s)` — if key doesn't exist, the map creates an empty vector automatically, then appends. No need to check existence first.
- Use `const auto&` in range-based for loops to avoid copying — especially important when values are `vector<string>`.
- Sort a **copy** of the string as the key, not the original — preserve original for output.

---

## Why Not Frequency Array Key?

A frequency-based key (counting 26 chars) is O(k) per word vs O(k log k) for sorting — theoretically faster.  
But in practice, with k ≤ 100:
- `to_string()` and string concatenation add overhead
- The key becomes long (e.g. `"1,0,0,0,1,..."`) — slower to hash
- Sorted key is short and fast to compute

**Sorted key wins in wall time for this problem's constraints.**  
Frequency key only pays off when word lengths are very large.

---

## Mistakes to Avoid

- `m[key] = {s}` — overwrites existing group instead of appending ❌
- Sorting `strs[i]` directly — modifies the original string ❌
- `for(auto pair : m)` — copies every key-value pair needlessly ❌