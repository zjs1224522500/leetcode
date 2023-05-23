#include <iostream>
#include <vector>

using namespace std;

void print_vector(const std::vector<int>& v)
{
    for (auto& e : v) {
        std::cout << e << " ";
    }
    std::cout << std::endl;
}

int main()
{
    // Construct
    cout << "Construct:" << endl;
    vector<int> v1;
    v1.push_back(1);
    print_vector(v1);

    vector<int> v2(v1.begin(), v1.end());
    print_vector(v2);

    vector<int> v3(3, 100);
    print_vector(v3);

    vector<int> v4(v3);
    print_vector(v4);

    // Assign
    cout << "Assign:" << endl;
    vector<int> v5 = v1;
    print_vector(v5);

    vector<int> v6;
    v6.assign(v3.begin(), v3.end());
    print_vector(v6);

    vector<int> v7;
    v7.assign(4, 100);
    print_vector(v7);

    // Insert
    cout << "Insert:" << endl;
    v7.push_back(200);
    print_vector(v7);

    v7.insert(v7.begin() + 1, 300);
    print_vector(v7);

    v7.insert(v7.end() - 1, 2, 400);
    print_vector(v7);

    // Delete
    cout << "Delete:" << endl;
    v7.pop_back();
    print_vector(v7);

    v7.erase(v7.begin());
    print_vector(v7);

    v7.erase(v7.begin() + 1, v7.begin() + 3);
    print_vector(v7);

    // Capacity
    cout << "Capacity:" << endl;
    cout << v7.empty() << endl;
    cout << v7.size() << endl;
    cout << v7.capacity() << endl;
    v7.resize(3);
    print_vector(v7);
    
    cout << v7.capacity() << endl;
    cout << v7.size() << endl;

    // Access
    cout << "Access:" << endl;
    cout << v7.front() << endl;
    cout << v7.back() << endl;
    cout << v7[1] << endl;
    cout << v7.at(2) << endl;


    return 0;
}