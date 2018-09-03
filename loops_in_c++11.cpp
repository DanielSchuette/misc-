#include <cstdio>
using namespace std;

int main(int argc, char **argv) {
    int arr[] = {1, 2, 3, 4, 5, 6};
    // array traversal prior to c++11
    for (int i = 0, n = (sizeof(arr) / sizeof(*arr)); i < n; i++) {
        printf("i is %d, element of arr at this index: %d\n", i, *(arr+i));
    }

    // modern c++
    // in this second loop, `i' will be the value of the respective array element
    for (auto i : arr) {
        printf("i is %d\n", i); 
    }
    return 0;
}
