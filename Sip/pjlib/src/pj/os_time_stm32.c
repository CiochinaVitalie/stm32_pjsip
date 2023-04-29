#include <pj/os.h>
#include <pj/errno.h>
#include <pj/compat/time.h>

#if defined(PJ_HAS_UNISTD_H) && PJ_HAS_UNISTD_H!=0
#    include <unistd.h>
#endif

#include <errno.h>

///////////////////////////////////////////////////////////////////////////////

PJ_DEF(pj_status_t) pj_gettimeofday(pj_time_val *p_tv)
{
    struct timeval the_time;
    int rc;

    PJ_CHECK_STACK();

    rc = gettimeofday(&the_time, NULL);
    if (rc != 0)
        return PJ_RETURN_OS_ERROR(pj_get_native_os_error());

    p_tv->sec = the_time.tv_sec;
    p_tv->msec = the_time.tv_usec / 1000;
    return PJ_SUCCESS;
}
