#define SIZE_X 100
#define SIZE_Y 100
int Mat[SIZE_X][SIZE_Y];



/*@ requires R1: SIZE_X > 0;
  @ requires R2: SIZE_Y > 0;
  @ requires R3: \valid(Mat+(0..((SIZE_X*SIZE_Y)-1)));
  @ assigns \nothing;
  @
  @ behavior B1:
  @   assumes \exists integer k, p; 0<=k<SIZE_X && 0<=p<SIZE_Y && Mat[k][p]==Val;
  @   ensures \result==1;
  @
  @ behavior B2:
  @   assumes \forall integer k, p; 0<=k<SIZE_X && 0<=p<SIZE_Y ==> Mat[k][p]!=Val;
  @   ensures \result==0;
  @
  @ complete behaviors B1, B2;
  @ disjoint behaviors B1, B2;
*/
int Search(int Val) {
  /*@ loop invariant 0<=i<=SIZE_X;
    @ loop invariant \forall integer k, p; 0<=k<i && 0<=p<SIZE_Y  ==> Mat[k][p]!=Val;
    @ loop assigns i;
    @ loop variant SIZE_X-i;
  */
  for(int i=0; i<SIZE_X; i++) {
    /*@ loop invariant 0<=j<=SIZE_Y;
      @ loop invariant \forall integer p; 0<=p<j  ==> Mat[i][p]!=Val;
      @ loop assigns j;
      @ loop variant SIZE_Y-j;
    */
    for(int j=0; j<SIZE_Y; j++) {
      if(Mat[i][j]==Val) return 1;
    }
  }
  return 0;
}
