class Solution {
public:
    
    int dir[4][2] = {{-1,0},{0,1}, {1,0}, {0,-1}};    
    //vector<vector<bool>> visited;
    int bfs(int src_x, int src_y, int m, int n, vector<vector<int>>& arr)
    {
        queue<pair<pair<int, int>, int>> q;
        q.push({{src_x, src_y}, 0});
        while(!q.empty())
        {
            int x = q.front().first.first;
            int y = q.front().first.second;
            int level = q.front().second;
            q.pop();
            for(int i=0; i<4; i++)
            {
                int dx = x + dir[i][0];
                int dy = y + dir[i][1];
                if(dx<m && dx>=0 && dy<n && dy>=0) 
                {
                    //visited[dx][dy] = true;
                    if(arr[dx][dy] == 0)
                        return level+1;
                    q.push({{dx,dy},level+1});
                }
            }
           
        }
         return -1;
    }
    
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& arr) 
    {
        int m = arr.size();
        int n = arr[0].size();
        vector<vector<int>> res;
        res.assign(m, vector<int>(n, 0));
        //visited.assign(m, vector<bool>(n, false));
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(arr[i][j] == 1)
                {
                    //visited[i][j] = true;
                    res[i][j] = bfs(i, j, m, n, arr);
                    //visited.assign(m, vector<bool>(n, false));
                }
                   
            }
        }
        return res;       
        
    }
};