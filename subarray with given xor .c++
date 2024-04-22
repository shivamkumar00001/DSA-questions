int numSubarrayWithXOR(vector<int> &A, int target) {
    int n = A.size();
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int subarrayXor = 0;
		for (int j = i; j < n; j++) {
			subarrayXor ^= A[j];
			if (subarrayXor == target) {
				ans++;
			}
		}
	}
	return ans;
}
