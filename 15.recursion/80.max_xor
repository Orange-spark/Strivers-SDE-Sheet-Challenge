#include <bits/stdc++.h> 

int maximumXor(vector<int> A)

{

    // Write your code here. 

    int ans(0), mask(0);

    unordered_set<int> st;

    for(int i = 31; i>=0; i--)

    {

        mask |= (1<<i);

        int temp = ans|(1<<i);

        for (int j = 0; j < A.size(); j++){

            int num = A[j] & mask;

            if (st.find(temp ^ num) != st.end()) {

                ans = temp;

                break;

            }

            st.insert(num);

        }

        st.clear();

    }

    return ans;


 

}
