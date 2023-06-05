bool searchMatrix(vector<vector<int>>& mat, int target) {

    if(mat.size()==0) return false;

    int r=mat.size(),c =mat[0].size() ;

    int left =0 ,right = (r*c)-1;

    while(left<=right)
    {
        int mid =(left+right)/2;
        
        if(mat[mid/c][mid%c]==target) return true;

        if(mat[mid/c][mid%c]<target)
        {
            left = mid+1;
        }
        else right = mid-1;

    }
        return false;
}
