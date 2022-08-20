
struct TrieNode
{
    struct TrieNode *children[ALPHABET_SIZE];

    bool isEndOfWord;
};

// implementation

struct TrieNode *getNode(void)
{
    struct TrieNode *pNode = new TrieNode;

    pNode->isEndOfWord = false;

    for (int i = 0; i < ALPHABET_SIZE; i++)
        pNode->children[i] = NULL;

    return pNode;
}

void insert(struct TrieNode *root, string key)
{
    struct TrieNode *pCrawl = root;

    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();

        pCrawl = pCrawl->children[index];
    }

    pCrawl->isEndOfWord = true;
}

bool search(struct TrieNode *root, string key)
{
    struct TrieNode *pCrawl = root;

    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!pCrawl->children[index])
            return false;

        pCrawl = pCrawl->children[index];
    }

    return (pCrawl != NULL && pCrawl->isEndOfWord);
}

TrieNode *delete (struct TrieNode *root, string key, int n = 0)
{
    if (root == nullptr)
    {
        return root;
    }
    if (n == key.length())
    {
        root->isEndOfWord = false;
        if (isempty(root))
        {
            delete root;
            root = nullptr;
        }
        return root;
    }
    int index = key[n] - 'a';

    root->children[index] = delete (root->children[index], key, n + 1);

    if (isempty(root) && root->isEndOfWord == false)
    {
        delete root;
        root = nullptr;
    }
    return root;
}
bool isEmpty(TrieNode *root)
{
    for (int i{}; i < 26; i++)
    {
        if (root->children[i] != nullptr)
            [return false;
            ]
    }
    return true;
}