#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unittestproject
{
	phone_talk* build_subscription(int duration_hour, int duration_minute, int duration_second, double cost)
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
			subscriptions[0] = build_subscription(0, 23, 13, 0.65);
			subscriptions[1] = build_subscription(0, 0, 12, 0.03);
			subscriptions[2] = build_subscription(0, 0, 3, 0.01);
			Assert::AreEqual(0.000490057, process(subscriptions, 3), 1);
			delete_subscription(subscriptions, 3);

		}
		TEST_METHOD(TestMethod2)
		{
			phone_talk* subscriptions[3];
			subscriptions[0] = build_subscription(0, 46, 21, 0.97);
			subscriptions[1] = build_subscription(0, 34, 1, 0.78);
			subscriptions[2] = build_subscription(0, 23, 3, 0.61);
			Assert::AreEqual(0.000380338, process(subscriptions, 3), 1);
			delete_subscription(subscriptions, 3);

		}
		TEST_METHOD(TestMethod3)
		{
			phone_talk* subscriptions[3];
			subscriptions[0] = build_subscription(1, 1, 2, 1.31);
			subscriptions[1] = build_subscription(0, 12, 11, 5.03);
			subscriptions[2] = build_subscription(0, 49, 35, 0.99);
			Assert::AreEqual(0.000994843, process(subscriptions, 3), 1);
			delete_subscription(subscriptions, 3);

		}
	};
}
