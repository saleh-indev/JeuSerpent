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


// ins�rer ici les fonctions que vous appelez avant que leurs definitions
// apparaissent dans le fichier
void imprime(const Grille &g); // definie en fin de fichier.


/* Renvoie true ssi la grille a la bonne forme et ne contient que des valeurs
 * de 0 � 9
 */
bool bienFormee(const Grille &g) {
    bool res = true;
    for (int i = 0; i< g.grille.size(); i++ ){
            for (int j = 0; j < g.grille.at(i).size(); j++){
                if (g.grille.at(i).at(j) < 0 or g.grille.at(i).at(j) >9){
                        res = false;
            }
        }
    for (int i = 0; i < g.grille.size(); i++ ){
        for (int j = 0; j < g.grille.at(i).size(); j++){
            if (g.grille.at(i).size() == 9 && g.grille.size() == 9){
                res = true;
            }
            else {
                res = false;
            }
        }
    }
  return res;
}
}


/* Verifie si la grille est valide: chaque valeur de 1 � 9 apparait au plus
 * une fois dans chque ligne, colonne et r�gion
 */
bool valide(const Grille &g) {

  bool res = true;
  /* a faire */
  return res;
}
/*
verifie si un chiffre peut etre a l'indice ind
*/
bool possible(const Grille &g, Indices ind,int x){
  //Verifie la case courante n'est pas vide
  if(g.grille.at(ind.lig).at(ind.col)!=0) return false;

  //Verification de la colonne et ligne correspondante
  for(int i=0;i<9;i++){
    if(g.grille.at(ind.lig).at(i)!=x) return false;
    if(g.grille.at(i).at(ind.col)!=x) return false;
  }

  //Verification de la zone
  int zone_ligne= ind.lig/3, zone_col=ind.col/3;
  for(int i=zone_ligne;i<zone_ligne+3;i++){
      for(int j=zone_col;j<zone_col+3;j++){
      if(g.grille.at(i).at(j)==x) return false;
    }
  }
  return true;
}


/* renvoie le vecteur des valeurs disponibles pour le couple d'indices ind,
 * compte-tenu des valeurs plac�es sur sa ligne, colonne et sa r�gion
*/
vector<int> possibles(const Grille &g, Indices ind) {
  vector<int> res;
  for(int i=1;i<=9;i++){
    if(possible(g,ind,i)) res.push_back(i);
  }
  return res;
}

/* recoit en argument le vecteur des valeurs possibles pour la case
 * d'indices ij. Parcourt les valeurs en cherchant si pour l'une d'entre
 * elles il existe un seul emplacement valide dans la r�gion.
 * Dans ce cas, stocke la valeur dans la case et renvoie true.
 * Renvoie false si pour chaque valeur possible il existe au moins deux
 * cases o� on pourrait potentiellement la ranger. Dans ce cas ne
 * modifie pas la grille.
 */
bool force(Grille &g, Indices ij, vector<int> possibles) {
  int compteur=0;
  for(int k=0;k<possibles.size();k++){
    compteur=0;
    for(int i=ij.lig/3;i<ij.lig+3;i++){
      for(int j=ij.col/3;j<ij.col+3;j++){
      if(g.grille.at(i).at(j)==possibles.at(k)) compteur++;
    }
    }
    if(compteur==1){
      g.grille.at(ij.lig).at(ij.col)=possibles.at(k);
      return true;
    } 
  }
  //Pour chaque valeur , il existe plusieurs possibilités
  return false;
}
/*
Verifie si une case est vide ou pas
*/
bool estCaseVide( Grille &g, Indices ind){
  return g.grille.at(ind.lig).at(ind.col)==0;
}

bool userSuggest(Grille &g) {
  int userSuggest=0;

  cout<<"Voulez-vous suggerer une valeur ? (0 ou 1)"<<endl;
   do{
     cin>>userSuggest;
    }while(userSuggest!=0 && userSuggest!=1);

  if(userSuggest){
      int valeur=0,i=0,j=0;
      cout<<"Donnez une valeur entre 1 et 9 :"<<endl;
    do{
      cin>>valeur;
    }while(valeur<1 || valeur>9);
    cout<<"Donnez les indices de la case entre 1 et 9:"<<endl;
    do{
      cin>>i;
    }while(i<1 || i>9);
    do{
      cin>>j;
    }while(j<1 || j>9);
    Indices ind;
    ind.col=j-1;
    ind.lig=i-1;
    if(estCaseVide(g,ind) && possible(g,ind,valeur)) {
      g.grille.at(ind.lig).at(ind.col)=valeur;
      return true;
    }
  }
  else return false;
}


Indices getIndicesCaseVide(const Grille &g){
  for(int i=0;i<9;i++){
      for(int j=0;j<9;j++){
      if(g.grille.at(i).at(j)==0) {
        Indices ind;
        ind.col=j;
        ind.lig=i;
        return ind;
      }
    }
  }
}
/*
Retourne le nombre de case vide de la grille
*/
int getNombreCaseVides(const Grille &g){
  int nbr=0;
   for(int i=0;i<9;i++){
      for(int j=0;j<9;j++){
      if(g.grille.at(i).at(j)==0) nbr++;
      }
   }
   return nbr;
}

bool joue(Grille &g) {
  cout << "Debut du traitement de la grille " << g.nom << endl;
  imprime(g);
  /* a faire */
  if(!bienFormee(g) || !valide(g)) return false;
  Indices ind;
  while(getNombreCaseVides(g)>0){
    ind=getIndicesCaseVide(g);
    if(!force(g,ind,possibles(g, ind))){
        continue;
    }
    if(!valide(g)) break;
    if(!bienFormee(g)) break;
  }
  if(getNombreCaseVides(g)==0) return true; //si la grille est resolue
  else return false;
}

/* quelques grilles pr�d�finies */
int main() {
  // Les grilles G2 � G3 peuvent se r�soudre sans aide de l'utilisateur
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
  // cette grille admet deux solutions diff�rentes mais demande une aide
  // de l'utilisateur si on se limite aux deux autres strat�gies d�finies
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
  cout<<"Après le jeu :"<<endl;
  imprime(g2);
  //joue(g3);
  /*
  joue(g4);
  joue(g5);
  */
  return 0;
}

		// Fonctions fournies, rien � modifier a priori.


/* Imprime une ligne de s�paration form�e du caract�re pass� en argument */
void imprimeL(char c) {
  cout << ' ';
  for(size_t i = 0; i < 9; i += 1) { cout << c << c << c << c; }
  /* pour prendre en compte les espaces ajout�s pr�sb des '+' */
  cout << c << c << c << c << c << c;
  cout << endl;
}

/* suppose la grille bien formee: 9 lignes de 9 colonnes de chiffres de 0 � 9 */
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
