/**
 * \file
 * \ingroup ut-stubs
 *
 * OSAL coverage stub replacement for sys/mman.h
 */

#ifndef OVERRIDE_SYS_MMAN_H
#define OVERRIDE_SYS_MMAN_H

#include "OCS_sys_mman.h"

/* ----------------------------------------- */
/* mappings for declarations in sys/mman.h */
/* ----------------------------------------- */

#define MAP_SHARED  OCS_MAP_SHARED
#define MAP_PRIVATE OCS_MAP_PRIVATE
#define PROT_EXEC   OCS_PROT_EXEC
#define PROT_READ   OCS_PROT_READ
#define PROT_WRITE  OCS_PROT_WRITE
#define PROT_NONE   OCS_PROT_NONE
#define MAP_FIXED   OCS_MAP_FIXED
#define mmap        OCS_mmap
#define munmap      OCS_munmap

#endif /* OVERRIDE_SYS_MMAN_H */
