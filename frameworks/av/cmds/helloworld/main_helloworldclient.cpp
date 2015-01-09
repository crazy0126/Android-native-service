#define LOG_TAG "main_helloworldclient"
#include <binder/IPCThreadState.h>
#include <binder/ProcessState.h>
#include <binder/IServiceManager.h>
#include <utils/Log.h>


#include <helloworld/HelloWorld.h>



using namespace android;

int main(int argc, char *argv[])
{
	//LOGI("HelloWorldService client is now starting\n");
	printf("\nHelloWorldService client is now starting\n ");

	sp<HelloWorld> h = HelloWorld::connect();
	
	printf("\nCall helloWorld of BpHelloWorld!\n");
	h->helloWorld("Jiangang is a excellent guy!");


	printf("finished!\n ");
	return(0);



}