/*
 * Copyright (c) 2024 Qualcomm Innovation Center, Inc. All rights reserved.
 * SPDX-License-Identifier: BSD-3-Clause-Clear
 */
#include "sdm_factory.h"
#include "concurrency_mgr.h"
#include <debug_handler.h>
#include <dlfcn.h>

#define __CLASS__ "SDMInterfaceFactory"

namespace sdm {

static SDMInterfaceFactoryImpl factory_ = {};

SDMInterfaceFactory *GetSDMInterfaceFactory() { return &factory_; }

SDMDisplayCapsIntf *SDMInterfaceFactoryImpl::CreateCapsIntf() {
  SDMDisplayCapsIntf *caps = ConcurrencyMgr::GetInstance();
  if (!caps) {
    DLOGE("Unable to open sdm capabilities interface");
    return nullptr;
  }

  return caps;
}

SDMDisplayDrawCycleIntf *SDMInterfaceFactoryImpl::CreateDrawCycleIntf() {
  SDMDisplayDrawCycleIntf *draw_cycle = ConcurrencyMgr::GetInstance();
  if (!draw_cycle) {
    DLOGE("Unable to open sdm draw cycle interface");
    return nullptr;
  }

  return draw_cycle;
}

SDMDisplayLayerBuilderIntf *SDMInterfaceFactoryImpl::CreateLayerBuilderIntf() {
  SDMDisplayLayerBuilderIntf *layer_builder = SDMLayerBuilder::GetInstance();
  if (!layer_builder) {
    DLOGE("Unable to open sdm layer builder interface");
    return nullptr;
  }

  return layer_builder;
}

SDMDisplayLifeCycleIntf *SDMInterfaceFactoryImpl::CreateLifeCycleIntf() {
  SDMDisplayLifeCycleIntf *life_cycle = ConcurrencyMgr::GetInstance();
  if (!life_cycle) {
    DLOGE("Unable to open sdm life cycle interface");
    return nullptr;
  }

  return life_cycle;
}

SDMDisplaySettingsIntf *SDMInterfaceFactoryImpl::CreateSettingsIntf() {
  SDMDisplaySettingsIntf *settings = ConcurrencyMgr::GetInstance();
  if (!settings) {
    DLOGE("Unable to open sdm settings interface");
    return nullptr;
  }

  return settings;
}

SDMDisplaySideBandIntf *SDMInterfaceFactoryImpl::CreateSideBandIntf() {
  SDMDisplaySideBandIntf *sideband = ConcurrencyMgr::GetInstance();
  if (!sideband) {
    DLOGE("Unable to open sdm sideband interface");
    return nullptr;
  }

  return sideband;
}

SDMDisplayAiqeIntf *SDMInterfaceFactoryImpl::CreateAiqeIntf() {
  SDMDisplayAiqeIntf *aqie_intf = ConcurrencyMgr::GetInstance();
  if (!aqie_intf) {
    DLOGI("Unable to retrieve aiqe intf");
    return nullptr;
  }

  return aqie_intf;
}
} // namespace sdm
