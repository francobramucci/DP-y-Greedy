#include <bits/stdc++.h>

using namespace std;

#define forr(i,a,b) for(int i = int(a); i < int(b); i++)
#define dfor(i,n) for(int i = n; i > 0; i--)
#define forn(i,n) forr(i,0,n)
#define endl '\n'
#define pb push_back
#define MAX 10000

using ll = long long;
using vi = vector<int>;
using ii = pair<int,int>;

int main(){
    int n;
    cout << "Ingrese el tamaño del tablero: "; cin >> n;

    int board[1000][1000] = {0};
    int sub[1000][1000] = {0};

    forn(i,n){
        forr(j,1,n+1){
            int w; cin >> w;
            board[i][j] = w;
            cout << board[i][j] << ' ';
        }
        cout << endl;
    }


    forn(i,n){
        forn(j,n+2){
            sub[i][j] = MAX;
        }
    }

    forr(i, 1, n+1){
        sub[0][i] = board[0][i];
    }

    // cout << endl << endl;
    
    // forn(i,n){
    //     forr(j,1,n+1){
    //         cout << sub[i][j] << ' ';
    //     }
    //     cout << endl;
    // }


    forr(i, 1, n){
        forr(j,1,n+1){
            sub[i][j] = board[i][j] + min(sub[i-1][j], min(sub[i-1][j+1], sub[i-1][j-1]));
        }
    }

    cout << endl << endl;

    forn(i,n){
        forr(j,1,n+1){
            cout << sub[i][j] << ' ';
        }
        cout << endl;
    }


    int minimo = MAX;

    forr(j,1,n+1){
        minimo = min(minimo, sub[n-1][j]);
        
    }
    cout << "El costo del camino mas corto es: " << minimo << "!!" << endl;
}