#pragma once

#define INDEX_RSEQ() \
    32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, \
    16, 15, 14, 13, 12, 11, 10,  9,  8,  7,  6,  5,  4,  3,  2,  1, 0

#define VA_ARGS_SIZE_IMPL(\
        ARG1,  ARG2,  ARG3,  ARG4,  ARG5,  ARG6,  ARG7,  ARG8,  ARG9,  ARG10, \
        ARG11, ARG12, ARG13, ARG14, ARG15, ARG16, ARG17, ARG18, ARG19, ARG20, \
        ARG21, ARG22, ARG23, ARG24, ARG25, ARG26, ARG27, ARG28, ARG29, ARG30, \
        ARG31, ARG32, \
        N, ... \
    ) N

#define VA_ARGS_SIZE_AUX(...) VA_ARGS_SIZE_IMPL(__VA_ARGS__)
#define VA_ARGS_SIZE(...)     VA_ARGS_SIZE_AUX(__VA_ARGS__, INDEX_RSEQ())
