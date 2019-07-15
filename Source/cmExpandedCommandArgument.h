/* Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
   file Copyright.txt or https://cmake.org/licensing for details.  */
#ifndef cmExpandedCommandArgument_h
#define cmExpandedCommandArgument_h

#include "cmConfigure.h" // IWYU pragma: keep

#include <string>

/** \class cmExpandedCommandArgument
 * \brief Represents an expanded command argument
 *
 * cmCommandArgument stores a string representing an expanded
 * command argument and context information.
 */

class cmExpandedCommandArgument
{
public:
  cmExpandedCommandArgument() = default;
  cmExpandedCommandArgument(std::string value, bool quoted)
    : Value(std::move(value))
    , Quoted(quoted)
  {
  }

  std::string const& GetValue() const { return this->Value; }

  bool WasQuoted() const { return this->Quoted; }

  bool operator==(const char* value) const { return this->Value == value; }
  bool operator==(std::string const& value) const
  {
    return this->Value == value;
  }

  bool empty() const { return this->Value.empty(); }

  const char* c_str() const { return this->Value.c_str(); }

private:
  std::string Value;
  bool Quoted = false;
};

#endif
