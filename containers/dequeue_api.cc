#include <iostream>
#include <deque>

using namespace std;

void print_deque(const std::deque<int>& d)
{
    for (auto& e : d) {
        std::cout << e << " ";
    }
    std::cout << std::endl;
}


int main() {
    // Construct
    cout << "Construct:" << endl;
    deque<int> d1;
    d1.push_back(1);
    d1.push_front(2);
    print_deque(d1);

    deque<int> d2(d1.begin(), d1.end());
    print_deque(d2);

    deque<int> d3(3, 100);
    print_deque(d3);

    deque<int> d4(d3);
    print_deque(d4);

    // Assign
    cout << "Assign:" << endl;
    deque<int> d5 = d1;
    print_deque(d5);
    deque<int> d6;
    d6.assign(d3.begin(), d3.end());
    print_deque(d6);
    deque<int> d7;
    d7.assign(4, 100);
    print_deque(d7);

    // Insert
    cout << "Insert:" << endl;
    d7.push_back(200);
    print_deque(d7);
    d7.push_front(300);
    print_deque(d7);
    d7.insert(d7.begin() + 1, 400);
    print_deque(d7);
    d7.insert(d7.end() - 1, 2, 500);
    print_deque(d7);

    // Delete
    cout << "Delete:" << endl;
    d7.pop_back();
    print_deque(d7);
    d7.pop_front();
    print_deque(d7);
    d7.erase(d7.begin());
    print_deque(d7);
    d7.erase(d7.begin(), d7.begin() + 2);
    print_deque(d7);

    // Access
    cout << "Access:" << endl;
    cout << d7.front() << endl;
    cout << d7.back() << endl;
    cout << d7[1] << endl;
    cout << d7.at(1) << endl;
    cout << d7[2] << endl;
    cout << d7.at(2) << endl;

    // Capacity
    cout << "Capacity:" << endl;
    cout << d7.empty() << endl;
    cout << d7.size() << endl;
    cout << d7.max_size() << endl;
    d7.resize(1);
    print_deque(d7);


    return  0;
}