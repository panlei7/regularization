#include "H5Cpp.h"
#include "exception.hpp"

using namespace H5;

namespace custorm_exception {
  void CatchHDF5Exception() {
    try {
      throw;
    }
    catch (const FileIException &error) {
      error.printError();
      throw;
    }
    catch (const AttributeIException &error) {
      error.printError();
      throw;
    }
    catch (const DataSpaceIException &error) {
      error.printError();
      throw;
    }
    catch (const DataSetIException &error) {
      error.printError();
      throw;
    }
    catch (const DataTypeIException &error) {
      error.printError();
      throw;
    }
  }
}
