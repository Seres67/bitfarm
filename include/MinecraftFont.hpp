#ifndef STARDEW_BOY_UNIFONTFONT_HPP
#define STARDEW_BOY_UNIFONTFONT_HPP

#include <bn_sprite_font.h>
#include <bn_sprite_items_big_font.h>
#include <bn_utf8_characters_map.h>

constexpr int8_t BIG_FONT_CHARACTER_WIDTHS[] = {
    6,  // 32
    2,  // 33 !
    8,  // 34 "
    10, // 35 #
    8,  // 36 $
    13, // 37 %
    9,  // 38 &
    2,  // 39 '
    6,  // 40 (
    6,  // 41 )
    6,  // 42 *
    9,  // 43 +
    3,  // 44 ,
    5,  // 45 -
    2,  // 46 .
    8,  // 47 /
    7,  // 48 0
    6,  // 49 1
    7,  // 50 2
    7,  // 51 3
    8,  // 52 4
    9,  // 53 5
    8,  // 54 6
    7,  // 55 7
    7,  // 56 8
    7,  // 57 9
    3,  // 58 :
    3,  // 59 ;
    6,  // 60 <
    8,  // 61 =
    6,  // 62 >
    8,  // 63 ?
    14, // 64 @
    9,  // 65 A
    10, // 66 B
    11, // 67 C
    10, // 68 D
    10, // 69 E
    9,  // 70 F
    11, // 71 G
    10, // 72 H
    5,  // 73 I
    8,  // 74 J
    9,  // 75 K
    9,  // 76 L
    10, // 77 M
    10, // 78 N
    12, // 79 O
    10, // 80 P
    12, // 81 Q
    12, // 82 R
    9,  // 83 S
    10, // 84 T
    10, // 85 U
    10, // 86 V
    10, // 87 W
    10, // 88 X
    10, // 89 Y
    10, // 90 Z
    4,  // 91 [
    8,  // 92
    4,  // 93 ]
    8,  // 94 ^
    9,  // 95 _
    4,  // 96 `
    9,  // 97 a
    10, // 98 b
    9,  // 99 c
    8,  // 100 d
    8,  // 101 e
    8,  // 102 f
    8,  // 103 g
    8,  // 104 h
    2,  // 105 i
    7,  // 106 j
    8,  // 107 k
    2,  // 108 l
    14, // 109 m
    9,  // 110 n
    8,  // 111 o
    9,  // 112 p
    8,  // 113 q
    7,  // 114 r
    7,  // 115 s
    5,  // 116 t
    8,  // 117 u
    10, // 118 v
    10, // 119 w
    10, // 120 x
    8,  // 121 y
    8,  // 122 z
    5,  // 123 {
    2,  // 124 |
    5,  // 125 }
    10, // 126 ~
};

constexpr bn::sprite_font BIG_FONT(bn::sprite_items::big_font, {}, BIG_FONT_CHARACTER_WIDTHS);

#endif // !STARDEW_BOY_UNIFONTFONT_HPP
