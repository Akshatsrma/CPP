sort(arr, arr + n); // array

sort(arr, arr + n, greater<int>()) // for decreasing sort;

    sort(v.begin(), v.end()); // vector

sort(v.begin(), v.end(), greater<int>());

// object
struct point
{
    int x, y;
};
bool MyComp(point p1, point p2)
{
    return p1.x < p2.x;
}

// bubble sort

void bubbleSort(int arr[], int n)
{

    bool flag = false;
    for (int i{}; i < n; i++)
    {
        for (int j{0}; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                flag = true;
            }
        }
        if (flag == false)
        {
            break;
        }
    }
}

// selection sort

void selectionSort(int arr[], int n)
{

    for (int i{}; i < n; i++)
    {
        int min{i};
        for (int j{i + 1}; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        swap(arr[i], arr[min]);
    }
}

// insertation sort

void iSort(int arr[], int n)
{

    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// merge sort

void merge(int arr[], int l, int m, int h)
{

    int n1 = m - l + 1, n2 = h - m;
    int left[n1], right[n2];
    for (int i = 0; i < n1; i++)
        left[i] = arr[i + l];
    for (int j = 0; j < n2; j++)
        right[j] = arr[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
            arr[k++] = left[i++];
        else
            arr[k++] = right[j++];
    }
    while (i < n1)
        arr[k++] = left[i++];
    while (j < n2)
        arr[k++] = right[j++];
}

void mergeSort(int arr[], int l, int r)
{
    if (r > l)
        int mid = l + (r - l) / 2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);
    merge(arr, l, mid, h)
}

// count inversions in array

int countAndMerge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1, n2 = r - m;
    int left[n1], right[n2];
    for (int i = 0; i < n1; i++)
        left[i] = arr[i + l];
    for (int j = 0; j < n2; j++)
        right[j] = arr[m + 1 + j];
    int res = 0, i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
        {
            arr[k++] = left[i++];
        }
        else
        {
            arr[k++] = right[j++];
            res = res + (n1 - i);
        }
    }
    while (i < n1)
        arr[k++] = left[i++];
    while (j < n2)
        arr[k++] = right[j++];
    return res;
}

int countInv(int arr[], int l, int r)
{
    int res = 0;
    if (l < r)
    {

        int m = (r + l) / 2;

        res += countInv(arr, l, m);
        res += countInv(arr, m + 1, r);
        res += countAndMerge(arr, l, m, r);
    }
    return res;
}
// lomuto partition (default last element as the pivot);
int iPartition(int arr[], int l, int h)
{
    int pivot = arr[h];
    int index{-1};
    for (int j{l}; j <= h - 1; j++)
    {
        if (arr[j] < pivot)
        {
            index++;
            swap(arr[index], arr[j]);
        }
    }
    swap(arr[index + 1], arr[h]);
    return index + 1;
}

// hoare partittion

int partition(int arr[], int l, int h)
{
    int pivot = arr[l];
    int i = l - 1, j = h + 1;
    while (true)
    {
        do
        {
            i++;
        } while (arr[i] < pivot);
        do
        {
            j--;
        } while (arr[j] > pivot);
        if (i >= j)
            return j;
        swap(arr[i], arr[j]);
    }
}
// quick sort
// using lomuto partition
void qSort(int arr[], int l, int h)
{
    if (l < h)
    {
        int p = iPartition(arr, l, h);
        qSort(arr, l, p - 1);
        qSort(arr, p + 1, h);
    }
}

// using hoares partition

void qSort(int arr[], int l, int h)
{
    if (l < h)
    {
        int p = partition(arr, l, h);
        qSort(arr, l, p);
        qSort(arr, p + 1, h);
    }
}

// you can do tail call elemination in quick sort algo by doing reccursion for the part with less elements and the other part you goto begin: (where begin is the function itself)

// kth smallest element in an unsorted array
int kthSmallest(int arr[], int n, int k)
{

    int h = n - 1;
    int l = 0;
    while (l <= h)
    {
        int p = iPartition(arr, l, h) if (p == k - 1)
        {
            return arr[p];
        }
        else if (p > k - 1)
        {
            h = p - 1;
        }
        else
        {
            l = p + 1;
        }
    }
    return -1;
}

// sort an array with 3 types of elements
void sort3(int arr[], int n)
{
    int l = 0, h = n - 1, mid = 0;
    while (mid <= h)
    {
        switch (arr[mid])
        {
        case 0:
            swap(arr[l], arr[mid]);
            l++;
            mid++;
            break;
        case 1:
            mid++;
            break;
        case 2:
            swap(arr[h], arr[mid]);
            h--;
            break;
        }
    }
}

// merge ovelapping intervals

bool mycomp(Interval a, Interval b)
{
    return a.s < b.s;
}

void mergeIntervals(Interval arr[], int n)
{
    sort(arr, arr + n, mycomp);

    int res = 0;

    for (int i = 1; i < n; i++)
    {
        if (arr[res].e >= arr[i].s)
        {
            arr[res].e = max(arr[res].e, arr[i].e);
            arr[res].s = min(arr[res].s, arr[i].s);
        }
        else
        {
            res++;
            arr[res] = arr[i];
        }
    }

    for (int i = 0; i <= res; i++)
        cout << "[" << arr[i].s << ", " << arr[i].e << "] ";
}

// cycle  sort
void cycleSortDistinct(int arr[], int n)
{
    for (int cs = 0; cs < n - 1; cs++)
    {
        int item = arr[cs];
        int pos = cs;
        for (int i = cs + 1; i < n; i++)
            if (arr[i] < item)
                pos++;
        swap(item, arr[pos]);
        while (pos != cs)
        {
            pos = cs;
            for (int i = cs + 1; i < n; i++)
                if (arr[i] < item)
                    pos++;
            swap(item, arr[pos]);
        }
    }
}

// heap sort

void buildHeap(int arr[], int n)
{
    for (int i = (n - 2) / 2; i >= 0; i--)
    {
        maxHeapify(arr, n, i);
    }
}

void maxHeapify(int arr, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (right < n && arr[right] > arr[larget])
    {
        largest = right;
    }
    if (left < n && arr[left] > arr[larget])
    {
        largest = left;
    }

    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        maxHeapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    buildHeap(arr, n);

    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// counting sort

void countSort(int arr[], int n, int k)
{
    int count[k];
    for (int i{}; i < k; i++)
        count[i] = 0;

    for (int i{}; i < n; i++)
        count[arr[i]]++;

    int output[n];

    for (int i{1}; i < k; i++)
        count[i] = count[i - 1] + count[i];

    for (int i{n - 1}; i >= 0; i--)
    {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

// radix sort

void countingSort(int arr[], int n, int exp)
{
    int output[n];
    int count[10] = {0};
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixsort(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];

    for (int exp = 1; mx / exp > 0; exp *= 10)
        countingSort(arr, n, exp);
}

// bucket sort
void bucketSort(int arr[], int n, int k)
{
    int max_val = arr[0];
    for (int i = 1; i < n; i++)
        max_val = max(max_val, arr[i]);

    max_val++;
    vector<int> bkt[k];

    for (int i = 0; i < n; i++)
    {
        int bi = (k * arr[i]) / max_val;
        bkt[bi].push_back(arr[i]);
    }

    for (int i = 0; i < k; i++)
        sort(bkt[i].begin(), bkt[i].end());

    int index = 0;
    for (int i = 0; i < k; i++)
        for (int j = 0; j < bkt[i].size(); j++)
            arr[index++] = bkt[i][j];
}
