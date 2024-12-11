//TP1: Réalisation d un confirmateur
//Objectifs du TP:
//	- Analyse d un contrat ACSL: analyse de chaque ligne ACSL à mettre en bout de ligne sous forme de commentaire
//	- codage de la fonction confirmateur à partir de l ACSL
//	- preuve

//Entrée:
_Bool E;

//Sortie:
_Bool S;

//Compteur (état interne) = nombre de ticks d une horloge temps-réel
static unsigned int Cpt;

//Temps de confirmation (configuration) en nombre de de ticks de la même horloge temps-réel
extern unsigned int ConfTime;


/*@
  @ requires ConfTime >= 1; // Prestate: La variable ConfTime doit être supérieure ou égale à 1
  @ assigns S, Cpt; // On peut modifier l espace mémoire alloué au booléen S et au unsigned int Cpt
  @ behavior OutputSetTo1: // Si l entrée E=1 et la valeur du compteur Cpt dépasse le temps de confirmation ConfTime, ce behavior écrit la valeur 1 dans la sortie S et incrémente le compteur Cpt
  @   assumes E == 1 && Cpt >= ConfTime; // Prestate: Pour ce behavior particulier, la variable E doit valoir 1 et Cpt doit être supérieure ou égale à ConfTime
  @   ensures Output: S == 1; // Poststate: Ce behavior écrit la valeur 1 dans la variable booléenne S.
  @   ensures Cpt == \old(Cpt) + 1; // Poststate: Ce behavior incrémente le compteur de 1 par rapport à son ancienne valeur.
  @   assigns S, Cpt; // Ce behavior a le droit de modifier l espace mémore alloué au booléen S et au unsigned int Cpt
  @ behavior OutPutSetTo0Input0: // Si l entrée E=0, ce behavior écrit la valeur 0 dans la sortie S et remet le compteur Cpt à 0.
  @   assumes E == 0; // Prestate: Pour ce behavior, la variable E doit valoir 0
  @   ensures S == 0; // Poststate: Ce behavior écrit la valeur 0 dans la variable de sortie S
  @   ensures Cpt == 0; // Poststate: Ce behavior remet le compteur à 0, c est à dire il écrit la valeur 0 dans la variable Cpt à 0
  @   assigns S, Cpt; // Ce behavior a le droit de modifier l espace mémore alloué au booléen S et au unsigned int Cpt
  @ behavior OutPutSetToInput1NotConfirmed: // Si l entrée E=1 et la valeur du compteur Cpt est inférieure strictement au temps de confirmation ConfTime,ce behavior écrit la valeur 0 dans la sortie S et incrémente le compteur Cpt
  @  assumes E == 1 && Cpt < ConfTime; // Prestate: Pour ce behavior, l entrée E doit valoir 1 et le compteur Cpt doit avoir une valeur strictement inférieure à la valeur du  temps de confirmation ConfTime
  @  ensures S == 0; // Poststate: Ce behavior écrit la valeur 0 dans la variable de sortie S
  @  ensures Cpt == \old(Cpt) + 1; // Poststate: Ce behavior incrémente le compteur de 1 par rapport à son ancienne valeur.
  @  assigns S, Cpt; // Ce behavior a le droit de modifier l espace mémore alloué au booléen S et au unsigned int Cpt
  @
  @ complete behaviors OutputSetTo1, OutPutSetTo0Input0, OutPutSetToInput1NotConfirmed; // Cette instruction permet de  spécifier que toutes les possibilités sont couvertes par ces 3 behaviors
  @ disjoint behaviors OutputSetTo1, OutPutSetTo0Input0; // Cette instruction permet de spécifier que les deux behaviors OutputSetTo1 et OutPutSetTo0Input0  ne se chevauchent pas, c est à dire que chaque behavior a son propre prestate distinct de l autre
  @ disjoint behaviors OutPutSetTo0Input0, OutPutSetToInput1NotConfirmed; // Cette instruction permet de spécifier que les deux behaviors OutPutSetTo0Input0 et OutPutSetToInput1NotConfirmed ne se chevauchent pas, c est à dire que chaque behavior a son propre prestate distinct de l autre
  @ disjoint behaviors OutputSetTo1, OutPutSetToInput1NotConfirmed; // Cette instruction permet de spécifier que les deux behaviors OutPutSetToInput1NotConfirmed et OutputSetTo1 ne se chevauchent pas, c est à dire que chaque behavior a son propre prestate distinct de l autre
*/
void Conf(void) {
	/*S == 1; //Code à remplacer par celui implémentant le confirmateur. */
  if (E==0) {
    S=0;
    Cpt=0;
  }
  else if (Cpt>=ConfTime) {
    S=1;
    Cpt++;
  }
  else {
    S=0;
    Cpt++;
  }
}