class MinHeap{
    int *arr;
    int size;
    int capacity;
    
    public:
    
    MinHeap(int c){
    size = 0; 
    capacity = c; 
    arr = new int[c];
    }

    int left(int i) { return (2*i + 1); } 
    int right(int i) { return (2*i + 2); } 
    int parent(int i) { return (i-1)/2; } 
    
    void insert(int x) 
    { 
    if (size == capacity)return;
    size++; 
    arr[size-1]=x; 
 
    for (int i=size-1;i!=0 && arr[parent(i)]>arr[i];) 
    { 
       swap(arr[i], arr[parent(i)]); 
       i = parent(i); 
    } 
    }
    
    void minHeapify(int i) 
    { 
    int lt = left(i); 
    int rt = right(i); 
    int smallest = i; 
    if (lt < size && arr[lt] < arr[i]) 
        smallest = lt; 
    if (rt < size && arr[rt] < arr[smallest]) 
        smallest = rt; 
    if (smallest != i) 
    { 
        swap(arr[i],arr[smallest]); 
        minHeapify(smallest); 
    } 
    }
    
    int extractMin() 
    { 
    if (size <= 0) 
        return INT_MAX; 
    if (size == 1) 
    { 
        size--; 
        return arr[0]; 
    }  
    swap(arr[0],arr[size-1]);
    size--; 
    minHeapify(0); 
  
    return arr[size]; 
    } 

    void decreaseKey(int i, int x) 
    { 
    arr[i] = x; 
    while (i != 0 && arr[parent(i)] > arr[i]) 
    { 
       swap(arr[i], arr[parent(i)]); 
       i = parent(i); 
    } 
    }
    
    void deleteKey(int i) 
    { 
        decreaseKey(i, INT_MIN); 
        extractMin(); 
    }

    void buildHeap(){
        for(int i=(size-2)/2;i>=0;i--)
            minHeapify(i);
    }
};

//sort a k sorted array
int sortK(int arr[], int n, int k) 
{
    priority_queue<int,vector<int>,greater<int>> pq(arr,arr+k+1);
     

    for(int i{};i<n;i++)
    {
       arr[i]=pq.top();
       pq.pop();
       if(i+k+1<n)
       pq.push(arr[i+k+1]);
    }

}

// k largest elements
void firstKElements(int arr[], int n, int k)
{
	
	priority_queue <int,vector<int>,greater<int>> minHeap;
	for(int i = 0; i < k; i++)
	{
		minHeap.push(arr[i]);
	}
	for(int i = k; i < n; i++)
	{
		if (minHeap.top() > arr[i])
			continue;
		else
		{
			minHeap.pop();
			minHeap.push(arr[i]);
		}
	}
	
	while(minHeap.empty()==false){
	    cout<<minHeap.top()<<" ";
	    minHeap.pop();
	}
}

//merge k sorted arrays

struct triplet{
    int val;
    int index;
    int vecNo;
   
   triplet(int v,int i,int vec)
   {
       val=v;
       index=i;
       vecNo=vec;
   }
};

struct myComp{
    bool operator()(triplet const &t1,triplet cont &t2)
    {
        return t1.val>t2.val;
    }
};

vector<int> mergeArr(vector<vector<int> > &arr) 
{     
      int k= arr.size();

      priority_queue<triplet,vector<triplet>,myComp> pq;
vector<int> ans{};
      for(int i{};i<k;i++)
      {
        Triplet temp(arr[i][0],0,i);
        pq.push(temp);
      }
       
      while(pq.empty()==false)
      {
          auto temp= pq.top();
          pq.pop();
          int val=temp.val;
          int index=temp.index;
          int vecNo=temp.vecNo;

          ans.push_back(val);
           if(index>=arr[vecNo].size()-1)
           {
             continue;
           }
          triplet t= new triplet(arr[vecNo][index+1],index+1,vecNo);
        
      }

      return ans;

}
// print medians from a stream of integers
void printMedians(int arr[],int n){
    priority_queue<int> s;
    priority_queue<int, vector<int>,greater<int>> g;
    s.push(arr[0]);
    cout<<arr[0]<<" ";
    for(int i=1;i<n;i++){
        int x=arr[i];
        if(s.size()>g.size())
        {
            if(s.top()>x){
                g.push(s.top());
                s.pop();
                s.push(x);
            }else g.push(x);
            cout<<(s.top()+g.top())/2.0<<" ";
        }else{
            if(x<=s.top()){
                s.push(x);
            }else{
                g.push(x);
                s.push(g.top());
                g.pop();
            }
            cout<<s.top()<<" ";
        }
    }
}

