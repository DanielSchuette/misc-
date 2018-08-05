/*
 * A program that calculates permutations of a string of integers
 * with a depth of min = 1 and max = 8
 * The user is prompted to input a depth and the output is printed 
 * to stdout
 * Brute force algorithm that should be improved!
 */
#include <iostream>
using namespace std;

int fac(int n);

int main() {
    // ask user for depth of permutation
    int depth;
    cout << "depth (1 - 8): ";
    cin >> depth;
    if ((depth < 1) || (depth > 8)) {
        return 1;
    }

    // define a counter variable to keep track of number of permutations
    int counter = 0;

    // loop to desired depth
    for (int i = 0; i < depth; i++) {
        int currDepth = 1;
        if (currDepth == depth) {
            cout << i << endl;
            counter++;
            continue;
        }
        for (int j = 0; j < depth; j++) {
            currDepth = 2;
            if (j == i) {
                continue;
            }
            if (currDepth == depth) {
                cout << i << j << endl;
                counter++;
                continue;
            }
            for (int k = 0; k < depth; k++) {
                currDepth = 3;
                if ((k == j) || (k == i)) {
                    continue;
                }
                if (currDepth == depth) {
                    cout << i << j << k << endl;
                    counter++;
                    continue;
                }
                for (int l = 0; l < depth; l++) {
                    currDepth = 4;
                    if ((l == k) || (l == j) || (l == i)) {
                        continue;
                    }
                    if (currDepth == depth) {
                        cout << i << j << k << l << endl;
                        counter++;
                        continue;
                    }
                    for (int m = 0; m < depth; m++) {
                        currDepth = 5;
                        if ((m == l) || (m == k) || (m == j) || (m == i)) {
                            continue;
                        }
                        if (currDepth == depth) {
                            cout << i << j << k << l << m << endl;
                            counter++;
                            continue;
                        }
                        for (int n = 0; n < depth; n++) {
                            currDepth = 6;
                            if ((n == m) || (n == l) || (n == k) || (n == j) || (n == i)) {
                                continue;
                            }
                            if (currDepth == depth) {
                                cout << i << j << k << l << m << n << endl;
                                counter++;
                                continue;
                            }
                            for (int o = 0; o < depth; o++) {
                                currDepth = 7;
                                if ((o == n) || (o == m) || (o == l) || (o == k) || (o == j) || (o == i)) {
                                    continue;
                                }
                                if (currDepth == depth) {
                                    cout << i << j << k << l << m << n << o << endl;
                                    counter++;
                                    continue;
                                }
                                for (int p = 0; p < depth; p++) {
                                    if ((p == o) || (p == n) || (p == m) || (p == l) || (p == k) || (p == j) || (p == i)) {
                                        continue;
                                    }
                                    cout << i << j << k << l << m << n << o << p << endl;
                                    counter++;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout << "number of permutations expected: " << fac(depth) << ", actual number: " << counter << endl;
}

int fac(int n) {
    int res = 1;
    for (int i = 1; i <=n; i++) {
        res *= i;
    }
    return res;
}
