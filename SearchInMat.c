//Search() returns 1 if Val is in TAB, 0 otherwise

//FAIRE LES CHOSES DANS CET ORDRE :
//1) ECRIRE LE CONTRAT DE LA FONCTION. 
//2) CODER LA FONCTION
//3) ESSAYER DE PROUVER ; EXPLIQUER POURQUOI CELA PROUVE OU POURQUOI CELA NE PROUVE PAS
//4) AU CAS OU CELA NE PROUVERAIT PAS, COMPLETER PAR CE QU'IL FAUT
//5) ARRIVER A 100% DE PREUVE

//Penser à mettre un commentaire en bout de ligne ACSL (comme pour les TPs précédents)

#define SIZE_X 100
#define SIZE_Y 100
int Tab[SIZE_X][SIZE_Y];



/*@ requires R1: SIZE_X > 0;
  @ requires R2: SIZE_Y > 0;
  @ requires R3: \valid(Mat+(0..SIZE_X-1)+(0..SIZE_Y-1));
  @ assigns \nothing;
  @
  @ behavior B1:
  @   assumes \exists integer k, p; 0<=k<SIZE_X && 0<=p<SIZE_X && Mat[k][p]==Val;
  @   ensures \result==1;
  @
  @ behavior B2:
  @   assumes \forall integer k, p; 0<=k<SIZE_X && 0<=p<SIZE_X && Mat[k][p]!=Val;
  @   ensures \result==0;
  @
  @ complete behaviors B1, B2;
  @ disjoint behaviors B1, B2;
*/
int Search(int Val) {
  /*@ loop invariant 0<=i<=SIZE;                                // "i" doit être compris entre "0" et "SIZE"
    @ loop invariant \forall integer k; 0<=k<i ==> Tab[k]!=Val; // Tout les éléments avent "i" de "Tab" ne sont pas égaux à "Val"
    @ loop assigns i;                                           // "i" est la seule variable modifiée
    @ loop variant SIZE-i;                                      // "SIZE-i" diminue à chaque itération
  */
  for(int i=0; i<SIZE_X; i++) {
    for(int j=0; j<SIZE_Y; j++) {
      if(Tab[i][j]==Val) return 1;
    }
  }
  return 0;
}
