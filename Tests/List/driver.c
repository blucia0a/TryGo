#include <stdlib.h>
#include <time.h>
#include "list.h"

#define LIST_SIZE 10000
#define NUM_THDS 2
#define NUM_ITER 100000

pthread_barrier_t bar;

void *thd_main(void *v){

  pthread_barrier_wait(&bar);
  int i;
  list *l = (list *)v;
  for( i = 0; i < NUM_ITER; i++ ){

    if(rand() % 2){

      add_at_head(l,(void *)(rand() % 100));

    }else{

      get_from_head(l,(void *)(rand() % 100));

    }
   
  }  

}

int main(int argc, char *argv[]){

  srand( time(NULL) );

  int i;

  pthread_t threads[NUM_THDS];
  pthread_barrier_init(&bar,NULL,NUM_THDS);

  list *l = new_list(LIST_SIZE);

  for( i = 0; i < NUM_THDS; i++ ){

    pthread_create(&(threads[i]),NULL,thd_main,(void*)l);

  }
  
  for( i = 0; i < NUM_THDS; i++ ){
    
    pthread_join(threads[i],NULL);

  }

}
