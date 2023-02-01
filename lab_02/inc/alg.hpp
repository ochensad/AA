//
//  alg.hpp
//  lab_02
//
//  Created by macbook on 20.10.2022.
//

#ifndef alg_hpp
#define alg_hpp

#include <stdio.h>
#include <vector>
using namespace std;

vector<vector<int>> ClassicMultMatrix(vector<vector<int>> matr1, vector<vector<int>> matr2);
vector<vector<int>> VinogradMultMatrix(vector<vector<int>> matr1, vector<vector<int>> matr2);
vector<vector<int>> VinogradOptimMultMatrix(vector<vector<int>> matr1, vector<vector<int>> matr2);

#endif /* alg_hpp */
