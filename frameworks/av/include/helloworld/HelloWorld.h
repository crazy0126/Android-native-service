#ifndef _HELLOWORLD_
#define _HELLOWORLD_
#include <helloworld/IHelloWorldClient.h>
#include <helloworld/IHelloWorld.h>
#include <helloworld/IHelloWorldService.h>
namespace android {
//class IHelloWorldService;//?????????????? 

class HelloWorld: public BnHelloWorldClient {

public:
	static sp<HelloWorld> connect();
	void notifyCallBack(const char* result);
	void helloWorld(const char* str);
private:
	sp<IHelloWorld> mHelloWorld;
	static sp<IHelloWorldService> mHelloWorldService;



}; // end of HelloWorld

}; //end of namespace android
#endif