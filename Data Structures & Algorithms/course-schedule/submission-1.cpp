class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegrees(numCourses, 0);
        unordered_map<int, vector<int>> adjList;

        for (auto p : prerequisites) {
            if (adjList.contains(p[1])) {
                adjList[p[1]].push_back(p[0]);
            } else {
                adjList[p[1]] = {p[0]};
            }

            indegrees[p[0]]++;
        }
        
        queue<int> q;
        unordered_set<int> compCourses;
        for (int i=0; i<indegrees.size(); i++) {
            if (indegrees[i] == 0) {
                q.push(i);
                compCourses.insert(i);
            }
        }

        while(!q.empty()) {
            int val = q.front();
            q.pop();

            auto vec = adjList[val];
            for (auto it : vec) {
                indegrees[it]--;
            }

            for (int i=0; i<indegrees.size(); i++) {
                if (indegrees[i] == 0 && !compCourses.contains(i)) {
                    q.push(i);
                    compCourses.insert(i);
                }
            }
        }

        return compCourses.size() == numCourses;
    }
};
