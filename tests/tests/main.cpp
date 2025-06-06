#include <gtest/gtest.h>
#include <tuple>
class Test : public testing::TestWithParam<
                 std::tuple<std::string, std::string, std::string>> {};
