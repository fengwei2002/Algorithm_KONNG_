// link: https://codeforces.com/problemset/problem/6/A A. Triangle
// time: 2024/8/6 00:47:46 https://github.com/funcdfs

#pragma region github_funcdfs // clang-format off
#include <bits/stdc++.h> 
/* using golang types */ using namespace std; using int32 = signed; using uint32 = unsigned; using float32 = double; using int64 = long long; using uint64 = unsigned long long; using float64 = long double; 
/* vec<(any)> cincout */ template <class T> istream &operator>> (istream &cin,  vector<T> &a)  { for (auto &x : a) { cin >> x; } return cin; }
template <class T> ostream &operator<< (ostream &cout, vector<T>           &a)  { int n = int(a.size()); if (!n) { return cout; } cout << a[0]; for (int i = 1; i < n; i++) { cout << ' ' << a[i]; } return cout; }
template <class T> istream &operator>> (istream &cin,  valarray<T>         &a)  { for (auto &x : a) { cin >> x; } return cin; }
template <class T> ostream &operator<< (ostream &cout, valarray<T>         &a)  { int n = int(a.size()); if (!n) { return cout; } cout << a[0]; for (int i = 1; i < n; i++) { cout << ' ' << a[i]; } return cout; }
template <class T> ostream &operator<< (ostream &cout, vector<vector<T>>   &a)  { int n = int(a.size()); if (!n) { return cout; } cout << a[0]; for (int i = 1; i < n; i++) { cout << '\n' << a[i]; } return cout; }
template <class T> ostream &operator<< (ostream &cout, vector<valarray<T>> &a)  { int n = int(a.size()); if (!n) { return cout; } cout << a[0]; for (int i = 1; i < n; i++) { cout << '\n' << a[i]; } return cout; }
#define endl '\n'    /* Use '\n' instead of std::endl to avoid unnecessary buffer flushes for performance */ 
#define print(...)   cout << format(__VA_ARGS__)           /* the format string is printed to the standard output */ 
#define println(...) cout << format("{0}\n", __VA_ARGS__); /* to print a single value and append a newline */
struct _init_end { _init_end() { cout << fixed << setprecision(      15      /* float output precision */);  { cin.tie(nullptr); ios::sync_with_stdio(false); }}} __author_github_funcdfs; 

#ifdef LOCAL /* For local debugging purposes */ 
#include "algo/dbg.h"
#else
#define dbg(...)      ;
#define eprint(...)   ;
#define eprintln(...) ;
#endif

auto solve() -> void; /* main --> */ int32 main() { solve(); return 0; }
#pragma endregion github_funcdfs   // clang-format on

// ----------------------------- /* Start of useful functions */ -----------------------------


auto solve() -> void {
   
   vector<int> a(4, 0);
   cin >> a;

   ranges::sort(a);
   if (a[0]+a[1]>a[2] || a[1]+a[2]>a[3]) {
      // C_4^3 == C_4^1 == 4
      // 如果第一根木棍和第二根木棍的总长大于第四根，那么就一定大于第三根，
      // 所以只要判断第一根木棍和第二根木棍的总长与第三根的关系。
      // 同理，如果第一根木棍和第三根木棍的总长大于第四根，那么第二根木棍和第三根木棍的总长也一定大于第四根，
      // 所以只要判断第二根木棍和第三根木棍的总长与第四根的关系。
      println("TRIANGLE");
   } else if (a[0]+a[1]==a[2] || a[1]+a[2]==a[3]) {
      println("SEGMENT");
   } else {
      println("IMPOSSIBLE");
   }
   
   return;
}

// ----------------------------- /* End of useful functions */ -------------------------------
