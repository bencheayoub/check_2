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
char switchBits(char c, int p1, int p2) {
        /* Move the bit in position p1 to position p2, and move the bit
           that was in position p2 to position p1. Precondition: p1 < p2 */
        char mask1 = (char)(1 << p1);
        char mask2 = (char)(1 << p2);
        char bit1 = (char)(c & mask1);
        char bit2 = (char)(c & mask2);
        char rest = (char)(c & ~(mask1 | mask2));
        char shift = (char)(p2 - p1);
        char result = (char)((bit1 << shift) | (bit2 >> shift) | rest);
        return result;
    }
bool checkPassword(const std::string& password) {
        std::vector<char> scrambled = scramble(password);
        std::vector<char> expected = {
            0xF4, 0xC0, 0x97, 0xF0, 0x77, 0x97, 0xC0, 0xE4,
            0xF0, 0x77, 0xA4, 0xD0, 0xC5, 0x77, 0xF4, 0x86,
            0xD0, 0xA5, 0x45, 0x96, 0x27, 0xB5, 0x77, 0xC2,
            0xD2, 0x95, 0xA4, 0xF0, 0xD2, 0xD2, 0xC1, 0x95
        };
        return scrambled == expected;
    }
};
int main() {
    std::string input;
    std::cout << "Enter vault password: ";
    std::cin >> input;

    // Extract the substring (excluding the first 8 and last 1 characters)
    std::string f = input.substr(8, input.length() - 9);

    VaultDoor8 vault;
    if (vault.checkPassword(f)) {
        std::cout << "Access granted." << std::endl;
    } else {
        std::cout << "Access denied!" << std::endl;
    }

    return 0;
}
