#include "string.hpp"
#include <iostream>
#include <utility>
using namespace std;

String::String(const char *s) : buf(strdup(s))
{
}

String::String(const String &s) : buf(strdup(s.buf))
{
}

String::String(int length) : buf(new char[length + 1])
{
}

String::String(String &&s) : buf(s.buf)
{
    s.buf = nullptr;
}

String &String::operator=(String &&s)
{
    swap(s);
    return *this;
}

String::~String()
{
	delete[] buf;
}

// functions
void String::swap(String &s)
{
	std::swap(buf, s.buf);
}

int String::size() const
{
    return strlen(buf);
}

String String::reverse() const
{
    String res;
    reverse_cpy(res.buf, buf);
    return res;
}

int String::indexOf(char c) const
{
	const char *res = strchr(buf, c);

	if (res == nullptr)
	{
		return -1;
	}

	int index = res - buf;
	return index;
}

int String::indexOf(const String &s) const
{
	const char *res = strstr(buf, s.buf);
	if (res == nullptr)
		return -1;
	int index = res - buf;
	return index;
}

void String::print(ostream &out) const
{
    out << buf;
}

void String::read(istream &in)
{
	in >> buf;
}

// operators
String &String::operator=(const String &s)
{
	if (this != &s)
    {
        String temp(s);
        swap(temp);
    }
	return *this;
}

char &String::operator[] (int index)
{
	if (!(in_bounds(index)))
	{
		cerr << "ERROR: Index Out of Bounds";
		return buf[0];
	}
	return buf[index];
}

const char &String::operator[] (int index) const 
{
    if (!(in_bounds(index)))
	{
		cerr << "ERROR: Index Out of Bounds";
		return buf[0];
	}
	return buf[index];
}

String &String::operator+=(const String &s)
{
	int rem = MAXLEN - 1 - strlen(buf);
	
	if (strlen(s.buf) > rem)
	{
		cerr << "ERROR: String Capacity Exceeded";
	}
	
	String temp(s);
	strncat(buf, temp.buf, rem);
	return *this;
}

bool String::operator==(const String &s) const
{
	return strcmp(buf, s.buf) == 0;
}

bool String::operator!=(const String &s) const
{
	return strcmp(buf, s.buf) != 0;
}

bool String::operator>(const String &s) const
{
	return strcmp(buf, s.buf) > 0;
}

bool String::operator<(const String &s) const
{
	return strcmp(buf, s.buf) < 0;
}

bool String::operator<=(const String &s) const
{
	return strcmp(buf, s.buf) <= 0;
}

bool String::operator>=(const String &s) const
{
	return strcmp(buf, s.buf) >= 0;
}

String String::operator+(const String &s) const
{
	String res(buf);
	res += s;
	return res;
}

// static helper methods
int String::strlen(const char *s)
{
	int len = 0;
	while (s[len] != '\0')
		++len;
	return len;
}

char *String::strcpy(char *dest, const char *src)
{
    int i = 0;
    for ( ; src[i] != '\0'; ++i)
        dest[i] = src[i];
    dest[i] = '\0';
    return dest;
}

char *String::strdup(const char *src)
{
    char *copy = new char[strlen(src) + 1];
    strcpy(copy, src); 
    return copy; 
}

char *String::strncpy(char *dest, const char *src, int n)
{
    int i = 0;
    for ( ; i < n && src[i] != '\0'; ++i)
        dest[i] = src[i];
    dest[i] = '\0';
    return dest;
}

char *String::strcat(char *dest, const char *src)
{
	int len = 0;
	while (dest[len] != '\0')
	{
		len = len + 1;
	}
	for (int i = 0; src[i] != '\0'; i++)
	{
		dest[len] = src[i];
		len = len + 1;
	}
	dest[len] = '\0';
	return dest;
}

char *String::strncat(char *dest, const char *src, int n)
{
	int len = 0;
	while (dest[len] != '\0')
	{
		len = len + 1;
	}
	for (int i = 0; i < n && src[i] != '\0'; i++)
	{
		dest[len] = src[i];
		len = len + 1;
	}
	dest[len] = '\0';
	return dest;
}

int String::strcmp(const char *left, const char *right)
{
	int len = 0;
	for (int i = 0; left[i] != '\0' && left[i] == right[i]; i++)
	{
		len = len + 1;
	}

	if (static_cast<unsigned char>(left[len]) < static_cast<unsigned char>(right[len]))
		return -1;
	else if (static_cast<unsigned char>(left[len]) == static_cast<unsigned char>(right[len]))
		return 0;
	return 1;
}

int String::strncmp(const char *left, const char *right, int n)
{
	int len = 0;
	for (int i = 0; i < n && left[i] != '\0' && left[i] == right[i]; i++)
	{
		len = len + 1;
	}

	if (len == n)
		return 0;
	if (static_cast<unsigned char>(left[len]) == static_cast<unsigned char>(right[len]))
		return 0;
	else if (static_cast<unsigned char>(left[len]) < static_cast<unsigned char>(right[len]))
		return -1;
	return 1;
}

void String::reverse_cpy(char *dest, const char *src)
{
	int len = 0;
	for (int i = 0; src[i] != '\0'; i++)
	{
		len = len + 1;
	}

	int right = len - 1;
	for (int i = 0; i < len; i++)
	{
		dest[i] = src[right];
		right = right - 1;
	}
	dest[len] = '\0';
}

const char *String::strchr(const char *str, char c)
{
	int i = 0;
	for (; str[i] != '\0'; i++)
	{
		if (str[i] == c)
		{
			return &str[i];
		}
	}

	if (c == str[i])
	{
		return &str[i];
	}
	return nullptr;
}

const char *String::strstr(const char *haystack, const char *needle)
{
	int length = strlen(needle);
	if (length == 0)
	{
		return haystack;
	}

	for (int i = 0; haystack[i] != '\0'; i++)
	{
		if (strncmp(&haystack[i], needle, length) == 0)
		{
			return &haystack[i]; 
		}
	}
	return nullptr;
}

ostream &operator<<(ostream &out, const String &s)
{
	s.print(out);
	return out;
}

istream &operator>>(istream &in, String &s)
{
	s.read(in);
	return in;
}