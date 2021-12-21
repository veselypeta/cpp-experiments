#include <gtest/gtest.h>
#include <type_traits>

/*
 * Exercises from C++ Best Practices p34-35
 */

static constexpr int i = 11;
const int *get_ptr(){
    return &i;
}

const int &get_ref(){
    return i;
}

TEST(AutoTypeDecl, IntPointer){

    const auto val = get_ptr();
    // Deduced type is: const int * const, const pointer to const int
    ASSERT_TRUE(std::is_pointer_v<decltype(val)>);
    ASSERT_TRUE(std::is_const_v<decltype(val)>);
    // pointer to const
    ASSERT_TRUE(std::is_const_v<std::remove_pointer_t<std::remove_const_t<decltype(val)>>>);
}

TEST(AutoTypeDecl, AutoWithoutAmpersand){
    // References are not deduces by auto
    // so type here weill be : const int
    const auto val = get_ref();

    ASSERT_FALSE(std::is_reference_v<decltype(val)>);
    ASSERT_TRUE(std::is_const_v<decltype(val)>);
}

TEST(AutoTypeDecl, AutoWithStar){

    // Star here is redundant
    // Type here is : const int * const
    const auto *val = get_ptr();

    ASSERT_TRUE(std::is_pointer_v<decltype(val)>);
    ASSERT_FALSE(std::is_pointer_v<std::remove_pointer_t<decltype(val)>>);
    ASSERT_TRUE(std::is_const_v<std::remove_pointer_t<decltype(val)>>);
}

TEST(AutoTypeDecl, AutoWithAmpersand){
    // type here is : const &int
    const auto &val = get_ref();

    ASSERT_TRUE(std::is_reference_v<decltype(val)>);
    ASSERT_TRUE(std::is_const_v<std::remove_reference_t<decltype(val)>>);
}



