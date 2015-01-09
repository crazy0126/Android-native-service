#ifndef _IHELLOWORLDSERVICE_H_
#define _IHELLOWORLDSERVICE_H_

#include <binder/IInterface.h>
#include <helloworld/IHelloWorldClient.h>
#include <helloworld/IHelloWorld.h>

namespace android {


class IHelloWorldService: public IInterface {
	public:
		enum {
		CONNECT = IBinder::FIRST_CALL_TRANSACTION,			
		};

	DECLARE_META_INTERFACE(HelloWorldService);

	virtual sp<IHelloWorld> connect(const sp<IHelloWorldClient> &helloWorldClient)=0;

};	// IHelloWroldService	

//--------------------------------------------------------------------------------------
class BnHelloWorldService: public BnInterface<IHelloWorldService>
{
	public:
	//

	virtual status_t onTransact(uint32_t code, const Parcel& data, Parcel* reply, uint32_t flags = 0);
};

};// namespace android
#endif
