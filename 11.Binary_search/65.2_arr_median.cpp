double median(vector<int>& arr1, vector<int>& arr2) {
	// Write your code here.
    if(arr1.size()>arr2.size()) return median(arr2,arr1);

    int n1 =arr1.size();
    int n2 = arr2.size();

    int tot = (n1+n2+1)/2;

    int low =0,high = n1;


    while(low<=high)
    {
        int cut1 =(low+high)/2;

        int cut2 = tot -cut1;

        int l1 = cut1==0 ? INT_MIN: arr1[cut1-1];
        int l2 = cut2 == 0? INT_MIN: arr2[cut2-1];

        int r1 = cut1==n1?INT_MAX:arr1[cut1];
        int r2 = cut2==n2?INT_MAX:arr2[cut2];
        
        if(l1<=r2 && l2<=r1)
        {
            if((n1+n2)%2)
            {
                return max(l1,l2);
            }
            return (double)(max(l1,l2)+min(r1,r2))/2;
        }
        else
        if(l1>r2)
        {
            high = cut1-1;
        }
        else 
            low = cut1+1;
    }

    return 0.0;
}
