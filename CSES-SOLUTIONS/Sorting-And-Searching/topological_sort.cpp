// Kahn's Algorithm
    vector<vector<int>> adj(numCourses);
    vector<int> indegree(numCourses, 0);
    for (auto& p : prerequisites) {
        indegree[p[1]]++;
        adj[p[0]].push_back(p[1]);
    }
    queue<int> q;
    for (int i = 0; i < numCourses; i++) {
        if (indegree[i] == 0) q.push(i);
    }
    int prereq = 0;
    while (!q.empty()) {
        int el = q.front();
        q.pop();
        prereq++;
        for (auto& next : adj[el]) {
            if (--indegree[next] == 0) {
                q.push(next);
            }
        }
    }
    return prereq == numCourses;
