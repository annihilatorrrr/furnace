/**
 * Furnace Tracker - multi-system chiptune tracker
 * Copyright (C) 2021-2025 tildearrow and contributors
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#include "engine.h"

#include "export/amigaValidation.h"
#include "export/sapr.h"
#include "export/tiuna.h"
#include "export/zsm.h"
#include "export/ipod.h"
#include "export/grub.h"

DivROMExport* DivEngine::buildROM(DivROMExportOptions sys) {
  DivROMExport* exporter=NULL;
  switch (sys) {
    case DIV_ROM_AMIGA_VALIDATION:
      exporter=new DivExportAmigaValidation;
      break;
    case DIV_ROM_TIUNA:
      exporter=new DivExportTiuna;
      break;
    case DIV_ROM_ZSM:
      exporter=new DivExportZSM;
      break;
    case DIV_ROM_SAP_R:
      exporter=new DivExportSAPR;
      break;
    case DIV_ROM_IPOD:
      exporter=new DivExportiPod;
      break;
    case DIV_ROM_GRUB:
      exporter=new DivExportGRUB;
      break;
    default:
      exporter=new DivROMExport;
      break;
  }
  return exporter;
}
