#include<bits/stdc++.h>
using namespace std;
#define hi ios_base::sync_with_stdio;cin.tie(NULL);cin.tie(NULL);
typedef long long int ll;
typedef long double ld;
typedef long long unsigned llu;
#define test				int test; cin>>test; while(test--)
#define loop(i,n,k) 		for(int i=n;i<k;i++)
#define rloop(i,n,k) 		for(int i=n;i>=k;i--)
#define INT(a) 				int a;scanf("%d",&a);
#define intin(temp)			scanf("%d",&temp);
#define longin(temp)		scanf("%lld",&temp);
#define LLI(a) 				ll a;scanf("%lld",&a);
#define DOUBLE(a) 			double a;scanf("%f",&a);
#define LD(a) 				long double a;scanf("%lf",&a);
#define pb(i) 				push_back(i)
#define sz(i) 				i.size()
#define mkp(i,j)			make_pair(i,j)
#define ip 					pair<int,int>
#define dp					pair<ll,ll>
#define FOR(i,n)			for(i=0;i<n;i++)
#define range(v)			v.begin(),v.end()
#define bye					return 0;
#define file				freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

template<class c>
c gcd (c a,c b){
	if(b==0)
		return a;
	gcd(b,a%b);
}template<class a>
bool prime(a n){
	for(a i=2;i<=sqrt(n);i++){
		if(n%i==0)
			return 0;
	}
	return 1;
}
bool bigger(pair<int,int>picachu,pair<int,int> qicachu){
	return (picachu.first<qicachu.first);
}void printarr(int arr[],int n){
	for(int i=0;i<n;i++)
		cout<<arr[i]<<' ';
	cout<<endl;
}
int chartoint(char c) {
    if (c >= 'a' && c <= 'z') return c - 'a';
    if (c >= 'A' && c <= 'Z') return c - 'A' + 26;
    return 52;
}
int kadane(int arr[],int n){
	int maximum= arr[0];
	int max_so_far = 0;
	for(int i=0;i<n;i++){
		max_so_far+=arr[i];
		if(max_so_far>maximum)
			maximum = max_so_far;
		if(max_so_far<0)
			max_so_far = 0;
	}
	return maximum;
}
template<class c>
c lcm(c a ,c b){
	c g = gcd(a,b);
	a/=g;
	b/=g;
	return (a*b*g);
}
void run(){	
	//take inputs here
	int n,m,g;
	cin >> n >> m >> g;
	vector<int> t(n);// for time vector
	vector<int> c(m);//for clothes
	for(auto &i:t)
		cin >> i;
	for(auto &i:c)
		cin >> i;
	/*here g is just for confusion we can take max clothes in a single time we have to see max time duration diffrence at which that time we see all now at previos rain from that we add the time with that and after the next rain the max diff of no rain max clothes will get dry and we pick all of them and left rest as they will never get dry as the max sun the can fell in this time duration you can imagine that*/
	vector<pair<int,int>> ans(n);
	loop(i,1,n){
		ans[i].first  = t[i]-t[i-1];//the time interval between rains
		ans[i].second = i;
	}
	//here we sort for the max time interval;
	sort(ans.begin()+1,ans.end());
	int ind = ans[n-1].second;
	//now count all dry means all the clothes whose time value ai is less than equal to current rait time
	int count  = 0;
	loop(i,0,m){
		if(c[i]<=t[ind]){
			count++;
		}
	}
	cout << count << endl;
}
int main(){
	hi;
	#ifndef ONLINE_JUDGE 
   	freopen("input.txt", "r", stdin); 
  	freopen("error.txt", "w", stderr); 
  	freopen("output.txt", "w", stdout); 
   	#endif 
   
  
   	{ 
      	run(); 
   	}
  	cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl; 
 	bye;
}
