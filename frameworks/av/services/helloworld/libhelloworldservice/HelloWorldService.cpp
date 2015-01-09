#include <binder/IServiceManager.h>
#include <binder/IPCThreadState.h>
#include <helloworld/HelloWorldService.h>
#include <utils/Log.h>


namespace android {
HelloWorldService::Client::Client(const sp<HelloWorldService>& helloWorldService, const sp<IHelloWorldClient>& helloWorldClient, int clientPid) {
	mHelloWorldService = helloWorldService;
	mHelloWorldClient = helloWorldClient;
	mClientPid = clientPid;
}

HelloWorldService::Client:: ~Client() {

}
void HelloWorldService::Client:: helloWorld(const char* str) {
	printf("\nHelloWorldService::Client:: str= %s.\n",str);
	sp<IHelloWorldClient> h = mHelloWorldClient;
	if(h != 0) {
		const char * result = "HelloWorldService::OK";
		printf("\nHelloWorldService::Client::helloWorld:: Call HelloWorldClient:notifyCallBack()!\n");
		h->notifyCallBack(result);

	}
}


//-----------------------------
void HelloWorldService::instantiate() {
	printf("\nHelloWorldService::instantiate()!");
	defaultServiceManager()->addService(
	String16("android.apps.IHelloWorldService"), new HelloWorldService());
}

sp<IHelloWorld> HelloWorldService::connect(const sp<IHelloWorldClient>& helloWorldClient) {
	printf("\nHelloWorldService::connect()!\n");
	//LOGI("%s\n", str);
	int callingPid = 1 /*getCallingPid()*/;
	sp<Client> client = new HelloWorldService::Client(this, helloWorldClient, callingPid);
	mClient = client;
	return client;
}
HelloWorldService::HelloWorldService(){
	//LOGI("HelloWorldService is created\n");
	printf("\nHelloWorldService is created\n");

}


HelloWorldService::~HelloWorldService(){
	//LOGI("HelloWorldService is destroyed\n");
	printf("\nHelloWorldService is destroyed\n");
}


status_t HelloWorldService::onTransact(
	uint32_t code, const Parcel& data, Parcel* reply, uint32_t flags)
{
	printf("\nHelloWorldService::onTransact()!");
	return BnHelloWorldService::onTransact(code, data, reply, flags);

}


//--------------------------------------------------------------------



};