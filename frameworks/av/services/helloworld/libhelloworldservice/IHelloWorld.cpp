#include <binder/Parcel.h>
#include <helloworld/IHelloWorld.h>

namespace android {

enum {
		HELLOWORLD = IBinder::FIRST_CALL_TRANSACTION,
	
};

class BpHelloWorld: public BpInterface<IHelloWorld>
{
public:
	BpHelloWorld(const sp<IBinder>& impl)
		: BpInterface<IHelloWorld> (impl)
	{
	}

	void helloWorld(const char* str)
	{
		printf("\nBpHelloWorld::helloWorld()!\n");
		Parcel data, reply;
		data.writeInterfaceToken(IHelloWorld::getInterfaceDescriptor());
		data.writeCString(str);
		remote()->transact(HELLOWORLD, data, &reply);

	}
};

IMPLEMENT_META_INTERFACE(HelloWorld, "android.hardware.IHelloWorld");

status_t BnHelloWorld::onTransact(uint32_t code, const Parcel& data, Parcel* reply, uint32_t flags )
{
	switch(code) {
		case HELLOWORLD: {
			printf("\nBnHelloWorld::onTransact: case HELLOWORLD!\n");
			CHECK_INTERFACE(IHelloWorld, data, reply);
			const char* str;
			str = data.readCString();
			helloWorld(str);
			return NO_ERROR;
		} break;
		default:
			return BBinder::onTransact(code, data, reply, flags);
	}
}


}; // end of namespace
