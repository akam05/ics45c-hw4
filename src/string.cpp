#include "string.hpp"
#include <iostream>
using namespace std;

String::String(const char *s)
{
}

String::String(const String &s)
{
}

String::String(int length) : buf(new char[length + 1]
{
}

String::~String()
{
	delete[] buf;
}

void String::swap(String &s)
{
	swap(buf, s.buf);
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