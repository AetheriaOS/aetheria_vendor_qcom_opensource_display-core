/*
 * Copyright (c) 2024 Qualcomm Innovation Center, Inc. All rights reserved.
 * SPDX-License-Identifier: BSD-3-Clause-Clear
 */
#ifndef SDM_INTERFACE_FACTORY
#define SDM_INTERFACE_FACTORY

#pragma once
#include "sdm_interface_factory.h"
#include <memory>

namespace sdm {

class SDMInterfaceFactoryImpl : public SDMInterfaceFactory {
public:
  SDMDisplayCapsIntf *CreateCapsIntf();
  SDMDisplayDrawCycleIntf *CreateDrawCycleIntf();
  SDMDisplayLayerBuilderIntf *CreateLayerBuilderIntf();
  SDMDisplayLifeCycleIntf *CreateLifeCycleIntf();
  SDMDisplaySettingsIntf *CreateSettingsIntf();
  SDMDisplaySideBandIntf *CreateSideBandIntf();
  SDMDisplayAiqeIntf *CreateAiqeIntf();

  void DestroyCapsIntf();
  void DestroyDrawCycleIntf();
  void DestroyLayerBuilderIntf();
  void DestroyLifeCycleIntf();
  void DestroySideBandIntf();
  void DestroySettingsIntf();
  void DestroyAiqeIntf();
};

} // namespace sdm

#endif
