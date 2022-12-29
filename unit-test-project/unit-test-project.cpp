#include "pch.h"
#include "CppUnitTest.h"
#include "../main-project/phone_talk.h"
#include "../main-project/processing.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unittestproject
{
	phone_talk* build_subscription(int duration_hour, int duration_minute, int duration_second,double cost)
	{
		phone_talk* subscription = new phone_talk;
		subscription->duration.hour = duration_hour;
		subscription->duration.minute = duration_minute;
		subscription->duration.second = duration_second;
		subscription->cost = cost;
		return subscription;
	}
	void delete_subscription(phone_talk* array[], int size)
	{
		for (int i = 0; i < size; i++)
		{
			delete array[i];
		}
	}

	TEST_CLASS(unittestproject)
	{
	public:
		TEST_METHOD(TestMethod1)
		{
			phone_talk* subscriptions[3];
			subscriptions[0] = build_subscription(0,23,13,0.01); 
			subscriptions[1] = build_subscription(0,0,12,0.03); 
			subscriptions[2] = build_subscription(0,0,3,0.01); 
			Assert::AreEqual(0.0001695076, process(subscriptions, 3),1);
			delete_subscription(subscriptions, 3);

		}
		TEST_METHOD(TestMethod2)
		{
			phone_talk* subscriptions[3];
			subscriptions[0] = build_subscription(0, 46, 21, 0.03);
			subscriptions[1] = build_subscription(0, 34, 1, 0.01);
			subscriptions[2] = build_subscription(1, 23, 3, 0.04);
			Assert::AreEqual(0.0005153153, process(subscriptions, 3),1);
			delete_subscription(subscriptions, 3);

		}
		TEST_METHOD(TestMethod3)
		{
			phone_talk* subscriptions[3];
			subscriptions[0] = build_subscription(1, 1, 2, 0.01);
			subscriptions[1] = build_subscription(0, 12, 11, 0.03);
			subscriptions[2] = build_subscription(0, 49, 35, 0.04);
			Assert::AreEqual(0.0004016241, process(subscriptions, 3), 1);
			delete_subscription(subscriptions, 3);

		}
	};
}

