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
     int penalty[10], dead_line[10];
     int maximum_penalty=0,n,temp;
     
     cout<<"Ingresar cantidad de casos: "<<endl;
     
     cin>>n;

     bool box[n];
     
     forn(i,n){
        cin>>penalty[i]>>dead_line[i];
     }

     for(int i=0; i<n-1; i++){
       for(int j=i+1; j<n; j++)

        if(penalty[i]<penalty[j]){
 
            temp = penalty[i];
            penalty[i] = penalty[j];
            penalty[j] = temp;

            temp = dead_line[i];
            dead_line[i] = dead_line[j];
            dead_line[j] = temp;

         }
     }

      cout<<"After Sorting"<<endl;
       for(int i=0; i<n; i++){
          cout<<penalty[i]<<" "<<dead_line[i]<<endl;
       }
       cout<<endl<<endl;
       memset(box,false,sizeof(box));
        for(int i=0; i<n; i++){
            for(int j=min(n,dead_line[i])-1; j>=0; j--){
                if(box[j]==false){
                      box[j]=true;
                maximum_penalty +=penalty[i];
                  break;
                }
            }
        }
        cout<<"Maximum penalty: "<<maximum_penalty<<endl;
    return 0;
}