logtagptr) cv_temp_logtagptr = CV_LOGTAG_PTR_CAST(CV_LOGTAG_FALLBACK); \
        if (!cv_temp_logtagptr) cv_temp_logtagptr = CV_LOGTAG_PTR_CAST(CV_LOGTAG_GLOBAL); \
        if (cv_temp_logtagptr && (cv_temp_msglevel > cv_temp_logtagptr->level)) break; \
        std::stringstream cv_temp_logstream; \
        cv_temp_logstream << __VA_ARGS__; \
        cv::utils::logging::internal::writeLogMessageEx( \
            cv_temp_msglevel, \
            (cv_temp_logtagptr ? cv_temp_logtagptr->name : nullptr), \
            __FILE__, \
            __LINE__, \
            CV_Func, \
            cv_temp_logstream.str().c_str()); \
        break; \
    }

#define CV_LOG_FATAL(tag, ...)   CV_LOG_WITH_TAG(tag, cv::utils::logging::LOG_LEVEL_FATAL, __VA_ARGS__)
#define CV_LOG_ERROR(tag, ...)   CV_LOG_WITH_TAG(tag, cv::utils::logging::LOG_LEVEL_ERROR, __VA_ARGS__)
#define CV_LOG_WARNING(tag, ...) CV_LOG_WITH_TAG(tag, cv::utils::logging::LOG_LEVEL_WARNING, __VA_ARGS__)
#define CV_LOG_INFO(tag, ...) CV_LOG_WITH_TAG(tag, cv::utils::logging::LOG_LEVEL_INFO, __VA_ARGS__)
#define CV_LOG_DEBUG(tag, ...) CV_LOG_WITH_TAG(tag, cv::utils::logging::LOG_LEVEL_DEBUG, __VA_ARGS__)
#define CV_LOG_VERBOSE(tag, v, ...) CV_LOG_WITH_TAG(tag, (cv::utils::logging::LOG_LEVEL_VERBOSE + (int)(v)), __VA_ARGS__)

#if CV_LOG_STRIP_LEVEL <= CV_LOG_LEVEL_INFO
# undef CV_LOG_INFO
# define CV_LOG_INFO(tag, ...)
#endif

#if CV_LOG_STRIP_LEVEL <= CV_LOG_LEVEL_DEBUG
# undef CV_LOG_DEBUG
# define CV_LOG_DEBUG(tag, ...)
#endif

#if CV_LOG_STRIP_LEVEL <= CV_LOG_LEVEL_VERBOSE
# undef CV_LOG_VERBOSE
# define CV_LOG_VERBOSE(tag, v, ...)
#endif

}}} // namespace

//! @}

#endif // OPENCV_LOGGER_HPP
                                                                                                                                                                                                                                                                                    