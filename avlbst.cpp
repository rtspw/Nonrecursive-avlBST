#include "avlbst.h"
#include "utility"


avlBST::avlBST() {

}

avlBST::~avlBST() {
    deleteAll();
}

avlBST::avlBST(const avlBST &other) {
    copy(other);
}

avlBST &avlBST::operator=(const avlBST &other) {
    if(this != &other) {
        deleteAll();
        copy(other);
    }
    return *this;
}

bool avlBST::empty() const {
    return !tree.size();
}

size_t avlBST::size() {
    return tree.size();
}




 // Concerns : vector.push_back creates copy
void avlBST::insert(const std::string &w, const size_t &pIdx, const size_t &lIdx, const size_t count) {
    node temp(w, pIdx, lIdx, count);
    if(empty()) {
        insertRoot(temp);
    }
    else {
        bool notBreak = true;
        bool useLog = true;
        bool createsNewDepth = false;
        int index = 0;
        std::vector<std::pair<size_t, int>> balanceLog;

        /* Iterates down the tree, along with changing the balance of the nodes accordingly */
        while(notBreak) {

            /* Case 1: Add to word count if character already exists
             * Also ignores balance value changes as no new nodes are added */
            if(temp.word == tree[index].word) {
                ++tree[index];
                tree[index].paragraphIndex.push_back(pIdx);
                tree[index].lineIndex.push_back(lIdx);
                notBreak = false;
                useLog = false;
            }

            /* Case 2: Makes left children, which goes down until there is a -1 index */
            else if(temp.word < tree[index].word) {
                balanceLog.push_back(std::make_pair(index, -1));
                if(leftIdxs[index] == -1) {
                    if(rightIdxs[index] == -1)
                        createsNewDepth = true;
                    insertLeft(temp, index);
                    notBreak = false;
                }
                    index = leftIdxs[index];
            }

            /* Case 3: Opposite of case 2 */
            else {
                balanceLog.push_back(std::make_pair(index, 1));
                if(rightIdxs[index] == -1) {
                    if(leftIdxs[index] == -1)
                        createsNewDepth = true;
                    insertRight(temp, index);
                    notBreak = false;
                }
                    index = rightIdxs[index];
            }
         }

        /* DEBUG!!!!
         * Uses log to adjust the balances of the tree of each affected index
         * However, only the last entry of the log is used if no new depth is made */
        if(useLog) {
            if(createsNewDepth) {
                for(size_t i=0; i < balanceLog.size() - 1; ++i)
                    tree[balanceLog[i].first].balance += balanceLog[i].second;
            }

        tree[balanceLog.back().first].balance += balanceLog.back().second;
        }

        /* Starts from added node and modifies height values up to the root */
        while(index != -1) {
            tree[index].height = 1 + getBigger(getHeight(leftIdxs[index]), getHeight(rightIdxs[index]));
            index = parentIdxs[index];
        }

        //rebalance();
    }


    for(size_t i = 0; i < tree.size(); ++i) {
        std::cout << tree[i] << "\t";
    }
    std::cout << std::endl;
    for(size_t i = 0; i < leftIdxs.size(); ++i) {
        std::cout << leftIdxs[i] << "\t";
    }
    std::cout << std::endl;
    for(size_t i = 0; i < rightIdxs.size(); ++i) {
        std::cout << rightIdxs[i] << "\t";
    }
    std::cout << std::endl;
    for(size_t i = 0; i < parentIdxs.size(); ++i) {
        std::cout << parentIdxs[i] << "\t";
    }
    std::cout << std::endl;
    std::cout << getBalance(0) << std::endl;
    std::cout << std::endl;

}


void avlBST::insertRoot(node &temp) {
    tree.push_back(temp);
    leftIdxs.push_back(-1);
    rightIdxs.push_back(-1);
    parentIdxs.push_back(-1);
}

void avlBST::insertLeft(node &temp, const int &index) {
    leftIdxs[index] = (tree.size()); // size refers to index of the inserted node
    leftIdxs.push_back(-1);
    rightIdxs.push_back(-1);
    parentIdxs.push_back(index);
    tree.push_back(temp);
}

void avlBST::insertRight(node &temp, const int &index) {
    rightIdxs[index] = (tree.size());
    leftIdxs.push_back(-1);
    rightIdxs.push_back(-1);
    parentIdxs.push_back(index);
    tree.push_back(temp);
}

void avlBST::rebalance() {
    int risingIndex = tree.size() - 1;
    do {
        risingIndex = parentIdxs[risingIndex];
        if(tree[risingIndex].balance <= -2 && tree[leftIdxs[risingIndex]].balance == -1) {
            std::cout << "LEFT LEFT CASE!!!" << std::endl;
            rotateRight(risingIndex);
        }
        else if(tree[risingIndex].balance <= -2 && tree[leftIdxs[risingIndex]].balance == 1) {
            std::cout << "LEFT RIGHT CASE!!!" << leftIdxs[risingIndex] << std::endl;
            rotateLeft(leftIdxs[risingIndex]);

            for(size_t i = 0; i < tree.size(); ++i) {
                std::cout << tree[i] << "\t";
            }
            std::cout << std::endl;
            for(size_t i = 0; i < leftIdxs.size(); ++i) {
                std::cout << leftIdxs[i] << "\t";
            }
            std::cout << std::endl;
            for(size_t i = 0; i < rightIdxs.size(); ++i) {
                std::cout << rightIdxs[i] << "\t";
            }
            std::cout << std::endl;
            for(size_t i = 0; i < parentIdxs.size(); ++i) {
                std::cout << parentIdxs[i] << "\t";
            }
            std::cout << std::endl;

            rotateRight(risingIndex);
        }
        else if(tree[risingIndex].balance >= 2 && tree[rightIdxs[risingIndex]].balance == -1) {
            std::cout << "RIGHT LEFT CASE!!!" << std::endl;
            rotateRight(rightIdxs[risingIndex]);
            rotateLeft(risingIndex);
        }
        else if(tree[risingIndex].balance >= 2 && tree[rightIdxs[risingIndex]].balance == 1) {
            std::cout << "RIGHT RIGHT CASE!!!" << std::endl;
            rotateLeft(risingIndex);
        }
    } while(parentIdxs[risingIndex] != -1);
}

/* rotateRight's variables:
 *      y       x
 *     /      /  \
 *    x   -> a   y
 *   / \        /
 *  a  b       b
 */
void avlBST::rotateRight(const int &index) {

    int bIdx = rightIdxs[leftIdxs[index]];
    tree[index].balance += 2;
    ++tree[leftIdxs[index]].balance;

    // Sets parent of x as parent of y
    parentIdxs[leftIdxs[index]] = parentIdxs[index];
    // Sets parent of y as x
    parentIdxs[index] = leftIdxs[index];
    // Sets right child of x as y
    rightIdxs[leftIdxs[index]] = index;

    // If b exists, sets parent of b as y
    if(bIdx != -1) {
        parentIdxs[bIdx] = index;
        leftIdxs[index] = bIdx;
    }
    else
        leftIdxs[index] = -1;
}

/* rotateLeft's variables:
 *      y         x
 *      \        /\
 *      x   ->  y  a
 *     /\       \
 *    b a        b
 */
void avlBST::rotateLeft(const int &index) {
    int bIdx = leftIdxs[rightIdxs[index]];
    tree[index].balance -= 2;
    --tree[rightIdxs[index]].balance;

    // Sets parent of x as parent of y
    parentIdxs[rightIdxs[index]] = parentIdxs[index];
    // Sets parent of y as x
    parentIdxs[index] = rightIdxs[index];
    // Sets left child of x as y
    leftIdxs[rightIdxs[index]] = index;

    // If b exists, sets parent of b as y
    if(bIdx != -1) {
        parentIdxs[bIdx] = index;
        rightIdxs[index] = bIdx;
    }
    else
        rightIdxs[index] = -1;
}

void avlBST::clear() {
    tree.clear();
    leftIdxs.clear();
    rightIdxs.clear();
    parentIdxs.clear();
}

// Get height insures we can get the height even when the node does not exist
int avlBST::getHeight(const int &x) {
    return (x == -1) ? 0 : tree[x].height;
}

// Gets the larger of two numbers
int avlBST::getBigger(const int &x, const int &y) {
    return (x > y) ? x : y;
}

// Calculates balance factor of node
int avlBST::getBalance(const int &x) {
    return (x == -1) ? 0 : getHeight(rightIdxs[x])  - getHeight(leftIdxs[x]);
}

void avlBST::copy(const avlBST &other) {
    tree = other.tree;
    leftIdxs = other.leftIdxs;
    rightIdxs = other.rightIdxs;
    parentIdxs = other.parentIdxs;
}

void avlBST::deleteAll() {
    tree.clear();
    leftIdxs.clear();
    rightIdxs.clear();
    parentIdxs.clear();
}
