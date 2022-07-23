bool solve(vector <vector <int>> matrix, int x1-1, int y1-1, int x2-1, int y2-1, int &k) {
	if (x2<0 or x2>=n) return false;
	if (y2<0 or y2>=m) return false;
	if (matrix[x1][y1]%matrix[x2][y2]==0) return true;

	if (k>1) {
		k--;
		return (solve(matrix, x1, y1, x2-1, y2, k) or solve(matrix, x1, y1, x2+1, y2, k) or solve(matrix, x1, y1, x2, y2-1, k) or solve(matrix, x1, y1, x2, y2+1, k));
	}

	return false;
}