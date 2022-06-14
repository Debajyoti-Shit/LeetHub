class Solution{
public:
    vector<vector<int> >dp;
    int minDistance(string& word1, string& word2) {
	    // dp[i][j] will denote minimum steps required to equalize word1[i:end] and word[2:j:end]
	    dp.resize(size(word1) + 1, vector<int>(size(word2) + 1, 1000));
	    return solve(word1, word2, 0, 0);
    }
    int solve(string &w1, string &w2, int i, int j) {
	    if(i == size(w1) && j == size(w2)) return 0;
	    if(i == size(w1) || j == size(w2)) return max(size(w1) - i, size(w2) - j);
	    if(dp[i][j] != 1000) return dp[i][j];  // directly return stored answer if already computed before
	    if(w1[i] == w2[j]) return solve(w1, w2, i + 1, j + 1);
	    return dp[i][j] = 1 + min(solve(w1, w2, i + 1, j), solve(w1, w2, i, j + 1));
    }
};




// class Solution {
// public:
//     int minDistance(string& word1, string& word2) {
// 	    return solve(word1, word2, 0, 0);
//     }
//     // recursive solver to find minimum deletions to equalize w1 & w2
//     int solve(string w1, string w2, int i, int j) {
// 	    if(i == size(w1) && j == size(w2)) return 0;  // reached end of both strings -> both strings have been equalized and no further steps required
// 	    if(i == size(w1)) return size(w2) - j;        // reached end of word1 -> need to delete remaining characters of word2 to equalize
//         if(j == size(w2)) return size(w1) - i;        // reached end of word2 -> need to delete remaining characters of word1 to equalize
// 	    if(w1[i] == w2[j]) return solve(w1, w2, i + 1, j + 1);  // no deletion required since the characters already match
// 	// 1 current character deletion + min(after deleting w1[i], after deleting w2[j])
// 	    return 1 + min(solve(w1, w2, i + 1, j), solve(w1, w2, i, j + 1));
//     }
// };