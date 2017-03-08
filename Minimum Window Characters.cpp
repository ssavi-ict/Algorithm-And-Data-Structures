#include<bits/stdc++.h>
#define DIST(x1,x2, y1, y2) (((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)))
#define DIST3D(x1,x2, y1, y2, z1, z2) (((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)) + ((z1-z2)*(z1-z2)))
#define CLR(a) a.clear()
#define VCLR(a, n) for(int i=0; i<=n+3; i++) a[i].clear()
#define SIZE(a) a.size()
#define ERASE(a, b) memset(a, b, sizeof a)
#define PB(a, b) a.push_back(b)
#define PB2(a,i,b) a[i].push_back(b)
#define LL long long
#define DBG cout<<"I Am Here"<<endl
#define DBGA(a) cout<<a<<endl
#define DBGI(b,a) cout<<b<<' '<<a<<endl
#define DBGL(i,s,e,b) or(int i=s; i<=e; i++) cout<<b<<endl
#define INF 1e9
#define INV 1e-6
#define sll(a) scanf("%I64d", &a)
#define pll(a) printf("%I64d\n", a)
#define si(a) scanf("%d", &a)
#define pii pair<int,int>
#define MAX 600005
#define CASE(i) printf("Case %d: ", i);
#define PI acos(-1)
#define piis pair<int, string>
#define fast1 ios_base::sync_with_stdio(false);
#define fast2 cin.tie(0)

using namespace std;

void solve(string str1, string str2, int n, int m) {

	int count1[256] = {};
	int count2[256] = {};
	int count = 0;
	int len = INT_MAX;
	int i = 0, j = 0, s = -1;

	for(int i = 0; i < m; i++) count2[str2[i]]++;

	for(int i = 0; i < n; i++) {
		/* skip the letter, not of our interest ;D */
		if(!count2[str1[i]]) continue;
		/* Increment character count */
		count1[str1[i]]++;
		/* increment overall encounterd character count */
		if(count1[str1[i]] <= count2[str1[i]]) count++;
		// If we have all the desired characters in the window
		if(count == m) {
			/* Move window start if start character is not of our interest, or
			 if its in excess than also move ahead and decrement its count */
			while(!count2[str1[j]] || count1[str1[j]] > count2[str1[j]]) {
				if (count1[str1[j]] > count2[str1[j]]) count1[str1[j]]--;
				j++;
			}
			// Check for optimal window length ;)
			if(i-j+1 < len) {
				len = i-j+1;
				s = j;
			}
		}
	}

	if(s == -1) cout << "No window possible";
	else for(int i = s; i < s+len; i++) cout << str1[i];
	cout << endl;
}

int main() {

	string str1 = "this is a test string";
	string str2 = "tist";
	solve(str1, str2, str1.length(), str2.length());
  	return 0;
}
