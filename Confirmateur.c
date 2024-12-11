//TP1: Réalisation d'un confirmateur
//Objectifs du TP: 
//	- Analyse d'un contrat ACSL: analyse de chaque ligne ACSL à mettre en bout de ligne sous forme de commentaire
//	- codage de la fonction confirmateur à partir de l'ACSL
//	- preuve

//Entrée:
_Bool E;

//Sortie:
_Bool S;

//Compteur (état interne) = nombre de ticks d'une horloge temps-réel
static unsigned int Cpt;

//Temps de confirmation (configuration) en nombre de de ticks de la même horloge temps-réel
extern unsigned int ConfTime;


/*@ requires ConfTime >= 1; // ConfTime doit être supérieur ou égal à 1
  @ assigns S, Cpt; // Les variable S et Cpt peuvent être modifiées
  @ behavior OutputSetTo1: //
  @   assumes E == 1 && Cpt >= ConfTime; // Si E vaut 1 et que Cpt est supérieur ou égal à ConfTime
  @   ensures Output: S == 1;
  @   ensures Cpt == \old(Cpt) + 1;
  @   assigns S, Cpt;
  @ behavior OutPutSetTo0Input0:
  @   assumes E == 0;
  @   ensures S == 0;
  @   ensures Cpt == 0;
  @   assigns S, Cpt;
  @ behavior OutPutSetToInput1NotConfirmed:
  @  assumes E == 1 && Cpt < ConfTime;
  @  ensures S == 0;
  @  ensures Cpt == \old(Cpt) + 1;
  @  assigns S, Cpt;
  @
  @ complete behaviors OutputSetTo1, OutPutSetTo0Input0, OutPutSetToInput1NotConfirmed; // Ils doivet couvir tout les sénario
  @ disjoint behaviors OutputSetTo1, OutPutSetTo0Input0;
  @ disjoint behaviors OutPutSetTo0Input0, OutPutSetToInput1NotConfirmed;
  @ disjoint behaviors OutputSetTo1, OutPutSetToInput1NotConfirmed;
*/
void Conf(void) {

	S == 1; //Code à remplacer par celui implémentant le confirmateur.

}
