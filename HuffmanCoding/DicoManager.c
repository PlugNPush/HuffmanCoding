

void add_charl(char*s)
{
   int t=strlen(s);

    realoc( s, t+1);

    s[t+1]='\ 0';
    s[t]=0;
}
void add_charr(char*s)
{
    int t=strlen(s);

    realoc( s, t+1);

    s[t+1]='\ 0';
    s[t]=1;
}

void create_dico(struct element* tree,char* code,)
{

    if (tree==NULL)
    {
        return(0);
    }
    else if(tree->left==NULL && tree->right==NULL)
    {
        fputc("%s : %s",tree->infochar,code,Dictionnaire.txt); //Si on arrive à une feuille, on rentre Lettre ; Code dans le fichier dictionnaire.

    }
    else
    {
        create_dico(tree->left,add_charl(code)); // on recommence ensuite avec si à gauche 0Code ex(0101)
        create_dico(tree->right,add_charr(code));// et à droite avec 1Code (ex 1101)
    }
}
