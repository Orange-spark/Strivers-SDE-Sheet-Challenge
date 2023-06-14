int singleNonDuplicate(vector<int>& arr)

{

    int low  = 0;

    int high= arr.size() - 1;

    if(arr[0]!=arr[1])

    return arr[0];

    else if (arr[high] != arr[high-1])

    return arr[high];

    else if (high==0)

    return arr[0];

    while(low<high){

        int mid = low + (high-low)/2;

        if(mid%2==0){

            if(arr[mid]==arr[mid+1]){

                low = mid + 2;

            }

            else 

            high = mid;

        }

        else{

            if(arr[mid]==arr[mid-1]){

                low = mid + 1;

            }

            else

            high = mid - 1;

        }

    }

    return arr[low];

    

}
