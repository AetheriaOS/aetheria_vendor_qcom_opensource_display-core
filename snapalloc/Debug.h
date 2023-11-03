// Copyright (c) 2023 Qualcomm Innovation Center, Inc. All rights reserved.
// SPDX-License-Identifier: BSD-3-Clause-Clear
#ifndef __DEBUG_H__
#define __DEBUG_H__

#include <debug_handler.h>
#include <display_properties.h>
#include <errno.h>

#define PROPERTY_VALUE_MAX 255

namespace snapalloc {
using display::DebugHandler;
class Debug {
 public:
  static inline DebugHandler *Get() { return DebugHandler::Get(); }
  static int GetProperty(const char *property_name, char *value);
  static int GetProperty(const char *property_name, int *value);
  static bool IsAhardwareBufferDisabled();
  static bool IsUBWCDisabled();
  static bool IsSecurePreviewBufferFormatEnabled(std::string *secure_preview_buffer_format);
  static bool IsSecurePreviewOnlyEnabled();
  static bool UseDMABufHeaps();
  static bool UseSystemHeapForSensors();
  static bool HwSupportsUBWCP();
};
}  // namespace snapalloc
#endif  // __DEBUG_H__