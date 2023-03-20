#include "help.h"

// Реализует выбор пользователя для взаимодействия с графом.
void MakeChoice(const vector<vector<int>>& adj_matr,
                 const vector<vector<int>>& inc_matr,
                 const vector<vector<int>>& adj_list,
                 const vector<pair<int, int>>& edg_list) {
    int choice;
    cin >> choice;
    while (choice != 0) {
        if (choice == 1) {
            OutputVerticesPowers(adj_matr, adj_list);
        } else if (choice == 2) {
            cout << "There are at all " << edg_list.size() << " edges\n";
        } else if (choice == 3) {
            OutputAdjacencyMatrix(adj_matr);
        } else if (choice == 4) {
            OutputIncidenceMatrix(inc_matr);
        } else if (choice == 5) {
            OutputAdjacencyList(adj_list);
        } else if (choice == 6) {
            OutputListOfEdges(edg_list);
        }
        Instructions();
        cin >> choice;
    }
}

// Проверка на ориентированность графа.
bool IsSimAdjMatr(const vector<vector<int>>& matr) {
    for (size_t i = 0; i < matr.size(); ++i) {
        for (size_t j = 0; j < i; ++j) {
            if (matr[i][j] != matr[j][i]) {
                return false;
            }
        }
    }
    return true;
}

// Вывод матрицы смежности.
void OutputAdjacencyMatrix(const vector<vector<int>>& adj_matr) {
    ofstream fout("output.txt");
    char out;
    cout << "Do you want your graph being writen in a file? (y/n)\n";
    cin >> out;
    if (out == 'y') {
        fout << "Adjacency matrix\n";
        for (size_t i = 0; i < adj_matr.size(); ++i) {
            for (size_t j = 0; j < adj_matr[i].size(); ++j) {
                fout << adj_matr[i][j] << ' ';
            }
            fout << '\n';
        }
    } else {
        cout << "Adjacency matrix\n";
        for (size_t i = 0; i < adj_matr.size(); ++i) {
            for (size_t j = 0; j < adj_matr[i].size(); ++j) {
                cout << adj_matr[i][j] << ' ';
            }
            cout << '\n';
        }
    }
}

// Вывод матрицы инцидентности.
void OutputIncidenceMatrix(const vector<vector<int>>& inc_matr) {
    vector<vector<int>> tmp;
    if (inc_matr.size() > 0) {
        tmp = vector<vector<int>>(inc_matr[0].size(), vector<int>(inc_matr.size()));
        for (size_t i = 0; i < inc_matr.size(); ++i) {
            for (size_t j = 0; j < inc_matr[i].size(); ++j) {
                tmp[j][i] = inc_matr[i][j];
            }
        }
    }
    ofstream fout("output.txt");
    char out;
    cout << "Do you want your graph being writen in a file? (y/n)\n";
    cin >> out;
    if (out == 'y') {
        fout << "Incidence matrix\n";
        for (size_t i = 0; i < tmp.size(); ++i) {
            for (size_t j = 0; j < tmp[i].size(); ++j) {
                fout << tmp[i][j] << ' ';
            }
            fout << '\n';
        }
    } else {
        cout << "Incidence matrix\n";
        for (size_t i = 0; i < tmp.size(); ++i) {
            for (size_t j = 0; j < tmp[i].size(); ++j) {
                cout << tmp[i][j] << ' ';
            }
            cout << '\n';
        }
    }
}

// Вывод списков смежности.
void OutputAdjacencyList(const vector<vector<int>>& adj_list) {
    ofstream fout("output.txt");
    char out;
    cout << "Do you want your graph being writen in a file? (y/n)\n";
    cin >> out;
    if (out == 'y') {
        fout << "Adjacency list\n";
        for (size_t i = 0; i < adj_list.size(); ++i) {
            fout << i + 1 << " - ";
            for (size_t j = 0; j < adj_list[i].size(); ++j) {
                fout << adj_list[i][j] + 1 << ' ';
            }
            fout << '\n';
        }
    } else {
        cout << "Adjacency list\n";
        for (size_t i = 0; i < adj_list.size(); ++i) {
            cout << i + 1 << " - ";
            for (size_t j = 0; j < adj_list[i].size(); ++j) {
                cout << adj_list[i][j] + 1 << ' ';
            }
            cout << '\n';
        }
    }
}

// Вывод списка ребер.
void OutputListOfEdges(const vector<pair<int, int>>& edg_list) {
    ofstream fout("output.txt");
    char out;
    cout << "Do you want your graph being writen in a file? (y/n)\n";
    cin >> out;
    if (out == 'y') {
        fout << "List of edges\n";
        for (size_t i = 0; i < edg_list.size(); ++i) {
            fout << edg_list[i].first + 1 << ' ' << edg_list[i].second + 1 << '\n';
        }
    } else {
        cout << "List of edges\n";
        for (size_t i = 0; i < edg_list.size(); ++i) {
            cout << edg_list[i].first + 1 << ' ' << edg_list[i].second + 1 << '\n';
        }
    }
}

// Ввод матрицы смежности и перевод в другие представления графа.
void FromAdjacencyMatrix(vector<vector<int>>& adj_matr,
                           vector<vector<int>>& inc_matr,
                           vector<vector<int>>& adj_list,
                           vector<pair<int, int>>& edg_list,
                           char inp) {
    ifstream fin("input.txt");
    cout << "Enter the size of matrix\n";
    int size;
    if (inp == 'y') {
        fin >> size;
    } else {
        cin >> size;
    }
    adj_matr = vector<vector<int>>(size, vector<int>(size));
    adj_list = vector<vector<int>>(size);
    cout << "Enter the matrix\n";
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (inp == 'y') {
                fin >> adj_matr[i][j];
            } else {
                cin >> adj_matr[i][j];
            }
            if (adj_matr[i][j] == 1) {
                adj_list[i].push_back(j);
            }
        }
    }
    if (IsSimAdjMatr(adj_matr)) {
        for (size_t i = 0; i < size; ++i) {
            for (size_t j = 0; j < i; ++j) {
                if (adj_matr[i][j] > 0) {
                    inc_matr.push_back(vector<int>(size));
                    inc_matr[inc_matr.size() - 1][i] = 1;
                    inc_matr[inc_matr.size() - 1][j] = 1;
                    edg_list.push_back(make_pair(i, j));
                }
            }
        }
    } else {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if (adj_matr[i][j] > 0) {
                    inc_matr.push_back(vector<int>(size));
                    inc_matr[inc_matr.size() - 1][i] = -1;
                    inc_matr[inc_matr.size() - 1][j] = 1;
                    edg_list.push_back(make_pair(i, j));
                }
            }
        }
    }
}

// Ввод матрицы инцидентности и перевод в другие представления графа.
void FromIncidenceMatrix(vector<vector<int>>& adj_matr,
                           vector<vector<int>>& inc_matr,
                           vector<vector<int>>& adj_list,
                           vector<pair<int, int>>& edg_list,
                           char inp) {
    ifstream fin("input.txt");
    int size, edges;
    cout << "Enter the count of vertices\n";
    if (inp == 'y') {
        fin >> size;
    } else {
        cin >> size;
    }
    cout << "Enter the count of edges\n";
    if (inp == 'y') {
        fin >> edges;
    } else {
        cin >> edges;
    }
    adj_matr = vector<vector<int>>(size, vector<int>(size));
    adj_list = vector<vector<int>>(size);
    inc_matr = vector<vector<int>>(edges, vector<int>(size));
    cout << "Enter the matrix\n";
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < edges; ++j) {
            int value;
            if (inp == 'y') {
                fin >> value;
            } else {
                cin >> value;
            }
            inc_matr[j][i] = value;
        }
    }
    for (int i = 0; i < edges; ++i) {
        int flag = 2, first, second;
        for (int j = 0; j < size; ++j) {
            if (flag == 0) {
                break;
            }
            if (inc_matr[i][j] != 0) {
                if (flag == 2) {
                    first = j;
                } else {
                    second = j;
                }
                --flag;
            }
        }
        if (inc_matr[i][first] != -1 && inc_matr[i][second] != -1) {
            edg_list.push_back(make_pair(first, second));
            adj_matr[first][second] = 1;
            adj_matr[second][first] = 1;
            adj_list[first].push_back(second);
            adj_list[second].push_back(first);
        } else {
            if (inc_matr[i][first] == -1) {
                edg_list.push_back(make_pair(first, second));
                adj_matr[first][second] = 1;
                adj_list[first].push_back(second);
            } else {
                edg_list.push_back(make_pair(second, first));
                adj_matr[second][first] = 1;
                adj_list[second].push_back(first);
            }
        }
    }
}

// Ввод списков смежности и перевод в другие представления графа.
void FromAdjacencyList(vector<vector<int>>& adj_matr,
                         vector<vector<int>>& inc_matr,
                         vector<vector<int>>& adj_list,
                         vector<pair<int, int>>& edg_list,
                         char inp) {
    ifstream fin("input.txt");
    cout << "Enter the count of vertices\n";
    int size;
    if (inp == 'y') {
        fin >> size;
    } else {
        cin >> size;
    }
    adj_matr = vector<vector<int>>(size, vector<int>(size));
    adj_list = vector<vector<int>>(size);
    for (int i = 0; i < size; ++i) {
        cout << "Enter the count of vertices connected with the " << i + 1 << '\n';
        int count;
        if (inp == 'y') {
            fin >> count;
        } else {
            cin >> count;
        }
        cout << "Enter these vertices\n";
        for (int j = 0; j < count; ++j) {
            int finish;
            if (inp == 'y') {
                fin >> finish;
            } else {
                cin >> finish;
            }
            adj_list[i].push_back(finish - 1);
            adj_matr[i][finish - 1] = 1;
        }
    }
    if (IsSimAdjMatr(adj_matr)) {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < i; ++j) {
                if (adj_matr[i][j] > 0) {
                    inc_matr.push_back(vector<int>(size));
                    inc_matr[inc_matr.size() - 1][i] = 1;
                    inc_matr[inc_matr.size() - 1][j] = 1;
                    edg_list.push_back(make_pair(i, j));
                }
            }
        }
    } else {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if (adj_matr[i][j] > 0) {
                    inc_matr.push_back(vector<int>(size));
                    inc_matr[inc_matr.size() - 1][i] = -1;
                    inc_matr[inc_matr.size() - 1][j] = 1;
                    edg_list.push_back(make_pair(i, j));
                }
            }
        }
    }
}

// Ввод списка ребер и перевод в другие представления графа.
void FromListOfEdges(vector<vector<int>>& adj_matr,
                        vector<vector<int>>& inc_matr,
                        vector<vector<int>>& adj_list,
                        vector<pair<int, int>>& edg_list,
                        char inp) {
    ifstream fin("input.txt");
    cout << "Does your graph oriented? (y/n)\n";
    char flag;
    cin >> flag;
    cout << "Enter the count of vertices?\n";
    int size;
    if (inp == 'y') {
        fin >> size;
    } else {
        cin >> size;
    }
    adj_matr = vector<vector<int>>(size, vector<int>(size));
    adj_list = vector<vector<int>>(size);
    cout << "Enter the count of edges\n";
    int count;
    if (inp == 'y') {
        fin >> count;
    } else {
        cin >> count;
    }
    if (flag == 'n') {
        for (int i = 0; i < count; ++i) {
            inc_matr.push_back(vector<int>(size));
            int first, second;
            if (inp == 'y') {
                fin >> first >> second;
            } else {
                cin >> first >> second;
            }
            edg_list.push_back(make_pair(first - 1, second - 1));
            adj_matr[first - 1][second - 1] = 1;
            adj_matr[second - 1][first - 1] = 1;
            adj_list[first - 1].push_back(second - 1);
            adj_list[second - 1].push_back(first - 1);
            inc_matr[inc_matr.size() - 1][first - 1] = 1;
            inc_matr[inc_matr.size() - 1][second - 1] = 1;
        }
    } else {
        for (int i = 0; i < count; ++i) {
            inc_matr.push_back(vector<int>(size));
            int first, second;
            if (inp == 'y') {
                fin >> first >> second;
            } else {
                cin >> first >> second;
            }
            edg_list.push_back(make_pair(first - 1, second - 1));
            adj_matr[first - 1][second - 1] = 1;
            adj_list[first - 1].push_back(second - 1);
            inc_matr[inc_matr.size() - 1][first - 1] = -1;
            inc_matr[inc_matr.size() - 1][second - 1] = 1;
        }
    }
}

// Вывод степеней или полустепеней.
void OutputVerticesPowers(const vector<vector<int>>& adj_matr,
                            const vector<vector<int>>& adj_list) {
    if (IsSimAdjMatr(adj_matr)) {
        cout << "Powers of vertices\n";
        for (size_t i = 0; i < adj_list.size(); ++i) {
            cout << i + 1 << " - " << adj_list[i].size() << "\n";
        }
    } else {
        cout << "Half-powers of approach\n";
        for (size_t i = 0; i < adj_matr.size(); ++i) {
            int power_in = 0;
            for (size_t j = 0; j < adj_matr.size(); ++j) {
                if (adj_matr[j][i]) {
                    ++power_in;
                }
            }
            cout << i + 1 << " - " << power_in << "\n";
        }
        cout << "\nHalf-powers of descent\n";
        for (size_t i = 0; i < adj_matr.size(); ++i) {
            int power_out = 0;
            for (int j = 0; j < adj_matr.size(); ++j) {
                if (adj_matr[i][j]) {
                    ++power_out;
                }
            }
            cout << i + 1 << " - " << power_out << "\n";
        }
    }
}

// Вывод инструкций по выбору взаимодействия с графом.
void Instructions() {
    cout << "Choice a function (write a number)\n";
    cout << "1 - count of powers/half-powers of vertices\n";
    cout << "2 - count of vertices\n";
    cout << "3 - output like an adjacency matrix\n";
    cout << "4 - output like a incidence matrix\n";
    cout << "5 - output like an adjacency list\n";
    cout << "6 - output like a list of edges\n";
    cout << "0 - exit\n";
}