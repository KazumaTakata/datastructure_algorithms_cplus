#include "./List.hpp"
#include <iostream>

using namespace std;

int main()
{
    List list = List();

    list.append(1);
    list.append(2);
    list.append(3);

    // list.insert(1, 10);

    list.remove(1);
    double inserted = list.get(1);

    cout << "ee";
}