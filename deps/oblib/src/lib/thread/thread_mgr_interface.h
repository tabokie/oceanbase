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

#ifndef OBLIB_THREAD_MGR_INTERFACE_H
#define OBLIB_THREAD_MGR_INTERFACE_H

#include "lib/atomic/ob_atomic.h"

namespace oceanbase {
namespace lib {

class TGRunnable {
public:
  virtual void run1() = 0;
  bool has_set_stop() const
  {
    return ATOMIC_LOAD(&stop_);
  }
  void set_stop(bool stop)
  {
    stop_ = stop;
  }
  uint64_t get_thread_idx() const
  {
    return thread_idx_;
  }
  void set_thread_idx(uint64_t thread_idx)
  {
    thread_idx_ = thread_idx;
  }

private:
  bool stop_ = true;
  static __thread uint64_t thread_idx_;
};

class TGTaskHandler {
public:
  virtual void handle(void* task) = 0;
  uint64_t get_thread_idx() const
  {
    return thread_idx_;
  }
  void set_thread_idx(uint64_t thread_idx)
  {
    thread_idx_ = thread_idx;
  }
  void set_thread_cnt(int64_t n_threads)
  {
    n_threads_ = n_threads;
  }
  int64_t get_thread_cnt()
  {
    return n_threads_;
  }

private:
  int64_t n_threads_ = 0;
  static __thread uint64_t thread_idx_;
};

}  // end of namespace lib
}  // end of namespace oceanbase

#endif /* OBLIB_THREAD_MGR_INTERFACE_H */
