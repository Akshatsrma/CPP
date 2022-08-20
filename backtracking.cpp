// all possible permutautions of the string without AB as a substring
bool isSafe(string str,int l, int i, int r){
    if(l!=0 && str[l-1]=='A' && str[i]=='B')
        return false;
    if(r==(l+1) && str[i]=='A' && str[l]=='B')
        return false;
    return true;
}

void permute(string str, int l, int r){
    
    if(l==r){
        cout<<str<<" ";
        return;
    }else{
        for(int i=l;i<=r;i++){
            if(isSafe(str,l,i,r)){
                swap(str[i],str[l]);
                permute(str,l+1,r);
                swap(str[i],str[l]);}
        }   
    }
}

// rat in a maze
bool issafe(innt maze[N][N],int i,int j)
{
    return (i<N && j<N && i>=0 && j>=0 && maze[i][j]!=0); 
}
 bool ratinamaze(int maze[N][N],vector<pair<int,int>>& path,int i,int j)
 {
    path.push_back({i,j});
    if(i==N-1 && j==N-1 && maze[i][j]==1)
    {
        return true;
    }
     if(issafe(maze,i+1,j))
     {
        if(ratinamaze(maze,path,i+1,j)) return true;
     }
     if(issafe(maze,i,j+1))
     {
        if(ratinamaze(maze,path,i,j+1)) return true;
     }
     path.pop_back();
     return false;
 }

 bool solvemaze(int maze[N][N])
 {
    vector<pair<int,int>> path{};
    if(ratinamaze(maze,path,0,0))
    {
        for(auto x:path)
        {
            cout<<x.first<<" "<<x.second<<endl;
        }
        return true;
    }
    return false;
 }

 // or gfg solution
 bool solveMazeRec( int maze[N][N], int i, int j, int sol[N][N]) 
{ 
    if ( i == N - 1 && j == N - 1 && maze[i][j] == 1) { 
        sol[i][j] = 1; 
        return true; 
    } 
  
    if (isSafe(maze, i, j) == true) { 
        sol[i][j] = 1; 
  
        if (solveMazeRec(maze, i + 1, j, sol) == true) 
            return true; 
  
        if (solveMazeRec(maze, i, j + 1, sol) == true) 
            return true; 
  
        sol[i][j] = 0; 
    } 
  
    return false; 
}


// N queen
 bool safe(int n,int i,int j, int borad[][n])
 {
    if(i>=n || j>=n || j<0 || i<0) return false;

    for(int x{0};x<j;x++)
    {
        if(board[i][x]==1)return false;

    }

      for(int x=i,y=j;x>=0 && y>=0;x--,y--)
      {
        if(board[x][y]==1)return false;
      }
       for(int x=i,int y=j;x>=0 && y<n;x--,y++)
      {
        if(board[x][y]==1)return false;
      }

      return true;
 }
 bool placequeen(int j,int n,int board[][n])
 {
    if(j==n)
    {
        return true;
    }
     for(int i{};i<n;i++)
     {
        if(safe(n,i,j,board))
        {
            board[i][j]=1;
            if(placequeen(j+1,n,board))
            {
                return true;
            }
            board[i][j]=0;
        }
     }
     return false;
 }

 bool nqueen(int n)
 {
     int board[n][n];

     for(int i{};i<n;i++)
     {
        for(int j{};j<n;j++)
        {
            board[i][j]=0;
        }
     }

     placequeen(0,n,board);
 }


// sudoku problem
bool isSafe(int board[N][N],int row, int col, int num) 
    { 
     
        for (int d = 0; d < N; d++)  
        { 
            
            if (board[row][d] == num) { 
                return false; 
            } 
        } 
  
        for (int r = 0; r < N; r++)  
        { 
               
            if (board[r][col] == num)  
            { 
                return false; 
            } 
        }  
        int s = (int)sqrt(N); 
        int boxRowStart = row - row % s; 
        int boxColStart = col - col % s; 
  
        for (int r = boxRowStart; 
             r < boxRowStart + s; r++)  
        { 
            for (int d = boxColStart; 
                 d < boxColStart + s; d++)  
            { 
                if (board[r][d] == num)  
                { 
                    return false; 
                } 
            } 
        } 
  
        return true; 
    } 

bool solve(int board[N][N],int n) 
{ 
	    int row = -1; 
        int col = -1; 
        bool isEmpty = true; 
        for (int i = 0; i < n; i++)  
        { 
            for (int j = 0; j < n; j++)  
            { 
                if (board[i][j] == 0)  
                { 
                    row = i; 
                    col = j; 
                    isEmpty = false; 
                    break; 
                } 
            } 
            if (!isEmpty) { 
                break; 
            } 
        } 
  
        if (isEmpty)  
        { 
            return true; 
        } 
        
        for (int num = 1; num <= n; num++)  
        { 
            if (isSafe(board, row, col, num))  
            { 
                board[row][col] = num; 
                if (solve(board, n))  
                { 
                    // print(board, n); 
                    return true; 
                } 
                else 
                { 
                    board[row][col] = 0; 
                } 
            } 
        } 
        return false; 
} 


