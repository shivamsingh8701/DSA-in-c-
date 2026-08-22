class Solution {
public:
    void solve(vector<int>& arr, int idx, int target,
               vector<int>& comb, vector<vector<int>>& ans) {

        if (target == 0) {
            ans.push_back(comb);
            return;
        }

        if (idx == arr.size() || target < 0)
            return;

        // Take current element
        comb.push_back(arr[idx]);
        solve(arr, idx, target - arr[idx], comb, ans);
        comb.pop_back();

        // Skip current element
        solve(arr, idx + 1, target, comb, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> comb;

        solve(candidates, 0, target, comb, ans);

        return ans;
    }
};