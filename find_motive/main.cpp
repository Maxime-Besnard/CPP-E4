#include <fstream>
#include "isMotive.h"

int main(int argc, char* argv[]) {

    string s = argv[1];
    string motif = argv[2];
    ifstream fichier(s.c_str());
    string buffer = "";
    int compteur = 0;

    if (fichier) {
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