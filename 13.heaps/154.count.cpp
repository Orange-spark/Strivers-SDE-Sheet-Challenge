#include <iostream>

#include <vector>

#include <unordered_map>

 

std::vector<int> countDistinctElements(std::vector<int>& arr, int k) {

    std::vector<int> result;

    std::unordered_map<int, int> frequencyMap;

 

    // Count the frequency of each element in the first window

    for (int i = 0; i < k; i++) {

        frequencyMap[arr[i]]++;

    }

 

    // Add the count of distinct elements in the first window to the result

    result.push_back(frequencyMap.size());

 

    // Process subsequent windows

    for (int i = k; i < arr.size(); i++) {

        // Remove the first element of the previous window from the frequency map

        frequencyMap[arr[i - k]]--;

        if (frequencyMap[arr[i - k]] == 0) {

            frequencyMap.erase(arr[i - k]);

        }

 

        // Add the current element to the frequency map

        frequencyMap[arr[i]]++;

 

        // Add the count of distinct elements in the current window to the result

        result.push_back(frequencyMap.size());

    }

 

    return result;

}
