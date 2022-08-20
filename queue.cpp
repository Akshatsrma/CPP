
struct Myqueue{
    int * arr;
    int front;
    int size;
    int cap;

    Myqueue(int c)
    {
        arr= new int[c];
     front=0;
     size=0;
     cap=c;
    }

    void push(int x)
    {
        if(size==cap)
        {
            return;
        }
        else{
            int rear= (front+size-1)%cap;
            int index= (rear+1)%cap;
            arr[index]= x;
            
            size++;
        }
    }
    void pop()
    {
        if(size==0)
        {
            return;
        }
        else
        {
            front=(front+1)%cap;    
            size--;
        }
    }
    int front()
    {
        if(size==0)
        {
            return -1;
        }
        else{
            return arr[front];
        }
    }
    int back()
    {
        if(size==0)
        {
            return -1;
        }
        else{
            return arr[(front+size-1)%cap];
        }
    }
}
// implementation using linked list
struct QNode { 
	int data; 
	QNode* next; 
	QNode(int d) 
	{ 
		data = d; 
		next = NULL; 
	} 
}; 

struct Queue { 
	QNode *front, *rear; 
	Queue() 
	{ 
		front = rear = NULL; 
	} 

	void enQueue(int x) 
	{ 

		 
		QNode* temp = new QNode(x); 

		 
		if (rear == NULL) { 
			front = rear = temp; 
			return; 
		} 

		 
		rear->next = temp; 
		rear = temp; 
	} 

	 
	void deQueue() 
	{ 
		 
		if (front == NULL) 
			return; 

	 
		QNode* temp = front; 
		front = front->next; 

	
		if (front == NULL) 
			rear = NULL; 

		delete (temp); 
	} 
}; 

// generate binary numbers from 1->N;
vector<string> generate(int N)
{
	queue<string> q{};
	q.push("1");
	vector<string> ans{};
	for(int i{};i<N;i++)
	{
	    string temp= q.front();
	    q.pop();
	    ans.push_back(temp);
	    q.push(temp+'0');
	    q.push(temp+'1');
	}
	return ans;
}

// circular tour
int printTour(petrolPump arr[], int n)
{
    int start;
 
    for (int i = 0; i < n; i++) {
        // Identify the first petrol pump from where we
        // might get a full circular tour
        if (arr[i].petrol >= arr[i].distance) {
            start = i;
            break;
        }
    }
 
    // To store the excess petrol
    int curr_petrol = 0;
 
    int i;
 
    for (i = start; i < n;) {
 
        curr_petrol += (arr[i].petrol - arr[i].distance);
 
        // If at any point remaining petrol is less than 0,
        // it means that we cannot start our journey from
        // current start
        if (curr_petrol < 0) {
 
            // We move to the next petrol pump
            i++;
 
            // We try to identify the next petrol pump from
            // where we might get a full circular tour
            for (; i < n; i++) {
                if (arr[i].petrol >= arr[i].distance) {
 
                    start = i;
 
                    // Reset rem_petrol
                    curr_petrol = 0;
 
                    break;
                }
            }
        }
 
        else {
            // Move to the next petrolpump if curr_petrol is
            // >= 0
            i++;
        }
    }
 
    // If remaining petrol is less than 0 while we reach the
    // first petrol pump, it means no circular tour is
    // possible
    if (curr_petrol < 0) {
        return -1;
    }
 
    for (int j = 0; j < start; j++) {
 
        curr_petrol += (arr[j].petrol - arr[j].distance);
 
        // If remaining petrol is less than 0 at any point
        // before we reach initial start, it means no
        // circular tour is possible
        if (curr_petrol < 0) {
            return -1;
        }
    }
 
    // If we have successfully reached intial_start, it
    // means can get a circular tour from final_start, hence
    // return it
    return start;
}

// other method
int printTour(petrolPump p[], int n)
{
    // deficit is used to store the value of the capacity as
    // soon as the value of capacity becomes negative so as
    // not to traverse the array twice in order to get the
    // solution
    int start = 0, deficit = 0;
    int capacity = 0;
    for (int i = 0; i < n; i++) {
        capacity += p[i].petrol - p[i].distance;
        if (capacity < 0) {
            // If this particular step is not done then the
            // between steps would be redundant
            start = i + 1;
            deficit += capacity;
            capacity = 0;
        }
    }
    return (capacity + deficit >= 0) ? start : -1;
}
// other method
