#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class VaultDoor8 {
public:
    std::vector<char> scramble(const std::string& password) {
        /* Scramble a password by transposing pairs of bits. */
        std::vector<char> a(password.begin(), password.end());
        for (size_t b = 0; b < a.size(); b++) {
            char c = a[b];
            c = switchBits(c, 1, 2);
            c = switchBits(c, 0, 3);
            c = switchBits(c, 5, 6);
            c = switchBits(c, 4, 7);
            c = switchBits(c, 0, 1);
            c = switchBits(c, 3, 4);
            c = switchBits(c, 2, 5);
            c = switchBits(c, 6, 7);
            a[b] = c;
        }
        return a;
    }
