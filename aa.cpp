#include<bits/stdc++.h>
using namespace std;

vector<vector<int> >g;
int n;
unordered_set<int> m;
int cnt=0;
void dfs(int cn,int pn){

    if(m.find(cn)==m.end()){
        if(pn!=0 && m.find(pn)==m.end()){
            m.insert(pn);
            m.insert(cn);
            cnt++;
        }
    }
    for(auto nei :g[cn]){
        if(nei!=pn){
            dfs(nei,cn);
        }
    }
}
void solve(){
    cin>>n;
    g.resize(n+1);
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);

    }
    dfs(1,0);
    cout<<cnt<<endl;
}


int main(){
    solve();
return 0;}