#include <iostream>
#include <queue>
#include <utility>
#include <set>

using namespace std;

int main() {
    int x, y, z, w;

    cin >> x >> y >> z;
    cout << endl;
    while (x != 0 && y!= 0 && z != 0) {
        set <int> bloqueados;

        for (int i = 0; i < z; i++) {
            cin >> w;
            bloqueados.insert(w);
        }
        int vis[400000];
        int ans = 0;
        queue <pair<int, int>> q;
        q.push(make_pair(x, 0));

        while (!q.empty() && q.front().first!= y) {
            int u = q.front().first;
            int ul = q.front().second;
            q.pop();
            if (vis[u] == 1 || bloqueados.count(u))
                continue;
            vis[u] = 1;

            if (u > 0 && u <= 100000){
                q.push(make_pair(u + 1, ul + 1));
                if (u > 0)
                    q.push(make_pair(u - 1, ul + 1));
                if (u % 2 == 0)
                    q.push(make_pair(u / 2, ul + 1));
                if (u != 55000) {
                    q.push(make_pair(u * 2, ul + 1));
                    q.push(make_pair(u * 3, ul + 1));
                }
            }
        }
        if (!q.empty() && q.front().first == y)
            cout << q.front().second << endl;
        else
            cout << "-1" << endl;
        
        cin >> x >> y >> z;
    }
    return 0;
}
