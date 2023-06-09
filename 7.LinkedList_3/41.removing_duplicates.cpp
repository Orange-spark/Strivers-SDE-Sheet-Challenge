int removeDuplicates(vector<int> &arr, int n) {
	// Write your code here.
	int i=0,cnt=0;

	while(i<n-1)
	{
		while(i<n-1 && arr[i]==arr[i+1])
		{
			i++;
		}
		cnt++;
		i++;
	}
	if(arr[n-1]!=arr[n-2])cnt++;

return cnt;
}
