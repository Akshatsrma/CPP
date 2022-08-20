// stack implementations

// vector
struct MyStack
{
    vector<int> v;

    void push(int x)
    {
        v.push_back(x);
    }

    int pop()
    {
        int res = v.back();
        v.pop_back();
        return res;
    }

    int peek()
    {
        return v.back();
    }

    int size()
    {
        return v.size();
    }

    bool isEmpty()
    {
        return v.empty();
    }
};

// array
struct MyStack
{
    int *arr;
    int cap;
    int top;
    MyStack(int c)
    {
        cap = c;
        arr = new int[cap];
        top = -1;
    }

    void push(int x)
    {
        if (top == cap - 1)
        {
            cout << "Stack is full" << endl;
            return;
        }
        top++;
        arr[top] = x;
    }

    int pop()
    {
        if (top == -1)
        {
            cout << "Stack is Empty" << endl;
            return INT_MIN;
        }
        int res = arr[top];
        top--;
        return res;
    }

    int peek()
    {
        if (top == -1)
        {
            cout << "Stack is Empty" << endl;
            return INT_MIN;
        }
        return arr[top];
    }

    int size()
    {
        return (top + 1);
    }

    bool isEmpty()
    {
        return top == -1;
    }

    // linkedlist
    struct Node
    {
        int data;
        Node *next;
        Node(int x)
        {
            data = x;
            next = NULL;
        }
    };

    struct MyStack
    {
        Node *head;
        int sz;
        MyStack()
        {
            head = NULL;
            sz = 0;
        }

        void push(int x)
        {
            Node *temp = new Node(x);
            temp->next = head;
            head = temp;
            sz++;
        }

        int pop()
        {
            if (head == NULL)
            {
                cout << "Stack is Empty" << endl;
                return INT_MAX;
            }
            int res = head->data;
            Node *temp = head;
            head = head->next;
            delete (temp);
            sz--;
            return res;
        }

        int peek()
        {
            if (head == NULL)
            {
                cout << "Stack is Empty" << endl;
                return INT_MAX;
            }
            return head->data;
        }

        int size()
        {
            return sz;
        }

        bool isEmpty()
        {
            return head == NULL;
        }
    };

    // remove consicutive dublicates from a string
    string removeConsecutiveDuplicates(string s)
    {
        stack<char> gg{};
        string ans{};
        for (auto x : s)
        {
            if (gg.empty())
            {
                gg.push(x);
            }
            else
            {
                char temp{};
                temp = gg.top();
                if (temp != x)
                {
                    gg.push(x);
                }
            }
        }

        while (!gg.empty())
        {
            ans += gg.top();
            gg.pop();
        }

        for (int i{}; i < ans.length() / 2; i++)
        {
            swap(ans[i], ans[ans.length() - i - 1]);
        }
        return ans;
    }

    // infix to postfix

    int prec(char c)
    {
        if (c == '^')
            return 3;
        else if (c == '/' || c == '*')
            return 2;
        else if (c == '+' || c == '-')
            return 1;
        else
            return -1;
    }

    void infixToPostfix(string s)
    {

        stack<char> st;
        string result;

        for (int i = 0; i < s.length(); i++)
        {
            char c = s[i];

            // If the scanned character is
            // an operand, add it to output string.
            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
                result += c;

            // If the scanned character is an
            // ‘(‘, push it to the stack.
            else if (c == '(')
                st.push('(');

            // If the scanned character is an ‘)’,
            // pop and to output string from the stack
            // until an ‘(‘ is encountered.
            else if (c == ')')
            {
                while (st.top() != '(')
                {
                    result += st.top();
                    st.pop();
                }
                st.pop();
            }

            // If an operator is scanned
            else
            {
                while (!st.empty() && prec(s[i]) <= prec(st.top()))
                {
                    if (c == '^' && st.top() == '^')
                        break;
                    else
                    {
                        result += st.top();
                        st.pop();
                    }
                }
                st.push(c);
            }
        }

        while (!st.empty())
        {
            result += st.top();
            st.pop();
        }

        cout << result << endl;
    }

    // maximum rectangular area  of a histogram.
    int getMaxArea(int arr[], int n)
    {
        stack<int> s;
        int res = 0;
        int tp;
        int curr;

        for (int i = 0; i < n; i++)
        {
            while (s.empty() == false && arr[s.top()] >= arr[i])
            {
                tp = s.top();
                s.pop();
                curr = arr[tp] * (s.empty() ? i : i - s.top() - 1);
                res = max(res, curr);
            }
            s.push(i);
        }
        while (s.empty() == false)
        {
            tp = s.top();
            s.pop();
            curr = arr[tp] * (s.empty() ? n : n - s.top() - 1);
            res = max(res, curr);
        }

        return res;
    }

    // implement k stacks in an array

    struct KStack
    {
        int *arr, *top, *next;
        int k, freeTop, cap;

        Kstack(int k1, int n)
        {
            k = k1;
            cap = n;
            arr = new int[cap];
            top = new int[k];
            next = new int[cap];
            freetop = 0;
            for (int i{}; i < cap; i++)
            {
                arr[i] = 0;
                next[i] = i + 1;
            }
            next[cap - 1] = -1;
            for (int i{}; i < k; i++)
            {
                top[i] = -1;
            }
        }
        bool isFull() { return (freeTop == -1); }

        bool isEmpty(int sn) { return (top[sn] == -1); }

        void push(int x, int sn)
        {
            if (isFull())
            {
                return;
            }
            int i = freetop;
            arr[i] = x;
            freetop = next[i];
            next[i] = top[sn];
            top[sn] = i;
        }
        int pop(int sn)
        {
            int i = top[sn];
            top[sn] = next[i];
            next[i] = freetop;
            freeTop = i;
            return arr[i];
        }
    }