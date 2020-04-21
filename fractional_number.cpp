#include <climits>
#include <iomanip>
#include <set>
#include <map>
#include <math.h>
#include <stack>
#include <list>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

struct pq {
	ll p = 0;
	ll q = 1;

	pq() {}

	pq(ll p, ll q) : p(p), q(q) {}

	pq(ll p) : p(p) {}

	ll gcd(ll a, ll b) {
		return b ? gcd(b, a % b) : a;
	}

	void simple() {
		ll g = gcd(this->p, this->q);
		this->p /= g;
		this->q /= g;
		if (this->q < 0) {
			this->q = -this->q;
			this->p = -this->p;
		}
	}

	pq operator+=(pq a) {
		ll g = gcd(this->q, a.q);
		this->p *= a.q / g;
		a.p *= this->q / g;
		this->p += a.p;
		this->q *= a.q / g;
		this->simple();
		return *this;
	}

	void operator=(pq a) {
		this->p = a.p;
		this->q = a.q;
	}

	pq operator+ (pq a) {
		pq ans = *this;
		ll g = gcd(ans.q, a.q);
		ans.p *= a.q / g;
		a.p *= ans.q / g;
		ans.p += a.p;
		ans.q *= a.q / g;
		ans.simple();
		return ans;
	}

	pq operator-() {
		return pq(-this->p, this->q);
	}

	pq operator*(pq a) {
		pq ans = *this;
		ans.p *= a.p;
		ans.q *= a.q;
		ans.simple();
		return ans;
	}

	pq operator*(ll a) {
		pq ans = *this;
		ans.p *= a;
		ans.simple();
		return ans;
	}

	pq operator*=(pq a) {
		this->p *= a.p;
		this->q *= a.q;
		this->simple();
		return *this;
	}
};
