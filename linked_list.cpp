
// pair wise swap
Node *pairwiseSwap(Node *head){
    if(head==NULL||head->next==NULL)
        return head;
    Node *curr=head->next->next;
    Node *prev=head;
    head=head->next;
    head->next=prev;
    while(curr!=NULL&&curr->next!=NULL){
        prev->next=curr->next;
        prev=curr;
        Node *next=curr->next->next;
        curr->next->next=curr;
        curr=next;
    }
    prev->next=curr;
    return head;
}


// LRU CACHE
class Node { 
    public:
	int key; 
	int value; 
	Node *pre; 
	Node *next; 

	
	Node(int k, int v) 
	{ 
		key = k; 
		value = v;
		pre=NULL;next=NULL;
	} 
}; 

class LRUCache {
    public:
	unordered_map<int, Node*> map; 
	int capacity, count; 
	Node *head, *tail; 

	
	LRUCache(int c) 
	{ 
		capacity = c; 
		head = new Node(0, 0); 
		tail = new Node(0, 0); 
		head->next = tail; 
		tail->pre = head; 
		head->pre = NULL; 
		tail->next = NULL; 
		count = 0; 
	} 

	void deleteNode(Node *node) 
	{ 
		node->pre->next = node->next; 
		node->next->pre = node->pre; 
	} 

	void addToHead(Node *node) 
	{ 
		node->next = head->next; 
		node->next->pre = node; 
		node->pre = head; 
		head->next = node; 
	} 
 
	int get(int key) 
	{ 
		if (map[key] != NULL) { 
			Node *node = map[key]; 
			int result = node->value; 
			deleteNode(node); 
			addToHead(node); 
			cout<<"Got the value : " << 
				result << " for the key: " << key<<endl; 
			return result; 
		} 
		cout<<"Did not get any value" <<
							" for the key: " << key<<endl; 
		return -1; 
	} 

	void set(int key, int value) 
	{ 
		cout<<"Going to set the (key, "<< 
			"value) : (" << key << ", " << value << ")"<<endl; 
		if (map[key] != NULL) { 
			Node *node = map[key]; 
			node->value = value; 
			deleteNode(node); 
			addToHead(node); 
		} 
		else { 
			Node *node = new Node(key, value); 
			map[key]= node; 
			if (count < capacity) { 
				count++; 
				addToHead(node); 
			} 
			else { 
				map.erase(tail->pre->key); 
				deleteNode(tail->pre); 
				addToHead(node); 
			} 
		} 
	} 
}; 





