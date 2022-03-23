/**
 * \file
 * \ingroup ut-stubs
 *
 * OSAL coverage stub replacement for vxWorks.h
 */

#ifndef OCS_VXWORKS_H
#define OCS_VXWORKS_H

#include "OCS_basetypes.h"

/* ----------------------------------------- */
/* constants normally defined in vxWorks.h */
/* ----------------------------------------- */
enum
{
    OCS_ERROR = -1,
    OCS_OK    = 0
};

enum
{
    OCS_WAIT_FOREVER = -1,
    OCS_NO_WAIT      = 0
};

/* ----------------------------------------- */
/* types normally defined in vxWorks.h */
/* ----------------------------------------- */
typedef int          OCS_STATUS;
typedef bool         OCS_BOOL;
typedef unsigned int OCS_UINT;
typedef int8_t       OCS_INT8;
typedef uint8_t      OCS_UINT8;
typedef int16_t      OCS_INT16;
typedef uint16_t     OCS_UINT16;
typedef int32_t      OCS_INT32;
typedef uint32_t     OCS_UINT32;

typedef long OCS_Vx_usr_arg_t;

/* Function pointers are used in many VxWorks modules. */
/*
 * NOTE: The FUNCPTR type in the actual library may be defined
 * without arguments, e.g. "int (*FUNCPTR)()".  This is acceptable
 * by some compilers but generally incompatible with the
 * "-Wstrict-prototype" gcc warning option.  So in this override it
 * is defined as an int argument.  This means that application code
 * may need to cast it at the time of use (which is generally done anyway).
 */
typedef int (*OCS_FUNCPTR)(int);
typedef void (*OCS_VOIDFUNCPTR)(void);

/* ----------------------------------------- */
/* prototypes normally declared in vxWorks.h */
/* ----------------------------------------- */

#endif /* OCS_VXWORKS_H */
