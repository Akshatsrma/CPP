// dynamic programming is the method in which we use small solutions of trivial problems to construct the main solution of the big problem

// memoization (top down)
int memo[1000000];
int fib(int n)
{
    if (memo[n] == -1)
    {
        int res;

        if (n == 0 || n == 1)
            return n;
        else
        {
            res = fib(n - 1) + fib(n - 2);
        }
        memo[n] = res;
    }
    return memo[n];
}

// tabulation (bottom up)

int fib(int n)
{
    int f[n + 1];

    f[0] = 0;
    f[1] = 1;
    for (int i{2}; i <= n; i++)
    {
        f[i] = f[i - 1] + f[i - 2];
    }
    return f[n];
}

// Longest common subsequences

// memoization
vector<vector<int>> arr(m + 1, vector<int>(n + 1, -1));
int lcs(string s1, string s2, int m, int n)
{
    if (arr[m][n] == -1)
    {
        if (m == 0 || n == 0)
        {
            arr[m][n] = 0;
        }
        if (s1[m - 1] == s2[n - 1])
        {
            arr[m][n] = 1 + lcs(s1, s2, m - 1, n - 1);
        }
        else
            arr[m][n] = max(lcs(s1, s2, m - 1, n), lcs(s1, s2, m, n - 1));
    }
    return arr[m][n];
}

// tabulation

int lcs(string s1, string s2, int m, int n)
{

    int dp[n + 1][m + 1];

    for (int i{}; i < n + 1; i++)
    {
        dp[i][0] = 0;
    }
    for (int i{}; i < m + 1; i++)
    {
        dp[0][i] = 0;
    }

    for (int i{1}; i < n + 1; i++)
    {
        for (int j{1}; j < m + 1; j++)
        {
            if (s1[i] == s2[j])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][m];
}

// coin change (count combinations)

// recursion

int coinchange(vector<int> coins, int sum, int n)
{
    if (sum == 0)
    {
        return 1;
    }
    if (n == 0)
    {
        return 0;
    }

    int res = coinchange(coins, sum, n - 1);
    if (coins[n - 1] <= sum)
    {
        res += coinchange(coins, sum - coins[n - 1], int n);
    }
    return res;
}

// bottom up table

int coinchange(vector<int> coins, int sum, int n)
{
    int dp[sum + 1][n + 1];

    for (int i{}; i <= sum; i++)
    {
        for (int j{}; j <= n; j++)
        {
            if (i == 0)
            {
                dp[i][j] = 1;
            }
            else if (i > 0 && j == 0)
            {
                dp[i][j] = 0;
            }
            else
            {
                dp[i][j] = dp[i][j - 1] + ((coins[j - 1] <= i) ? dp[i - coins[j - 1]][j] : 0);
            }
        }
    }
}
// optimized solution // think about it
int count(int S[], int m, int n)
{
    // table[i] will be storing the number of solutions for
    // value i. We need n+1 rows as the table is constructed
    // in bottom up manner using the base case (n = 0)
    int table[n + 1];
    // Initialize all table values as 0
    memset(table, 0, sizeof(table));
    // Base case (If given value is 0)
    table[0] = 1;
    // Pick all coins one by one and update the table[] values
    // after the index greater than or equal to the value of the
    // picked coin
    for (int i = 0; i < m; i++)
        for (int j = S[i]; j <= n; j++)
            table[j] += table[j - S[i]];
    return table[n];
}

//  edit distance porblem( convert one string to another with minimum number of operations)

int editdistance(string s1, string s2, int n, int m)
{
    if (n == 0)
        return m;
    if (m == 0)
        return n;

    if (s1[n - 1] == s2[m - 1])
    {
        return editdistance(s1, s2, n - 1, m - 1);
    }
    else
    {
        return 1 + min(editdistance(s1, s2, n - 1, m), editdistance(s1, s2, n - 1, m - 1), editdistance(s1, s2, n, m - 1));
    }
}

// tabulation

int editdistance(string s1, string s2, int n, int m)
{
    int dp[n + 1][m + 1];

    for (int i{}; i <= n; i++)
    {
        dp[i][0] = i;
    }
    for (int j{}; j <= m; j++)
    {
        dp[0][j] = j;
    }

    for (int i{1}; i <= n; i++)

    {
        for (int j{1}; j < n; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = 1 + min(dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]);
            }
        }
    }
}

// longest incerasing subsequence
int LIS(int arr[], int n)
{
    int lis[n];
    lis[0] = 1;
    for (int i = 1; i < n; i++)
    {
        lis[i] = 1;
        for (int j = 0; j < i; j++)
            if (arr[i] > arr[j])
                lis[i] = max(lis[i], lis[j] + 1);
    }
    int res = lis[0];
    for (int i = 0; i < n; i++)
    {
        res = max(lis[i], res);
    }
    return res;
}

// efficient method (tail array )
int ceilIdx(int tail[], int l, int r, int key)
{
    while (r > l)
    {
        int m = l + (r - l) / 2;
        if (tail[m] >= key)
            r = m;
        else
            l = m + 1;
    }

    return r;
}

int LIS(int arr[], int n)
{

    int tail[n];
    int len = 1;

    tail[0] = arr[0];

    for (int i = 1; i < n; i++)
    {

        if (arr[i] > tail[len - 1])
        {
            tail[len] = arr[i];
            len++;
        }
        else
        {
            int c = ceilIdx(tail, 0, len - 1, arr[i]);

            tail[c] = arr[i];
        }
    }

    return len;
}

// maximum cut problem

int maxcut(int n, int a, int b, int c)
{
    if (n < 0)
    {
        return -1;
    }
    if (n == 0)
    {
        return 0;
    }
    int temp = max(maxcut(n - a, a, b, c), maxcut(n - b, a, b, c), maxcut(n - c, a, b, c));

    return (temp == -1) ? temp : temp + 1;
}

// tabulation
bool mycomp(int a, int b)
{
    return a < b;
}
int maxcut(int n, int a, int b, int c)
{
    int dp[n + 1];

    dp[0] = 0;

    for (int i{1}; i <= n; i++)
    {

        int p = (i - a >= 0) ? dp[i - a] : -1;
        int q = (i - b >= 0) ? dp[i - b] : -1;
        int r = (i - c >= 0) ? dp[i - c] : -1;

        dp[i] = max({p, q, r}, mycomp);
        if (dp[i] != -1)
        {
            dp[i]++;
        }
    }
    return dp[n];
}

// minimum number of coins to make a value

int mincoins(int arr[], int val, int n)
{
    if (val == 0)
    {
        return 0;
    }

    int res{INT_MAX};

    for (int i{}; i < n; i++)
    {
        if (arr[i] <= val)
        {
            int sub_res = mincoins(arr, val - arr[i], n) if (sub_res != INT_MAX)
                res = min(res, sub_res + 1);
        }
    }
    return res;
}

// tabulation

int mincoins(int arr[], int val, int n)
{
    int dp[val + 1];
    dp[0] = 0;
    for (int i{1}; i < val + 1; i++)
    {
        int res{INT_MAX};
        for (int j{}; j < n; j++)
        {
            if (arr[j] <= i)
            {
                int sub_res = dp[i - arr[j]];
                if (sub_res != INT_MAX)
                {
                    res = min(res, sub_res + 1);
                }
            }
            dp[i] = res;
        }
    }
    return dp[val];
}

// min number of jumps to reach last cell
int minJumps(int arr[], int n)
{
    if (n == 1)
    {
        return 0;
    }
    int res{INT_MAX};
    for (int i{} : i < n - 1; i++)
    {
        if (arr[i] + i >= n - 1)
        {
            int sub_res = minJumps(arr, i + 1);
            if (sub_res != INT_MAX)
                res = min(res, 1 + sub_res);
        }
    }
    return res;
}

int minJumps(int arr[], int n)
{

    int dp[n];

    dp[0] == 0;

    for (int i{1}; i < n + 1; i++)
    {
        dp[i] = INT_MAX;
        for (int j{}; j < i; j++)
        {
            if (arr[j] + j >= i)
            {
                int temp = dp[j];
                if (temp != INT_MAX)
                {
                    dp[i] = min(dp[i], temp + 1);
                }
            }
        }
    }
    return dp[n - 1];
}

// 0-1 knapsack

int knapsack(int v[], int w[], int n, int weight)
{
    if (n == 0)
    {
        return 0;
    }
    if (weight == 0)
    {
        return 0;
    }
    int res = knapsack(v, w, n - 1, weight);

    if (w[n - 1] <= weight)
    {
        res = max(res, v[n - 1] + knapsack(v, w, n - 1, weight - w[n - 1]));
    }
    return res;
}
// tabulation
int knapsack(int v[], int w[], int n, int weight)
{
    int dp[weight + 1][n + 1];

    for (int i{}; i < weight + 1; i++)
    {
        for (int j{}; j < n + 1; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else
            {

                dp[i][j] = dp[i][j - 1];
                if (i >= w[j - 1])
                {
                    dp[i][j] = max(dp[i][j], v[j - 1] + dp[i - w[j - 1]][j - 1]);
                }
            }
        }
    }
    return dp[weight][n];
}

// optimal game

int game(int arr[], int j, int s, int total)
{
    if (s + 1 == j)
    {
        return max(arr[s], arr[j]);
    }
    return max(total - game(arr, j - 1, s, total - arr[j]), total - game(arr, j, s + 1, total - arr[s]));
}

// solution 2

int game(int arr[], int j, int s)
{

    return max(
        arr[s] + min(
                     game(arr, j, s + 2), game(arr, j - 1, s + 1)),
        arr[j] + min(
                     game(arr, j - 2, s), game(arr, j - 1, s + 1);))
}
// tabulation
int sol(int arr[], int n)
{
    int dp[n][n];

    for (int i = 0; i < n - 1; i++)
    {
        dp[i][i + 1] = max(arr[i], arr[i + 1]);
    }

    for (int gap = 3; gap < n; gap = gap + 2)
    {
        for (int i = 0; i + gap < n; i++)
        {
            int j = gap + i;

            dp[i][j] = max((arr[i] + min(dp[i + 1][j], dp[i + 1][j - 1])),
                           (arr[i] + min(dp[i + 1][j - 1], dp[i][j - 2])));
        }
    }

    return dp[0][n - 1];
}

// eggs and floor problem

int eggs(int e, int floors)
{
    if (floors == 1 || floors == 0)
    {
        return floors;
    }
    if (e == 1)
    {
        return f;
    }
    int res{INT_MAX};
    for (int i{1}; i <= floors; i++)
    {
        temp_res = max(eggs(e - 1, i - 1), eggs(e, floors - i));
        res = min(res, 1 + temp_res);
    }
    return res;
}

// tabulation
int res(int e, int f)
{

    int dp[f + 1][e + 1];

    for (int i = 1; i <= e; i++)
    {
        dp[1][i] = 1;
        dp[0][i] = 0;
    }

    for (int j = 1; j <= f; j++)
    {
        dp[j][1] = j;
    }

    for (int i = 2; i <= f; i++)
    {
        for (int j = 2; j <= e; j++)
        {
            dp[i][j] = INT_MAX;
            for (int x = 1; x <= i; x++)
            {
                dp[i][j] = min(dp[i][j], 1 + max(dp[x - 1][j - 1], dp[i - x][j]));
            }
        }
    }

    return dp[f][e];
}

// count bst's with n keys

int countBST(int n)
{
    if (n == 1 || n == 0)
    {
        return 1;
    }
    int res{};
    for (int i{0}; i < n; i++)
    {
        res += countBST(i) * count(n - i - 1);
    }
    return res{};
}
// tabulation

int countBST(int n)
{
    int dp[n + 1];

    dp[0] = d[1] = 1;

    for (int i = 2; i < n + 1; i++)
    {
        dp[i] = 0;

        for (int j{}; j < i; j++)
        {
            dp[i] += dp[j] * dp[i - j - 1];
        }
    }
    return dp[n];
}
// better solution ->
//   formula -> res(n)= 1/(n+1) * 2nCn

// maximum sum with no consicutives

int maximumsum(int arr[], int n)
{

    if (n == 1)
    {
        return arr[0];
    }
    if (n == 2)
    {
        return max(arr[0], arr[1]);
    }
    else
        return max(arr[n - 1] + maximumsum(arr, n - 2), maximumsum(arr, n - 1));
}

// tabulation
int maximumsum(int arr[], int n)
{
    if (n == 1)
    {
        return arr[0];
    }
    int dp[n + 1];

    dp[1] = arr[0];
    dp[2] = max(arr[0], arr[1]);

    for (int i{3}; i <= n; i++)
    {
        dp[i] = max(arr[i - 1] + dp[i - 2], dp[i - 1]);
    }
    return dp[n];
}
// efficient one->
int maxSum(int arr[], int n)
{
    if (n == 0)
        return arr[0];
    int prev_prev = arr[0];
    int prev = max(arr[0], arr[1]);
    int res = prev;
    for (int i = 3; i <= n; i++)
    {
        res = max(prev, prev_prev + arr[i - 1]);
        prev_prev = prev;
        prev = res;
    }
    return res;
}

// subset problem
int subset(int arr[], int n, int sum)
{
    if (n == 0)
    {
        if (sum == 0)
        {
            return 1;
        }
        return 0;
    }

    int res = subset(arr, n - 1, sum);

    if (sum >= arr[n - 1])
    {
        res += subset(arr, n - 1, sum - arr[n - 1]);
    }

    return res;
}

// tabulation

int subset(int arr[], int n, int sum)
{
    int dp[sum + 1][n + 1];

    for (int i{}; i < sum + 1; i++)
    {
        dp[i][0] = 0;
    }
    for (int i{}; i < n + 1; i++)
    {
        dp[0][i] = 1;
    }

    for (int i{1}; i < sum + 1; i++)
    {
        for (int j{1}; j < n + 1; j++)
        {
            dp[i][j] = dp[i][j - 1];
            if (i >= arr[j - 1])
            {
                dp[i][j] += dp[i - arr[j - 1]][j - 1];
            }
        }
    }

    return dp[sum][n];
}

//  matrix chain multiplications

int matrix(int arr[], int e, int s = 0)
{
    if (e == s + 1)
    {
        return 0;
    }

    int res{INT_MAX};
    for (int i{s + 1}; i < e; i++)
    {
        int temp_res{};
        int temp1 = matrix(arr, i, s);
        int temp2 = matrix(arr, e, i);

        temp_res += temp1 + temp2 + arr[s] * arr[i] * arr[e];
        res = min(res, temp_res);
    }
    return res;
}

int mChain(int p[], int n)
{

    int dp[n][n];
    for (int i = 0; i < n - 1; i++)
        dp[i][i + 1] = 0;

    for (int gap = 2; gap < n; gap++)
    {
        for (int i = 0; i + gap < n; i++)
        {
            int j = i + gap;
            dp[i][j] = INT_MAX;
            for (int k = i + 1; k < j; k++)
            {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + p[i] * p[k] * p[j]);
            }
        }
    }

    return dp[0][n - 1];
}

// minimum cuts to make string palindrome
// my sol
bool ispalindrome(string str, int s, int e)
{
    if (s == e)
        return true;
    for (int i = s; i <= e; i++, e--)
    {
        if (str[i] != str[e])
        {
            return false;
        }
    }
    return true;
}

int cuts(string str, int s, int e)
{
    if (ispalindrome(str, s, e))
    {
        return 0;
    }

    int res{INT_MAX};
    for (int i{s}; i < e; i++)
    {
        int temp_res{};
        if (ispalindrome(str, s, i))
        {
            temp_res = 1 + cuts(str, i + 1, e);
        }
        res = min(res, temp_res);
    }
    return res;
}

// gfg sol
bool isPalindrome(string input, int start, int end)
{

    while (start < end)
    {
        if (input[start] != input[end])
            return false;
        start++;
        end--;
    }
    return true;
}

int palPart(string str)
{
    int n = str.length();

    int dp[n][n];

    for (int i = 0; i < n; i++)
    {
        dp[i][i] = 0;
    }

    for (int gap = 1; gap < n; gap++)
    {
        for (int i = 0; i + gap < n; i++)
        {
            int j = i + gap;

            if (isPalindrome(str, i, j))
            {
                dp[i][j] = 0;
            }
            else
            {
                dp[i][j] = INT_MAX;

                for (int k = i; k < j; k++)
                {
                    dp[i][j] = min(dp[i][j], 1 + dp[i][k] + dp[k + 1][j]); // here he has taken all the cuts possible one by one and calculated the minimum.
                }
            }
        }
    }

    return dp[0][n - 1];
}

// allocate book pages

int sum(int arr[], int b, int e)
{
    int s = 0;
    for (int i = b; i <= e; i++)
        s += arr[i];
    return s;
}

int minPages(int arr[], int n, int k)
{
    if (k == 1)
        return sum(arr, 0, n - 1);
    if (n == 1)
        return arr[0];
    int res = INT_MAX;
    for (int i = 1; i < n; i++)
    {
        res = min(res, max(minPages(arr, i, k - 1), sum(arr, i, n - 1)));
    }
    return res;
}

// tabulation
int minPages(int arr[], int n, int k)
{
    int dp[k + 1][n + 1];
    for (int i = 1; i <= n; i++)
        dp[1][i] = sum(arr, 0, i - 1);
    for (int i = 1; i <= k; i++)
        dp[i][1] = arr[0];

    for (int i = 2; i <= k; i++)
    {
        for (int j = 2; j <= n; j++)
        {
            int res = INT_MAX;
            for (int p = 1; p < j; p++)
            {
                res = min(res, max(dp[i - 1][p], sum(arr, p, j - 1)));
            }
            dp[i][j] = res;
        }
    }
    return dp[k][n];
}
