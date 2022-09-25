#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char* argv[]) {

    bool isMotive(string s, string motif);

    string s = argv[1];
    string motif = argv[2];
    ifstream fichier(s.c_str());
    string buffer = "";
    int compteur = 0;
   
    if (fichier){
        while (fichier >> buffer) {
            if (isMotive(buffer, motif)) {
                compteur++;
            }
        }
        
        fichier.close();
    }
    else {
        std::cout << "The file " << s << " could not be opened.";
        return 1;
    }
        std::cout << "The file " << s << " contains " << compteur << " words containing the motive " << motif;
        return 0;

}

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