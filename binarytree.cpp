// insert
Node* insert(Node* root,int x)
{
    if(root==nullptr)
    {
        return new Node(x);
    }

    if(x<root->key)
    {
       root->left=insert(root->left,x);
    }
    if(x>root->key)
    {
       root->right=insert(root->right,x);
    }
    return root;
}
//iterative 
Node *insert(Node *root, int x){
    Node *temp=new Node(x);
    Node *parent=NULL,*curr=root;
    while(curr!=NULL){
        parent=curr;
        if(curr->key>x)
            curr=curr->left;
        else if(curr->key<x)
            curr=curr->right;
        else
            return root;
    }
    if(parent==NULL)
        return temp;
    if(parent->key>x)
        parent->left=temp;
    else
        parent->right=temp;
    return root;
} 

// delete from bst

Node* findSuccessor(Node* root)
{
 root=root->right;

 while(root!=nullptr && root->left!=nullptr)
 {
   root=root->left;
 }
}
Node *delNode(Node *root, int x)
{
    if(root==nullptr)
    {
        return root;
    }
    
     if(root->key==x)
     {if(root->left==NULL){
            Node *temp=root->right;
            delete root;
            return temp;
        }
        else if(root->right==NULL){
            Node *temp=root->left;
            delete root;
            return temp;
        }
        else{
                  Node* succ=findSuccessor(root);
                  root->key=succ->key;
                  root->right=delNode(root->right,succ->key);
                 
        }
     }
     else if(root->key<x)
     {
        root->right=delNode(root->right,x);
     }
     else 
     root->left==delNode(root->left,x);


     return root;
}

//floor in Bst

Node *floor(Node *root, int x)
{
   Node* res{nullptr};

   while(root!=nullptr)
   {
    if(x>root->key)
    {
        res=root;
        root=root->right;
    }
    else if(x<root->key)
    {
        root=root->left;
    }
    else
    return root;
   }
return res;
}

//ceil in bst
Node *ceil(Node *root, int x)
{
    Node* res{};

    while(root!=nullptr)
    {
        if(x<root->key)
        {
            res=root;
            root=root->left;
        }
        else if(x>root->key)
        {
            root=root->right;
        }
        else return root;
    }
    return res;
}

// read map and set now

 // functionslike insert, erase,find,count,clear,begin(),end(),[] operator in map,empty(),size();

 // ceil on the left side in an array
 
void printCeiling(int arr[], int n){
    cout<<"-1"<<" ";
    set<int> s;
    s.insert(arr[0]);
    for(int i=1;i<n;i++){
        if(s.lower_bound(arr[i])!=s.end())
            cout<<*(s.lower_bound(arr[i]))<<" ";
        else
            cout<<"-1"<<" ";
        s.insert(arr[i]);
    }
}

// fix bst with 2 nodes swapped

Node* first{NULL};
Node* second{NULL};
Node* prev{NULL};
void fixBST(Node* root) {

    if(root==nullptr)
    {return ;}
   
      fixBST(root->left);
      
     
            if( prev!=nullptr && prev->key>root->key)
            {
               if(first==nullptr)
               {
                first=prev;
               }
                second=root;
            }
      

      prev=root;
      fixBst(root->right);
}

// sum of nodes in same vertical line
void vSumR(Node *root,int hd,map<int,int> &mp){
    if(root==NULL)return;
    vSumR(root->left,hd-1,mp);
    mp[hd]+=root->key;
    vSumR(root->right,hd+1,mp);
}    

// print vertical elements(vertical traversal)
void vTraversal(Node *root){
   map<int,vector<int>> m{};
   queue<pair<Node*,int>> q{}; 
   q.insert({root,0});

   while(q.empty()==false)
   {
    auto x= q.front();
    q.pop();
    int vl= x.second;
    Node* temp= x.first;
      
     m[vl].push_back(temp.key);
     if(temp->left!=NULL)
            q.push({temp->left,vl-1});
        if(temp->right!=NULL)
            q.push({temp->right,vl+1});
   }

   for(auto x:m){
        for(int y:x.second)
            cout<<y<<" ";
        cout<<endl;
    }
}

// top view and bottom view are similar to the above 







