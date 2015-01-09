#define LOG_TAG "main_helloworldservice"
#include <binder/IPCThreadState.h>
#include <binder/ProcessState.h>
#include <binder/IServiceManager.h>
#include <utils/Log.h>


#include <helloworld/HelloWorldService.h>


using namespace android;

int main( int args, char *argv[])
{
	HelloWorldService::instantiate();
	ProcessState::self()->startThreadPool();
	//LOGI("HelloWorldService is starting now\n");
	printf("HelloWorldService is starting now\n");
	IPCThreadState::self()->joinThreadPool();
	return 0;


}