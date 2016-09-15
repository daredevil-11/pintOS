#include <stdio.h>
#include "tests/threads/tests.h"
#include "threads/thread.h"
#include "threads/init.h"
#include "threads/malloc.h"
#include "threads/synch.h"
#include "devices/timer.h"

static struct semaphore sema;
static thread_func sema_thread;

void
test_sema_change(void){
	sema_init (&sema, 0);
	msg("sema value set to 0");
	thread_create ("A", PRI_DEFAULT, sema_thread, NULL);
}

static void
sema_thread(void * aux UNUSED){
	sema_up(&sema);
	msg("1) %s changed sema value to 1", thread_name());
	timer_sleep (1 * TIMER_FREQ);
	sema_down(&sema);
	msg("2) %s changed sema value to 0", thread_name());
	msg(">>>> The next msg will not be seen as sema_down tried for sema = 0, thus thread blocked");
	sema_down(&sema);
	msg("3) This message will not be seen!");
}