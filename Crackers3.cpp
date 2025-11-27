#include <iostream>
#include <vector>

using namespace std;
// --- FONCTION : Vérifie si un code testé respecte les règles d'une ligne ---
bool verifierLigne(const vector<int>& codeTest, const vector<int>& ligneNombres, int cibleBP, int cibleMP) {
    int bp = 0; // Bien Placé
    int mp = 0; // Mal Placé

    // On copie pour ne pas modifier les originaux
    vector<int> code = codeTest;
    vector<int> ligne = ligneNombres;
    vector<bool> codeUtilise(3, false);
    vector<bool> ligneUtilise(3, false);

    // 1. Compter les BIEN PLACÉS (Verts)
    for (int i = 0; i < 3; i++) {
        if (code[i] == ligne[i]) {
            bp++;
            codeUtilise[i] = true;
            ligneUtilise[i] = true;
        }
    }

    // 2. Compter les MAL PLACÉS (Bleus/Jaunes)
    for (int i = 0; i < 3; i++) {
        if (codeUtilise[i]) continue;
        for (int j = 0; j < 3; j++) {
            if (ligneUtilise[j]) continue;

            if (code[i] == ligne[j]) {
                mp++;
                ligneUtilise[j] = true;
                break;
            }
        }
    }

    // Le test est réussi seulement si on a exactement le même nombre de BP et MP
    return (bp == cibleBP && mp == cibleMP);
}


int main() {
    // --- 1. INPUT ---
    vector<vector<int>> vc = {
        {1,0,2},
        {2,0,1},
        {3,0,0},
        {2,1,0},
        {2,0,1}
    };

    vector<vector<int>> vn = {
        {4,6,3},
        {5,6,9},
        {5,7,8},
        {2,9,1},
        {2,4,5}
    };
 /*vector<vector<int>> vc = {
        {1,1,1}, // Ligne 0
        {3,0,0}, // Ligne 1 (Tout Faux !)
        {2,1,0}, // Ligne 2
        {1,0,2}, // Ligne 3
        {1,1,1}  // Ligne 4
    };

    vector<vector<int>> vn = {
        {2,3,4},
        {5,6,7},
        {5,6,4},
        {4,0,1},
        {1,2,4}
    };
    vector<vector<int>> vc = {{2,0,1},
                                {2,0,1},
                                    {2,0,1},
                                   {2,0,1},
                                    {3,0,0}};
    vector<vector<int>> vn = {{1,5,4},
                                {5,8,7},
                                    {8,1,9},
                                   {6,0,5},
                                    {7,0,2}};*/
    

    // --- 2. RECHERCHE DE LA COMBINAISON ---
    // On teste toutes les combinaisons possibles (000 -> 999)
    for (int i = 0; i <= 9; i++) {
        for (int j = 0; j <= 9; j++) {
            for (int k = 0; k <= 9; k++) {
                vector<int> candidat = {i,j,k};
                bool candidatValide = true;

                // Vérifier ce candidat contre TOUTES les lignes de conditions
                for (size_t l = 0; l < vn.size(); l++) {
                    
                     
                    if (!verifierLigne(candidat, vn[l], vc[l][1], vc[l][2])) {
                       
                        candidatValide = false;
                        break;
                    }
                }

                // Si le candidat est valide, on affiche et on quitte
                if (candidatValide) {
                    cout << "\n RESULTAT TROUVE : " << i << j << k  << endl;
                    
                      return 0;
                }
            }
        }
    }


    return 0;
}


