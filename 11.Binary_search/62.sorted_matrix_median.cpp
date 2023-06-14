

int count_elem(vector<vector<int>> &matrix,int key)
{
    int cnt =0;

    int  r =matrix.size(),c =matrix[0].size();    

    for(int i=0;i<r;i++)
    {
        int low = 0,high = c-1;

        while(low<=high)
        {
            int mid =(low+high)/2;

            int x = matrix[i][mid];
            
            if(x<=key)
                low = mid+1;
            else
                high =mid-1;

        }
        cnt+=low;
    }
    return cnt;
}

int getMedian(vector<vector<int>> &matrix)
{
    // Write your code here.
    int  r =matrix.size(),c =matrix[0].size();

    int low =0,high = 1e5;

    int med = r*c/2;

    while(low<=high)
    {
        int mid = (low+high)/2;

        int cnt =count_elem(matrix,mid);

        if(cnt<=med)
            low = mid+1;
        else 
            high = mid-1;

    }
    return low;
}
