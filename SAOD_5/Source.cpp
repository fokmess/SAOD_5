#include <iostream> 
#include <vector>
#include <algorithm>
using namespace std;

struct edge
{
	int x, y, w;
	edge() {}
	edge(int w, int x, int y) {
	
		this->w = w;
		this->x = x;
		this->y = y;
	}

};
struct PointCmp {
	bool operator () (const edge& a, const edge& b) const {
		return a.w < b.w;
	}
};

int main() {

	vector <edge> q;

	bool bund[5] = { false };
	
	q.push_back(edge(6, 4, 3));
	q.push_back(edge(7,0,3));
	q.push_back(edge(8,4,0));
	q.push_back(edge(9,0,2));
	q.push_back(edge(11,0,1));  
	q.push_back(edge(12,2,3));
	q.push_back(edge(13,4,1));
	q.push_back(edge(14,4,1));
	q.push_back(edge(14,4,2));
	q.push_back(edge(15,1,2));

	sort(q.begin(), q.end(), PointCmp());

	for (int i = 0; i < q.size(); i++)
	{
		if (!(bund[q[i].x] && bund[q[i].y])) {

			cout << q[i].x+1 << "-" << q[i].y+1 << ": " << q[i].w << endl;

			bund[q[i].y] = bund[q[i].x] = true;
		}
	}

	return 0;
 }