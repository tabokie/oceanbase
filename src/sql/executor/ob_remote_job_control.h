/**
 * Copyright (c) 2021 OceanBase
 * OceanBase CE is licensed under Mulan PubL v2.
 * You can use this software according to the terms and conditions of the Mulan PubL v2.
 * You may obtain a copy of Mulan PubL v2 at:
 *          http://license.coscl.org.cn/MulanPubL-2.0
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
 * EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
 * MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
 * See the Mulan PubL v2 for more details.
 */

#ifndef OCEANBASE_SQL_EXECUTOR_OB_REMOTE_JOB_CONTROL_
#define OCEANBASE_SQL_EXECUTOR_OB_REMOTE_JOB_CONTROL_

#include "sql/executor/ob_job_control.h"

namespace oceanbase {
namespace sql {
class ObRemoteJobControl : public ObJobControl {
public:
  explicit ObRemoteJobControl();
  virtual ~ObRemoteJobControl();

  virtual int get_ready_jobs(common::ObIArray<ObJob*>& jobs, bool serial_schedule = false) const;

private:
  DISALLOW_COPY_AND_ASSIGN(ObRemoteJobControl);
};
}  // namespace sql
}  // namespace oceanbase
#endif /* OCEANBASE_SQL_EXECUTOR_OB_REMOTE_JOB_CONTROL_ */
