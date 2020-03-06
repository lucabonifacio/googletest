#ifndef GTEST_INTERNAL_WINCEADAPTER_TIME_H
#define GTEST_INTERNAL_WINCEADAPTER_TIME_H

#include <time.h>

#ifdef  __cplusplus
extern "C" {
#endif

/************************************************************************/
/* support gmtime_r, localtime_r, time, clock, asctime, mktime, ctime   */
/************************************************************************/
struct tm* __cdecl bwcea_gmtime(const time_t* pTime);
struct tm* __cdecl bwcea_localtime(const time_t* pTime);
time_t __cdecl time(time_t* pTime);
clock_t __cdecl clock(void);
char* __cdecl asctime(const struct tm* pTm);
time_t __cdecl mktime(struct tm* pTm);
char* __cdecl ctime(const time_t* pTimer);
struct tm* __cdecl bwcea_gmtime_r(const time_t* pTime, struct tm *tmp);
errno_t __cdecl bwcea_gmtime_s(struct tm *result, const time_t *timer);
struct tm* __cdecl bwcea_localtime_r(const time_t* pTime, struct tm *tmp);
errno_t __cdecl localtime_s(struct tm* _tm, const time_t* pTime);

// Remark: make sure to not export gmtime/localtime (but define them as inline
// functions) to avoid problems with inconsistent DLL linkage if another library
// provides method declarations for them
static __inline struct tm* gmtime(const time_t* pTime)
{
    return bwcea_gmtime(pTime);
}

static __inline errno_t gmtime_s(struct tm *result, const time_t *timer)
{
    return bwcea_gmtime_s(result, timer);
}

static __inline struct tm* localtime(const time_t* pTime)
{
    return bwcea_localtime(pTime);
}

static __inline struct tm* gmtime_r(const time_t* pTime, struct tm *tmp)
{
    return bwcea_gmtime_r(pTime, tmp);
}

static __inline struct tm* localtime_r(const time_t* pTime, struct tm *tmp)
{
    return bwcea_localtime_r(pTime, tmp);
}

#ifdef  __cplusplus
}
#endif

#endif // GTEST_INTERNAL_WINCEADAPTER_TIME_H

