/* Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
   file Copyright.txt or https://cmake.org/licensing for details.  */
#ifndef cmLinkDirectoriesCommand_h
#define cmLinkDirectoriesCommand_h

#include "cmConfigure.h" // IWYU pragma: keep

#include <string>
#include <vector>

#include "cm_memory.hxx"

#include "cmCommand.h"

class cmExecutionStatus;

/** \class cmLinkDirectoriesCommand
 * \brief Define a list of directories containing files to link.
 *
 * cmLinkDirectoriesCommand is used to specify a list
 * of directories containing files to link into executable(s).
 * Note that the command supports the use of CMake built-in variables
 * such as CMAKE_BINARY_DIR and CMAKE_SOURCE_DIR.
 */
class cmLinkDirectoriesCommand : public cmCommand
{
public:
  /**
   * This is a virtual constructor for the command.
   */
  std::unique_ptr<cmCommand> Clone() override
  {
    return cm::make_unique<cmLinkDirectoriesCommand>();
  }

  /**
   * This is called when the command is first encountered in
   * the CMakeLists.txt file.
   */
  bool InitialPass(std::vector<std::string> const& args,
                   cmExecutionStatus& status) override;

private:
  void AddLinkDir(std::string const& dir,
                  std::vector<std::string>& directories);
};

#endif
