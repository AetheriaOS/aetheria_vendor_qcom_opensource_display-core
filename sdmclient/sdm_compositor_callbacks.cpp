/*
 * Copyright (c) 2022-2024 Qualcomm Innovation Center, Inc. All rights reserved.
 * SPDX-License-Identifier: BSD-3-Clause-Clear
 */

#include "sdm_compositor_callbacks.h"

#include <debug_handler.h>

#define __CLASS__ "SDMCompositorCallbacks"

namespace sdm {

void SDMCompositorCallbacks::RegisterCallback(SDMCompositorCbIntf *cb, bool enable) {
  if (!enable || !cb) {
    callbacks_ = nullptr;
    return;
  } else {
    callbacks_ = cb;
  }
}

void SDMCompositorCallbacks::OnHotplug(uint64_t display, bool connected) {
  if (!callbacks_) {
    DLOGW("Callbacks interface is not initialized!");
    return;
  }

  callbacks_->OnHotplug(display, connected);
}

void SDMCompositorCallbacks::OnRefresh(uint64_t display) {
  if (!callbacks_) {
    DLOGW("Callbacks interface is not initialized!");
    return;
  }

  callbacks_->OnRefresh(display);
}

void SDMCompositorCallbacks::OnVsync(uint64_t display, int64_t timestamp,
                                     int32_t vsync_period_nanos) {
  if (!callbacks_) {
    DLOGW("Callbacks interface is not initialized!");
    return;
  }

  callbacks_->OnVsync(display, timestamp, vsync_period_nanos);
}

void SDMCompositorCallbacks::OnSeamlessPossible(uint64_t display) {
  if (!callbacks_) {
    DLOGW("Callbacks interface is not initialized!");
    return;
  }

  callbacks_->OnSeamlessPossible(display);
}

void SDMCompositorCallbacks::OnVsyncIdle(uint64_t display) {
  if (!callbacks_) {
    DLOGW("Callbacks interface is not initialized!");
    return;
  }

  callbacks_->OnVsyncIdle(display);
}

void SDMCompositorCallbacks::OnVsyncPeriodTimingChanged(uint64_t display,
                                                        SDMVsyncPeriodChangeTimeline &timeline) {
  if (!callbacks_) {
    DLOGW("Callbacks interface is not initialized!");
    return;
  }

  callbacks_->OnVsyncPeriodTimingChanged(display, timeline);
}

}  // namespace sdm