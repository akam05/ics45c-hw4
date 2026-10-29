#include <gtest/gtest.h>
#include <string.h>

#include <algorithm>

#include "string.hpp"
#include "alloc.hpp"

TEST(StringFunction, strlen) {
    EXPECT_EQ(String::strlen(""), 0);
    EXPECT_EQ(String::strlen("foo"), 3);
}

TEST(StringFunction, strcpy) {
    char result[10];
    EXPECT_EQ(String::strcpy(result, "foo"), result);
    EXPECT_STREQ(result, "foo");

    EXPECT_EQ(String::strcpy(result, "a"), result);
    EXPECT_STREQ(result, "a");

    EXPECT_EQ(String::strcpy(result, ""), result);
    EXPECT_STREQ(result, "");
}

TEST(StringFunction, strdup) {
    EXPECT_TRUE(false);
}

TEST(StringFunction, strncpy) {
    char result[10];
	EXPECT_EQ(String::strncpy(result, "test", 3), result);
	EXPECT_STREQ(result, "tes");
	EXPECT_EQ(result[3], '\0');

	EXPECT_EQ(String::strncpy(result, "test", 0), result);
	EXPECT_STREQ(result, "");
}

TEST(StringFunction, strcat) {
    char result[10] = "test";
	EXPECT_EQ(String::strcat(result, "ing"), result);
	EXPECT_STREQ(result, "testing");
}

TEST(StringFunction, strncat) {
    char result[10] = "test";
	EXPECT_EQ(String::strncat(result, "ing", 2), result);
	EXPECT_STREQ(result, "testin");
}

TEST(StringFunction, strcmp) {
    EXPECT_EQ(String::strcmp("test","test"),0);
	EXPECT_EQ(String::strcmp("",""),0);
	EXPECT_GT(String::strcmp("wave","chat"),0);
	EXPECT_GT(String::strcmp("waves","chat"),0);
    EXPECT_LT(String::strcmp("test","tester"),0);
	EXPECT_LT(String::strcmp("chat","wave"),0);
}

TEST(StringFunction, strncmp) {
    EXPECT_EQ(String::strncmp("test","test",4),0);
	EXPECT_EQ(String::strncmp("test","test",0),0);
	EXPECT_GT(String::strncmp("wave","chat",1),0);
	EXPECT_LT(String::strncmp("chat","wave",1),0);
    EXPECT_LT(String::strncmp("test","tester",6),0);
    EXPECT_GT(String::strncmp("test", "team", 3), 0);
    EXPECT_EQ(String::strncmp("test", "team", 2), 0);
}

TEST(StringFunction, reverse_cpy) {
    char result[20];
	String::reverse_cpy(result, "test");
	EXPECT_STREQ(result, "tset");
}

TEST(StringFunction, strchr) {
    char result[20] = "test";
    char empty[] = "";
	EXPECT_EQ(String::strchr(result, 't'), result);
	EXPECT_EQ(String::strchr(result, 'e'), result + 1);
    EXPECT_EQ(String::strchr(result, '3'), nullptr);
    EXPECT_EQ(String::strchr(result, '\0'), result + 4);
    EXPECT_EQ(String::strchr(empty, 'a'), nullptr);
}

TEST(StringFunction, strstr) {
    char result[20] = "tester";
	EXPECT_EQ(String::strstr(result, "tester"),result);
	EXPECT_EQ(String::strstr(result, "ester"),result + 1);
    EXPECT_EQ(String::strstr(result, "dqjiojio"), nullptr);
    EXPECT_EQ(String::strstr(result, "testers"), nullptr);
}
