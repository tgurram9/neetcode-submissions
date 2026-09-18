class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegrees(numCourses, 0);
        vector<vector<int>> adjList(numCourses);

        for (auto p : prerequisites) {
            adjList[p[1]].push_back(p[0]);
            indegrees[p[0]]++;
        }
        
        queue<int> q;
        int finished = 0;
        for (int i=0; i<indegrees.size(); i++) {
            if (indegrees[i] == 0) {
                q.push(i);
                finished++;
            }
        }

        while(!q.empty()) {
            int val = q.front();
            q.pop();

            auto vec = adjList[val];
            for (auto it : vec) {
                indegrees[it]--;
                if (indegrees[it] == 0) {
                    q.push(it);
                    finished++;
                }
            }
        }

        return finished == numCourses;
    }
};
