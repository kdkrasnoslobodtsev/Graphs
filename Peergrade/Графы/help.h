#ifndef PEERGRADE_HELP_H
#define PEERGRADE_HELP_H

#endif //PEERGRADE_HELP_H

#include <fstream>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

// Реализует выбор пользователя для взаимодействия с графом.
void MakeChoice(const vector<vector<int>>& adj_matr,
                 const vector<vector<int>>& inc_matr,
                 const vector<vector<int>>& adj_list,
                 const vector<pair<int, int>>& edg_list);

// Проверка на ориентированность графа.
bool IsSimAdjMatr(const vector<vector<int>>& matr);

// Вывод матрицы смежности.
void OutputAdjacencyMatrix(const vector<vector<int>>& adj_matr);

// Вывод матрицы инцидентности.
void OutputIncidenceMatrix(const vector<vector<int>>& inc_matr);

// Вывод списков смежности.
void OutputAdjacencyList(const vector<vector<int>>& adj_list);

// Вывод списка ребер.
void OutputListOfEdges(const vector<pair<int, int>>& edg_list);

// Ввод матрицы смежности и перевод в другие представления графа.
void FromAdjacencyMatrix(vector<vector<int>>& adj_matr,
                           vector<vector<int>>& inc_matr,
                           vector<vector<int>>& adj_list,
                           vector<pair<int, int>>& edg_list,
                           char inp);

// Ввод матрицы инцидентности и перевод в другие представления графа.
void FromIncidenceMatrix(vector<vector<int>>& adj_matr,
                           vector<vector<int>>& inc_matr,
                           vector<vector<int>>& adj_list,
                           vector<pair<int, int>>& edg_list,
                           char inp);

// Ввод списков смежности и перевод в другие представления графа.
void FromAdjacencyList(vector<vector<int>>& adj_matr,
                         vector<vector<int>>& inc_matr,
                         vector<vector<int>>& adj_list,
                         vector<pair<int, int>>& edg_list,
                         char inp);

// Ввод списка ребер и перевод в другие представления графа.
void FromListOfEdges(vector<vector<int>>& adj_matr,
                        vector<vector<int>>& inc_matr,
                        vector<vector<int>>& adj_list,
                        vector<pair<int, int>>& edg_list,
                        char inp);

// Вывод степеней или полустепеней.
void OutputVerticesPowers(const vector<vector<int>>& adj_matr,
                            const vector<vector<int>>& adj_list);

// Вывод инструкций по выбору взаимодействия с графом.
void Instructions();