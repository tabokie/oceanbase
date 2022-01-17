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

#ifndef OCEANBASE_SQL_RESOLVER_DCL_OB_CREATE_ROLE_STMT_
#define OCEANBASE_SQL_RESOLVER_DCL_OB_CREATE_ROLE_STMT_

#include "sql/resolver/ddl/ob_ddl_stmt.h"
#include "lib/string/ob_strings.h"
#include "share/ob_define.h"

namespace oceanbase {
namespace sql {
class ObCreateRoleStmt : public ObDDLStmt {
public:
  explicit ObCreateRoleStmt(common::ObIAllocator* name_pool);
  ObCreateRoleStmt();
  virtual ~ObCreateRoleStmt();

  void set_tenant_id(const uint64_t tenant_id)
  {
    tenant_id_ = tenant_id;
  }
  uint64_t get_tenant_id()
  {
    return tenant_id_;
  }
  void set_role_name(const common::ObString& role_name)
  {
    role_name_ = role_name;
  }
  const common::ObString& get_role_name() const
  {
    return role_name_;
  }
  void set_password(const common::ObString& password)
  {
    password_ = password;
  }
  const common::ObString& get_password() const
  {
    return password_;
  }
  virtual bool cause_implicit_commit() const
  {
    return true;
  }
  virtual obrpc::ObDDLArg& get_ddl_arg()
  {
    return create_role_arg_;
  }
  DECLARE_VIRTUAL_TO_STRING;

private:
  // data members
  uint64_t tenant_id_;
  common::ObString role_name_;
  common::ObString password_;
  obrpc::ObCreateRoleArg create_role_arg_;

private:
  DISALLOW_COPY_AND_ASSIGN(ObCreateRoleStmt);
};
}  // end namespace sql
}  // end namespace oceanbase
#endif  // OCEANBASE_SQL_RESOLVER_DCL_OB_CREATE_ROLE_STMT_
