// -*- mode:C++; tab-width:8; c-basic-offset:2; indent-tabs-mode:t -*-
// vim: ts=8 sw=2 smarttab ft=cpp

#ifndef CEPH_RGW_USAGE_H
#define CEPH_RGW_USAGE_H

#include <string>
#include <map>

#include "common/Formatter.h"
#include "rgw_formats.h"
#include "rgw_user.h"

namespace rgw { namespace sal { class RGWStore; } }


class RGWUsage
{
public:
  static int show(const DoutPrefixProvider *dpp, rgw::sal::RGWStore* store,
		  rgw::sal::RGWUser* user , rgw::sal::RGWBucket* bucket,
		  uint64_t start_epoch, uint64_t end_epoch, bool show_log_entries,
		  bool show_log_sum,
		  std::map<std::string, bool> *categories, RGWFormatterFlusher& flusher);

  static int trim(const DoutPrefixProvider *dpp, rgw::sal::RGWStore *store,
		  rgw::sal::RGWUser* user , rgw::sal::RGWBucket* bucket,
		  uint64_t start_epoch, uint64_t end_epoch);

  static int clear(rgw::sal::RGWStore *store);
};


#endif