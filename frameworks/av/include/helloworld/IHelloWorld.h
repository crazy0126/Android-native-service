#ifndef _IHELLOWORLD_H_
#define _IHELLOWORLD_H_

#include <binder/IInterface.h>


namespace android {



class IHelloWorld : public IInterface
{
public:

	DECLARE_META_INTERFACE(HelloWorld);
	virtual void helloWorld(const char* str) = 0;
};



class BnHelloWorld : public BnInterface<IHelloWorld>
{
	public:
	//

	virtual status_t onTransact(uint32_t code, const Parcel& data, Parcel* reply, uint32_t flags = 0);
};



};// namespace android


#endif
