class Solution {
public:

    bool static cmp(const pair<int,int> p1 ,const pair<int,int> p2)
    {
        if(p1.first != p2.first) 
        {
            return (p1.first < p2.first);
        }
    
        else return (p1.second > p2.second);
    }
    void dijkstras(int src, int n, vector<pair<int, int>> adj[], vector<pair<int, int>> &ans, int distanceThreshold)
    {
        // initiating distance vector with infinites
        vector<int> distance(n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        // pushing source node to priority queue and marking o in distance vector
        distance[src] = 0;
        pq.push({0,src});

        while(!pq.empty())
        {
            int prev_node = pq.top().second;
            int prev_wt = pq.top().first;
            pq.pop();
            // iterate through adjacent nodes of popped element
            for(auto it: adj[prev_node])
            {
                int child_node = it.first;
                int child_dist = it.second;
                // if we find a shorter distance, update the distance vector and add to priority queue
                if(distance[child_node] > distance[prev_node]+ child_dist)
                {
                    distance[child_node] = distance[prev_node]+child_dist;
                    pq.push({distance[child_node], child_node});
                }
            }
        }

        int count = 0;
        for(int i = 0 ; i < n; i++)
        {
            if(i != src && distance[i] <= distanceThreshold) count++;
        }

        ans.push_back({count, src});
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // ds to store adjacency list
        vector<pair<int, int>> adj[n];

        // creating adjacency list
        for(int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        vector<pair<int, int>> ans;

        // passing every item on adjacency list to dijkstra's algorithm
        for(int i = 0; i < n; i++)
        {
            dijkstras(i, n, adj, ans, distanceThreshold);
        }

        sort(ans.begin(),ans.end(),cmp);

        return ans[0].second;
    }
};