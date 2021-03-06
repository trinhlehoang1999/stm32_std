// This file is part of OpenCV project.
// It is subject to the license terms in the LICENSE file found in the top-level directory
// of this distribution and at http://opencv.org/license.html.

#ifndef OPENCV_CORE_ASYNC_HPP
#define OPENCV_CORE_ASYNC_HPP

#include <opencv2/core/mat.hpp>

#ifdef CV_CXX11
//#include <future>
#include <chrono>
#endif

namespace cv {

/** @addtogroup core_async

@{
*/


/** @brief Returns result of asynchronous operations

Object has attached asynchronous state.
Assignment operator doesn't clone asynchronous state (it is shared between all instances).

Result can be fetched via get() method only once.

*/
class CV_EXPORTS_W AsyncArray
{
public:
    ~AsyncArray() CV_NOEXCEPT;
    CV_WRAP AsyncArray() CV_NOEXCEPT;
    AsyncArray(const AsyncArray& o) CV_NOEXCEPT;
    AsyncArray& operator=(const AsyncArray& o) CV_NOEXCEPT;
    CV_WRAP void release() CV_NOEXCEPT;

    /** Fetch the result.
    @param[out] dst destination array

    Waits for result until container has valid result.
    Throws exception if exception was stored as a result.

    Throws exception on invalid container state.

    @note Result or stored exception can be fetched only once.
    */
    CV_WRAP void get(OutputArray dst) const;

    /** Retrieving the result with timeout
    @param[out] dst destination array
    @param[in] timeoutNs timeout in nanoseconds, -1 for infinite wait

    @returns true if result is ready, false if the timeout has expired

    @note Result or stored exception can be fetched only once.
    */
    bool get(OutputArray dst, int64 timeoutNs) const;

    CV_WRAP inline
    bool get(OutputArray dst, double timeoutNs) const { return get(dst, (int64)timeoutNs); }

    bool wait_for(int