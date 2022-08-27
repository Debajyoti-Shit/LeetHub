class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        int res = INT_MIN;
        vector<int> row_sum(m, 0);
        for (int l = 0; l < n; ++l)
        {
            fill(row_sum.begin(), row_sum.end(), 0);
            for (int r = l; r < n; ++r)
            {
                // Kadane algorithm for a possible shortcut to next iteration or even an early return
                int cur_sum = 0, best_sum = INT_MIN;
                for (int i = 0; i < m; ++i)
                {
                    row_sum[i] += matrix[i][r];
                    if (cur_sum < 0)
                        cur_sum = row_sum[i];
                    else
                        cur_sum += row_sum[i];
                    best_sum = max(best_sum, cur_sum);
                }
                if (best_sum == k)
                    return k;
                else if (best_sum < k)
                {
                    res = max(res, best_sum);
                    continue;
                }
                // Otherwise, try binary search of running sums
                cur_sum = 0;
                set<int> s{0};
                for (auto& sum: row_sum)
                {
                    cur_sum += sum;
                    auto it = s.lower_bound(cur_sum - k);
                    if (it != s.end())
                        res = max(res, cur_sum - *it);
                    if (res == k)
                        return k;
                    s.insert(cur_sum);
                }
            }
        }
        return res;
    }
};