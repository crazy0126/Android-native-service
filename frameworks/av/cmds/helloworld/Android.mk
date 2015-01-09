LOCAL_PATH:= $(call my-dir)



include $(CLEAR_VARS)

LOCAL_SRC_FILES:= \
	main_helloworldservice.cpp
LOCAL_SHARED_LIBRARIES := \
	libutils \
	libbinder \
	libhelloworldservice

LOCAL_MODULE:= helloworldservice

include $(BUILD_EXECUTABLE)




include $(CLEAR_VARS)

LOCAL_SRC_FILES:= \
	main_helloworldclient.cpp
LOCAL_SHARED_LIBRARIES := \
	libutils \
	libbinder \
	libhelloworldservice

LOCAL_MODULE:= helloworldclient

include $(BUILD_EXECUTABLE)
