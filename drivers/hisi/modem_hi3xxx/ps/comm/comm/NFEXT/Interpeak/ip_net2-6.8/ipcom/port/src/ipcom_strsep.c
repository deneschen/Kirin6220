/*
 ******************************************************************************
 *                     SOURCE FILE
 *
 *     Document no: @(#) $Name: VXWORKS_ITER18A_FRZ10 $ $RCSfile: ipcom_strsep.c,v $ $Revision: 1.6 $
 *     $Source: /home/interpeak/CVSRoot/ipcom/port/src/ipcom_strsep.c,v $
 *     $Author: lob $ $Date: 2004-05-10 17:31:55 $
 *     $State: Exp $ $Locker:  $
 *
 *     INTERPEAK_COPYRIGHT_STRING
 *     Design and implementation by Firstname Lastname <email@interpeak.se>
 ******************************************************************************
 */

/*
 ****************************************************************************
 * 1                    DESCRIPTION
 ****************************************************************************
 */

/*
 ****************************************************************************
 * 2                    CONFIGURATION
 ****************************************************************************
 */

#include "ipcom_config.h"


/*
 ****************************************************************************
 * 3                    INCLUDE FILES
 ****************************************************************************
 */

#define IPCOM_USE_CLIB_PROTO
#include "ipcom_clib.h"


/*
 ****************************************************************************
 * 4                    EXTERN PROTOTYPES
 ****************************************************************************
 */

/*
 ****************************************************************************
 * 5                    DEFINES
 ****************************************************************************
 */

/*
 ****************************************************************************
 * 6                    TYPES
 ****************************************************************************
 */

/*
 ****************************************************************************
 * 7                    LOCAL PROTOTYPES
 ****************************************************************************
 */

/*
 ****************************************************************************
 * 8                    DATA
 ****************************************************************************
 */

/*
 ****************************************************************************
 * 9                    LOCAL FUNCTIONS
 ****************************************************************************
 */

/*
 ****************************************************************************
 * 10                   PUBLIC FUNCTIONS
 ****************************************************************************
 */

/*
 *===========================================================================
 *                    ipcom_strsep
 *===========================================================================
 * Description:
 * Parameters:
 * Returns:
 *
 */
#if defined(IPCOM_STRSEP) && IPCOM_STRSEP == 1
IP_PUBLIC char *
ipcom_strsep(char **cp, const char *d)
{
    char *s, *tok;
    const char *spanp;
    Ip_s32 c, sc;
    
    s = *cp;
    if(s == IP_NULL)
        return IP_NULL;
    
    for(tok = s;;)
    {
        c = *s++;
        spanp = d;
        do 
        {
            sc = *spanp++;
            if(sc == c) 
            {
                if(c == 0)
                    s = IP_NULL;
                else
                    s[-1] = 0;
                *cp = s;
                return tok;
            }
        }
        while(sc != 0);
    }
}

#else
int ipcom_strsep_empty_file;
#endif


/*
 ****************************************************************************
 *                      END OF FILE
 ****************************************************************************
 */