#include <bits/stdc++.h>
using namespace std;

#define N 1000000
#define INF 2000000001
typedef long long int lli;
typedef pair<lli, int> ii;

int n, m, S, D;
vector<ii> G[N];
lli dist[N];

void Input()
{
	ifstream fcin;
	fcin.open("input.txt");

	int i, v1, v2;
	lli w;
	fcin >> n >> m >> S >> D;

	for (i = 0; i < m; i++) {
		fcin >> v1 >> v2 >> w;
		G[v1].push_back(ii(w, v2));
		G[v2].push_back(ii(w, v1));
	}

	fcin.close();
}

void Solve()
{
	int i, v, vi;
	lli cost, dv;
	set<ii> djk;
	ii u;

	//initialize
	for (i = 0; i < N; i++)
		dist[i] = INF;
	dist[S] = 0;
	djk.insert(ii(0, S));

	//�������� ��������
	while (!djk.empty()) {

		u = *djk.begin();
		djk.erase(u);
		v = u.second; dv = u.first;

		for (i = 0; i < G[v].size(); i++) {
			vi = G[v][i].second;
			cost = G[v][i].first;
			if (dv + cost < dist[vi]) {
				if (dist[vi] != INF) {
					djk.erase(djk.find(ii(dist[vi], vi)));
				}

				dist[vi] = dv + cost;
				djk.insert(ii(dist[vi], vi));
			}
		}
	}
}

void Print()
{
	ofstream fcout;
	fcout.open("output.txt");

	fcout << dist[D] << endl;

	fcout.close();
}