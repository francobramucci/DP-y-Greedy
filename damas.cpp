#include <bits/stdc++.h>

using namespace std;

#define forr(i,a,b) for(int i = int(a); i < int(b); i++)
#define dfor(i,n) for(int i = n; i > 0; i--)
#define forn(i,n) forr(i,0,n)
#define endl '\n'
#define pb push_back

using ll = long long;
using vi = vector<int>;
using ii = pair<int,int>;


int main(){
    int n;
    cout << "Ingrese el tamaño del tablero: "; cin >> n;

    vector<vi> board(n);
    vector<vi> sub(n);

    forn(i,n){
        forn(j,n){
            int w; cin >> w;
            board[i].push_back(w);
            cout << board[i][j] << ' ';
        }
        cout << endl;
    }

    forn(i,n){
        sub[0].push_back(board[0][i]);
    }

}