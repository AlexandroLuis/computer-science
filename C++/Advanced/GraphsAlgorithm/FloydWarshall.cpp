#include <iostream>

#define MAX 999
int Distancia[MAX][MAX];

using namespace std;

void FloydWarshall(int a){
	for(int i = 0; i <= a; i++){
		for(int j = 0; j <= a; j++){
			for(int k = 0; k <= a; k++){
				if((Distancia[j][i] + Distancia[i][k]) < Distancia[j][k])
                    Distancia[j][k] = Distancia[j][k] + Distancia[i][k];
			}
		}
	}
}

int main(){
	int a, b, c, d, e;
	
	cin >> a >> b >> c;
	
    for(int i = 0; i <= a; i++){
        for(int j = 0; j <= a; j++){
            Distancia[i][j] = MAX;
        }
    }
	
	for(int i = 0; i < b; i++){
		cin >> d >> e;
		Distancia[d][e] = 1;
		Distancia[e][d] = 1;
	}
	
	FloydWarshall(a);
	for(int i = 0; i < c; i++){
		cin >> a >> b;
		
		if((Distancia[a][b] == MAX)||(Distancia[b][a] == MAX))
			cout << "Deu ruim" << endl;
        else
            cout << "Lets que lets" << endl;
	}
	return 0;
}
