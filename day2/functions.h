#include <cmath>

class Day2{
    private:
        struct Report{
            struct Level{
                int value;
                Level* next;
                Level* last;
                bool safe;

                bool spreadBool();

                Level(int input);
                ~Level();
            };
            Level* head;
            Report* next;
            bool safe;

            void addLevel(int value);

            Report();
            ~Report();
        };
        Report* head;
    public:
        int numSafe;

        void addToReport(int value);
        void newReport();

        Day2();
        ~Day2();
};
