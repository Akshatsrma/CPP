// perfect peak of element( all left are small and all on right are big)

int Solution::perfectPeak(vector<int> &v) {
int n = v.size();
    int pos_ind = -1; // the index where the given conditions are satisfied
    int i;
    int max_left = v.front();
    
    for (i = 1; i < n; i++) {
        if (pos_ind != -1) {
            if (v[i] <= v[pos_ind]) {
                pos_ind = -1;
            }
        } else {
            if (v[i] > max_left) {
                pos_ind = i;
            }
        }
        max_left = max(v[i], max_left);
    }
    return pos_ind != -1 && pos_ind != n - 1;
}

// first missing positive integer
int Solution::firstMissingPositive(vector<int> &A) {
    int n = A.size();
    for (int i = 0; i < n; i++) {
        if (A[i] > 0 && A[i] <= n) {
            int pos = A[i] - 1;
            if (A[pos] != A[i]) {
                swap(A[pos], A[i]);
                i--;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (A[i] != i + 1) return (i + 1);
    }
    return n + 1;
}

// min characters required to make a string palindromic(add at the start);// using lps 
vector<int> minChar(string pat)
{
    int M = pat.size();
    vector<int>lps(M);
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while(i<M)
    {
        if(pat[i]==pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else{
            if(len!=0)
            {
                len = lps[len-1];
            }
            else{
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}


int Solution::solve(string A) {
    string str = A;
    reverse(str.begin() , str.end());
    string canca = A + "$" + str;
    vector<int>lps = minChar(canca);
   
    return A.size() - lps.back();
}

// Given n and k, return the kth permutation sequence of 1-n;
int fact(int n)
{
    if(n>12)
        return INT_MAX;
    return (n==1 || n==0) ? 1: n * fact(n - 1);
}
string Solution::getPermutation(int N, int B) {
    
    vector<int> C;
    for(int i=1;i<=N;i++)
        C.push_back(i);
    
    string ans="";
    int block;
    for(int i=0;i<N;i++)
    {
        int p=fact(N-1-i);
        block=B/p;
        if(B%p==0)  
            block--;
        ans+=to_string(C[block]);
        C.erase(C.begin()+block);
        B=B-(block)*p;
    }
    return ans;
}
// subarrays with the given xor how many
int Solution::solve(vector<int> &A, int B) {
    unordered_map<int,long> m{};
    int count{};
    int xorr{};
    
    
    for(int i{};i<A.size();i++)
    {
       xorr= xorr^A[i];
       if(xorr==B) count++;
       
       if(m.find(xorr^B) != m.end()) {
count += m[xorr^B];
}
       
       m[xorr]++;
    }
   return count;
}
