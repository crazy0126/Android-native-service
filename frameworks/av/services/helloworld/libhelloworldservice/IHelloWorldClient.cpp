#include <helloworld/IHelloWorldClient.h>

namespace android {

enum {
	NOTIFY_CALLBACK = IBinder::FIRST_CALL_TRANSACTION,
};


class BpHelloWorldClient: public BpInterface<IHelloWorldClient>
{
public:
	BpHelloWorldClient(const sp<IBinder>& impl)
		: BpInterface<IHelloWorldClient> (impl)
	{
	}

	virtual void notifyCallBack(const char* result)
	{
		Parcel data, reply;
		data.writeInterfaceToken(IHelloWorldClient::getInterfaceDescriptor());
		data.writeCString(result);
		remote()->transact(NOTIFY_CALLBACK, data, &reply);

	}
};

IMPLEMENT_META_INTERFACE(HelloWorldClient, "android.hardware.IHelloWorldClient");

status_t BnHelloWorldClient::onTransact(uint32_t code, const Parcel& data, Parcel* reply, uint32_t flags )
{
	switch(code) {
		case NOTIFY_CALLBACK: {
			CHECK_INTERFACE(IHelloWorld, data, reply);
			
			const char* result = data.readCString();
			notifyCallBack(result);			//?????????????????????
			return NO_ERROR;
		} break;
		default:
			return BBinder::onTransact(code, data, reply, flags);
	}
}


}; //end of namespace android
