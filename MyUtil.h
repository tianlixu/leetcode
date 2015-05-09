#ifndef MY_UTIL_H
#define MY_UTIL_H

/*
 * My util header file
 */


#include <iostream>
#include <string>
#include <vector>
#include <climits> // INT_MIN, INT_MAX

using namespace std;

namespace fos {
    void printArray(int a[], int len)
    {   
        for (int i=0; i<len; i++)
            cout << a[i] << " ";
        cout << endl;
    }

}

#endif

