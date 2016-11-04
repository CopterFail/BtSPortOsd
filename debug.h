
#ifndef __DEBUG_H__
#define __DEBUG_H__

//#define DEBUG

#ifdef DEBUG
extern Serial Debug;
#define Dbg Debug.printf
#else
#define Dbg 
#endif

#endif
