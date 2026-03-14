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

void printBoard (vector<vector<int>> inp) {
    // for (int i = 0; i < 8; i++) {
    //     for (int j = 0; j < 8; j++) {
    //         if(inp[i][j] == 11){
    //             cerr << "♙ ";
    //         } else if(inp[i][j] == 10){
    //             cerr << "♟ ";
    //         } else if(inp[i][j] == 21){
    //             cerr << "♖ ";
    //         } else if(inp[i][j] == 20){
    //             cerr << "♜ ";
    //         } else if(inp[i][j] == 31){
    //             cerr << "♘ ";
    //         } else if(inp[i][j] == 30){
    //             cerr << "♞ ";
    //         } else if(inp[i][j] == 41){
    //             cerr << "♗ ";
    //         } else if(inp[i][j] == 40){
    //             cerr << "♝ ";
    //         } else if(inp[i][j] == 51){
    //             cerr << "♕ ";
    //         } else if(inp[i][j] == 50){
    //             cerr << "♛ ";
    //         } else if(inp[i][j] == 61){
    //             cerr << "♔ ";
    //         } else if(inp[i][j] == 60){
    //             cerr << "♚ ";
    //         } else {
    //             cerr << "  ";
    //         }
            
    //     }
    //     cerr << endl;
    // }
    // cerr << "\n----------------\n\n";
}

void testPosition (vector<vector<vector<int>>> boards) {
	vector<vector<int>> offload;
	
	for (int i = 0; i < 8; i++) {
	    for (int j = 0; j < 8; j++) {
	        
	        // black forward
	        if (boards[0][i][j] == 11 && boards[0][i + 1][j] == 00) {
	            offload = boards[0];
	            offload[i + 1][j] = offload[i][j];
	            offload[i][j] = 0;
	            printBoard(offload);
	            boards.push_back(offload);

	            if(boards[0][1][j] == 11){
	                offload = boards[0];
	                offload[i + 2][j] = offload[i][j];
	                offload[i][j] = 0;
	                printBoard(offload);
	                boards.push_back(offload);
	            }
	        } 
	        
	        // white forward
	        if (boards[0][i][j] == 10 && boards[0][i - 1][j] == 00) {
	            offload = boards[0];
	            offload[i - 1][j] = offload[i][j];
	            offload[i][j] = 0;
	            printBoard(offload);
	            boards.push_back(offload);

	            if(boards[0][6][j] == 10){
	                offload = boards[0];
	                offload[i - 2][j] = offload[i][j];
	                offload[i][j] = 0;
	                printBoard(offload);
	                boards.push_back(offload);
	            }
	        }
	        
	        // black take left
	        if (boards[0][i][j] == 11 && boards[0][i + 1][j - 1] != 00) {
	            offload = boards[0];
	            offload[i + 1][j - 1] = offload[i][j];
	            offload[i][j] = 0;
	            printBoard(offload);
	            boards.push_back(offload);
	        }
	        
	        // black take right
	        if (boards[0][i][j] == 11 && boards[0][i + 1][j + 1] != 00) {
	            offload = boards[0];
	            offload[i + 1][j + 1] = offload[i][j];
	            offload[i][j] = 0;
	            printBoard(offload);
	            boards.push_back(offload);
	        }
	    }
	}
}

int main() {
	vector<vector<vector<int>>> boards = {
		{
			{21, 31, 41, 51, 61, 41, 31, 21},
			{11, 11, 11, 11, 11, 11, 11, 11},
			{00, 00, 00, 00, 00, 00, 00, 00},
			{00, 00, 00, 00, 00, 00, 00, 00},
			{00, 00, 00, 00, 00, 00, 00, 00},
			{00, 00, 00, 00, 00, 00, 00, 00},
			{10, 10, 10, 10, 10, 10, 10, 10},
			{20, 30, 40, 50, 60, 40, 30, 20}
		}
	};

	vector<vector<int>> offload;

//     testPosition({{
//             {21, 31, 41, 51, 61, 41, 31, 21},
//     		{11, 11, 11, 11, 00, 11, 11, 11},
//     		{00, 00, 00, 00, 00, 00, 00, 00},
//     		{00, 00, 00, 00, 11, 00, 00, 00},
//     		{00, 00, 00, 10, 00, 00, 00, 00},
//     		{00, 00, 00, 00, 00, 00, 00, 00},
//     		{10, 10, 10, 00, 10, 10, 10, 10},
//     		{20, 30, 40, 50, 60, 40, 30, 20}
//         }}
// 	);

    int n = 0;


	while (boards.size() > 0){
	    n++;

	for (int i = 0; i < 8; i++) {
	    for (int j = 0; j < 8; j++) {
	        if(i != 7){
    	        // black forward
    	        if (boards[0][i][j] == 11 && boards[0][i + 1][j] == 00) {
    	            offload = boards[0];
    	            offload[i + 1][j] = offload[i][j];
    	            offload[i][j] = 0;
    	            printBoard(offload);
    	            boards.push_back(offload);
    
    	            if(boards[0][1][j] == 11){
    	                offload = boards[0];
    	                offload[i + 2][j] = offload[i][j];
    	                offload[i][j] = 0;
    	                printBoard(offload);
    	                boards.push_back(offload);
    	            }
    	        } 
	        }
    	        
	        if(j != 0){
    	        // black take left
    	        if (boards[0][i][j] == 11 && boards[0][i + 1][j - 1] != 00) {
    	            offload = boards[0];
    	            offload[i + 1][j - 1] = offload[i][j];
    	            offload[i][j] = 0;
    	            printBoard(offload);
    	            boards.push_back(offload);
    	        }
	        }
	        
	        if(j != 7){
    	        // black take right
    	        if (boards[0][i][j] == 11 && boards[0][i + 1][j + 1] != 00) {
    	            offload = boards[0];
    	            offload[i + 1][j + 1] = offload[i][j];
    	            offload[i][j] = 0;
    	            printBoard(offload);
    	            boards.push_back(offload);
    	        }
	        }
	        
	        
	        if(i != 0){
    	        // black forward
    	        if (boards[0][i][j] == 10 && boards[0][i - 1][j] == 00) {
    	            offload = boards[0];
    	            offload[i - 1][j] = offload[i][j];
    	            offload[i][j] = 0;
    	            printBoard(offload);
    	            boards.push_back(offload);
    
    	            if(boards[0][1][j] == 11){
    	                offload = boards[0];
    	                offload[i - 2][j] = offload[i][j];
    	                offload[i][j] = 0;
    	                printBoard(offload);
    	                boards.push_back(offload);
    	            }
    	        } 
	        }
    	        
	        if(j != 0){
    	        // black take left
    	        if (boards[0][i][j] == 10 && boards[0][i - 1][j - 1] != 00) {
    	            offload = boards[0];
    	            offload[i - 1][j - 1] = offload[i][j];
    	            offload[i][j] = 0;
    	            printBoard(offload);
    	            boards.push_back(offload);
    	        }
	        }
	        
	        if(j != 7){
    	        // black take right
    	        if (boards[0][i][j] == 10 && boards[0][i - 1][j + 1] != 00) {
    	            offload = boards[0];
    	            offload[i - 1][j + 1] = offload[i][j];
    	            offload[i][j] = 0;
    	            printBoard(offload);
    	            boards.push_back(offload);
    	        }
	        }
	    }
	}
    
	boards.erase(boards.begin());
	
	cerr << boards.size() << " - " << n << endl;

	}


	return 0;
}
