#include <iostream>
#include "Node.h"
using namespace std;

int main() {
    Node a = Node(3, 4);
    Node b = Node(1,0);
    cout<< "odleglosc = "<<pointsDistance(a,b)<<endl;

    return 0;
}