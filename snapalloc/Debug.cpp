// Copyright (c) 2023 Qualcomm Innovation Center, Inc. All rights reserved.
// SPDX-License-Identifier: BSD-3-Clause-Clear

#include "Debug.h"

#include <log/log.h>

namespace snapalloc {
int Debug::GetProperty(const char *property_name, int *value) {
  if (DebugHandler::Get()->GetProperty(property_name, value)) {
    return -ENOTSUP;
  }
  return 0;
}
int Debug::GetProperty(const char *property_name, char *value) {
  if (DebugHandler::Get()->GetProperty(property_name, value)) {
    return -ENOTSUP;
  }
  return 0;
}
bool Debug::IsAhardwareBufferDisabled() {
  int value = 0;
  DebugHandler::Get()->GetProperty(DISABLE_AHARDWARE_BUFFER_PROP, &value);
  return (value == 1);
}
bool Debug::IsUBWCDisabled() {
  int value = 0;
  DebugHandler::Get()->GetProperty(DISABLE_UBWC_PROP, &value);
  return (value == 1);
}
bool Debug::IsSecurePreviewBufferFormatEnabled(std::string *secure_preview_buffer_format) {
  char value[PROPERTY_VALUE_MAX] = "0";
  int error = DebugHandler::Get()->GetProperty(SECURE_PREVIEW_BUFFER_FORMAT_PROP, value);
  if (error != 0) {
    return -ENOTSUP;
  }
  *secure_preview_buffer_format = value;
  return 0;
}
bool Debug::IsSecurePreviewOnlyEnabled() {
  int value = 0;
  DebugHandler::Get()->GetProperty(SECURE_PREVIEW_ONLY_PROP, &value);
  return (value == 1);
}
bool Debug::UseDMABufHeaps() {
  int value = 0;
  DebugHandler::Get()->GetProperty(USE_DMA_BUF_HEAPS_PROP, &value);
  return (value == 1);
}
bool Debug::HwSupportsUBWCP() {
  int value = 0;
  DebugHandler::Get()->GetProperty(HW_SUPPORTS_UBWCP, &value);
  return (value == 1);
}
}  // namespace snapalloc