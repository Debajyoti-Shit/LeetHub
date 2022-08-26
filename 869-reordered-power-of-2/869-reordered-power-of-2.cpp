class Solution {
public:
    string sortStr(int n) {
        // since the input is an integer,
        // we convert it to a string first
        string t = to_string(n);
        // use STL to sort
        sort(t.begin(), t.end());
        // return the string
        return t;
    }
    
    // the idea is to sort `n` and compare all sorted power of two
    // if they are matched, then it means they can be reordered to each other
    bool reorderedPowerOf2(int n) {
        // since the sorted string of n is always same
        // so we convert it here instead of doing it in the loop
        string s = sortStr(n);
        for (int i = 0; i <= 30; i++) {
            // power of 2 = 1 << i
            // we sort each power of 2 string
            string t = sortStr(1 << i);
            // and compare with `s`
            // if they are matched, then return true
            if (s == t) return true;
        }
        // otherwise it is not possible to reorder to a power of 2
        return false;
    }
};