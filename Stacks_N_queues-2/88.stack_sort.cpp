#include <bits/stdc++.h> 
void sortStack(stack<int> &stack1)
{
	// Write your code here
	if(stack1.size()==1) return;

	int x = stack1.top();
	stack1.pop();

	sortStack(stack1);

	stack<int> s;

	while(!stack1.empty() && x<stack1.top())
	{
		s.push(stack1.top());
		stack1.pop();
	}
	stack1.push(x);
	while(!s.empty())
	{
		stack1.push(s.top());
		s.pop();
	}
	
}
