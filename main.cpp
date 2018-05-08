#include <iostream>
#include "node.h"
#include "avlbst.h"
using namespace std;

int main() {

    avlBST aa;
//    aa.insert("5", 2, 3, 1);
//    aa.insert("2", 5, 2, 1);
//    aa.insert("3", 5, 1, 1);
//    aa.insert("6", 4, 3, 1);
//    aa.insert("4", 4, 3, 1);
//    aa.insert("3", 2, 6, 1);

//    aa.insert("a", 2, 3, 1);
//    aa.insert("8", 5, 2, 1);
//    aa.insert("6", 5, 1, 1);
//    aa.insert("4", 4, 3, 1);
//    aa.insert("2", 4, 3, 1);
//    aa.insert("0", 2, 6, 1);
//    aa.insert("9", 2, 6, 1);
//    aa.insert("3", 2, 6, 1);

    // LEFT LEFT CASE
    aa.insert("8", 1, 1, 1);
    aa.insert("9", 1, 1, 1);
    aa.insert("6", 1, 1, 1);
    aa.insert("7", 1, 1, 1);
    aa.insert("4", 1, 1, 1);
    aa.insert("3", 1, 1, 1);

    // LEFT LEFT SIMPLE CASE
//    aa.insert("3",1,1,1);
//    aa.insert("2",1,1,1);
//    aa.insert("1",1,1,1);

    // LEFT Right CASE
//    aa.insert("8", 1, 1, 1);
//    aa.insert("9", 1, 1, 1);
//    aa.insert("4", 1, 1, 1);
//    aa.insert("2", 1, 1, 1);
//    aa.insert("6", 1, 1, 1);
//    aa.insert("5", 1, 1, 1);
//    aa.insert("7", 1, 1, 1);
    cout << aa.size() << endl;

    // Right Right Simple Case
//    aa.insert("3",1,1,1);
//    aa.insert("4",1,1,1);
//    aa.insert("5",1,1,1);

    // Right Right Case
//    aa.insert("3",1,1,1);
//    aa.insert("1",1,1,1);
//    aa.insert("5",1,1,1);
//    aa.insert("4",1,1,1);
//    aa.insert("7",1,1,1);
//    aa.insert("8",1,1,1);

//    aa.insert("5", 1, 1, 1);
//    aa.insert("3", 1, 1, 1);
//    aa.insert("7", 1, 1, 1);
//    aa.insert("2", 1, 1, 1);
//    aa.insert("8", 1, 1, 1);
//    aa.insert("9", 1, 1, 1);
//    aa.insert("a", 1, 1, 1);
    return 0;

}
