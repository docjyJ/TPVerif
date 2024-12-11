//TP2: initialisation des n premiers éléments d'un tableau à 0
//Objectifs du TP: 
//      - Analyse d'un contrat ACSL: analyse de chaque ligne ACSL à mettre en bout de ligne sous forme de commentaire.
//      - codage de la fonction InitWithZero à partir de l'ACSL
//      - preuve

#define SIZE_MAX 1000

/*@ requires R1: 0<n && n < SIZE_MAX;					// "n" doit être compris entre "0" et "SIZE_MAX"
  @ requires R2: \valid(t+(0..(n-1)));					// "t" doit être un tableau de "n" éléments de l'adresse "t" à "t+n-1"
  @ ensures E1: \forall integer k; 0<=k<n ==> t[k]==0;	// S'assure que tous les éléments de "t" sont égaux à "0" à la fin de la fonction
  @ assigns t[0..(n-1)];								// Cette fonction peut modifier tous les éléments de "t".
*/
void InitWithZero(int *t, int n) {
	int i;

	/*@ loop invariant I_RANGE_i: 0 <= i <= n;						// Pour chaque itération, "i" doit être compris entre "0" et "n"
	  @ loop invariant I_E1: \forall integer k; 0<=k<i ==> t[k]==0; // Pour chaque itération, les éléments de "t" avant "i" doivent être égaux à "0"
	  @ loop assigns i, t[0..(n-1)];								// Cette boucle peut modifier "i" et tous les éléments de "t"
	  @ loop variant n-i;											// "n-i" doit être décroissant à chaque itération
	*/
	for(i=0;i<n;i++) {
		t[i]=0;
	}

}
