#include "isMotive.h"

string s;
string motif;
bool isMotive(string s, string motif) {
    if (s.size() < motif.size()) {
        return false;
    }

    int j = 0;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == motif[j]) {
            j++;
        }
        else {
            j = 0;
        }

        if (j == motif.size()) {
            return true;
        }

        if (j == 0 && (s.size() - i) <= motif.size()) {
            return false;
        }
    }
    return false;
}