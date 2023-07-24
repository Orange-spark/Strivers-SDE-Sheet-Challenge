int quickselect(int start, int end, vector<int> &arr, int k) {
    if (start > end) return 0;

    int pivot = end;
    int ptr1 = start;
    int ptr2 = end - 1;

    while (ptr1 <= ptr2) {
        if (arr[ptr1] > arr[end] && arr[ptr2] <= arr[end]) {
            swap(arr[ptr1], arr[ptr2]);
            ptr1++;
            ptr2--;
            continue;
        }

        if (arr[ptr1] <= arr[end]) ptr1++;
        if (arr[ptr2] > arr[end]) ptr2--;
    }

    swap(arr[end], arr[ptr1]); 
    if (ptr1 == k) return arr[ptr1];
    else if (ptr1 > k) return quickselect(start, ptr1 - 1, arr, k);
    else return quickselect(ptr1 + 1, end, arr, k);
}

vector<int> kthSmallLarge(vector<int> &arr, int n, int k) {
    return { quickselect(0, n - 1, arr, k - 1), quickselect(0, n - 1, arr, n - k) };
}
