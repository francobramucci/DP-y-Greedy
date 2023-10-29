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

int main()
{
    int penalty[1000], dead_line[1000];
    int maximum_penalty=0, total_penalty, n, temp;
    map<ii, int> pos;

    cout<<"Ingresar cantidad de tareas: ";
    cin>>n;

    forn(i,n){
        cin >> penalty[i] >> dead_line[i];
        total_penalty += penalty[i];
        pos[{penalty[i], dead_line[i]}] = i;
    }

    int scheduler[n];

    bool box[n];
    memset(box, false, sizeof(box));

    /*
    *   Ordenamos todas las tareas según su penalidad en orden decreciente
    */

    forn(i,n){
        for(int j=i+1; j<n; j++){

            if(penalty[i] < penalty[j]){

                temp = penalty[i];
                penalty[i] = penalty[j];
                penalty[j] = temp;

                temp = dead_line[i];
                dead_line[i] = dead_line[j];
                dead_line[j] = temp;

            }
        }
    }

    //   cout<<"After Sorting"<<endl;
    //    for(int i=0; i<n; i++){
    //       cout<<penalty[i]<<" "<<dead_line[i]<<endl;
    //    }
    //    cout<<endl<<endl;

    for(int i=0; i<n; i++){
        for(int j=min(n,dead_line[i]); j>=1; j--){
            if(box[j]==false){
                box[j]=true;
                scheduler[j] = pos[{penalty[i], dead_line[i]}];
                maximum_penalty += penalty[i];
                break;
            }
            
        }
    }
    
    int final_penalty = total_penalty - maximum_penalty;
    
    cout << endl <<"Penalidad final: "<< final_penalty << endl;
    
    cout << "El scheduler que minimiza la penalidad es: " << endl;
    
    forr(i,1,n){
        cout << scheduler[i] << endl;
    }
    
    return 0;
}