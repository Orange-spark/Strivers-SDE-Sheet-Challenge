bool isValidParenthesis(string expression)
{
    // Write your code here.
    stack<char> st;

    for(auto i:expression)
    {
        if(!st.empty())
        {
            auto x = st.top();
            if((i=='}' && x=='{')or (i==')' && x=='(' ) or(i==']'&&x=='['))
            {
                st.pop();
                continue;
            }
        }
        st.push(i);
    }

    return st.empty();
}
