/**
 * \file
 * \ingroup ut-stubs
 *
 * OSAL coverage stub replacement for signal.h
 */

#ifndef OVERRIDE_SIGNAL_H
#define OVERRIDE_SIGNAL_H

#include "OCS_signal.h"

/* ----------------------------------------- */
/* mappings for declarations in signal.h */
/* ----------------------------------------- */

#define SIG_SETMASK  OCS_SIG_SETMASK
#define SIGHUP       OCS_SIGHUP
#define SIGINT       OCS_SIGINT
#define SIGABRT      OCS_SIGABRT
#define SIGSEGV      OCS_SIGSEGV
#define SIGBUS       OCS_SIGBUS
#define SIGFPE       OCS_SIGFPE
#define SIGILL       OCS_SIGILL
#define SIGRTMIN     OCS_SIGRTMIN
#define SIGRTMAX     OCS_SIGRTMAX
#define SIGEV_SIGNAL OCS_SIGEV_SIGNAL

#define sighandler_t OCS_sighandler_t
#define sigset_t     OCS_sigset_t
#define sig_atomic_t OCS_sig_atomic_t
#define sigevent     OCS_sigevent

#define kill        OCS_kill
#define sigaddset   OCS_sigaddset
#define sigdelset   OCS_sigdelset
#define sigemptyset OCS_sigemptyset
#define sigfillset  OCS_sigfillset
#define sigismember OCS_sigismember
#define signal      OCS_signal
#define sigprocmask OCS_sigprocmask
#define sigsuspend  OCS_sigsuspend
#define sigwait     OCS_sigwait

#endif /* OVERRIDE_SIGNAL_H */
