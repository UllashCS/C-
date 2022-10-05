#ifndef SAMPLEAPPLICATION_CPP
#define SAMPLEAPPLICATION_CPP

void normalFunction();
void friendFunction();

class SampleApplication {
public:
    void setPriVar (int in_priVar) {
        m_priVar = in_priVar;
    }

    int getPriVar() {
        return m_priVar;
    }

    friend void friendFunction();

private:
    int m_priVar;
};

#endif
