#ifndef MY_UTIL_H
#define MY_UTIL_H

/*
 * My util header file
 */


#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <climits> // INT_MIN, INT_MAX

using namespace std;

namespace fos {
    void printArray(int a[], int len)
    {   
        for (int i=0; i<len; i++)
            cout << a[i] << " ";
        cout << endl;
    }

    /*
     * get a random between [min, max]
     * e.g, get a random number between 0 and 10
     *
     * std::srand(time(0));
     * int a = random(0, 10);
     */
    int random(int min, int max)
    {
        return (std::rand() % (max - min + 1) + min);
    }
}

#endif

