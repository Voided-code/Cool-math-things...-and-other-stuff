#pragma region Includes
#include <iostream>
#include <iomanip>
#include <string>
#include <string_view>
#include <sstream>

#include <vector>
#include <array>
#include <deque>
#include <list>
#include <forward_list>

#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

#include <stack>
#include <queue>

#include <utility>
#include <tuple>
#include <optional>
#include <variant>
#include <any>

#include <algorithm>
#include <numeric>
#include <functional>

#include <iterator>
#include <limits>
#include <cmath>
#include <cstdlib>
#include <cstdint>
#include <cstddef>

#include <memory>
#include <new>

#include <chrono>
#include <random>

#include <fstream>
#include <filesystem>

#include <bitset>
#include <climits>
#include <cassert>
#include <exception>
#include <stdexcept>
#include <type_traits>
#pragma endregion
using namespace std;

int main() {
    const int min = 2, lim = 10000;
    int tries = 1;
    auto start = std::chrono::high_resolution_clock::now();
    
    for (int a = min; a <= lim; ++a) {
        for (int b = a + 1; b <= lim; ++b) {
            if ((a & 1 && b & 1) ||
            (a % 3 != 0 && b % 3 != 0) ||
            (a % 4 != 0 && b % 4 != 0)) continue;

            long long c2 = a * a + b * b;
            long long c = sqrt(c2);

            if (c * c == c2) {
                printf("%d, %d, %d\n%d\n\n", a, b, c, tries);
            }

            ++tries;
        }
    }
    
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    
    cout << "Average time between tries: " << duration.count() / tries << 
    " nanoseconds\nTotal: " << duration.count() / pow(10, 6) << " miliseconds";
    

    return 0;
}