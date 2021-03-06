/* Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
   file Copyright.txt or https://cmake.org/licensing for details.  */
#ifndef cmCTestConfigureCommand_h
#define cmCTestConfigureCommand_h

#include "cmConfigure.h" // IWYU pragma: keep

#include "cmCTestHandlerCommand.h"
#include "cmCommand.h"

#include <string>
#include <utility>

#include "cm_memory.hxx"

class cmCTestGenericHandler;

/** \class cmCTestConfigure
 * \brief Run a ctest script
 *
 * cmCTestConfigureCommand defineds the command to configures the project.
 */
class cmCTestConfigureCommand : public cmCTestHandlerCommand
{
public:
  cmCTestConfigureCommand();

  /**
   * This is a virtual constructor for the command.
   */
  std::unique_ptr<cmCommand> Clone() override
  {
    auto ni = cm::make_unique<cmCTestConfigureCommand>();
    ni->CTest = this->CTest;
    ni->CTestScriptHandler = this->CTestScriptHandler;
    return std::unique_ptr<cmCommand>(std::move(ni));
  }

  /**
   * The name of the command as specified in CMakeList.txt.
   */
  std::string GetName() const override { return "ctest_configure"; }

protected:
  cmCTestGenericHandler* InitializeHandler() override;

  enum
  {
    ctc_FIRST = ct_LAST,
    ctc_OPTIONS,
    ctc_LAST
  };
};

#endif
