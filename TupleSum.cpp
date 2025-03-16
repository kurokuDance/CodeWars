#include <tuple>
#include <iostream>
#include <type_traits>
#include <vector>

template <size_t Index = 0, typename... Args>
double processTupleElement(const std::tuple<Args...>& t) {
    if constexpr (Index < sizeof...(Args)) {
        double result = 0;
        if constexpr (std::is_arithmetic<std::decay_t<decltype(std::get<Index>(t))>>::value &&
            !std::is_same_v<std::decay_t<decltype(std::get<Index>(t))>, char>)
            result = std::get<Index>(t);
        return result + processTupleElement<Index + 1>(t);
    }
    return 0;
}

template <typename... Ts>
double tuple_sum(const std::tuple<Ts...>& tpl)
{
    return processTupleElement(tpl);
}