#include <iostream>
#include <vector>
#include <string>
#include <fstream> // pour les lecture-ecriture dans les fichiers

using namespace std;

typedef struct {
  string nom;
  vector<vector<int>> grille;
} Grille;

typedef struct {
  size_t lig;
  size_t col;
} Indices;


// insérer ici les fonctions que vous appelez avant que leurs definitions
// apparaissent dans le fichier
void imprime(const Grille &g); // definie en fin de fichier.


/* Renvoie true ssi la grille a la bonne forme et ne contient que des valeurs
 * de 0 à 9
 */
bool bienFormee(const Grille &g) {
  bool res = true;
  /* a faire */
  return res;
}


/* Verifie si la grille est valide: chaque valeur de 1 à 9 apparait au plus
 * une fois dans chque ligne, colonne et région
 */
bool valide(const Grille &g) {
  bool res = true;
  /* a faire */
  return res;
}


/* renvoie le vecteur des valeurs disponibles pour le couple d'indices ind,
 * compte-tenu des valeurs placées sur sa ligne, colonne et sa région
*/
vector<int> possibles(const Grille &g, Indices ind) {
  vector<int> res;
  /* a faire */
  return res;
}


/* recoit en argument le vecteur des valeurs possibles pour la case
 * d'indices ij. Parcourt les valeurs en cherchant si pour l'une d'entre
 * elles il existe un seul emplacement valide dans la région.
 * Dans ce cas, stocke la valeur dans la case et renvoie true.
 * Renvoie false si pour chaque valeur possible il existe au moins deux
 * cases où on pourrait potentiellement la ranger. Dans ce cas ne
 * modifie pas la grille.
 */
bool force(Grille &g, Indices ij, vector<int> vpossibles) {
  bool res = false;
  /* a faire */
  return res;
}


bool userSuggest(Grille &g) {
  bool res = false;
  /* a faire */
  return res;
}


bool joue(Grille &g) {
  bool res = false;
  cout << "Debut du traitement de la grille " << g.nom << endl;
  imprime(g);
  /* a faire */
  return res;
}

/* quelques grilles prédéfinies */
int main() {
  // Les grilles G2 à G3 peuvent se résoudre sans aide de l'utilisateur
  Grille g2 = { "G2",
		{ { 5, 3, 0, 0, 7, 0, 0, 0, 0 },
		  { 6, 0, 0, 1, 9, 5, 0, 0, 0 },
		  { 0, 9, 8, 0, 0, 0, 0, 6, 0 },
		  { 8, 0, 0, 0, 6, 0, 0, 0, 3 },
		  { 4, 0, 0, 8, 0, 3, 0, 0, 1 },
		  { 7, 0, 0, 0, 2, 0, 0, 0, 6 },
		  { 0, 6, 0, 0, 0, 0, 2, 8, 0 },
		  { 0, 0, 0, 4, 1, 9, 0, 0, 5 },
		  { 0, 0, 0, 0, 8, 0, 0, 7, 9 }
		}};
  Grille g3 = { "G3",
		{ { 0, 2, 7, 0, 6, 5, 0, 4, 9 },
		  { 3, 5, 0, 0, 0, 9, 0, 0, 8 },
		  { 8, 9, 0, 0, 0, 0, 0, 0, 0 },
		  { 2, 0, 0, 0, 9, 0, 0, 0, 0 },
		  { 0, 0, 0, 6, 8, 7, 0, 0, 0 },
		  { 0, 0, 0, 0, 3, 0, 0, 0, 5 },
		  { 0, 0, 0, 0, 0, 0, 0, 6, 3 },
		  { 7, 0, 0, 2, 0, 0, 0, 8, 4 },
		  { 4, 8, 0, 9, 7, 0, 1, 5, 0}
		}};
  Grille g4 = { "G4",
		{ { 8, 0, 0, 0, 0, 0, 1, 0, 0 },
		  { 0, 3, 4, 0, 2, 0, 6, 0, 0 },
		  { 0, 9, 0, 4, 0, 0, 0, 0, 2 },
		  { 5, 1, 0, 0, 4, 2, 9, 6, 0 },
		  { 0, 0, 0, 0, 6, 0, 0, 0, 0 },
		  { 0, 6, 7, 1, 5, 0, 0, 2, 3 },
		  { 9, 0, 0, 0, 0, 4, 0, 3, 0 },
		  { 0, 0, 2, 0, 1, 0, 7, 4, 0 },
		  { 0, 0, 8, 0, 0, 0, 0, 0, 1 }
		}};
  // cette grille admet deux solutions différentes mais demande une aide
  // de l'utilisateur si on se limite aux deux autres stratégies définies
  Grille g5 = { "G5",
		{ { 0, 0, 8, 0, 0, 0, 2, 0, 0 },
		  { 0, 0, 4, 3, 0, 0, 0, 0, 1 },
		  { 0, 5, 0, 0, 0, 7, 0, 8, 9 },
		  { 0, 0, 5, 7, 4, 0, 0, 0, 2 },
		  { 0, 0, 0, 1, 0, 3, 0, 0, 0 },
		  { 4, 0, 0, 0, 2, 0, 6, 0, 0 },
		  { 2, 6, 0, 5, 0, 0, 0, 7, 0 },
		  { 5, 0, 0, 0, 0, 2, 9, 0, 0 },
		  { 0, 0, 1, 0, 0, 0, 5, 0, 0 }
		}};
  joue(g2);
  joue(g3);
  /*
  joue(g4);
  joue(g5);
  */
  return 0;
}

		// Fonctions fournies, rien à modifier a priori.


/* Imprime une ligne de séparation formée du caractère passé en argument */
void imprimeL(char c) {
  cout << ' ';
  for(size_t i = 0; i < 9; i += 1) { cout << c << c << c << c; }
  /* pour prendre en compte les espaces ajoutés prèsb des '+' */
  cout << c << c << c << c << c << c;
  cout << endl;
}

/* suppose la grille bien formee: 9 lignes de 9 colonnes de chiffres de 0 à 9 */
void imprime(const Grille &g) {
  for(size_t i = 0; i < 9; i += 1) {
    imprimeL(i % 3 == 0 ? '+' : '-'); // ligne d'en-tete
    for(size_t j = 0; j < 9; j += 1) {
      char c = '0' + g.grille.at(i).at(j);
      cout << (j % 3 == 0 ? " + " : " " ) << ' ' << c << ' ';
    }
    cout << "+" << endl;
  }
  imprimeL('+'); // ligne finale du bas
  cout << endl;
}
