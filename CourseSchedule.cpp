class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        int visited = 0;
        vector<vector<int>> graph(numCourses, vector<int>());
        vector<int> indegree(numCourses, 0);        
        int edges = prerequisites.size();
        for(int i=0; i<edges; i++)
        {
            int take = prerequisites[i][0];
            int req = prerequisites[i][1];
            graph[req].push_back(take);
            ++indegree[take];
        }
        
        queue<int> q;
        for(int i=0; i<numCourses; i++)
        {
            if(indegree[i] == 0)
            {
                ++visited;
                q.push(i);
            }
        }
        if(q.size() == 0)
            return false;
        while(!q.empty())
        {
            int ele = q.front();
            q.pop();
            int n = graph[ele].size();
            for(int i=0; i<n; i++)
            {
                --indegree[graph[ele][i]];
                if(indegree[graph[ele][i]] == 0)
                {
                    ++visited;
                    q.push(graph[ele][i]);
                }
            }
        }
        if(visited == numCourses)
            return true;
        return false;
    }
};