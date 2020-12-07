/*A = 010101
B = 10111000
C = 00000
D = 10010
E = 0110
F = 10111001
G = 10111110
H = 010110
I = 1010
J = 10111111
K = 10111100
L = 10111101
M = 01010010
N = 0111
O = 0001
P = 010111
Q = 01000
R = 10011
S = 10110
T = 1000
U = 001
V = 1011101
W = 01010011
X = 00001
Y = 0101000
Z = 01001

int supprimer_x(int *tableau, int taille, int X)
{
	int nbSupprime = 0;
	int *pLecture=tableau, *pEcriture=tableau;
	for(pLecture=tableau ; pLecture<tableau+taille ; pLecture++)
	{
		/*On 'ecrit' l'element si ce n'est pas X*/
		int element = *pLecture;
		if(element == X)
			nbSupprime++;
		else
		{
			*pEcriture = element;
			pEcriture++;
		}
	}
	return nbSupprime;
}

Node *createLinkedList(void *value) {
    Node *head = NULL;
    head = (Node*) malloc(sizeof(Node));
 
    if (head == NULL) printf("Erreur lors de l'allocation mémoire d'un Noeud");
 
    head->next = NULL;
    head->value = value;
 
    return head;
}

void add(Node *headNode, Node *newNode) {
 
    Node *lastNode = headNode;
 
    if (find(headNode, newNode->value) != -1) {
        printf("\nElement déjà présent dans la liste ");
        return;
    }
 
    while (lastNode->next != NULL) {
        lastNode = lastNode->next;
    }
 
    lastNode->next = newNode;
}

def Supprimer(noeud, cle):
    if noeud is None:
        return
 
    # si cle est inférieure à la valeur du noeud, rechercher dans le sous-arbre gauche
    if cle < noeud.val:
        noeud.gauche = Supprimer(noeud.gauche, cle)
 
    # si cle est supérieure à la valeur du noeud, rechercher dans le sous-arbre droit
    elif(cle > noeud.val):
        noeud.droit = Supprimer(noeud.droit, cle)
 
    # sinon
    else:
 
        # noeud a un fils unique
        if noeud.gauche is None:
            temp = noeud.droit
            noeud = None
            return temp
 
        elif noeud.droit is None:
            temp = noeud.gauche
            noeud = None
            return temp
 
        # noeud a deux enfants
        succ = Successeur(noeud.droit)
 
        # le cas de prédécesseur
        # pred=Predecesseur(noeud.gauche)
 
        # remplacer la valeur du noeud à supprimer avec la valeur du successeur
        noeud.val = succ.val
 
        # supprimer le successeur
        noeud.droit = Supprimer(noeud.droit, succ.val)
 
        # le cas de prédecesseur
        #noeud.gauche = Supprimer(noeud.gauche, succ.val)
 
    return noeud


23.1 
(∗) Écrire une fonction qui recherche un nombre n dans un arbre d’entiers. La
fonction doit renvoyer 1 si n est présent, 0 sinon.

void Recherchen(TypeNoeud * racine, int n, int *retour)
{
if (racine != NULL)
{
if (racine->donnee == n)
*retour = 1;
Recherchen(racine->fg, n, retour);
Recherchen(racine->fd, n, retour);
}
}



typedef struct node
{
    unsigned int key;
    struct node *left;
    struct node *right;
} node ;

node *Arbre = NULL;

void addNode(node **tree, unsigned int key)
{
    node *tmpNode;
    node *tmpTree = *tree;

    node *elem = malloc(sizeof(node));
    elem->key = key;
    elem->left = NULL;
    elem->right = NULL;

    if(tmpTree)
    do
    {
        tmpNode = tmpTree;
        if(key > tmpTree->key )
        {
            tmpTree = tmpTree->right;
            if(!tmpTree) tmpNode->right = elem;
        }
        else
        {
            tmpTree = tmpTree->left;
            if(!tmpTree) tmpNode->left = elem;
        }
    }
    while(tmpTree);
    else  *tree = elem;
}

void clearTree(node **tree)
{
    node *tmpTree = *tree;

    if(!tree) return;

    if(tmpTree->left)  clearTree(&tmpTree->left);

    if(tmpTree->right) clearTree(&tmpTree->right);
        
    free(tmpTree);

    *tree = NULL;
}