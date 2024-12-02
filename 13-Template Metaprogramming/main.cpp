#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <iterator>

using namespace std;

//meta function (in fact a struct)
template<typename T, typename U>
struct my_is_same {
    static const bool value = false;
};

template<typename T>
struct my_is_same<T, T> {
    static const bool value = true;
};

template<typename It>
int my_distance(It first, It last) {
    using category = typename iterator_traits<It>::iterator_category;
    //constexpr使得bool值为false的子句源代码在编译时消失
    if constexpr (my_is_same<random_access_iterator_tag, category>::value) {
        return last - first;
    } else {
        int result = 0;
        while (first != last) {
            ++first;
            ++result;
        }
        return result;
    }
}

//remove_const
template<typename T>
struct my_remove_const {
    using type = T;
};

template<typename T>
struct my_remove_const<const T> {
    using type = T;
};

//is_pointer
template<typename T>
struct my_is_pointer {
    static const bool value = false;
};

template<typename T>
struct my_is_pointer<T *> {
    static const bool value = true;
};

int main() {
    set<string> names{"Anna", "Wang", "Li", "Wu", "Avery"};
    auto anna_iter = find(names.begin(), names.end(), "Anna");
    auto avery_iter = find(names.begin(), names.end(), "Avery");
    int dis = my_distance(anna_iter, avery_iter);
    cout << dis << endl;
    cout << my_is_same<int, int>::value << endl;
    cout << my_is_same<int, double>::value << endl;
    using my_int = my_remove_const<const int>::type;
    my_int i = 3;
    i++;
    cout << i << endl;
    cout << my_is_pointer<int>::value << endl;
    cout << my_is_pointer<int *>::value << endl;

    return 0;
}
