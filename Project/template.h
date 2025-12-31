#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

#define LOCAL
// ANSI color codes
#define RESET "\033[0m"
#define BOLD "\033[1m"

#define BLACK "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"

#define BRIGHT_BLACK "\033[90m" // Gray
#define BRIGHT_RED "\033[91m"
#define BRIGHT_GREEN "\033[92m"
#define BRIGHT_YELLOW "\033[93m"
#define BRIGHT_BLUE "\033[94m"
#define BRIGHT_MAGENTA "\033[95m"
#define BRIGHT_CYAN "\033[96m"
#define BRIGHT_WHITE "\033[97m"

#define BG_RED "\033[41m"
#define BG_GREEN "\033[42m"
#define BG_YELLOW "\033[43m"
#define BG_BLUE "\033[44m"
#define BG_MAGENTA "\033[45m"
#define BG_CYAN "\033[46m"
#define BG_WHITE "\033[47m"

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using ll = long long;
using ull = unsigned long long;
using pair_iint = pair<int, int>;
using pair_ll = pair<long long, long long>;

using vec_int = vector<int>;
using vec_ll = vector<long long>;
using vec_str = vector<string>;
using vec_char = vector<char>;
using vec_bool = vector<bool>;

using vec_int_2d = vector<vector<int>>;
using vec_ll_2d = vector<vector<long long>>;
using vec_char_2d = vector<vector<char>>;
using vec_2d_pair_iint = vector<vector<pair_iint>>;

using list_int = list<int>;
using list_char = list<char>;
using list_ll = list<long long>;
using list_str = list<string>;

using deq_int = deque<int>;
using deq_ll = deque<long long>;
using deq_str = deque<string>;

using stk_int = stack<int>;
using stk_ll = stack<long long>;

using que_int = queue<int>;
using que_char = queue<char>;
using que_str = queue<string>;
using que_ll = queue<long long>;

using pque_max = priority_queue<int>;
using pque_min = priority_queue<int, vector<int>, greater<int>>;

using pque_ll_max = priority_queue<long long>;
using pque_ll_min = priority_queue<long long, vector<long long>, greater<long long>>;

using set_int = set<int>;
using set_ll = set<long long>;
using set_char = set<char>;
using set_str = set<string>;

using mset_int = multiset<int>;
using mset_ll = multiset<long long>;

using uset_int = unordered_set<int>;
using uset_ll = unordered_set<long long>;
using uset_str = unordered_set<string>;

using map_int = map<int, int>;
using map_ll = map<long long, long long>;
using map_int_str = map<int, string>;
using map_str_int = map<string, int>;

using map_int = map<int, int>;
using map_ll = map<long long, long long>;
using map_int_str = map<int, string>;
using map_str_int = map<string, int>;

using vec_pair_int = vector<pair<int, int>>;
using vec_pair_ll = vector<pair<long long, long long>>;

using map_pair = map<int, pair<int, int>>;
using umap_pair = unordered_map<int, pair<int, int>>;

#ifdef LOCAL
#define debug(x) cerr << #x << " = " << x << endl
#else
#define debug(x)
#endif

// --- Fast I/O and helpers
static inline void fast_io()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

template <class T>
T findMax(T a, T b)
{
    return (a > b) ? a : b;
}

template <class T>
void print(T val, bool allow)
{
    if (allow)
        cout << val << endl;
}