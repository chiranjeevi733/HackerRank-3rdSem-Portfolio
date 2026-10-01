int diagonalDifference(vector<vector<int>> arr) {
    int primary_sum = 0;
    int secondary_sum = 0;
    int n = arr.size();
    
    for (int i = 0; i < n; i++) {
        primary_sum += arr[i][i];
        secondary_sum += arr[i][n - 1 - i];
    }
    
    return abs(primary_sum - secondary_sum);
}
