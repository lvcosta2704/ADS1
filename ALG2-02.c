#include <stdio.h>
#include <stdlib.h>

int main () {
int qntd,p,x;
int *array = NULL;
int number;
scanf("%d", &qntd);
array = realloc(array, qntd*sizeof(int));

for (int i = 0; i < qntd; i++){
scanf("%d", &number);
array[i] = number;
}

scanf("%d", &x);
scanf("%d", &p);

array = realloc(array, (qntd+1)*sizeof(int));

for (int i = qntd; i > p; i--){
array[i] = array[i-1];
}

array[p] = x;
qntd++;

for (int i = 0; i < qntd; i++)
{
  printf("%d ", array[i]);
}

free(array);
return 0;
}
