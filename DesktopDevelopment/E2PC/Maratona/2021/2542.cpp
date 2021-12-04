#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n;

    while(cin>>n){
        int m,l;
        cin >> m >> l;
        vector<int> M[m];
        vector<int> L[l];

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int a;
                cin>>a;
                M[i].push_back(a);
            }
        }

        for(int i=0;i<l;i++){
            for(int j=0;j<n;j++){
                int a;
                cin>>a;
                L[i].push_back(a);
            }
        }

        int xv,xy;
        cin >> xv >> xy;
        int a;
        cin >> a;
        long long s = M[xv-1][a-1];
        long long S = L[xy-1][a-1];

        if(s>S)
            cout << "Marcos" << endl;
        else if(s<S)
            cout << "Leonardo" << endl;
        else
            cout << "Empate" << endl;
    }
    return 0;
}