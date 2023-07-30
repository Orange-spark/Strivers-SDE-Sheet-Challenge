int editDistance(string s1, string s2)
{
    // Approach 1 : Brute Force Recursion
    // if(s1.size() == 0){
	// 	return s2.size();
	// }
	// if(s2.size() == 0){
	// 	return s1.size();
	// }
	// if(s1[0] == s2[0]){
	// 	return editDistance(s1.substr(1), s2.substr(1));
	// }
	// else{
	// 	int a = editDistance(s1.substr(1), s2) + 1;
	// 	int b = editDistance(s1.substr(1), s2.substr(1)) + 1;
	// 	int c = editDistance(s1, s2.substr(1)) + 1;
	// 	return min(a, min(b, c));
	// }

	// DP
	int m = s1.size();
	int n = s2.size();
	int** output = new int*[m+1];
	for(int i = 0;i<=m;i++){
		output[i] = new int[n+1];
	}
	for(int i = 0;i<=m;i++){
		output[i][0] = i;
	}
	for(int i = 0;i<=n;i++){
		output[0][i] = i;
	}
	for(int i = 1;i<=m;i++){
		for(int j = 1;j<=n;j++){
			if(s1[m-i] == s2[n-j]){
				output[i][j] = output[i-1][j-1];
			}else{
				output[i][j] = min(output[i-1][j],min(output[i][j-1],output[i-1][j-1]))+1;
			}
		}
	}
	return output[m][n];
}
