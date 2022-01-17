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

#ifndef OCEANBASE_LIBOBLOG_OB_LOG_HBASE_MODE_H_
#define OCEANBASE_LIBOBLOG_OB_LOG_HBASE_MODE_H_

#include "lib/hash/ob_hashset.h"                // ObHashSet
#include "lib/hash/ob_linear_hash_map.h"        // ObLinearHashMap

namespace oceanbase
{
namespace share
{
namespace schema
{
class ObTableSchema;
} // namespace schema
} // namespace share

namespace liboblog
{

class ObLogHbaseUtil
{
public:
  ObLogHbaseUtil();
  virtual ~ObLogHbaseUtil();

public:
  // Determine if the table is an hbase model,
  // if yes, join; otherwise do nothing
  //
  // Determine if the table is an hbase model:
  // 1. table_name contains $
  // 2. contains four columns K, Q, T, V
  // 3. T is of type bigint
  // Note: All of the above conditions are not necessarily met for an hbase table
  int add_hbase_table_id(const oceanbase::share::schema::ObTableSchema &table_schema);

  // Determine if conversion is required
  // table exists and is a T column
  int judge_hbase_T_column(const uint64_t table_id,
      const uint64_t column_id,
      bool &chosen);

  int is_hbase_table(const uint64_t table_id,
      bool &chosen);

public:
  int init();
  void destroy();

private:
  static const int64_t HBASE_TABLE_COLUMN_COUNT = 4;
  const char *K_COLUMN = "K";
  const char *Q_COLUMN = "Q";
  const char *T_COLUMN = "T";
  const char *V_COLUMN = "V";

  static const int64_t DEFAULT_TABLE_SET_SIZE = 1024;
  typedef common::hash::ObHashSet<uint64_t> HbaseTableIDSet;

  struct TableID
  {
    uint64_t table_id_;

    TableID(const uint64_t table_id) :
      table_id_(table_id)
    {}

    int64_t hash() const
    {
      return static_cast<int64_t>(table_id_);
    }

    bool operator== (const TableID &other) const
    {
      return table_id_ == other.table_id_;
    }

    void reset()
    {
      table_id_ = common::OB_INVALID_ID;
    }

    TO_STRING_KV(K_(table_id));
  };

  typedef common::ObLinearHashMap<TableID, uint64_t/*column id*/> ColumnIDMap;

private:
  int filter_hbase_mode_table_(const oceanbase::share::schema::ObTableSchema &table_schema,
      bool &is_hbase_mode_table);

private:
  bool            inited_;

  HbaseTableIDSet table_id_set_;
  ColumnIDMap     column_id_map_;

private:
  DISALLOW_COPY_AND_ASSIGN(ObLogHbaseUtil);
};

}
}
#endif
