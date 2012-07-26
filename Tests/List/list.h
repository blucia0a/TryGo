typedef struct _list{

  int head;
  int size;
  void **contents;

} list;

list *new_list( int size );
int get_from_head( list *l, void *e );
int add_at_head( list *l, void *elem );
