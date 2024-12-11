//La fonction doit copier les n premiers éléments du tableau T1 dans le tableau T2 
//FAIRE LES CHOSES DANS CET ORDRE :
//1) ECRIRE LE CONTRAT DE LA FONCTION. Penser à mettre un commentaire en bout de chaque ligne d'ACSL (comme pour les TPs précédents)
//2) CODER LA FONCTION
//3) ESSAYER DE PROUVER ; EXPLIQUER POURQUOI CELA PROUVE OU POURQUOI CELA NE PROUVE PAS
//4) AU CAS OU CELA NE PROUVERAIT PAS, COMPLETER PAR CE QU'IL FAUT
//5) ARRIVER A 100% DE PREUVE

//Penser à mettre un commentaire en bout de ligne ACSL (comme pour les TPs précédents)

/*@ requires R1: n>0;                                   // "n" doit être supérieur à "0"
  @ requires R2: \valid(T1+(0..n-1));                   // "T1" doit être un tableau de "n" éléments de l'adresse "t" à "t+n-1"
  @ requires R3: \valid(T2+(0..n-1));                   // "T2" doit être un tableau de "n" éléments de l'adresse "t" à "t+n-1"
  @ requires R4: \separated(T1+(0..n-1), T2+(0..n-1));  // "T1" et "T2" doivent pas se chevaucher dans la mémoire
  @ assigns T2[0..n-1];                                 // Cette fonction ne modifie tout les éléments de "T2"
  @ ensures \forall integer k; 0<=k<n ==> T1[k]==T2[k]; // Tout les éléments de "T1" seront égaux à "T2"
*/
void CopieTab(int *T1, int *T2, int n) {
  /*@ loop invariant 0<=i<=n;                                    // "i" doit être compris entre "0" et "n"
    @ loop invariant \forall integer k; 0<=k<i ==> T1[k]==T2[k]; // Tout les éléments avent "i" de "T1" sont égaux à "T2"
    @ loop assigns i, T2[0..(n-1)];                              // "i" est la seule variable modifiée
    @ loop variant n-i;                                          // "n-i" diminue à chaque itération
  */
  for(int i=0; i<n; i++) {
    T2[i] = T1[i];
  }
}
