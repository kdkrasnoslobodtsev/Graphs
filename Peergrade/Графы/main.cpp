#include "help.h"

// Точка входа.
int main() {
    char quit;
    do {
        cout << "Do you want to entre graph with the file \"input.txt\"? (y/n)\n";
        char inp_flag;
        cin >> inp_flag;
        vector<vector<int>> adj_matr;
        vector<vector<int>> inc_matr;
        vector<vector<int>> adj_list;
        vector<pair<int, int>> edg_list;
        cout << "Choose the way you want to enter the graph (write the number)\n"
             << "1 - Adjacency matrix\n"
             << "2 - Incidence matrix\n"
             << "3 - Adjacency list\n"
             << "4 - List of edges\n";
        int num;
        cin >> num;
        if (num == 1) {
            FromAdjacencyMatrix(adj_matr, inc_matr, adj_list, edg_list, inp_flag);
        } else if (num == 2) {
            FromIncidenceMatrix(adj_matr, inc_matr, adj_list, edg_list, inp_flag);
        } else if (num == 3) {
            FromAdjacencyList(adj_matr, inc_matr, adj_list, edg_list, inp_flag);
        } else if (num == 4) {
            FromListOfEdges(adj_matr, inc_matr, adj_list, edg_list, inp_flag);
        } else {
            cout << "Incorrect number";
            continue;
        }
        Instructions();
        MakeChoice(adj_matr, inc_matr, adj_list, edg_list);
        cout << "Do you want to quit? (y/n)\n";
        cin >> quit;
    } while (quit == 'n');
    cout << "Thanks for using. I hope you had a fun";
}