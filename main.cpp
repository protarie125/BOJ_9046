#include <algorithm>
#include <bit>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <ranges>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = int64_t;
using vl = vector<ll>;

ll T;
string s;

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  cin >> T;
  cin.ignore();
  while (0 < (T--)) {
    getline(cin, s);

    vl cts(26, 0);
    for (const auto& x : s) {
      if ('a' <= x && x <= 'z') {
        cts[x - 'a'] += 1;
      }
    }

    ll mx = -1;
    vector<char> mxc{};
    for (auto i = 0; i < 26; ++i) {
      if (cts[i] > mx) {
        mx = cts[i];
        mxc = {static_cast<char>(i + 'a')};
      } else if (cts[i] == mx) {
        mxc.push_back(i + 'a');
      }
    }

    if (mxc.size() != 1) {
      cout << "?\n";
    } else {
      cout << mxc[0] << '\n';
    }
  }

  return 0;
}