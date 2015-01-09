LOCAL_PATH:= $(call my-dir)
include $(CLEAR_VARS)

LOCAL_SRC_FILES:= \
	IHelloWorldService.cpp \
	HelloWorldService.cpp \
	HelloWorld.cpp \
	IHelloWorld.cpp \
	IHelloWorldClient.cpp


LOCAL_SHARED_LIBRARIES := \
    libutils \
    libcutils \
    libbinder 


LOCAL_PRELINK_MODULE:= false
LOCAL_MODULE:= libhelloworldservice

include $(BUILD_SHARED_LIBRARY)
