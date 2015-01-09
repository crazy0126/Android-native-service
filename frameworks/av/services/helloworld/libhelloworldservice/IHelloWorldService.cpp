#include <helloworld/IHelloWorldService.h>



namespace android {


class BpHelloWorldService: public BpInterface<IHelloWorldService>
{
public:
	
	BpHelloWorldService(const sp<IBinder>& impl)
		: BpInterface<IHelloWorldService> (impl)
	{
	}
	
	sp<IHelloWorld> connect(const sp<IHelloWorldClient>& helloWorldClient) {
		Parcel data, reply;

		data.writeInterfaceToken(
			IHelloWorldService::getInterfaceDescriptor());
			data.writeStrongBinder(helloWorldClient->asBinder());

		printf("\nZhao: BpHelloWorldService::helloWorld Call remote()->transact()!\n ");

		remote()->transact(BnHelloWorldService::CONNECT, data, &reply);


		return interface_cast<IHelloWorld>(reply.readStrongBinder());
	}

};
//---------------------------------------------------------------------------------------------
IMPLEMENT_META_INTERFACE(HelloWorldService, "android.apps.IHelloWorldService");

status_t BnHelloWorldService::onTransact( uint32_t code, const Parcel &data,Parcel *reply, uint32_t flags)
{
	printf("\nBnHelloWorldService::onTransact Starts!\n");
	switch(code){

	//
	case CONNECT: {
		//
		CHECK_INTERFACE(IHelloWorldService, data, reply);

		sp<IHelloWorldClient> helloWorldClient = interface_cast<IHelloWorldClient>(data.readStrongBinder());
		sp<IHelloWorld> helloWorld = connect(helloWorldClient);
		reply->writeStrongBinder(helloWorld->asBinder());
		return NO_ERROR;
	} break;
	default:
		printf("\nBnHelloWorldService::onTransact BBinder::onTransact()!\n");
		return BBinder::onTransact(code, data, reply, flags);
	}

}

}; // namespace android
