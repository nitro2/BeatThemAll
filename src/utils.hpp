#ifndef _UTILS_HPP_
#define _UTILS_HPP_

#include <typeinfo>
#include "spdlog/spdlog.h"
#include "spdlog/sinks/basic_file_sink.h"

template <typename Base, typename T>
inline bool instanceof (const std::shared_ptr<T> &)
{
    // return dynamic_cast<const std::shared_ptr<Base>>(ptr) != nullptr;
    return std::is_base_of<Base, T>::value;
}

// #define DEBUG_PRINT(msg) std::cout << typeid(*this).name() << "-" << __FUNCTION__ << " at line " << __LINE__ << " - " << msg << std::endl;
#define DEBUG_PRINT(msg) spdlog::info(msg)
static void initLogger()
{
    auto file_logger = spdlog::basic_logger_mt("basic_logger", "logs.txt");
    spdlog::set_default_logger(file_logger);
}
#endif // _UTILS_HPP_
