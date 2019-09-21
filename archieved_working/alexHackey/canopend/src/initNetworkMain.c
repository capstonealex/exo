


#include "CANopen.h"
#include "CO_OD_storage.h"
#include "CO_Linux_tasks.h"
#include "CO_time.h"
#include "application.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sched.h>
#include <signal.h>
#include <errno.h>
#include <sys/epoll.h>
#include <net/if.h>
#include <linux/reboot.h>
#include <sys/reboot.h>

#ifndef CO_SINGLE_THREAD
#include "CO_command.h"
#include <pthread.h>
#endif




int main (int argc, char *argv[]) {
	printf("Starting canOpen program");
	initNetwork();

}