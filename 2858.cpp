#include <iostream>
using namespace std;

int main(void)
{
	int r, b;
	int s;
	int l, w;

	cin >> r >> b;
	s = (r + 4) / 2;
	for (l=s-1; l>0; l--)
	{
		if ((l-2)*(s-l-2) == b)
			break;
	}
	cout << l << ' ' << s-l << '\n';
	return (0);
}
