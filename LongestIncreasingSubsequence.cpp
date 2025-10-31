#include <iostream>
#include <vector>
using namespace std;

int LIS(vector<int>& arr) {
    int n = arr.size();
    vector<int> dp(n, 1);
    int maxLen = 1;

    for (int i = 1; i < n; i++)
        for (int j = 0; j < i; j++)
            if (arr[i] > arr[j])
                dp[i] = max(dp[i], dp[j] + 1);

    for (int x : dp) maxLen = max(maxLen, x);
    return maxLen;
}

int main() {
    int n;
    cout << "📈 Longest Increasing Subsequence\nEnter array size: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << "✅ Length of LIS: " << LIS(arr) << endl;
}
