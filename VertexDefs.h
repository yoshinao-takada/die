#ifndef VERTEXDEFS_H_
#define VERTEXDEFS_H_

#define COORD_TOP_LEFT      -0.5f, 0.5f, 0.0f
#define COORD_TOP_RIGHT     0.5f, 0.5f, 0.0f
#define COORD_BOTTOM_LEFT      -0.5f, -0.5f, 0.0f
#define COORD_BOTTOM_RIGHT     0.5f, -0.5f, 0.0f
#define COLOR_RED           1.0f, 0.0f, 0.0f
#define COLOR_GREEN         0.0f, 1.0f, 0.0f
#define COLOR_BLUE          0.0f, 0.0f, 1.0f
#define COLOR_YELLOW        1.0f, 1.0f, 0.0f
#define TEX_TOP_LEFT        0.0f, 1.0f
#define TEX_TOP_RIGHT       1.0f, 1.0f
#define TEX_BOTTOM_LEFT     0.0f, 0.0f
#define TEX_BOTTOM_RIGHT    1.0f, 0.0f

#define VERTEX_DEF  { \
    COORD_TOP_RIGHT, COLOR_RED, TEX_TOP_RIGHT, \
    COORD_BOTTOM_RIGHT, COLOR_GREEN, TEX_BOTTOM_RIGHT, \
    COORD_BOTTOM_LEFT, COLOR_BLUE, TEX_BOTTOM_LEFT, \
    COORD_TOP_LEFT, COLOR_YELLOW, TEX_TOP_LEFT \
}

#define POINT_INDEX_DEF { \
    0, 1, 3, \
    1, 2, 3 \
}

/*
  5 +-----+ 4
    |o o o|
    |     |
    |o o o| 1   4     5     0
  0 +-----+-----+-----+-----+
    |o   o|o    |    o|o   o|
    |  o  |  o  |     |     |
    |o   o|    o|o    |o   o|
  2 +-----+-----+-----+-----+
    |     | 3   6     7     2
    |  O  |
    |     |
  7 +-----+ 6

*/
#define DIE_TEX0    0.0f, (2.0f/3.0f)
#define DIE_TEX1    (3.0f/4.0f), (2.0f/3.0f)
#define DIE_TEX2    0.0f, (1.0f/3.0f)
#define DIE_TEX3    (3.0f/4.0f), (1.0f/3.0f)
#define DIE_TEX4    (2.0f/4.0f), (2.0f/3.0f)
#define DIE_TEX5    (3.0f/4.0f), (2.0f/3.0f)
#define DIE_TEX6    (2.0f/4.0f), (1.0f/3.0f)
#define DIE_TEX7    (3.0f/4.0f), (1.0f/3.0f)
#define DIE_COORD0  -0.5f, 0.5f, 0.5f
#define DIE_COORD1  0.5f, 0.5f, 0.5f
#define DIE_COORD2  -0.5f, -0.5f, 0.5f
#define DIE_COORD3  0.5f, -0.5f, 0.5f
#define DIE_COORD4  0.5f, 0.5f, -0.5f
#define DIE_COORD5  -0.5f, 0.5f, -0.5f
#define DIE_COORD6  0.5f, -0.5f, -0.5f
#define DIE_COORD7  -0.5f, -0.5f, -0.5f

#define DIE_VERTICES    { \
    DIE_COORD0, DIE_TEX0, \
    DIE_COORD0, DIE_TEX1, \
    DIE_COORD0, DIE_TEX2, \
    DIE_COORD0, DIE_TEX3, \
    DIE_COORD0, DIE_TEX4, \
    DIE_COORD0, DIE_TEX5, \
    DIE_COORD0, DIE_TEX6, \
}

#define DIE_TRIANGLES { \
    5,0,4, 4,0,1, \
    0,2,1, 1,2,3, \
    1,3,4, 4,3,6, \
    4,6,5, 5,6,7, \
    5,7,0, 0,7,2, \
    2,7,3, 3,7,6 \
}
#endif /* VERTEXDEFS_H_ */
