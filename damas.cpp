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

    cout <<  "\nIngrese el valor de cada celda: \n";
    forn(i,n){
        forr(j,1,n+1){
            int w; cin >> w;
            board[i][j] = w;
            cout << board[i][j] << ' ';
        }
        cout << endl;
    }

    /*
    *   Inicializamos nuestro array "sub" con valores máximo para los casos de las columnas
    *   más a la izquierda y más a la derecha. También agregamos los valores de las celdas finales
    */
    memset(sub, MAX, sizeof(sub));

    forr(i, 1, n+1){
        sub[0][i] = board[0][i];
    }

    /*
    *   En este bucle for anidado resolvemos el problema, partiendo del subproblema de estar en una
    *   celda anterior a la final y utilizando dicho resultado para calcular la de las celdas subsiguientes.
    *   De esta forma guardamos el menor costo acumulado para llegar a una de las casillas del final
    *   y en cada mínimo estamos eligiendo el mejor camino de cada casilla hasta el final.
    */
    forr(i, 1, n){
        forr(j,1,n+1){
            int mini = min({sub[i-1][j], sub[i-1][j+1], sub[i-1][j-1]});
            sub[i][j] = board[i][j] + mini;
        }
    }

    cout << endl << endl;

    forn(i,n){
        forr(j,1,n+1){
            cout << sub[i][j] << ' ';
        }
        cout << endl;
    }

    /*
    *   Ahora solamente nos queda saber cúal casilla del inicio es la que tiene el menor costo acumulado
    *   hasta llegar al final
    */
    int minimo = MAX;
    vector<ii> path;
    ii aux;

    forr(j,1,n+1){
        if(sub[n-1][j] < minimo){
            minimo = sub[n-1][j];
            aux = {n,j};
        }
    }
    
    path.pb(aux);

    cout << endl << "El costo del camino mas corto es: " << minimo << "!!" << endl;
    
    /*
    *   Para calcular qué celdas componen el camino de menor costo aplicamos backtracking a partir de la
    *   celda del inicio con menor costo acumulado.
    */
    int mini = MAX;
    int col = path[0].second;

    for(int i = n-1; i > 0; i--){
        mini = min({sub[i-1][col], sub[i-1][col+1], sub[i-1][col-1]});

        if(mini == sub[i-1][col]) col;
        else if(mini == sub[i-1][col-1]) col--;
        else if(mini == sub[i-1][col+1]) col++;
        path.pb({i, col});
    }

    cout << endl << "El camino más corto es: " << endl;
    forn(i, path.size()){
        cout << path[i].first << ", " << path[i].second << endl;
    }

}