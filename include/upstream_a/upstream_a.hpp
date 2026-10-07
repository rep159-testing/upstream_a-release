#ifndef UPSTREAM_A__UPSTREAM_A_HPP_
#define UPSTREAM_A__UPSTREAM_A_HPP_

#include <string>

namespace upstream_a
{

/// Number of elements in the XML document `xml`, or -1 if it does not parse.
int count_elements(const std::string & xml);

}  // namespace upstream_a

#endif  // UPSTREAM_A__UPSTREAM_A_HPP_
