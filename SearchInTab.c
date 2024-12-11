//Search() returns 1 if Val is in TAB, 0 otherwise

//FAIRE LES CHOSES DANS CET ORDRE :
//1) ECRIRE LE CONTRAT DE LA FONCTION. 
//2) CODER LA FONCTION
//3) ESSAYER DE PROUVER ; EXPLIQUER POURQUOI CELA PROUVE OU POURQUOI CELA NE PROUVE PAS
//4) AU CAS OU CELA NE PROUVERAIT PAS, COMPLETER PAR CE QU'IL FAUT
//5) ARRIVER A 100% DE PREUVE

//Penser à mettre un commentaire en bout de ligne ACSL (comme pour les TPs précédents)

#define SIZE 100
int Tab[SIZE];



/*@ requires R1: SIZE > 0;                  // "SIZE" doit être supérieur à "0"
  @ requires R2: \valid(Tab+(0..(SIZE-1))); // "Tab" doit être un tableau valide
  @ assigns \nothing;                       // Cette fonction ne modifie rien
  @
  @ behavior B1:                                           // Séanrio 1
  @   assumes \exists integer k; 0<=k<SIZE && Tab[k]==Val; // Il existe un élément de "Tab" qui est égal à "Val"
  @   ensures \result==1;                                  // La fonction doit retourner "true"
  @
  @ behavior B2:                                            // Sénario 2
  @   assumes \forall integer k; 0<=k<SIZE ==> Tab[k]!=Val; // Tout les éléments de "Tab" qui n'est pas égal à "Val"
  @   ensures \result==0;                                   // La fonction doit retourner "false"
  @
  @ complete behaviors B1, B2; // Les scénarios doivent couvrir tout les cas possibles
  @ disjoint behaviors B1, B2; // Les scénarios ne doivent pas se chevaucher
*/
int Search(int Val) {
  /*@ loop invariant 0<=i<=SIZE;                                // "i" doit être compris entre "0" et "SIZE"
    @ loop invariant \forall integer k; 0<=k<i ==> Tab[k]!=Val; // Tout les éléments avent "i" de "Tab" ne sont pas égaux à "Val"
    @ loop assigns i;                                           // "i" est la seule variable modifiée
    @ loop variant SIZE-i;                                      // "SIZE-i" diminue à chaque itération
  */
  for(int i=0; i<SIZE; i++) {
    if(Tab[i]==Val) return 1;
  }
  return 0;
}
