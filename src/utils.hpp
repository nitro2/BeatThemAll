#ifndef _UTILS_HPP_
#define _UTILS_HPP_
template <typename Base, typename T>
inline bool instanceof (const std::shared_ptr<T> &)
{
    // return dynamic_cast<const std::shared_ptr<Base>>(ptr) != nullptr;
    return std::is_base_of<Base, T>::value;
}

#endif // _UTILS_HPP_
