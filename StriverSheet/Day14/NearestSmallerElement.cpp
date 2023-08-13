vector<int> Solution::prevSmaller(vector<int> &A) {
    vector<int> res((int)A.size(), -1);
    int n = (int) A.size();
    stack<int> st;
    for(int i=0; i<n; i++) {
        while(!st.empty() && A[st.top()] >= A[i]) st.pop();
        if(!st.empty() && A[st.top()] < A[i]) res[i] = A[st.top()];
        st.push(i); 
    }
    return res;
}
