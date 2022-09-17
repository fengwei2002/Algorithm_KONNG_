// Problem: 方格取数
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/description/1029/
// date: 2022-07-22 11:42:05
// Memory Limit: 64 MB
// Time Limit: 1000 ms


/* https://github.com/fengwei2002/algorithm */
// for dbg:
// #define d(a)  // cout << #a << " = " << a << ' ';
// #define dline // cout << " ----- " << endl;
// #define dendl // cout << " | \n";
#define d(a)  cout << #a << " = " << a << ' ';
#define dline cout << " ----- " << endl;
#define dendl cout << " | \n";

#define INF 0x3f3f3f3f
#define LL long long
#define PII pair<int, int>

#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>
#include <unordered_map>
#include <vector>

using namespace std;

const int N = 15; 
int g[N][N]; 
int f[N+N][N][N]; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n = 0; 
    cin >> n; 
    int a, b, c; 
    while (cin >> a >> b >> c, a || b || c) {
    	g[a][b] = c; 
    }
    
    for (int k = 2; k <= n + n; k++) {
    	for (int i1 = 1; i1 <= n; i1++) {
    		for (int i2 = 1; i2 <= n; i2++) {
    			int j1 = k - i1; 
    			int j2 = k - i2; 
    			
    			if (j1 >= 1 && j1 <= n && j2 >= 1 && j2 <= n) {
    				int t = g[i1][j1]; 
    				if (j1 != j2) {
    					t += g[i2][j2]; 
    				} 
    				
    				int &x = f[k][i1][i2]; 
    				x = max(x, f[k - 1][i1 - 1][i2 - 1]); 
    				x = max(x, f[k - 1][i1][i2 - 1]); 
    				x = max(x, f[k - 1][i1 - 1][i2]); 
    				x = max(x, f[k - 1][i1][i2]); 
    				
    				x += t; 
    			}
    		}
    	}
    }
    
    cout << f[n+n][n][n] << endl; 
    
    return 0;
}