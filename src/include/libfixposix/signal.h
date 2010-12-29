/*******************************************************************************/
/* Permission is hereby granted, free of charge, to any person or organization */
/* obtaining a copy of the software and accompanying documentation covered by  */
/* this license (the "Software") to use, reproduce, display, distribute,       */
/* execute, and transmit the Software, and to prepare derivative works of the  */
/* Software, and to permit third-parties to whom the Software is furnished to  */
/* do so, all subject to the following:                                        */
/*                                                                             */
/* The copyright notices in the Software and this entire statement, including  */
/* the above license grant, this restriction and the following disclaimer,     */
/* must be included in all copies of the Software, in whole or in part, and    */
/* all derivative works of the Software, unless such copies or derivative      */
/* works are solely in the form of machine-executable object code generated by */
/* a source language processor.                                                */
/*                                                                             */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  */
/* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,    */
/* FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT   */
/* SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE   */
/* FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE, */
/* ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER */
/* DEALINGS IN THE SOFTWARE.                                                   */
/*******************************************************************************/

#pragma once

#include <libfixposix/aux.h>

CPLUSPLUS_GUARD

#include <signal.h>

typedef void (*lfp_sighandler_t) (int);

lfp_sighandler_t lfp_sig_dfl(void);

lfp_sighandler_t lfp_sig_err(void);

lfp_sighandler_t lfp_sig_hold(void);

lfp_sighandler_t lfp_sig_ign(void);

// FIXME: inline NSIG
// NSIG is nowhere in POSIX, so some systems might not have it
// Linux and FreeBSD do, and that's enough for the moment
#if defined(NSIG)
#define LFP_NSIG NSIG
#else
# error "Cannot determine number of signals"
#endif

int lfp_sigrtmin(void);

int lfp_sigrtmax(void);

END_CPLUSPLUS_GUARD