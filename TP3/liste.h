#define faux  0
#define vrai 1
#define NONORDONNE 0
#define CROISSANT 1
#define DECROISSANT 2

//#include <stdbool.h>

typedef void objet;
typedef int booleen;



//un element de la liste
typedef struct element {
	objet* reference ;//reference un objet
	struct element* suivant; //element suivant de la liste
	
}Element;



//le type listes
typedef struct {
	Element* premier;//premier elemnt de la liste
	Element* dernier;
	Element* courant;
	int nbElt;
	int type;
	char* (*afficher)(objet*);
	int (*comparer)(objet*,objet*);
}Liste;

////////////////////////////////////////////////////////
int comparer (objet* objet1, objet* objet2);
char* afficher(objet* objet);
//void initliste(liste* li,int type,char* (*afficher) (objet*),int (*comparer)(objet*,objet*));

////////////////////////////////////////////////////////

//initialiser la liste pointee pa li 
void initListe(Liste* li,int type,char*(*afficher)(objet*),int(*comparer)(objet*,objet*));


//CREATION DUNE LISTE


Liste* creerListe(int type,char* (*afficher)(objet*),int (*comparer)(objet*,objet*));



//booleen listevide(liste* li);
booleen listevide(Liste* li);


int nbElement(Liste* li);


//AJOUT EN TETE DE LISTE
static Element* creeElement();


void insererEnTeteDeListe(Liste* li,objet* objet);



//ajout apres lelement precedent
// insert dans la liste li,objet apres precendent
//si precedent est NULL,inserer en tet de liste
static void insererApres(Liste*li,Element *precedent,objet* objet);
//ajout en fin de liste
void insererEnFinDeListe(Liste *li,void *objet);

//void insererEnFinDeListe(Liste *li,objet *objet);
//void insererEnFinDeListe(liste *li, objet *objet);


//se positionner sur le premier element de la liste li
void ouvrireListe(Liste* li);





booleen finListe(Liste* li);




//courant elemt
static Element *elementCourant (Liste *li);



//objet courant
objet* objetCourant (Liste *li);


//lister liste(liste* li)
void listerListe(Liste *li);



//chercher un objet
objet* chercherUnobjet(Liste *li,objet *objetCherche); 




//retrait  en tete de liste
objet* extraireEnTeteDeListe (Liste *li);
//retrait de elt qui suit elet precedent 

static objet* extraireApres(Liste *li, Element *precedent);




// retrait de lobjet en fin de liste
objet* extraireEnFinDeListe(Liste *li );



//retrait dun objet a partir de sa reference
booleen extraireUnobjet (Liste *li,objet *objet);

void detruireListe(Liste *li);

