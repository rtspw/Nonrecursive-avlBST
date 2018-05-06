#include <iostream>
#include "node.h"
#include "avlbst.h"
using namespace std;

int main() {

    avlBST aa;
    aa.insert("5", 2, 3, 1);
    aa.insert("2", 5, 2, 1);
    aa.insert("3", 5, 1, 1);
    aa.insert("6", 4, 3, 1);
    aa.insert("4", 4, 3, 1);
    aa.insert("3", 2, 6, 1);
    cout << aa.size() << endl;
    return 0;

}
