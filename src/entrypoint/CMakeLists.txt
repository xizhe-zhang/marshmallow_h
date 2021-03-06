add_definitions(-DMARSHMALLOW_ENTRYPOINT_LIBRARY)

set(MARSHMALLOW_ENTRYPOINT_SRCS)
set(MARSHMALLOW_ENTRYPOINT_LIBS)

if(MARSHMALLOW_ANDROID)
	if(ANDROID_NATIVE_API_LEVEL LESS 9)
		message(FATAL_ERROR "Marshmallow requires ANDROID_NATIVE_API_LEVEL set to at least 9!")
	endif()

	set(ANDROID_JNI_GLUE_DIR "${ANDROID_NDK}/sources/android/native_app_glue")
	include_directories(${ANDROID_JNI_GLUE_DIR})

	list(APPEND MARSHMALLOW_ENTRYPOINT_SRCS
	    "${ANDROID_JNI_GLUE_DIR}/android_native_app_glue.c"
	    "android.cpp"
	)

	list(APPEND MARSHMALLOW_ENTRYPOINT_LIBS "android" "log")
elseif(UNIX)
	list(APPEND MARSHMALLOW_ENTRYPOINT_SRCS "unix.cpp")
	list(APPEND MARSHMALLOW_ENTRYPOINT_LIBS "marshmallow_event")
elseif(WIN32)
	list(APPEND MARSHMALLOW_ENTRYPOINT_SRCS "win32.cpp")
endif()

add_library(marshmallow_entrypoint STATIC ${MARSHMALLOW_ENTRYPOINT_SRCS})

target_link_libraries(marshmallow_entrypoint ${MARSHMALLOW_ENTRYPOINT_LIBS})

install(TARGETS marshmallow_entrypoint
        ARCHIVE DESTINATION lib COMPONENT development)

