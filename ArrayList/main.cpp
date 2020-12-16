#include <iostream>
#include "arraylist.cpp"

using namespace std;

int main()
{
    arraylist<int> a = arraylist<int>();

    std::initializer_list<int> list = {7, 4, 9, 10, 3, 2, 0};
    // std::initializer_list<int> list = {1, 2, 3, 4, 5, 6, 7, 8};
    // std::initializer_list<int> list = {1, 2, 4, 3, 5, 6, 7, 8};
    // std::initializer_list<int> list = {8, 7, 6, 5, 4, 3, 2, 1};
    // std::initializer_list<int> list = {8, 7, 6, 5, 4, 1, 2, 3};

    a.push_back(list);
    a.print();
    a.mergeSort(0, a.getLen());
    a.print();

    // std::initializer_list<int> l = {1, 2, 3, 4, 5, 6, 8, 9, 10, 11, 13, 14, 15, 16, 17, 18};
    // std::initializer_list<int> l = {1, 2, 3, 4, 5, 6, 8};
    // a.push_back(l);
    // a.print();
    // // int out = a.binarySearch(1);
    // out != -1 ? std::cout << "Found element at: " << out << std::endl
    //                       << "Element: " << a.get(out) << std::endl
    //           : std::cout << "Element not found" << std::endl;
    // for (int elem : l)
    // {
    //     std::cout << "Finding: " << elem << std::endl;
    //     int out = a.binarySearch(elem, 0, a.getLen());
    //     out != -1 ? std::cout << "Found element at: " << out << std::endl : std::cout << "Element not found" << std::endl;
    //     std::cout << std::endl;
    // }

    return 0;
}

// // std::cout << "Removing: 9" << std::endl;
// // int out = a.remove(9);
// // out != -1 ? std::cout << "Removed" << std::endl : std::cout << "Not found" << std::endl;

// // std::cout << "Removing: 14" << std::endl;
// // out = a.remove(14);
// // out != -1 ? std::cout << "Removed" << std::endl : std::cout << "Not found" << std::endl;

// // std::cout << "Removing: 8" << std::endl;
// // out = a.remove(8);
// // out != -1 ? std::cout << "Removed" << std::endl : std::cout << "Not found" << std::endl;

// // std::cout << "Removing: 1" << std::endl;
// // out = a.remove(1);
// // out != -1 ? std::cout << "Removed" << std::endl : std::cout << "Not found" << std::endl;

// // std::cout << "Removing: 18" << std::endl;
// // out = a.remove(18);
// // out != -1 ? std::cout << "Removed" << std::endl : std::cout << "Not found" << std::endl;

// // a.print();

// // std::cout << "Two pointer transposition linear search-ing 13" << std::endl;
// // a.twoPointerTranspositionLinearSearch(13);
// // a.print();
// // std::cout << "Transposition linear search-ing 15" << std::endl;
// // a.transpositionLinearSearch(15);
// // a.print();
// // int err = a.push_back({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20});
// // if (err != 0)
// //     return err;

// // err = a.push_back({21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38});
// // if (err != 0)
// //     return err;

// // for (int i = 39; i <= 64; i++)
// // {
// //     a.push_back(i);
// // }

// // a.print();