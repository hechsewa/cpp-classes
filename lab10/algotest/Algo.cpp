//
// Created by Student on 11/05/17.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <array>
#include <set>
#include <map>
#include "Algo.h"

using namespace std;

namespace algo {
    std::set<string> Keys(const std::map<string, int> &m) {

    }

    std::set<string> Values(const std::map<string, int> &m) {

    }

    std::map<string, int> DivisableBy(const std::map<string, int> &m, int divisor) {

    }

    void SortInPlace(std::vector<int> *v) {

    }

    std::vector<int> Sort(const std::vector<int> &v) {
        return vector<int>();
    }

    void SortByFirstInPlace(std::vector<std::pair<int, int>> *v) {

    }

    void SortBySecondInPlace(std::vector<std::pair<int, int>> *v) {

    }

    void SortByThirdInPlace(std::vector<std::tuple<int, int, int>> *v) {

    }

    std::vector<std::string> MapToString(const std::vector<double> &v) {
        std::vector<std::string> vec;
        std::transform(v.begin(), v.end(), vec.begin(), [](double c){return std::to_string(c);} );
        return vec;
    }

    std::string Join(const std::string &joiner, const std::vector<double> &v) {
        return std::string();
    }

    int Sum(const std::vector<int> &v) {
        return 0;
    }

    int Product(const std::vector<int> &v) {
        return 0;
    }

    bool Contains(const std::vector<int> &v, int element) {
        auto found = std::find(v.begin(), v.end(), element);
        return (found != v.end());
    }

    bool ContainsKey(const std::map<string, int> &v, const std::string &key) {
        return false;
    }

    bool ContainsValue(const std::map<string, int> &v, int value) {
        return false;
    }

    std::vector<std::string> RemoveDuplicates(const std::vector<std::string> &v) {
        return vector<string>();
    }

    void RemoveDuplicatesInPlace(std::vector<std::string> *v) {

    }

    void InitializeWith(int initial_value, std::vector<int> *v) {
        std::fill(v->begin(), v->end(),initial_value);
    }

    std::vector<int> InitializedVectorOfLength(int length, int initial_value) {
        std::vector<int> vec;
        std::fill_n(vec.begin(), length, initial_value);
        return vec;
    }

    void CopyInto(const std::vector<int> &v, int n_elements, std::vector<int> *out) {
        std::copy(v.begin(), v.begin()+n_elements, std::back_inserter(*out));

    }

    int HowManyShortStrings(const std::vector<std::string> &v, int inclusive_short_length) {
        return 0;
    }
}