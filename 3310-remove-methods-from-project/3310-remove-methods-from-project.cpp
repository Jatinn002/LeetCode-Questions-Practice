class Solution {
public:
    vector<int> remainingMethods(int n, int k,
                                 vector<vector<int>>& invocations) {
        vector<vector<int>> graph(n);

        for (auto& edge : invocations)
            graph[edge[0]].push_back(edge[1]);

        vector<char> suspicious(n, 0);
        stack<int> st;
        st.push(k);

        while (!st.empty()) {
            int node = st.top();
            st.pop();

            if (suspicious[node])
                continue;

            suspicious[node] = 1;

            for (int next : graph[node])
                if (!suspicious[next])
                    st.push(next);
        }

        for (auto& edge : invocations) {
            if (!suspicious[edge[0]] && suspicious[edge[1]]) {
                vector<int> ans(n);
                iota(ans.begin(), ans.end(), 0);
                return ans;
            }
        }

        vector<int> ans;

        for (int i = 0; i < n; i++) {
            if (!suspicious[i])
                ans.push_back(i);
        }

        return ans;
    }
};