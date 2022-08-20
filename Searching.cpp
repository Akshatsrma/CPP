// binary search iterative
int bSearch(int arr[], int n, int x)
{

    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (x > arr[mid])
        {
            low = mid + 1;
        }
        else if (x < arr[mid])
        {
            high = mid - 1;
        }
        else
            return mid;
    }
    return -1;
}
// binary search recursive
int bSearch(int arr[], int low, int high, int x)
{

    int mid = (high + low) / 2;

    if (arr[mid] == x)
    {
        return mid;
    }
    else if (arr[mid] > x)
    {
        return bSearch(arr, low, mid - 1, x)
    }
    else
        return bSearch(arr, mid + 1, high, x);
}

// square root of number using binary search

int sqRootFloor(int x)
{
    int low = 1, high = x, ans = -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        int mSq = mid * mid;

        if (mSq == x)
            return mid;
        else if (mSq > x)
            high = mid - 1;
        else
        {
            low = mid + 1;
            ans = mid;
        }
    }

    return ans;
}
// search in a rotated array

int search(int arr[], int n, int x)
{

    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == x)
        {
            return mid;
        }

        if (arr[low] < arr[mid])
        {
            if (x >= arr[low] && x < arr[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        else
        {
            if (x > arr[mid] && x <= arr[high])
            {
                low = mid + 1
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    return -1;
}
// peak element
int getPeak(int arr[], int n)
{
    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if ((mid == 0 || arr[mid - 1] <= arr[mid]) &&
            (mid == n - 1 || arr[mid + 1] <= arr[mid]))
            return mid;
        if (mid > 0 && arr[mid - 1] >= arr[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

// two pointer approach

// finding a pair with sum equal to x in a sorterd array
bool isPresent(int arr[], int n, int sum)
{
    int l = 0, h = n - 1;
    int mid;
    while (l <= h)
    {
        if (arr[l] + arr[h] == sum)
            return true;
        else if (arr[l] + arr[h] > sum)
            h--;
        else
            l++;
    }
    return false;
}

// finding a triplet with sum equal to x in a sorterd array
// same approach as pair

void triplet(int arr[], int n, int sum)
{

    for (int i{}; i < n; i++)
    {
        int temp = sum - arr[i];
        isPresent(arr, n, temp) // pass i+1 as the low and n as the high to the pair finding function
    }
}
// get median of 2 sorted arrays
double getMed(int a1[], int a2[], int n1, int n2)
{
    int begin = 0;
    int end = n1 - 1;
    while (begin < end)
    {
        int i1 = (begin + end) / 2;

        int i2 = (n1 + n2 + 1) / 2 - i1;

        int max1 = i1 == 0 ? INT_MIN : a1[i1 - 1];
        int min1 = i1 == n1 ? INT_MAX : a1[i1];

        int min2 = (i2 == n2) ? INT_MAX : a2[i2]
        int max2 = (i2 == 0) ? INT_MIN : a2[i2 - 1];

        if (max1 <= min2 && max2 <= min1)
        {
            if ((n1 + n2) % 2 == 0)
                return ((double)max(max1, max2) + min(min1, min2)) / 2;
            else
                return ((double)max(max1, max2));
        }
        else if (max1 > min2)
        {
            end = i1 - 1;
        }
        else
        {
            begin = i1 + 1;
        }
    }
}

// slow fast method
int repeat(int arr[], int n)
{
    int slow = arr[0], fast = arr[0];

    do
    {
        slow = arr[slow];
        fast = arr[arr[fast]];

    } while (slow != fast);

    slow = arr[0];

    while (slow != fast)
    {
        slow = arr[slow];
        fast = arr[fast];
    }
    return slow;
}

// page allocation binary search
bool isFeasible(int arr[], int n, int k, int ans)
{
    int req = 1, sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (sum + arr[i] > ans)
        {
            req++;
            sum = arr[i];
        }
        else
        {
            sum += arr[i];
        }
    }
    return (req <= k);
}
int minPages(int arr[], int n, int k)
{

    int mx{INT_MIN};
    int sum{};
    for (int i{}; i < n; i++)
    {
        if (arr[i] > mx)
        {
            mx = arr[i];
        }
        sum += arr[i];
    }

    int low = mx;
    int high = sum;
    int sol{high};
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (isFeasible(arr, n, k, mid))
        {
            sol = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return res;
}
