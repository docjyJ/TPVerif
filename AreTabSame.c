//La fonction doit retourner 1 si les n premiers éléments des tableaux T1 et T2 sont égaux, ou 0 dans le cas contraire. 
//FAIRE LES CHOSES DANS CET ORDRE :
//1) ECRIRE LE CONTRAT DE LA FONCTION. Penser à mettre un commentaire en bout de chaque ligne d'ACSL (comme pour les TPs précédents)
//2) CODER LA FONCTION
//3) ESSAYER DE PROUVER ; EXPLIQUER POURQUOI CELA PROUVE OU POURQUOI CELA NE PROUVE PAS
//4) AU CAS OU CELA NE PROUVERAIT PAS, COMPLETER PAR CE QU'IL FAUT
//5) ARRIVER A 100% DE PREUVE

//Penser à mettre un commentaire en bout de ligne ACSL (comme pour les TPs précédents)

/*@ requires R1: n>0;                                  // "n" doit être supérieur à "0"
  @ requires R2: \valid(T1+(0..(n-1)));                // "T1" doit être un tableau de "n" éléments de l'adresse "t" à "t+n-1"
  @ requires R3: \valid(T2+(0..(n-1)));                // "T2" doit être un tableau de "n" éléments de l'adresse "t" à "t+n-1"
  @ requires R4: \separated(T1+(0..n-1), T2+(0..n-1)); // "T1" et "T2" doivent pas se chevaucher dans la mémoire
  @ assigns \nothing;                   // Cette fonction ne modifie rien
  @
  @ behavior B1:                                          // Sénario 1
  @   assumes \forall integer k; 0<=k<n ==> T1[k]==T2[k]; // Tout les éléments de "T1" sont égaux à "T2"
  @   ensures \result==1;                                 // La fonction doit retourner "true"
  @
  @ behavior B2:                                          // Séanrio 2
  @   assumes \exists integer k; 0<=k<n && T1[k]!=T2[k];  // Il existe un élément de "T1" qui n'est pas égal à "T2"
  @   ensures \result==0;                                 // La fonction doit retourner "false"
  @
  @ complete behaviors B1, B2;                            // Les scénarios doivent couvrir tout les cas possibles
  @ disjoint behaviors B1, B2;                            // Les scénarios ne doivent pas se chevaucher
*/
_Bool SameTab(int *T1, int *T2, int n) {
  /*@ loop invariant 0<=i<=n;                                    // "i" doit être compris entre "0" et "n"
    @ loop invariant \forall integer k; 0<=k<i ==> T1[k]==T2[k]; // Tout les éléments avent "i" de "T1" sont égaux à "T2"
    @ loop assigns i;                                            // "i" est la seule variable modifiée
    @ loop variant n-i;                                          // "n-i" diminue à chaque itération
  */
  for(int i=0; i<n; i++) {
    if(T1[i]!=T2[i]) return 0;
  }
  return 1;
}
