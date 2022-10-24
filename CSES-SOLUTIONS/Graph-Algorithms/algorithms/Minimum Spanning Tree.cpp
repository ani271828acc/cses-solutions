class UnionFind {
public:
	UnionFind(int n) : parent(n) {
		  iota(parent.begin(), parent.end(), 0);
	}
	int Find(int x) {
		int temp = x;
		while (temp != parent[temp]) {
			temp = parent[temp];
		}
		while (x != temp) {
			int next = parent[x];
			parent[x] = temp;
			x = next;
		}
		return temp;
	}
	bool Union(int x, int y) {
		int xx = Find(x);
		int yy = Find(y);
		if (xx == yy) return false;
		parent[xx] = yy;
		return true;
	}

private:
	vector<int> parent;
};
int minimumCost(int n, vector<vector<int>>& connections) {
	sort(connections.begin(), connections.end(), [](const auto& lhs, const auto& rhs){
		return lhs[2] < rhs[2];
	});
	UnionFind uf(n + 1);
	int sum = 0, count = 0;
	for (auto& c : connections) {
		if (uf.Union(c[0], c[1])) {
			count++;
			sum += c[2];
		}
		if (count == n - 1) return sum; // Return earlier once graph is connected.
	}
	return -1;
}
