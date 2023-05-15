#include <iostream>
#include <fstream>
#include "btree.h"
using namespace std;

int main(int argc, char** argv) {
    if (argc != 3) {
        cerr << "myCreate: Invalid format." << endl;
        cerr << "Usage: myCreate <album file> <index file>" << endl; 
        exit(1);
    }

    BTree myTree;
    myTree.writeHeader(argv[2]);  
 
    ifstream infile(argv[1]);
    if (!infile.is_open()) {
        cerr << "myCreate: Failed to open file \"" << argv[1] << "\"" << endl;
        myTree.close();
        exit(1);
    }

    Album alb;
    while (infile >> alb) {
        myTree.insert(alb);   
    }    

    myTree.printTree();
    myTree.close();
    return 0;
}

