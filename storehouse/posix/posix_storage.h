/* Copyright 2016 Carnegie Mellon University, NVIDIA Corporation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include "storehouse/storage_backend.h"
#include "storehouse/storage_config.h"

namespace storehouse {

struct PosixConfig : public StorageConfig {
};

class PosixStorage : public StorageBackend {
public:
  PosixStorage(PosixConfig config);

  ~PosixStorage();

  StoreResult get_file_info(
    const std::string &name,
    FileInfo &file_info) override;

  /* make_random_read_file
   *
   */
  StoreResult make_random_read_file(
    const std::string& name,
    RandomReadFile*& file) override;

  /* make_write_file
   *
   */
  StoreResult make_write_file(
    const std::string& name,
    WriteFile*& file) override;

protected:
  const std::string data_directory_;
};

}
