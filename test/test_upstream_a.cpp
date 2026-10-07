#include <gtest/gtest.h>

#include "upstream_a/upstream_a.hpp"

TEST(UpstreamA, CountsEveryElement)
{
  EXPECT_EQ(3, upstream_a::count_elements("<a><b/><c/></a>"));
}

TEST(UpstreamA, CountsNestedElements)
{
  EXPECT_EQ(4, upstream_a::count_elements("<a><b><c/></b><d/></a>"));
}

TEST(UpstreamA, MalformedXmlIsMinusOne)
{
  EXPECT_EQ(-1, upstream_a::count_elements("<a>"));
}

TEST(UpstreamA, EmptyInputIsMinusOne)
{
  EXPECT_EQ(-1, upstream_a::count_elements(""));
}
