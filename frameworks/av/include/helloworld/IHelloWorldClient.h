#ifndef _IHELLOWORLDCLIENT_H
#define _IHELLOWORLDCLIENT_H

#include <binder/IInterface.h>
#include <binder/Parcel.h>

namespace android {

class IHelloWorldClient: public IInterface
{
public:
	DECLARE_META_INTERFACE(HelloWorldClient);
	virtual void notifyCallBack(const char* result) = 0;

};
//----------------------------------------------------------------------------
class BnHelloWorldClient: public  BnInterface<IHelloWorldClient>
{
public:
	virtual status_t onTransact(uint32_t code, const Parcel& data, Parcel* reply, uint32_t flags = 0);

};

}; //end of namesapce android
#endif