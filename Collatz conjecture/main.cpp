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
    long long totalTime = 0, stepTime = 0, nanosecond = pow(10, 9), current = 2, heighestSteps = 0, heighestNumber = 0, heighestTime = 0;
    
    while (true) {
        int n = current, steps = 0;
        auto start = std::chrono::high_resolution_clock::now();
        
        while (n > 1){
            ++steps;
            
            if(n % 2 == 0){
                n /= 2;
            } else {
                n = n * 3 + 1;
            }
        }
        
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
        stepTime += duration.count();
        totalTime += duration.count();
        
        if(steps > heighestSteps){
            heighestSteps = steps;
            heighestNumber = current;
        }
        
        if(duration.count() > heighestTime){
            heighestTime = duration.count();
        }

        if(stepTime > 0.25 * nanosecond){
            system("cls");
            cout << "Heighest: " << heighestNumber << " with " << heighestSteps << " steps\n" << 
            "Heighest time: " << heighestTime << " nanoseconds\n" <<
            "Current No.: " << current << " with " << steps << " steps\n" << 
            "Time taken: " << duration.count() << " nanoseconds\n" << 
            "Avg time: " << totalTime / current << " nanoseconds\n";
            
            stepTime = 0;
        }
        ++current;
    }
    
    return 0;
}