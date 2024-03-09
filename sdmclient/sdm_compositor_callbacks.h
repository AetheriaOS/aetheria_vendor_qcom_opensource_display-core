/*
 * Copyright (c) 2022-2024 Qualcomm Innovation Center, Inc. All rights reserved.
 * SPDX-License-Identifier: BSD-3-Clause-Clear
 */

#include "sdm_compositor_cb_intf.h"

#include <core/sdm_types.h>

namespace sdm {

class SDMCompositorCallbacks {
 public:
  void RegisterCallback(SDMCompositorCbIntf *cb, bool enable);
  void OnHotplug(uint64_t display, bool connected);
  void OnRefresh(uint64_t display);
  void OnVsync(uint64_t display, int64_t timestamp, int32_t vsync_period_nanos);
  void OnSeamlessPossible(uint64_t display);
  void OnVsyncIdle(uint64_t display);
  void OnVsyncPeriodTimingChanged(uint64_t display, SDMVsyncPeriodChangeTimeline &timeline);

 private:
  // non-owning reference - must always be reset to null on/before client deinit
  SDMCompositorCbIntf *callbacks_ = nullptr;
};

}  // namespace sdm