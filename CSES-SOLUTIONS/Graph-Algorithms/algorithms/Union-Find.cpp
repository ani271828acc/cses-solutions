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
		// Path compression below
        while (x != temp) {
            int next = parent[x];
            parent[x] = temp;
            x = next;
        }
        return x;
    }

    void Union(int x, int y) {
        int xx = Find(x);
        int yy = Find(y);
        if (xx != yy) {
            parent[xx] = yy;
        }
    }

    private:
           vector<int> parent;
};
