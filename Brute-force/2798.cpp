#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	int n, m;
	cin >> n >> m;
	vector<int> v;
	int sum = 0;

	for (int i=0; i<n; i++){
		int temp;
		cin >> temp;
		v.push_back(temp);
	}

	for (int i=0; i<n-2; i++){
		for (int j=i+1; j<n-1; j++){
			for (int k=j+1; k<n; k++){
				int s = v[i] + v[j] + v[k];
				if (s <= m && (m - sum > m - s))
					sum = s;
			}
		}
	}
	cout << sum << '\n';
	return (0);
}
