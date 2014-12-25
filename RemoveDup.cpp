#include <iostream>
using namespace std;

/*
 * Remove Duplicates from Sorted Array
 * Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
 * Do not allocate extra space for another array, you must do this in place with constant memory.
 * For example, Given input array A = [1,1,2],
 * Your function should return length = 2, and A is now [1,2].
 */
int rmvDup(int a[], unsigned int len)
{
    int cursor = 0;

    for (int i=1; i<len; i++) {
        if (a[cursor] != a[i]) {
            ++ cursor;
            if (cursor != i) {
                a[cursor] = a[i];                
            }
        }
    }

    return cursor+1;
}

int rmvDup(int a[], unsigned int len, int keep)
{
    if (len <= keep) {
        return len;
    }
        
    int cursor = keep;
    for (int i=keep; i<len; i++) {
        if (a[i] != a[cursor - keep]) {
            a[cursor++] = a[i];
        }
    }

    return cursor;
}

void printArray(int a[], unsigned int len)
{
    for (int i=0; i<len; i++) {
        cout << a[i] <<" ";
    }
    cout << endl;
}

int main()
{
    int a[] = {1, 1, 1, 2, 3, 4, 4, 4, 4, 5, 6, 6, 7};
    int len = sizeof(a)/sizeof(a[0]);

    printArray(a, len);

    //int len1 = rmvDup(a, len);
    //printArray(a, len1);
    int len2 = rmvDup(a, len, 2);
    printArray(a, len2);
    
	return 0;
}

