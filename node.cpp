#include "node.h"

std::ostream &operator<<(std::ostream &out, const node &n) {
    out << "("<< n.word << "\t | Count: " << n.count << "\t | Balance: " << n.balance << "\t | Height: " << n.height << ")";
    return out;
}

bool operator==(const node &a, const node &b) {
    return a.word == b.word;
}

bool operator<(const node &a, const node &b) {
    return a.word < b.word;
}

bool operator>(const node &a, const node &b) {
    return a.word > b.word;
}

node &node::operator++() {
    ++count;
    return *this;
}
node node::operator++(int) {
    node temp = *this;
    ++*this;
    return temp;
}
node &node::operator--() {
    --count;
    return *this;
}
node node::operator--(int) {
    node temp = *this;
    --*this;
    return temp;
}
