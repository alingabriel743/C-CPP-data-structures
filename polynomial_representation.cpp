#include <iostream>

using namespace std;

class Term {
public:
	int coeff;
	int exp;
};

class Poly {
private:
	int n;
	Term* t;

public:
	Poly(int n) {
		this->n = n;
		t = new Term[this->n];
	}
	~Poly() {
		delete t;
	}
	Poly operator+(Poly& s);
	friend istream & operator>>(istream& is, Poly& p);
	friend ostream & operator<<(ostream& os, Poly& p);
};

Poly Poly::operator+(Poly& p) {
	int i, j, k;
	i = j = k = 0;
	Poly *sum = new Poly(n+p.n);
	while (i < n && j < p.n) {
		if (t[i].exp < p.t[j].exp) {
			sum->t[k++] = p.t[j++];
		}
		else if (t[i].exp > p.t[j].exp) {
			sum->t[k++] = t[i++];
		}
		else {
			sum->t[k].exp = t[i].exp;
			sum->t[k++].coeff = t[i++].coeff + p.t[j++].coeff;
		}
	}

	for (; i < n; i++) sum->t[k++] = t[i];
	for (; j < p.n; j++) sum->t[k++] = p.t[j];
	sum->n = k;
	return *sum;

}

istream& operator>>(istream& is, Poly& p) {
	for (int i = 0; i < p.n; i++) {
		cout << "Term no " << i + 1 <<": ";
		cin >> p.t[i].coeff >> p.t[i].exp;
	}

	return is;

}

ostream& operator<<(ostream& os, Poly& p) {
	for (int i = 0; i < p.n; i++) {
		cout << p.t[i].coeff << "x" << p.t[i].exp << "+";
	}

	return os;
}

int main() {
	Poly p1(3), p2(2);
	cin >> p1;
	cin >> p2;
	Poly sum = p1 + p2;
	cout << sum;

	return 0;
}

