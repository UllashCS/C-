#ifndef MOCKMATHOPS_HPP
#define MOCKMATHOPS_HPP
#include <gmock/gmock.h>

class MockMathOpsC {
    public:
    MOCK_METHOD(int, AddoToN, (int num));
    MOCK_METHOD(int, Fact, (int num));
	MOCK_METHOD(void, fake_memset, (void * ptr, char set,int size));
};

class MockMathOpsCEnv {
	public:
		MockMathOpsCEnv() {
			__mockMathOps_instance = std::make_shared<MockMathOpsC>();
		}
		virtual ~MockMathOpsCEnv() {
			__mockMathOps_instance.reset();
		}
		static std::shared_ptr<MockMathOpsC> GetInstance() {
			return __mockMathOps_instance;
		}
	private:
		static std::shared_ptr<MockMathOpsC> __mockMathOps_instance;
};

#endif