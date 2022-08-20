struct MyHash
{
    int *arr;
    int cap,size;
    
    MyHash(int c)
    {
        cap=c;
        size=0;
        arr=new int[cap];
        for(int i=0;i<cap;i++)
            arr[i]=-1;
    }
    
    int hash(int key){
        return key%cap;
    }
    bool insert(int key)
    {
        if(size==cap)
            return false;
        int i=hash(key);
        while(arr[i]!=-1 && arr[i]!=-2 && arr[i]!=key)
            i=(i+1)%cap;
        if(arr[i]==key)
            return false;
        else{
            arr[i]=key;
            size++;
            return true;
        }
    }
    bool search(int key)
    {
        int h=hash(key);
        int i=h;
        while(arr[i]!=-1){
            if(arr[i]==key)
                return true;
            i=(i+1)%cap;
            if(i==h)
                return false;
        }
        return false;
    }
    bool erase(int key)
    {   
        int h=hash(key);
        int i=h;
        while(arr[i]!=-1){
            if(arr[i]==key){
                arr[i]=-2;
                return true;
            }
            i=(i+1)%cap;
            if(i==h)
                return false;
        }
        return false;
    }
};

// unordered set<int> s;
int main(){
    
    unordered_set <int> s;
    s.insert(10);
    s.insert(5);
    s.insert(15);
    s.insert(20);
    for(int x: s)
        cout<<x<<" ";
        
    cout<<endl;
    for(auto it=s.begin();it!=s.end();it++)
        cout<<*it<<" ";
    cout<<endl;
    cout<<s.size()<<endl;
    s.clear();
    cout<<s.size()<<endl;
    
    s.insert(10);
    s.insert(5);
    s.insert(15);
    s.insert(20);
    cout<<s.size()<<endl;
    
    if(s.find(15)==s.end())
        cout<<"Not Found";
    else
        cout<<"Found "<<(*s.find(15));
    
    cout<<endl;   
    if(s.count(15))
        cout<<"Found";
    else
        cout<<"Not Found";
    cout<<endl;
    
    cout<<s.size()<<endl;
    s.erase(15);
    cout<<s.size()<<endl;
    auto it=s.find(10);
    s.erase(it);
    cout<<s.size()<<endl;
    
    s.erase(s.begin(),s.end());
        
    return 0;
}
// output -
// 20 15 10 5 
// 20 15 10 5 
// 4
// 0
// 4
// Found 15
// Found
// 4
// 3
// 2


// hash map 
int main(){
    
    unordered_map <string,int> m;
    m["gfg"]=20;
    m["ide"]=30;
    m.insert({"courses",15});
    
    if(m.find("ide")!=m.end())
        cout<<"Found";
    else
        cout<<"Not Found ";
    
    cout<<endl;
    
    for(auto it=m.begin();it!=m.end();it++)
        cout<<(it->first)<<" "<<(it->second)<<endl;
    
    if(m.count("ide")>0)
        cout<<"Found";
    else
        cout<<"Not Found";
    cout<<endl;
    
    cout<<m.size()<<endl;
    m.erase("ide");
    m.erase(m.begin());
    cout<<m.size()<<endl;
    m.erase(m.begin(),m.end());
        
    return 0;
}
// output-
//  Found
// courses 15
// gfg 20
// ide 30
// Found
// 3
// 1


//
void countFreq(int arr[], int n)
{
    unordered_map<int,int> map{};

    for(int i{};i<n;i++)
    {
        map[arr[i]]++;
    }

    for(auto x:map)
    {
        cout<<x.first<<" -"<<x.second<<endl;
    }
}

bool intersection(int arr[], int n,int sum)
{
 unordered_set<int> s{};
 s.insert(0);
 int sum{};
   for(int i{};i<n;i++)
   {
       sum+=arr[i];
       if(s.count(sum))
       {
           return true;
       }
       s.insert(sum);
   }
}

int largestZeroSubarray(int arr[], int n)
{
    unordered_map<int,int> mp{};

    int pre_sum{};
 
    for(int i{};i<n;i++)
    {
       arr[i]= (arr[i]==1)? 1:-1;
    }
int res{};
    for(int i{};i<n;i++)
    {
        pre_sum+=arr[i];
       if(pre_sum==0)
       {
           res=i+1;
       }
       if(mp.count(pre_sum)==mp.end())
       {
           mp.insert({pre_sum,i});
       }
        if(mp.count(pre_sum))
        {
            res=max(res,i-mp[pre_sum])
        }
        
    }
    return res;
}

// largest common subarray with the same sum in binary array

// same problem just take a difference array and find the longest subarray with sum zero.



// more than n/k occurences (o(nk)) solution using moorays method and hashing
void printNByK(int arr[], int n, int k)
{

   unordered_map<int,int> mp{};

   for(int i{};i<n;i++)
   {
       if(mp.count(arr[i]))
       {
           mp[arr[i]]++;
       }
       else if(mp.size()<k-1)
       {
           mp[arr[i]]=1;
       }
       else{
           for(auto x:mp)
           {
               x.second--;
               if(x.second==0)
               {
                   mp.erase(x.first);
               }
           }
       }
   }
   for(auto x:mp){
        int count=0;
        for(int i=0;i<n;i++){
            if(x.first==arr[i])
                count++;
        
       }
        if(count>n/k)
            cout<<x.first<<" ";
    }

}
