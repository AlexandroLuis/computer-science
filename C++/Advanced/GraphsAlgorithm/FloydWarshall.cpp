#include <iostream>

using namespace std;

void FloydWarshall(int distancia[999][999], int a){
	for(int i = 0; i <= a; i++){
		for(int j = 0; j <= a; j++){
			for(int k = 0; k <= a; k++){
				if((distancia[j][i] + distancia[i][k]) < distancia[j][k])
                    distancia[j][k] = distancia[j][k] + distancia[i][k];
			}
		}
	}
}


int main(){
	int a, b, c;
	
	cin >> a >> b >> c;
	
	int Val[999][999], d, e;
	
    for(int i = 0; i <= a; i++){
        for(int j = 0; j <= a; j++){
            Val[i][j] = 999;
        }
    }
	
	for(int i = 0; i <= b; i++){
		cin >> d >> e;
		Val[d][e] = 1;
		Val[e][d] = 1;
	}
	
	FloydWarshall(Val, a);
	
	for(int i = 0; i < c; i++){
		cin >> a >> b;
		
		if((Val[a][b] == 999)||(Val[b][a] == 999))
			cout << "Deu ruim" << endl;
        else
            cout << "Lets que lets" << endl;
	}
	
	return 0;
}
