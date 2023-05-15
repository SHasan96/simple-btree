#include <iostream>
#include <fstream>
#include "btree.h"
using namespace std;

int main(int argc, char** argv) {
    if (argc != 3) {
        cerr << "myUpdate: Invalid format." << endl;
        cerr << "Usage: myUpdate <existing index file> <transaction file>" << endl; 
        exit(1);
    }

    BTree myTree;
    myTree.reset(argv[1]);
   
    ifstream infile(argv[2]);
    if (!infile.is_open()) {
        cerr << "myUpdate: Failed to open transaction file \"" << argv[2] << "\"" << endl;
        myTree.close();
        exit(1);
    }

    // Assuming format to of transcation file to be consistent
    Album alb;
    string oper, key;
    while (infile >> oper >> ws) {
        if(oper == "S") { // S = search
            infile >> key >> ws;
            if (!myTree.search(key)) 
                cout << "\t\"" << key << "\" not found" << endl;
            else 
                cout << "\t" << myTree.retrieve(key) << endl;
        }

        if(oper == "I") { // I = insert
            infile >> alb >> ws;
            myTree.insert(alb);
        }
    }    
    cout << endl;
    myTree.totalio();
    myTree.close();
    return 0;
}

