#include "String.hpp"

#include <algorithm>

String::String()
{}

String::String(const char* cString)
    : value(cString)
{}

String::String(const String& string)
    : value(string.value)
{}

String& String::operator=(const String& string)
{
    value = string.value;
    return *this;
}

String::String(String&& string) noexcept
    : value(std::move(string.value))
{}

String& String::operator=(String&& string) noexcept
{
    value = std::move(string.value);
    return *this;
}

String::~String()
{}

unsigned String::size() const
{
    return value.size();
}

const char* String::c_str() const
{
    return value.c_str();
}

bool String::equals(const String& other) const
{
    return value == other.value;
}

bool String::equals(const char* other) const
{
    return value == other;
}

int String::index(char c) const
{
    for (unsigned i = 0; i < value.size(); ++i)
        if (value[i] == c)
            return static_cast<int>(i);
    return -1;
}

String& String::concat(const String& string)
{
    value += string.value;
    return *this;
}

String& String::concat(const char* string)
{
    value += string;
    return *this;
}

String& String::toUpper()
{
    std::transform(std::begin(value), std::end(value), std::begin(value), [](auto c){return std::toupper(c);});
    return *this;
}

String& String::toLower()
{
    std::transform(std::begin(value), std::end(value), std::begin(value), [](auto c){return std::tolower(c);});
    return *this;
}

int String::find(String& string)
{
    auto find = value.find(string.value);
    return find == std::string::npos ? ~0 : find;
}

int String::find(const char* cString)
{
    auto find = value.find(cString);
    return find == std::string::npos ? ~0 : find;
}

String& String::replace(const String& target, const String& replacement)
{
    auto find = value.find(target.value);
    if (find == std::string::npos)
        return *this;

    value.replace(find, target.value.size(), replacement.value);
    return *this;
}

String& String::replace(const String& target, const char* replacement)
{
    return replace(target, String(replacement));
}

String& String::replace(const char* target, const String& replacement)
{
    return replace(String(target), replacement);
}

String& String::replace(const char* target, const char* replacement)
{
    return replace(String(target), String(replacement));
}

String& String::erase(int from, int to)
{
    value.erase(from, (to - from));
    return *this;
}

String& String::erase_front(int to)
{
    return erase(0, to + 1);
}

std::string const& String::toString() const
{
    return value;
}

char String::operator[](unsigned index) const
{
    return value[index];
}

char& String::operator[](unsigned index)
{
    return value[index];
}

bool operator==(const String& left, const String& right)
{
    return left.value == right.value;
}

bool operator==(const String& left, const char* right)
{
    return left.value == right;
}

bool operator==(const char* left, const String& right)
{
    return right.value == left;
}

bool operator!=(const String& left, const String& right)
{
    return left.value != right.value;
}

bool operator!=(const String& left, const char* right)
{
    return left.value != right;
}

bool operator!=(const char* left, const String& right)
{
    return right.value != left;
}

bool operator<(const String& left, const String& right)
{
    return strcmp(left.c_str(), right.c_str()) < 0;
}

bool operator<(const String& left, const char* right)
{
    return strcmp(left.c_str(), right) < 0;
}

bool operator<(const char* left, const String& right)
{
    return strcmp(left, right.c_str()) < 0;
}

String operator+(const String& left, const String& right)
{
    return String(left).concat(right);
}

String operator+(const String& left, const char* right)
{
    return String(left).concat(right);
}

String operator+(const char* left, const String& right)
{
    return String(left).concat(right);
}

String& String::operator+=(const String& string)
{
    return concat(string);
}
