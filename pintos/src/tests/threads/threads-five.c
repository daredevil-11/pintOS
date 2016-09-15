#include <stdio.h>
#include "tests/threads/tests.h"
#include "threads/thread.h"
#include "threads/init.h"
#include "threads/malloc.h"
#include "threads/synch.h"

int priority[] = {19, 21, 13, 15, 17};
char* name[] = {"A", "B", "C", "D", "E"};
static thread_func thread_priority;


void
test_threads_five (void){

  //thread_set_priority (PRI_MIN);
  int i = 0;
  for (i = 0; i < 5; i++) 
    {
      thread_create (name[i], priority[i], thread_priority, NULL);
    }

}

static void
thread_priority (void *aux UNUSED) 
{
  msg ("Thread %s with priority %d starting.", thread_name (), thread_get_priority());
}

