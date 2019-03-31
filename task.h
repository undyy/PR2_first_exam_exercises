#include<iostream>
#include<fstream>
#include<set>
#include<map>
#include<unordered_map>
#include<string>
#include<algorithm>
#include<numeric>
#include "vector.h"

using namespace std;

size_t amount_more_than(const Vector<string> &v, size_t n)
{
    set<string> s{ v.begin(), v.end() };
    return count_if(s.begin(), s.end(), [=](const auto &a){ return count(v.begin(), v.end(), a) > n; });
}

Vector<string> which_more_than(const Vector<string> &v, size_t n)
{
    set<string> s{ v.begin(), v.end() };
    Vector<string> out{};
    copy_if(s.begin(), s.end(), back_inserter(out), [=](const auto &o){ return count(v.begin(), v.end(), o) > n; });
    return out;
}

Vector<string> strings_ending_with(const Vector<string> &v, string s)
{
    set<string> uniq;
    uniq.insert(v.begin(), v.end());
    Vector<string> out(uniq.size());
    copy_if(uniq.begin(), uniq.end(), back_inserter(out), [=](const auto &o){ return o.size() > s.size() && o.substr(o.size() - s.size()) == s; });
    return out;
}

bool palindrome(const string &s)
{
    string temp{ s };
    transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
    string rev{ temp };
    reverse(rev.begin(), rev.end());
    return rev == temp;
}

bool palindromes(const Vector<string> &v)
{
    return any_of(v.begin(), v.end(), palindrome);
}

Vector<string> list_palindromes(const Vector<string> &v)
{
    set<string> s{ v.begin(), v.end() };
    Vector<string> out{};
    copy_if(s.begin(), s.end(), back_inserter(out), palindrome);
    return out;
}

string longest_word(const Vector<string> &v)
{
    return *(max_element(v.begin(), v.end(), [](const auto &first, const auto &second){ return first.size() < second.size(); }));
}

string shortest_word(const Vector<string> &v)
{
    return *(min_element(v.begin(), v.end(), [](const auto &first, const auto &second){ return first.size() < second.size(); }));
}
