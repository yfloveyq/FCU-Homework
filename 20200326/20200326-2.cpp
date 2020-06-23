#include <iostream>
#include <cstdlib>

using namespace std;

int main() {

    int Alp[26] = {0};
    int alp[26] = {0};
    char n[] = {"To be, or not to be:that is the question"};


    for (int i = 0; n[i] != 0; ++i) {
        if (n[i] >= 'a' && n[i] <= 'z')
            alp[n[i] - 'a']++;
        else if (n[i] >= 'A' && n[i] <= 'Z')
            Alp[n[i] - 'A']++;
    }

    int out[26];

    for (int l = 0; l < 26; ++l) {
        out[l] = alp[l] + Alp[l];
    }

    for (int j = 0; j < 26; ++j) {
        cout << char(j+'a') << " " << out[j] << endl;
    }


    return 0;
}