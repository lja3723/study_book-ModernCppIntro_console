#include <iostream>
using std::cout; using std::endl;
using std::ostream;

class CoinMoney {
public:
	CoinMoney() : c50(0), c100(0), c500(0)
	{}
	CoinMoney(int c, int cc, int ccc) : c50(c), c100(cc), c500(ccc)
	{}
	virtual ~CoinMoney()
	{}

	explicit operator int() const
	{
		return (50 * c50 + 100 * c100 + 500 * c500);
	}

	/*int get_value() const
	{
		return (50 * c50 + 100 * c100 + 500 * c500);
	}

	void print() const
	{
		cout << "50�� "
			<< c50 << "��, 100�� "
			<< c100 << "��, 500�� "
			<< c500 << "��, �� "
			<< get_value() << "��" << endl;
	}*/

	//getters
	int get_c50() const { return c50; }
	int get_c100() const { return c100; }
	int get_c500() const { return c500; }
	//setters
	void set_c50(int c) { c50 = c; }
	void set_c100(int c) { c100 = c; }
	void set_c500(int c) { c500 = c; }

protected:
	int c50;
	int c100;
	int c500;
};

//global function
CoinMoney add(const CoinMoney& m1, const CoinMoney& m2)
{
	CoinMoney sum;
	sum.set_c50(m1.get_c50() + m2.get_c50());
	sum.set_c100(m1.get_c100() + m2.get_c100());
	sum.set_c500(m1.get_c500() + m2.get_c500());
	return sum;
}

ostream& operator<<(ostream& os, const CoinMoney& m)
{
	os << "50�� "
		<< m.get_c50() << "��, 100�� "
		<< m.get_c100() << "��, 500�� "
		<< m.get_c500() << "��, �� "
		<< int(m) << "��" << endl;
	return os;
}

int main()
{
	CoinMoney m1(1, 2, 3);
	CoinMoney m2{ 2, 3, 4 };
	cout << "m1 = " << m1;
	cout << "m2 = " << m2;
	int value = int(m2);
	cout << "m2�� �� " << value << "��" << endl;
	return 0;
}