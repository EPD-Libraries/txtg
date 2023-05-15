# TXTG

Experimental `TexToGo` file format parser

## Format

### Header

| Offset | Type                                   | Description                                                  |
|--------|----------------------------------------|--------------------------------------------------------------|
| 0x00   | u32                                    | Header size                                                  |
| 0x04   | char[4]                                | Magic                                                        |
| 0x08   | u16                                    | Texture Width                                                |
| 0x0A   | u16                                    | Texture Height                                               |
| 0x0C   | u16                                    | Texture Count                                                |
| 0x0E   | u8                                     | Mip Count                                                    |
| 0x0F   | u8                                     | Unknown                                                      |
| 0x10   | char[12]                               | Unknown Data Region                                          |
| 0x1C   | char[32]                               | Unknown Data Region (Possibly checksum/id)                   |
| 0x3C   | u8                                     | Unknown (Likely a byte value)                                |
| 0x3D   | u8                                     | Unknown (Always matches `0x3C`?)                             |
| 0x3E   | u16                                    | Unknown (Always `0x0003`?)                                   |
| 0x40   | f32                                    | Unknown Float (Typically 70, found 50 in `MaterialAlb.txtg`) |
| 0x44   | Dword                                  | Unknown Param (Second Bytes is often `0x7F`)                 |
| 0x48   | u16                                    | Unknown (Always `512`?)                                      |
| 0x4A   | u16                                    | Unknown (Always `512`?)                                      |
| 0x4C   | Dword                                  | Unknown Data Block                                           |

### Indices

Following the header seems to be an array of mip index ([TextureEntry](#texture-entry)) arrays.

```cpp
std::array<TextureEntry[texture_count], mip_count> indices;
```

#### Texture Entry

| Offset | Type | Description         |
|--------|------|---------------------|
| 0x00   | u16  | Texture Index       |
| 0x02   | u8   | Mip-Map Index       |
| 0x04   | u8   | Unknown (Always 1?) |

### Offsets?

Following the texture indices is an array of offset entries ([OffsetEntry](#offset-entry))

```cpp
std::array<OffsetEntry, texture_count*mip_count> indices;
```

#### Offset Entry

| Offset | Type | Description         |
|--------|------|---------------------|
| 0x00   | u32  | Compressed Size     |
| 0x04   | u32  | Unknown (Always 6?) |
