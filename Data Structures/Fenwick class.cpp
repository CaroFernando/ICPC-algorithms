
class fenwick{
 public:
  vector<ll> fenw;
  int n;

  fenwick(int _n) : n(_n) {
    fenw.resize(n);
  }

  void modify(int x, ll v) {
    while (x < n) {
      fenw[x] += v;
      //fenw[x] = max(fenw[x],v);
	  x |= (x + 1);
    }
  }

  ll get(int x) {
    ll v{};
    while (x >= 0) {
      v += fenw[x];
      //v = max(v,fenw[x]);
      x = (x & (x + 1)) - 1;
    }
    return v;
  }

};


