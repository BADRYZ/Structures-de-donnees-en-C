#define faux 0
#define vrai 1
typedef int booleen;
typedef void Objet;





typedef int booleen;
///////////
typedef void objet;
////// MEMORISATION DUN ARBRE BINAIRE
typedef struct noeud {
	objet* reference;
	struct noeud* gauche;
	struct noeud* droite;
	
}Noeud;

typedef  struct {
	Noeud* racine;
	char* (*afficher)(objet*);
	int (*comparer)(objet*,objet*);
}Arbre;

Noeud* cNd(objet* objet,Noeud* gauche,Noeud* droite);

Noeud* cF (objet* objet);

void initArbre (Arbre* arbre,Noeud* racine,char* (*afficher) (objet*),int (*comparer)(objet*,objet*));

Arbre* creeArbre (Noeud* racine, char* (*afficher)(objet*),int (*comparer)(objet*,objet*));

void prefixe (Noeud* racine,char* (*afficher)(objet*));

void infixe (Noeud* racine,char*(*afficher)(objet*));

void postfixe(Noeud* racine , char* (*afficher)(objet*));
Noeud* trouverNoeud (Noeud* racine, Objet* objet,int(*comparer)(Objet*,Objet*));


//Noeud* trouverNoeud(Noeud* racine , Objet* objet,int (*comparer)(objet*,objet*));

void enLargeur(Noeud* racine,char* (*afficher) (objet*));

int taille(Noeud* racine);

booleen estFeuille (Noeud* racine);

int nbFeuilles (Noeud* racine);

void listerFeuilles (Noeud* racine,char* (*afficher)(objet*));

int hauteur (Noeud* racine);

booleen egaliteArbre (Noeud* racine1,Noeud* racine2,int (*comparer)(objet*,objet*));

