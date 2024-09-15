// link: https://codeforces.com/contest/510/problem/A A. Fox And Snake
// time: 2024/9/14 22:12:19 https://github.com/funcdfs

// #region main
package main; import ( "bufio"; "fmt"; "os"; ); var _in, _out = new(bufio.Reader), new(bufio.Writer)
func _github_funcdfs[T any](sep, end string, arr ...T) { for idx := range arr { fmt.Fprint(_out, arr[idx]); if idx == len(arr)-1 { fmt.Fprint(_out, end); } else { fmt.Fprint(_out, sep) } } }
func main() { _in = bufio.NewReader(os.Stdin); _out = bufio.NewWriter(os.Stdout); defer _out.Flush(); solve() }
func input      [T any] ()           T { var value T; fmt.Fscan(_in, &value); return value }
func inputSlice [T any] (size int) []T { data := make([]T, size); for idx := 0; idx < size; idx++ { data[idx] = input[T](); }; return data }
func print      [T any] (arr ...T)     { _github_funcdfs("", "", arr...) }
func println    [T any] (arr ...T)     { _github_funcdfs(" ", "\n", arr...) }
// #endregion main


// ----------------------------- /* Start of useful functions */ -----------------------------

func solve() {

	n, m := input[int](), input[int]()
	
	flag := false
	for i := 0; i < n; i++ {
		if i % 2 == 0 {
			for i := 0; i < m; i++ {
				print("#")
			}
			println("")
		} else {
			if flag {
				print("#")
				for i := 1; i < m; i++ {
					print(".")
				}
				println("")
			} else {
				for i := 1; i < m; i++ {
					print(".")
				}
				print("#")
				println("")
			}
			flag = !flag
		}
	}

}

// ----------------------------- /* End of useful functions */ -------------------------------