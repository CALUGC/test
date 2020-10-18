#include<bits/stdc++.h>
using namespace std;
#define ll long long 
struct mas{
	ll data[2][2];
	mas(ll a=0,ll b=0,ll c=0,ll d=0){
		data[0][0]=a,data[0][1]=b,data[1][0]=c,data[1][1]=d;
	}
};
mas mul(mas a,mas b){
	mas tmp;
	for(ll i=0;i<2;i++){
		for(ll j=0;j<2;j++){
			for(ll k=0;k<2;k++){
				tmp.data[i][j]+=a.data[i][k]*b.data[k][j];
			}
		}
	}
	return tmp;
}
mas poww(mas a,ll n){
	if(n==1)return a;
	mas tmp=poww(a,n/2);
	tmp=mul(tmp,tmp);
	if(n&1)return mul(tmp,a);
	return tmp;
}
int main(){
	ll n;
	mas base(1,1,1,0);
	while(cin>>n){
		mas ans=poww(base,n);
		cout<<ans.data[1][0]<<"\n";
	}
}