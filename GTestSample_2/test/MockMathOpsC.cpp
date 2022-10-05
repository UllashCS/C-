#include "../src/UtilsC.hpp"
#include "MockMathOpsC.hpp"

std::shared_ptr<MockMathOpsC> MockMathOpsCEnv::__mockMathOps_instance;

int AddoToN (int num){
    return MockMathOpsCEnv::GetInstance()->AddoToN(num);
}

int Fact(int num){
    return MockMathOpsCEnv::GetInstance()->Fact(num);
}

void fake_memset (void * ptr, char set,int size) {

    if (NULL != ptr) {
        for (int i = 0; i < 10* sizeof(int); i++) {
            *(((char*)ptr)+i) = set;
        }

        MockMathOpsCEnv::GetInstance()->fake_memset(ptr, set, size);
    }
}