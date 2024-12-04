// for file reading
#include <iostream>
#include <fstream>

class MemoryReader{
    private:
        struct Mul{
            int num1,num2;
            int product;
            Mul* next;

            Mul(int num1, int num2);
            ~Mul();
        };

        Mul* head;
        int sum;
        bool enable;

        void addMul(int num1, int num2);
        unsigned int onCharM(std::string line, unsigned int pos);
        unsigned int onCharD(std::string line, unsigned int pos);

    public:
        void readLine(std::string line);
        int getSum();
        
        MemoryReader();
        ~MemoryReader();
};
