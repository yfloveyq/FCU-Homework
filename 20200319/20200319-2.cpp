#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int main() {

    string s[] = {"Tainan", "Taichung", "Taiwan", "Taipei", "Yilan", "Hualian", "Zhanghua", "Pingtong", "Keelung",
                  "Nantou"};

    for (int i = 9; i; --i) {
        for (int j = 0; j < i; ++j) {
            if (s[j] > s[j + 1]) {
                string t;
                t = s[j];
                s[j] = s[j + 1];
                s[j + 1] = t;

            }
        }
    }

    for (int k = 0; k < 10; ++k) {
        cout << s[k] << endl;
    }

    return 0;
}
