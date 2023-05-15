#include <iostream>
#include <fstream>
#include "btree.h"

int main(int argc, char** argv) {
    if (argc != 3) {
        cerr << "Invalid format." << endl;
        exit(1);
    }

    BTree myTree;
    myTree.writeHeader(argv[2]);   
    ifstream infile(argv[1]);
    if (!infile.is_open()) {
        cerr << "Failed to open file." << endl;
        exit(1);
    }
    Album alb;
    while (infile >> alb) {
        myTree.insert(alb);   
    }    

    myTree.printTree();
    myTree.inorder();
    myTree.reverse();
    cout << "\tTotal nodes: " << myTree.countNodes() << endl;
    cout << "\tNumber of leaves: " << myTree.countLeaves() << endl; 
    myTree.totalio();
    //Album target("00006", "Any Song", "Any Artist"); // for serching
    string target = "8";
    cout << boolalpha << "Searching for key: " << target << "   Found: " << myTree.search(target) << endl;
    Album targetAlb = myTree.retrieve(target);
    cout << targetAlb << endl;
    //cout << "\tNumber of leaves: " << myTree.countLeaves() << endl;
    myTree.close();
    return 0;
}

