/**
 * @file RiverSizes.cpp
 * @author skk
 * @brief 
 * You're given a two-dimensional array (a matrix) of potentially 
 * unequal height and width containing only 0s and 1s. Each 0 represents 
 * land, and each 1 represents part of a river. A river consists of any 
 * number of 1s that are either horizontally or vertically adjacent 
 * (but not diagonally adjacent). The number of adjacent 1s forming 
 * a river determine its size.
 * 
 * Note that a river can twist. In other words, it doesn't have to be a 
 * straight vertical line or a straight horizontal line; it can be L-shaped, 
 * for example.
 * 
 * Write a function that returns an array of the sizes of all rivers 
 * represented in the input matrix. The sizes don't need to be in any 
 * particular order.
 * 
 * Sample Input
 * matrix = [
 *             [1, 0, 0, 1, 0],
 *             [1, 0, 1, 0, 0],
 *             [0, 0, 1, 0, 1],
 *             [1, 0, 1, 0, 1],
 *             [1, 0, 1, 1, 0],
 *           ]
 * 
 * Sample Output
 * 
 * [1, 2, 2, 2, 5] // The numbers could be ordered differently.
 * 
 * // The rivers can be clearly seen here:
 * // [
 * //   [1,  ,  , 1,  ],
 * //   [1,  , 1,  ,  ],
 * //   [ ,  , 1,  , 1],
 * //   [1,  , 1,  , 1],
 * //   [1,  , 1, 1,  ],
 * // ]
 * 
 * @version 0.1
 * @date 2023-01-01
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
// #include <unordered_map>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
// typedef std::pair<int, int> pair;

// struct pair_hash
// {
// 	template <class T1, class T2>
// 	std::size_t operator() (const std::pair<T1, T2> &pair) const
// 	{
// 		return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
// 	}
// };



int main() {

  riverSizer();

  return 0;
}