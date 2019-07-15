/* Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
   file Copyright.txt or https://cmake.org/licensing for details.  */
#ifndef cmPropertyMap_h
#define cmPropertyMap_h

#include "cmConfigure.h" // IWYU pragma: keep

#include "cmProperty.h"
#include "tsl/hopscotch_map.h"

#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

/** \class cmPropertyMap
 * \brief String property map.
 */
class cmPropertyMap : public tsl::hopscotch_map<std::string, cmProperty>
{
public:
  // -- General

  //! Clear property list
  void Clear();

  // -- Properties

  //! Set the property value
  void SetProperty(const std::string& name, const char* value);

  //! Append to the property value
  void AppendProperty(const std::string& name, const char* value,
                      bool asString = false);

  //! Get the property value
  const char* GetPropertyValue(const std::string& name) const;

  //! Remove the property @a name from the map
  void RemoveProperty(const std::string& name);

  // -- Lists

  //! Get a sorted list of property keys
  std::vector<std::string> GetKeys() const;

  //! Get a sorted by key list of property key,value pairs
  std::vector<std::pair<std::string, std::string>> GetList() const;

private:
  std::unordered_map<std::string, std::string> Map_;
};

#endif
