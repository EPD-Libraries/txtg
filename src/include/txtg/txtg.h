#pragma once

#include <exio/binary_reader.h>
#include <exio/binary_writer.h>
#include <exio/error.h>
#include <exio/swap.h>
#include <exio/types.h>
#include <exio/util/magic_utils.h>
#include <nonstd/span.h>

namespace oepd {

namespace txtg {

struct Header {
  u16 header_size;
  u16 version;
  std::array<char, 4> magic;
  u16 width;
  u16 height;
  u16 texture_count;
  u8 mip_map_count;
  u8 unknown_1;  // Always 0x02?
  std::array<char, 0x0C> unknown_data_block;
  std::array<char, 0x20> checksum;
  u16 format;
  u16 unknown_2;  // Always 0x0300?
  f32 unknown_3;  // Float Value
  u32 unknown_4;  // Second byte is typically 0xF7
  u16 unknown_6;  // Always 0x0200?
  u16 unknown_7;  // Always 0x0200?
  u16 unknown_8;  // First bytes is always(?) 0x2, second byte changes (3, 5, 7...)
  u16 unknown_9;  // Always 0x01?
};

struct TextureEntry {
  u16 texture_index;
  u8 mip_index;
  u8 unknown_1;  // Always 0x01?
};

class TXTG {
  TXTG(tcb::span<const u8> data);
};

}  // namespace txtg

}  // namespace oepd