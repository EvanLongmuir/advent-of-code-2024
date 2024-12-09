#include <string>
class Calibrations{
    private:
        struct Equation{
            struct Number{
                Number* next;

                unsigned long value;

                Number(unsigned long value);
            };
            Equation* next;
            Number* head;
            void addNumber(unsigned long number);

            bool checkValid(Number* number, unsigned long currentResult = 0);

            unsigned long value;

            Equation(unsigned long value);
            ~Equation();
        };
        Equation* head;
        void newEquation(unsigned long result);
        void addToEquation(unsigned long value);
    public:
        void readLine(std::string line);
        unsigned long getSum();

        ~Calibrations();
};
