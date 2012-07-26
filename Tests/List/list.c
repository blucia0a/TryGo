#include <stdlib.h>
#include <assert.h>
#include "list.h"

list *new_list( int size ){

  list *l = malloc( sizeof( list ) );

  l->head = 0;
  l->size = size;
  l->contents = malloc( sizeof( void * ) * size );

  return l;

}

int get_from_head( list *l, void *e ){

  int i = -1;

  IR_SyntheticEvent();
  i = l->head; 
  
  if( i >= 0 ){

    IR_SyntheticEvent();
    l->head = i - 1;

    assert( l->head < i );  

    IR_SyntheticEvent();
    e = l->contents[i]; 

    return 0;

  }  

  return -1;
  
}

int add_at_head( list *l, void *elem ){

  int i;

  IR_SyntheticEvent();
  i = l->head;

  if( i >= l->size ){

    return -1;

  }

  IR_SyntheticEvent();
  l->contents[i] = elem;

  assert(l->head == i);

  IR_SyntheticEvent();
  l->head = i + 1;

  return 0;

}
