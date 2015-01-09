#include <binder/IPCThreadState.h>

#include <helloworld/HelloWorld.h>

#include <helloworld/IHelloWorldService.h>
#include <binder/IServiceManager.h>
#include <helloworld/HelloWorld.h>

namespace android {
sp<IHelloWorldService> HelloWorld::mHelloWorldService;
sp<HelloWorld> HelloWorld::connect()
{
	printf("\nHelloWorld: connect()\n");
	sp<HelloWorld> h = new HelloWorld();
	sp<IServiceManager> sm = defaultServiceManager();
	sp<IBinder> binder;

	do {
		binder = sm->getService(String16("android.apps.IHelloWorldService"));
		if(binder != 0)
			break;
		usleep(500000);
	} while(true);

	mHelloWorldService = interface_cast<IHelloWorldService>(binder);
	h->mHelloWorld = mHelloWorldService->connect(h);
	return h;

}

void HelloWorld::notifyCallBack(const char* result)
{
	printf("\nHelloWorld: notifyCallBack:result= %s.\n",result);
}

void HelloWorld::helloWorld(const char* str)
{
	sp<IHelloWorld> h = mHelloWorld;
	h->helloWorld(str);
}


};// end of namespace