class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (int i = 0; i < asteroids.size(); i++)
        {      
            bool is_destroyed = false;
            while (!st.empty() && st.top() > 0 && asteroids[i] < 0)
            {
                if (st.top() < -asteroids[i]) {
                    st.pop();
                    continue;
                }
                else if (st.top() == -asteroids[i]) {
                    st.pop();
                }

                is_destroyed = true;
                break;
            }

            if (!is_destroyed)
                st.push(asteroids[i]);          
        }

        vector<int> res(st.size());
        for (int i = st.size() - 1; i >= 0; i--) {
            res[i] = st.top();
            st.pop();
        }
        return res;
    }
};