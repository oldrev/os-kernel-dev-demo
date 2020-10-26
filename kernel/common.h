#pragma once

#define __DO_CONCAT(x,y) x##y

#define CONCAT(x, y) __DO_CONCAT(x, y)

#define __DO_STRINGIFY(s) #s
#define STRINGIFY(s) __DO_STRINGIFY(s)

#define __USED        __attribute__((__used__))