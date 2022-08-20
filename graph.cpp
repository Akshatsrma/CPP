void addEdge(vector<int> adj[], int u, int v)
{
  adj[u].push_back(v);
  adj[v].push_back(u);
}

// BFS
// undirected graph with a source vertex s given
void BFS(vector<int> adj[], int V, int s)
{
  bool visited[v]{};
  for (int i{}; i < v; i++)
  {
    visited[i] = false;
  }
  queue<int> q{};
  visited[s] = true;
  q.push(s);

  while (q.empty() == false)
  {
    int u = q.front();
    q.pop();
    cout << u << " ";
    for (auto v : adj[u])
    {
      if (!visited[v])
      {
        visited[v] = true;
        q.push(v);
      }
    }
  }
}

//  B.F.S on disconnected graphs.

void BFS(vector<int> adj[], bool visited[], int s)
{
  queue<int> q{};
  visited[s] = true;
  q.push(s);

  while (q.empty() == false)
  {
    int u = q.front();
    q.pop();
    cout << u << " ";
    for (auto v : adj[u])
    {
      if (!visited[v])
      {
        visited[v] = true;
        q.push(v);
      }
    }
  }
}

void BFSinitializer(vector<int> adj[], int v)
{
  bool visited[v];
  for (int i{}; i < v; i++)
  {
    visited[i] = false;
  }
  for (int i{}; i < v; i++)
  {
    if (visited[i] == false)
    {
      BFS(adj, visited, i)
    }
  }
}

// DFS

// basic dfs with givn source

void DFSRec(vector<int> adj[], int s, bool visited[])
{
  visited[s] = true;
  cout << s << " ";

  for (int u : adj[s])
  {
    if (visited[u] == false)
      DFSRec(adj, u, visited);
  }
}

void DFS(vector<int> adj[], int V, int s)
{
  bool visited[V];
  for (int i = 0; i < V; i++)
    visited[i] = false;

  DFSRec(adj, s, visited);
}

// on disconnected graph
void DFS(vector<int> adj[], bool visited[], int s)
{

  visited[s] = true;
  cout << s << " ";
  for (auto v : adj[s])
  {
    if (visited[v] == false)
      DFS(adj, visited, v);
  }
}

void DFSin(vector<int> adj[], int v)
{
  bool visited[v];
  for (int i{}; i < v; i++)
  {
    visited[i] = false;
  }

  for (int i{}; i < v; i++)
  {
    if (visited[i] == false)
    {
      DFS(adj, visited, i);
      cout << endl;
    }
  }
}

// shortest path using bfs
void BFS(vector<int> adj[], int V, int s, int dist[])
{
  bool visited[V];
  for (int i = 0; i < V; i++)
    visited[i] = false;

  queue<int> q;

  visited[s] = true;
  q.push(s);

  while (q.empty() == false)
  {
    int u = q.front();
    q.pop();

    for (int v : adj[u])
    {
      if (visited[v] == false)
      {
        dist[v] = dist[u] + 1;
        visited[v] = true;
        q.push(v);
      }
    }
  }
}

// detect cycle
// in undirectional graph
bool DFSCycle(vector<int> adj[], bool visited[], int u, int parent)
{

  visited[u] = true;
  for (auto v : adj[u])
  {
    if (visited[v] == false)
    {
      if (DFSCycle(adj, visited, v, u))
        return true;
    }
    else if (parent != u)
    {
      return true;
    }
  }
  return false;
}

bool DFS(vector<int> adj[], int V)
{
  bool visited[v];
  for (int i{}; i < v; i++)
  {
    visited[i] = false;
  }

  for (int i{}; i < v; i++)
  {
    if (visited[i] == false)
    {
      if (DFSCycle(adj, visited, i, -1))
      {
        return true;
      }
    }
  }
  return false;
}

// in directional graph

bool DFSdCycle(vector<int> adj[], bool visited[], int u, bool rec[])
{

  visited[u] = true;
  rec[u] = true;

  for (auto v : adj[u])
  {
    if (visited[v] == false)
    {
      if (DFSdCycle(adj, visited, v, rec))
      {
        return true;
      }
    }
    else if (rec[v] == true)
    {
      return true;
    }
  }
  rec[u] = false;
  return false;
}

bool DFS(vector<int> adj[], int V)
{
  bool visited[v];
  bool rec[v];
  for (int i{}; i < v; i++)
  {
    visited[i] = false;
    rec[i] = false;
  }

  for (int i{}; i < v; i++)
  {
    if (visited[i] == false)
    {
      if (DFSCycle(adj, visited, i, rec))
      {
        return true;
      }
    }
  }
  return false;
}

// topological sorting
// bfs method(kahn's method)

void topologicalSort(vector<int> adj[], int V)
{
  vector<int> in_degree(V, 0);

  for (int u = 0; u < V; u++)
  {
    for (int x : adj[u])
      in_degree[x]++;
  }

  queue<int> q;
  for (int i = 0; i < V; i++)
    if (in_degree[i] == 0)
      q.push(i);

  while (!q.empty())
  {
    int u = q.front();
    q.pop();
    cout << u << " ";

    for (int x : adj[u])
      if (--in_degree[x] == 0)
        q.push(x);
  }
}

// dfs method

void topologicalSorting(vector<int> adj[], int u, stack<int> &s, bool visited[])
{
  visited[u] = true;

  for (auto v : adj[u])
  {
    if (visited[v] == false)
    {
      topologicalSorting(adj, v, s, visited);
    }
  }

  s.push(u);
  return;
}

void function(vector<int> adj[], int v)
{
  bool visited[v];
  for (int i{}; i < v; i++)
  {
    visited[i] = false;
  }
  stack<int> s{};
  for (int i{}; i < v; i++)
  {
    if (visited[i] == false)
    {
      topologicalSorting(adj, i, s, visited)
    }
  }

  while (s.empty() == false)
  {
    cout << s.top() << " ";
    s.pop();
  }
}

// shortest path from source in WDAG // using topological sorting
void Graph::shortestPath(int s)
{
  stack<int> Stack;
  int dist[V];

  bool *visited = new bool[V];
  for (int i = 0; i < V; i++)
    visited[i] = false;

  for (int i = 0; i < V; i++)
    if (visited[i] == false)
      topologicalSortUtil(i, visited, Stack);

  for (int i = 0; i < V; i++)
    dist[i] = INF;
  dist[s] = 0;

  while (Stack.empty() == false)
  {
    int u = Stack.top();
    Stack.pop();

    list<AdjListNode>::iterator i;
    if (dist[u] != INF)
    {
      for (i = adj[u].begin(); i != adj[u].end(); ++i)
        if (dist[i->getV()] > dist[u] + i->getWeight())
          dist[i->getV()] = dist[u] + i->getWeight();
    }
  }

  for (int i = 0; i < V; i++)
    (dist[i] == INF) ? cout << "INF " : cout << dist[i] << " ";
}

// minimum spanning tree
// for checking minimum spanning tree for a directed graph, we have to see allthe spanning trees and then find the minimum
// prims algorithm(undirected weighted graph);

int primsalgo(int graph[V][V], int v)
{
  int key[v];
  int res = 0;

  bool MST[v];
  for (int i{}; i < v; i++)
  {
    MST[i] = false;
    key[i] = INT_MAX;
  }
  key[0] = 0;

  for (int count = 0; count < v; count++)
  {
    int u{-1};
    for (int i{}; i < v; i++)
    {
      if (!MST[i] && (u == -1 || key[i] < key[u]))
      {
        u = i;
      }
    }
    MST[u] = true;
    res += key[u];

    for (int i{}; i < v; i++)
    {
      if (graph[u][i] != 0 && !MST[i])
      {
        if (key[i] > graph[u][i])
        {
          key[i] = graph[u][i];
        }
      }
    }
  }
  return res;
}
// we can optimize it using vectors in  the graph and priority queue to store the key values as well so that we can get the minimum in log(v) time, total time comp- O(ElogV)

// Dijkstra's shortest distance from given source algorithm

vector<int> dijkstra(int graph[V][V], int src)
{
  int dist[v];
  bool MST[v];
  for (int i{}; i < v; i++)
  {
    dist[i] = INT_MAX;
    MST[v] = false;
  }

  dist[0] = 0;
  for (int count = 0; count < v - 1; count++)
  {
    int u{-1};
    for (int i{}; i < v; i++)
    {
      if (!MST[i] && (u == -1 || key[i] < key[u]))
      {
        u = i;
      }
    }
    MST[u] = true;

    for (int i{}; i < v; i++)
    {
      if (graph[u][i] != 0 && !MST[i])
      {
        dist[i] = min(dist[i], graph[u][i] + dist[u]);
      }
    }
  }
}

// same optimizatons  as prims algorithm // O(Elogv)

// Strongly connected components problem(strongley connected component-> every pair is reachable from one another)
// our task is to print all the strongly connected components in a directed graph.

// kosa raju's algorithm

void kosaraju(vector<int> adj[], int v)
{
  stack<int> s{};
  vector<bool> visited(v, true);
  topologicalSorting(adj, visited, s);

  vector<int> transpose[v];

  for (int i{}; i < v; i++)
  {
    for (auto x : adj[i])
    {
      transpose[x].push_back(i);
    }
  }

  for (auto &x : visited)
  {
    x = false;
  }
  while (s.empty() == false)
  {
    int temp = s.top();
    s.pop();
    if (visited[temp] == false)
    {
      dfs(transpose, visited, temp);
      cout << endl;
    }
  }
}

// bellman ford algorithm

// for shortest distance from source to other vertices in a directed graph.
struct Edge
{
  int src, dest, weight;
};

struct Graph
{
  int V, E;
  struct Edge *edge;
};
void BellmanFord(struct Graph *graph, int src)
{
  int V = graph->V;
  int E = graph->E;
  int dist[V];

  for (int i = 0; i < V; i++)
    dist[i] = INT_MAX;
  dist[src] = 0;

  for (int i = 1; i <= V - 1; i++)
  {
    for (int j = 0; j < E; j++)
    {
      int u = graph->edge[j].src;
      int v = graph->edge[j].dest;
      int weight = graph->edge[j].weight;
      if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
        dist[v] = dist[u] + weight;
    }
  }

  for (int i = 0; i < E; i++)
  {
    int u = graph->edge[i].src;
    int v = graph->edge[i].dest;
    int weight = graph->edge[i].weight;
    if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
    {
      printf("Graph contains negative weight cycle");
      return;
    }
  }

  printArr(dist, V);

  return;
}
// time complexity ->O(VE);

// Articulation point in undirected connected graph

void Articulationdfs(vector<int> graph[], vector<int> &lowvalue, vector<int> &discoverytime, int u, int visited[], vector<int> &parent)
{

  static int time = 0;
  lowvalue[u] = discoverytime[u] = ++time;
  visited[u] = true;
  int temp{};
  for (auto v : graph[u])
  {
    if (visited[v] == false)
    {
      parent[v] = u;
      Articulationdfs(graph, lowvalue, discoverytime, v, visited, parent);
      temp++;
      lowvalue[u] = min(lowvalue[u], lowvalue[v]);
      if (parent == -1 && temp > 1)
      {
        // markit as true;
      }
      if (parent != -1 && lowvalue[v] >= discoverytime[u])
      {
        // mark it as true;
      }
    }
    else if (v != parent[u])
    {
      lowvalue[u] = min(lowvalue[u], discovertytime[v]);
    }
  }
}

void articulationPoint(vector<int> graph[], int v)
{
  vector<int> discoverytime(v){};
  vector<int> lowvalue(v){};
  bool visited[v];
  vector<int> parent{};
  for (int i{}; i < v; i++)
  {
    parent[i] = -1;
    visited[i] = false;
  }
  for (int i{}; i < v; i++)
  {
    if (visited[i] == false)
      dfs()
  }
}

// bridges in a graph*(if removing an edge increases the number of connected components then it is called a bridge)
//  same algorithm as the articulation point one just one point(if lowvalue[v]>discoverytime[u]  => it means that it is a bridge)
void Graph::bridgeUtil(int u, bool visited[], int disc[], int low[], int parent[])
{
  static int time = 0;
  visited[u] = true;
  disc[u] = low[u] = ++time;

  list<int>::iterator i;
  for (i = adj[u].begin(); i != adj[u].end(); ++i)
  {
    int v = *i;
    if (!visited[v])
    {
      parent[v] = u;
      bridgeUtil(v, visited, disc, low, parent);
      low[u] = min(low[u], low[v]);

      if (low[v] > disc[u])
        cout << u << " " << v << endl;
    }
    else if (v != parent[u])
      low[u] = min(low[u], disc[v]);
  }
}

// tarjan's algorithm for strongely connected copmponents
void Graph::SCCUtil(int u, int disc[], int low[], stack<int> *st, bool stackMember[])
{
  static int time = 0;

  disc[u] = low[u] = ++time;
  st->push(u);
  stackMember[u] = true;

  list<int>::iterator i;
  for (i = adj[u].begin(); i != adj[u].end(); ++i)
  {
    int v = *i;

    if (disc[v] == -1)
    {
      SCCUtil(v, disc, low, st, stackMember);

      low[u] = min(low[u], low[v]);
    }

    else if (stackMember[v] == true)
      low[u] = min(low[u], disc[v]);
  }

  int w = 0;
  if (low[u] == disc[u])
  {
    while (st->top() != u)
    {
      w = (int)st->top();
      cout << w << " ";
      stackMember[w] = false;
      st->pop();
    }
    w = (int)st->top();
    cout << w << "\n";
    stackMember[w] = false;
    st->pop();
  }
}
// O(V+E);
