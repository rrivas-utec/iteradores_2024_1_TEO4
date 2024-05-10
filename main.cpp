#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include <type_traits>

using namespace std;

template <typename Iterator>
void show_iterator_category(Iterator ite) {
    if constexpr (is_same_v<typename Iterator::iterator_category, std::forward_iterator_tag>) {
        cout << "Iterador Forward\n";
    }
    if constexpr (is_same_v<typename Iterator::iterator_category, std::bidirectional_iterator_tag>) {
        cout << "Iterador Bidireccional\n";
    }
    if constexpr (is_same_v<typename Iterator::iterator_category, std::random_access_iterator_tag>) {
        cout << "Iterador Random\n";
    }
}

template <typename Iterator>
auto sumarizar(Iterator inicio, Iterator fin) {
    typename Iterator::value_type total{};
    for (auto it = inicio; it != fin; ++it) {
        total += *it;
    }
    return total;
}

int main() {
    vector v1 = {10, 20, 30};
    list l1 = {10, 20, 30};
    forward_list fl1 = {10, 20, 30};

    auto it3 = fl1.begin();
    cout << *it3 << endl;
    it3++;
//    --it3;
//    auto it4 = it3 + 4;
    show_iterator_category(it3);

    auto it2 = l1.begin();
    auto it1 = v1.begin();
    show_iterator_category(it2);
    show_iterator_category(it1);


    return 0;
}
