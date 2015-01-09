#ifndef _HELLOWORLDSERVICE_H_
#define _HELLOWORLDSERVICE_H_

#include <binder/Parcel.h>
#include <helloworld/IHelloWorldService.h>
#include <utils/Log.h>
#include <helloworld/IHelloWorld.h>


namespace android {
class HelloWorldService : public BnHelloWorldService
{
public:
	//
	class Client;//used to print helloworld string.

	static void instantiate();
	//
	virtual sp<IHelloWorld> connect(const sp<IHelloWorldClient>& helloWorldClient);
	//
	virtual status_t onTransact(uint32_t code, const Parcel& data, Parcel* reply, uint32_t flags);


	class Client : public BnHelloWorld
	{
		public:
		    virtual void helloWorld(const char* str);

		    Client(const sp<HelloWorldService>& helloWorldService, const sp<IHelloWorldClient>& helloWorldClient, int clientPid);
		    ~Client();
		private:
		    sp<HelloWorldService>	mHelloWorldService;
		    sp<IHelloWorldClient>	mHelloWorldClient;
		    int 			mClientPid;

	};

private:
	//
	sp<Client>	mClient;
	HelloWorldService();
	virtual ~HelloWorldService();

};



}; // namesapce android

#endif