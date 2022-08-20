// applications for greedy
//  activity selection
//  fractional knapsack
//  Job sequencing
//  prims algo
//  kruskals algo
//  dijstras algo
//  huffman coding

// activity selection
bool myCmp(pair<int, int> a, pair<int, int> b)
{
    return (a.second < b.second);
}

int maxActivities(pair<int, int> arr[], int n)
{
    sort(arr, arr + n, myCmp);

    int prev = 0;
    int res = 1;

    for (int curr = 1; curr < n; curr++)
    {

        if (arr[curr].first >= arr[prev].second)
        {
            res++;

            prev = curr;
        }
    }

    return res;
}

// fractional knapsack
bool mycomp(pair<int, int> a, pair<int, int> b)
{
    return ((static_cast<double>(a.second) / a.first) > (static_cast<double>(b.second) / b.first));
}
void fractionalKnapsack(vector<pair<int, int>> vec, int weight)
{
    sort(vec.begin(), vec.end(), mycomp);
    double res{};
    for (int i{}; i < vec.size() && weight != 0; i++)
    {
        if (arr[i].first < weight)
        {
            weight = weight - arr[i].first;
            res += arr[i].second;
        }
        else
        {
            res += arr[i].second * ((double)weight / arr[i].first);
            weight = 0;
        }
    }
    return res;
}

// job sequencing problem
bool mycomp(Job a, Job b)
{
    return a.profit > b.profit;
}
class Solution
{
public:
    vector<int> JobScheduling(Job vec[], int n)
    {
        sort(vec, vec + n, mycomp);
        vector<int> time(n, -1);
        int profit{};
        int jobs{};
        for (int i{}; i < n; i++)
        {
            int curr = vec[i].dead - 1;
            while (curr >= 0 && time[curr] != -1)
            {
                curr--;
            }
            if (curr < 0)
            {
                continue;
            }
            time[curr] = 1;
            profit += vec[i].profit;
            jobs++;
        }
        vector<int> temp{};
        temp.push_back(jobs);
        temp.push_back(profit);
        return temp;
    }
};

// huffman coding

void traverse(Node *head, string s ='')
{

    if (head->val != '$')
    {
        cout << head->val << " ->" << s << endl;
        return;
    }

    traverse(head->left, s + "0");
    traverse(head->right, s + "1");
}

struct mycomp
{
    boool operator()(Node *a, Node *b)
    {
        return a->freq < b->freq;
    }
} Node *buildHuffmantree(vector<char> val, vector<int> freq)
{

    priority_queue<Node *, vector<Node *>, mycomp> pq{};

    for (int i{}; i < val.size(); i++)
    {
        Node *temp = new Node(val[i], freq[i]);
        pq.push(temp);
    }

    while (pq.size() != 1)
    {
        Node *a = pq.top();
        pq.pop();
        Node *b = pq.top();
        pq.pop();

        Node *head = new Node('$', a->freq + b->freq);
        head->left = a;
        head->right = b;
        pq.push(head);
    }

    Node *head = pq.top();
    pq.pop();
    return head;
}
void printhuffman(vector<char> val, vector<int> freq)
{
    Node *head = buildHuffmantree(val, freq);

    traverse(head);
}
