#include <iostream>
#include <set>

using namespace std;

bool is_close(double px, double py, double pz, double R, double eps = 1e-6) 
{
		double dist = px * px + py * py + pz * pz;
		return dist + eps < R * R;
}

int main() 
{
	double x0, y0, z0, R;
	cin >> x0 >> y0 >> z0 >> R;
	int n;
	cin >> n;
	set<pair<long long int, long long int>> aster;
	while (n>0) 
	{
		long long int uuid, ts;
		double x, y, z;
		cin >> uuid >> ts >> x >> y >> z;
		if (is_close(x0 - x, y0 - y, z0 - z, R))
			aster.insert({ts, uuid});
		n--;
	}
	set<long long> ids;
	for (auto i : aster) 
	{
		if (!ids.count(i.second)) 
		{
			cout << i.second << endl;
			ids.insert(i.second);
		}
	}
	return 0;
}