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
    long lim = 100;
    auto start = std::chrono::high_resolution_clock::now();

    for(int current = 2; current <= lim; ++current){
        bool prime = true;
        for(int i = 2; i <= sqrt(current); i++){
            if(current % i == 0){
                prime = false;
                break;
            }
        }
        if(prime){
            printf("%d\n", current);
        }
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    
    cout << "Average time between tries: " << duration.count() / lim << 
    " nanoseconds\nTotal: " << duration.count() / pow(10, 6) << " miliseconds";

    return 0;
}