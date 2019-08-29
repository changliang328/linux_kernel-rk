/*************************************************************************/ /*!
@File
@Title          KM server Transport Layer implementation
@Copyright      Copyright (c) Imagination Technologies Ltd. All Rights Reserved
@Description    Main bridge APIs for Transport Layer client functions
@License        Dual MIT/GPLv2

The contents of this file are subject to the MIT license as set out below.

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

Alternatively, the contents of this file may be used under the terms of
the GNU General Public License Version 2 ("GPL") in which case the provisions
of GPL are applicable instead of those above.

If you wish to allow use of your version of this file only under the terms of
GPL, and not to allow others to use your version of this file under the terms
of the MIT license, indicate your decision by deleting the provisions above
and replace them with the notice and other provisions required by GPL as set
out in the file called "GPL-COPYING" included in this distribution. If you do
not delete the provisions above, a recipient may use your version of this file
under the terms of either the MIT license or GPL.

This License is also included in this distribution in the file called
"MIT-COPYING".

EXCEPT AS OTHERWISE STATED IN A NEGOTIATED AGREEMENT: (A) THE SOFTWARE IS
PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
PURPOSE AND NONINFRINGEMENT; AND (B) IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/ /**************************************************************************/

#ifndef __TLSERVER_H_
#define __TLSERVER_H_

#if defined (__cplusplus)
extern "C" {
#endif

#include <stddef.h>

#include "img_defs.h"
#include "pvr_debug.h"
#include "connection_server.h"

#include "tlintern.h"

/*
 * Transport Layer Client API Kernel-Mode bridge implementation
 */

PVRSRV_ERROR TLServerConnectKM(CONNECTION_DATA *psConnection);
PVRSRV_ERROR TLServerDisconnectKM(CONNECTION_DATA *psConnection);

PVRSRV_ERROR TLServerOpenStreamKM(IMG_PCHAR pszName,
			   IMG_UINT32 ui32Mode,
			   PTL_STREAM_DESC* ppsSD,
			   DEVMEM_EXPORTCOOKIE** ppsBufCookie);

PVRSRV_ERROR TLServerCloseStreamKM(PTL_STREAM_DESC psSD);

PVRSRV_ERROR TLServerAcquireDataKM(PTL_STREAM_DESC psSD,
			   IMG_UINT32* puiReadOffset,
			   IMG_UINT32* puiReadLen);

PVRSRV_ERROR TLServerReleaseDataKM(PTL_STREAM_DESC psSD,
				 IMG_UINT32 uiReadOffset,
				 IMG_UINT32 uiReadLen);

/*
 * TEST INTERNAL ONLY
 */

PVRSRV_ERROR TLServerTestIoctlKM(IMG_UINT32  uiCmd,
				IMG_PBYTE   uiIn1,
				IMG_UINT32  uiIn2,
				IMG_UINT32*	puiOut1,
				IMG_UINT32* puiOut2);

#if defined (__cplusplus)
}
#endif

#endif /* __TLSERVER_H_ */

/*****************************************************************************
 End of file (tlserver.h)
*****************************************************************************/

