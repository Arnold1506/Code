class SGTree {
	vector<int> seg;
public:
	SGTree(int n) {
		seg.resize(4 * n + 1);
	}

	void build(int ind, int l, int r, int arr[]) {
		if (l == r) {
			seg[ind] = arr[l];
			return;
		}

		int mid = (l + r) / 2;
		build(2 * ind +1, l, mid, arr);
		build(2 * ind + 2, mid + 1, r, arr);
		seg[ind] = min(seg[2 * ind +1], seg[2 * ind + 2]);
	}

	int query(int ind, int l, int r, int ql, int qr) {
		// no overlap
		// ql qr l r or l r ql qr
		if (qr < l || ql > r || qr < 0) return INT_MAX;

		// complete overlap
		// [ql l r qr]
		if (ql <= l && r <= qr) return seg[ind];

		int mid = (l + r) >> 1;
		int left = query(2 * ind+1, l,mid,ql,qr);
		int right = query(2 * ind +2, mid + 1, r,ql,qr );
		return min(left, right);
	}
	void update(int ind, int l, int r, int i, int val) {
		if (l==r) {
			seg[ind] = val;
			return;
		}

		int mid = (l+r) >> 1;
		if (i <= mid) update(2 * ind+1 , l, mid, i, val);
		else update(2 * ind + 2, mid + 1, r, i, val);
		seg[ind] = min(seg[2 * ind+1], seg[2 * ind +2]);
	}
};
