#include<bits/stdc++.h>
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt","w",stdout)
using namespace std;


#define MAX_N 100000
int main(){
    input;
    int t;              
    cin>>t;
    for (int i=0; i<t; i++){
        int n,k;        
        cin>>n>>k;
        string s;       
        cin>>s;

        if(count(s.begin(),s.end(),'0')==n){
            cout<<n<<endl;
            continue;
        }

        int req;
        int last_zero=-1;

        int mn=-1;
        
        for(int i=0;i<=n-1;i++){
            if(last_zero==-1 && mn==-1){
                mn=s[i]-'0';
            }

            if(i==n-1 || s[i+1]<s[i]){
                if(last_zero==-1){
                    req=10-mn;
                    if(req<=k){
                        last_zero=i;
                        k-=req;
                    }
                }
                else{
                    req=10;
                    if(req<=k){
                        last_zero=i;
                        k-=req;
                    }   
                }
            }
        }

        for(int i=0;i<=last_zero;i++){
            s[i]='0';
        }

        int ans=0;

        for(int i =0; i<n;i++){
            if(s[i]!='0'){
                break;
            }
            
            ans++;
        }

        cout<<ans<<endl;

    }
    return 0;
}
