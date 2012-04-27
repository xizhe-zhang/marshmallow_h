set(BUILD_UNIT_TESTS OFF CACHE BOOL "" FORCE)
set(CMAKE_BUILD_TYPE "RelWithDebug" CACHE STRING "" FORCE)

set(MARSHMALLOW_BUILD_TITLE "Marshmallow N9" CACHE STRING "Build Title")

option(MARSHMALLOW_DEBUG "Marshmallow Debugging" ON)
set(MARSHMALLOW_DEBUG_VERBOSITY "2" CACHE STRING "Verbosity Level")

set(MARSHMALLOW_VIEWPORT_HEIGHT  "480"    CACHE STRING "Viewport window height")
set(MARSHMALLOW_VIEWPORT_WIDTH   "854"    CACHE STRING "Viewport window width")
set(MARSHMALLOW_VIEWPORT_VHEIGHT "480.0f" CACHE STRING "Viewport virtual height")
set(MARSHMALLOW_VIEWPORT_VWIDTH  "854.0f" CACHE STRING "Viewport virtual width")
set(MARSHMALLOW_VIEWPORT_DEPTH   "32"     CACHE STRING "Viewport default depth")

option(MARSHMALLOW_VIEWPORT_OPENGL "Use OpenGL Viewport"                 ON)
option(MARSHMALLOW_OPENGL_GLX "Use OpenGL GLX Viewport (unix)"           ON)
option(MARSHMALLOW_OPENGL_GLES2 "Use EGL + OpenGL ES 2.0 (requires GLX)" ON)

option(MARSHMALLOW_CONTRIB_LIBPNG "Use bundled LibPNG" OFF)
option(MARSHMALLOW_CONTRIB_LUA    "Use bundled LUA"    OFF)
option(MARSHMALLOW_CONTRIB_ZLIB   "Use bundled ZLIB"   OFF)

option(MARSHMALLOW_WITH_BOX2D "Use Box2D" ON)
option(MARSHMALLOW_WITH_LUA   "Use Lua"   OFF)
