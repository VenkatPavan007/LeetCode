class Solution {
public:
    //vector<vector<bool>> visited;
    int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    void bfs(vector<vector<int>>&arr, int i, int j)
    {
        int n = arr.size();
        int m = arr[0].size();
        queue<pair<int, int>> q;
        q.push({i,j});
        while(!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;            
            q.pop();            
            for(int k=0; k<4; k++)
            {
                int dx = x + dir[k][0];
                int dy = y + dir[k][1];                
                if(dx<n && dx>=0 && dy<m && dy>=0 && arr[dx][dy] == 1)
                {                    
                    arr[dx][dy] = 2;
                    q.push({dx,dy});
                }
                
            }           
        }
    }
    
    int numEnclaves(vector<vector<int>>& arr) 
    {
        int rows = arr.size();
        int cols = arr[0].size();
        
        // first and last row
        for(int i=0; i<cols; i++)
        {
            if(arr[0][i] == 1 )
            {                
                arr[0][i] = 2;
                bfs(arr,0,i);
            }
            if(arr[rows-1][i] == 1)
            {                
                arr[rows-1][i] = 2;
                bfs(arr, rows-1, i);
            }
        }
        
        // first and last column
        for(int i=0; i<rows; i++)
        {
            if(arr[i][0] == 1)
            {
                arr[i][0] = 2;
                bfs(arr, i, 0);
            }
            if(arr[i][cols-1] == 1)
            {
                arr[i][cols-1] = 2;
                bfs(arr, i, cols-1);
            }
        }
        
        int ans = 0;
        for(int i=0; i<rows; i++)
        {
            for(int j=0; j<cols; j++)
            {
                if(arr[i][j] == 1)
                    ++ans;
            }
        }            
        return ans;
    }
};