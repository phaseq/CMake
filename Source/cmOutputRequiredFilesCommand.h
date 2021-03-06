/* Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
   file Copyright.txt or https://cmake.org/licensing for details.  */
#ifndef cmOutputRequiredFilesCommand_h
#define cmOutputRequiredFilesCommand_h

#include "cmConfigure.h" // IWYU pragma: keep

#include <set>
#include <stdio.h>
#include <string>
#include <vector>

#include "cm_memory.hxx"

#include "cmCommand.h"

class cmDependInformation;
class cmExecutionStatus;

class cmOutputRequiredFilesCommand : public cmCommand
{
public:
  std::unique_ptr<cmCommand> Clone() override
  {
    return cm::make_unique<cmOutputRequiredFilesCommand>();
  }
  bool InitialPass(std::vector<std::string> const& args,
                   cmExecutionStatus& status) override;

  void ListDependencies(cmDependInformation const* info, FILE* fout,
                        std::set<cmDependInformation const*>* visited);

private:
  std::string File;
  std::string OutputFile;
};

#endif
