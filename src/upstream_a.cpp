#include "upstream_a/upstream_a.hpp"

#include <libxml/parser.h>
#include <libxml/tree.h>

namespace upstream_a
{
namespace
{

int count_element_nodes(xmlNode * node)
{
  int count = 0;
  for (xmlNode * current = node; current != nullptr; current = current->next) {
    if (current->type == XML_ELEMENT_NODE) {
      ++count;
    }
    count += count_element_nodes(current->children);
  }
  return count;
}

}  // namespace

int count_elements(const std::string & xml)
{
  xmlDocPtr doc = xmlReadMemory(
    xml.data(), static_cast<int>(xml.size()), "input.xml", nullptr,
    XML_PARSE_NONET | XML_PARSE_NOERROR | XML_PARSE_NOWARNING);
  if (doc == nullptr) {
    return -1;
  }
  const int count = count_element_nodes(xmlDocGetRootElement(doc));
  xmlFreeDoc(doc);
  return count;
}

}  // namespace upstream_a
