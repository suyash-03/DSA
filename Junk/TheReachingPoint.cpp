// bool solve(vector <vector <int>> matrix, int x1-1, int y1-1, int x2-1, int y2-1, int &k) {
// 	if (x2<0 or x2>=n) return false;
// 	if (y2<0 or y2>=m) return false;
// 	if (matrix[x1][y1]%matrix[x2][y2]==0) return true;

// 	if (k>1) {
// 		k--;
// 		return (solve(matrix, x1, y1, x2-1, y2, k) or solve(matrix, x1, y1, x2+1, y2, k) or solve(matrix, x1, y1, x2, y2-1, k) or solve(matrix, x1, y1, x2, y2+1, k));
// 	}

// 	return false;
// }

#include <bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
#define int long long int
#define pb emplace_back 
#define run ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);cerr.tie(0);


#define mod 1000000007
int exp(int x,int y){int res=1;x=x%mod;while(y>0){if(y&1)res=(res*x)%mod;y=y>>1;x=(x*x)%mod;}return res;}
int modinv(int x){return exp(x,mod-2);}
int add(int a,int b){a%=mod,b%=mod;a=((a+b)%mod+mod)%mod;return a;}
int sub(int a,int b){a%=mod,b%=mod;a=((a-b)%mod+mod)%mod;return a;}
int mul(int a,int b){a%=mod,b%=mod;a=((a*b)%mod+mod)%mod;return a;}

vector<int> pp;
void printNSE(vector<int> arr, int n)
{
stack<pair<int, int>> s;
vector<int> ans(n);

for (int i = 0; i < n; i++)
{
  int next = arr[i];

  if (s.empty())
  {
    s.push({next, i});
    continue;
  }

  while (!s.empty() && s.top().first > next)
  {
    ans[s.top().second] = i;
    s.pop();
  }

  s.push({next, i});
}

while (!s.empty())
{
  ans[s.top().second] = -1;
  s.pop();
}

for (int i = 0; i < n; i++)
{
  pp.push_back(ans[i]);
}
}

signed main()
{

run;

int n, i, x, ans = -1;

cin >> n;

vector<int> a(n, 0), v;

for (i = 0; i < n; i++)
  cin >> a[i];

printNSE(a, n);
vector<int> pp1(n);
for (int i = 0; i < n; i++)
{
  pp1[i] = pp[i];
  if (pp[i] != -1)
    pp[i] = n - (pp[i] - i);

  ans = max(ans, pp[i]);
}

if (ans == -1)
{
  cout << 0 << endl;
  return 0;
}
int ans1 = 0;
for (i = 0; i < n; i++)
{
  if (pp[i] == ans)
  {
    ans1 = max(ans1, -a[pp1[i]] + a[i]);
  }
}
int oo = 1e8;
x = mul(ans1, exp(oo, ans));
cout << x << endl;
}