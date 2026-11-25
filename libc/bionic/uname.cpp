/*
 * SPDX-FileCopyrightText: 2026 The ExpressiveOS Project
 * SPDX-License-Identifier: Apache-2.0
 */

#include <sys/utsname.h>

#include "custom_rom_hide.h"

extern "C" int __uname(struct utsname*);

int uname(struct utsname* buf) {
  int rc = __uname(buf);
  if (rc == 0) {
    custom_rom_hide_normalize_utsname(buf);
  }
  return rc;
}
