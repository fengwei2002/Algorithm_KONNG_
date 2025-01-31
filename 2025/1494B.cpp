// link: https://codeforces.com/contest/1494/problem/B -> B. Berland Crossword
// time: 2025/1/28 12:51:13 https://github.com/funcdfs

#pragma region github_funcdfs // clang-format off
#include <bits/stdc++.h>
using namespace std; /* golang types */
/* int  int8  int16   int32   int64  */ using int8 = signed char; using int16 = short; using int32 = int; using int64 = long long;
/* uint uint8 uint16  uint32  uint64 */ using uint8 = unsigned char; using uint16 = unsigned short; using uint32 = unsigned int; using uint64 = unsigned long long;
/* byte rune  float32 float64        */ using byte = unsigned char; using rune = int; using float32 = float; using float64 = double;
template <class T> istream &operator>> (istream &cin, vector<T>            &a)  { for (auto &x : a) { cin >> x; } return cin; }
template <class T> ostream &operator<< (ostream &cout, vector<T>           &a)  { int n = int(a.size()); if (!n) { return cout; } cout << a[0]; for (int i = 1; i < n; i++) { cout << ' ' << a[i]; } return cout; }
template <class T> istream &operator>> (istream &cin,  valarray<T>         &a)  { for (auto &x : a) { cin >> x; } return cin; }
template <class T> ostream &operator<< (ostream &cout, valarray<T>         &a)  { int n = int(a.size()); if (!n) { return cout; } cout << a[0]; for (int i = 1; i < n; i++) { cout << ' ' << a[i]; } return cout; }
template <class T> ostream &operator<< (ostream &cout, vector<vector<T>>   &a)  { int n = int(a.size()); if (!n) { return cout; } cout << a[0]; for (int i = 1; i < n; i++) { cout << '\n' << a[i]; } return cout; }
template <class T> ostream &operator<< (ostream &cout, vector<valarray<T>> &a)  { int n = int(a.size()); if (!n) { return cout; } cout << a[0]; for (int i = 1; i < n; i++) { cout << '\n' << a[i]; } return cout; }
struct __init_io { __init_io() { std::cout << fixed << setprecision(       15   ); cin.tie(nullptr); ios::sync_with_stdio(false);  }} __author_github_funcdfs; // Global instance of __init_io to apply I/O settings.
#define endl '\n'
void solve(); int32 main() { solve(); return 0; }
#ifdef LOCAL
#include <algo/dbg.h>
#else
#define dbg(...)      ;
#define eprint(...)   ;
#define eprintln(...)
#endif
template<class T1, class T2> bool Min(T1& a, const T2& b) { return b < a ? a = b, true : false; }
template<class T1, class T2> bool Max(T1& a, const T2& b) { return a < b ? a = b, true : false; }
#pragma endregion github_funcdfs   // clang-format on

// ----------------------------- /* Start of useful functions */ -----------------------------


void solve() {
   int tt = 0;
   cin >> tt;
   while (tt--) {
      int n = 0;
      cin >> n;
      int U, R, D, L;
      cin >> U >> R >> D >> L;
      // the size of the grid is n*n
      // U, R, D, L, represent the count of black point
      auto check = [&]() -> bool {
         for (int top_left = 0; top_left <= 1; top_left++) {
            for (int top_right = 0; top_right <= 1; top_right++) {
               for (int bottom_left = 0; bottom_left <= 1; bottom_left++) {
                  for (int bottom_right = 0; bottom_right <= 1; bottom_right++) {
                     int remaining_U = U - top_left - top_right;
                     int remaining_R = R - top_right - bottom_right;
                     int remaining_D = D - bottom_left - bottom_right;
                     int remaining_L = L - top_left - bottom_left;
                     if ((remaining_U >= 0 && remaining_U <= n - 2) &&
                         (remaining_R >= 0 && remaining_R <= n - 2) &&
                         (remaining_D >= 0 && remaining_D <= n - 2) &&
                         (remaining_L >= 0 && remaining_L <= n - 2)) {
                        return true;
                     }
                  }
               }
            }
         }
         return false;
      };

      if (check() == true) {
         println("YES");
      } else {
         println("NO");
      }
   }

   return;
}

// ----------------------------- /* End of useful functions */ -------------------------------
