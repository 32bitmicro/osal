/*
 * File:  bsp_start.c
 *
 * Purpose:
 *  OSAL main entry point.
 */

/*
**  Include Files
*/
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "generic_vxworks_bsp_internal.h"

OS_BSP_GenericVxWorksGlobalData_t OS_BSP_GenericVxWorksGlobal;

/* ---------------------------------------------------------
    OS_BSP_Lock_Impl()

     Helper function to get exclusive access to BSP
   --------------------------------------------------------- */
void OS_BSP_Lock_Impl(void)
{
    int status;

    status = semTake(OS_BSP_GenericVxWorksGlobal.AccessMutex, WAIT_FOREVER);
    if (status != OK)
    {
        BSP_DEBUG("semTake: errno=%d\n", errno);
    }
}

/* ---------------------------------------------------------
    OS_BSP_Unlock_Impl()

     Helper function to release exclusive access to BSP
   --------------------------------------------------------- */
void OS_BSP_Unlock_Impl(void)
{
    int status;

    status = semGive(OS_BSP_GenericVxWorksGlobal.AccessMutex);
    if (status != OK)
    {
        BSP_DEBUG("semGive: errno=%d\n", errno);
    }
}

/* ---------------------------------------------------------
    OS_BSP_Shutdown_Impl()

     Helper function to abort the running task
   --------------------------------------------------------- */
void OS_BSP_Shutdown_Impl(void)
{
    abort();
}

/******************************************************************************
**  Function:  OS_BSPMain()
**
**  Purpose:
**    vxWorks/BSP Application entry point.
**
**  Arguments:
**    (none)
**
**  Return:
**    integer return code, with zero indicating normal exit, nonzero
**    indicating an off-nominal condition
*/

int OS_BSPMain(void)
{
    /*
     * Initially clear the global object (this contains return code)
     */
    memset(&OS_BSP_Global, 0, sizeof(OS_BSP_Global));
    memset(&OS_BSP_GenericVxWorksGlobal, 0, sizeof(OS_BSP_GenericVxWorksGlobal));

    /*
     * Initialize the low level access sem
     */
    OS_BSP_GenericVxWorksGlobal.AccessMutex = semMInitialize(OS_BSP_GenericVxWorksGlobal.AccessMutexMem,
                                                             SEM_Q_PRIORITY | SEM_INVERSION_SAFE | SEM_DELETE_SAFE);

    if (OS_BSP_GenericVxWorksGlobal.AccessMutex == (SEM_ID)0)
    {
        BSP_DEBUG("semMInitialize: errno=%d\n", errno);
    }

    /*
     * Call application specific entry point.
     * This should set up all user tasks and resources, then return
     */
    OS_Application_Startup();

    /*
     * OS_Application_Run() implements the background task.
     * The user application may provide this, or a default implementation
     * is used which just calls OS_IdleLoop().
     */
    OS_Application_Run();

    /*
     * Return to shell with the current status code
     */
    return OS_BSP_Global.AppStatus;
}
