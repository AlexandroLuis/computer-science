#include <iostream>

using namespace std;

int calc(int x) {
    return (x < 0)? x*-1 : x;
}
int main() {
    int x1, y1, x2, y2;
    while (1) {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        if (x1 == 0 && y1 == 0 && x2 == 0 && y2 == 0)
            break;
        else if (x1 == x2 && y1 == y2)
            cout << "0" << endl;
        else if (x1 == x2 || y1 == y2 || calc(x1-x2) == calc(y1-y2))
            cout << "1" << endl;
        else
            cout << "2" << endl;
    }
    return 0;
}