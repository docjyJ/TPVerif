#define SIZE 100
int Tab[SIZE];

/*@ requires \valid(Tab + (0 .. SIZE-1));
  @ ensures \result == 1 <==> (\exists integer i; 0 <= i < SIZE && Tab[i] == Val);
  @ ensures \result == 0 <==> (\forall integer i; 0 <= i < SIZE ==> Tab[i] != Val);
  @*/
int Search(int Val) {
    /*@ loop invariant 0 <= i <= SIZE;
      @ loop invariant \forall integer j; 0 <= j < i ==> Tab[j] != Val;
      @ loop assigns i;
      @ loop variant SIZE - i;
      @*/
    for(int i = 0; i < SIZE; i++) {
        if(Tab[i] == Val) return 1;
    }
    return 0;
}
