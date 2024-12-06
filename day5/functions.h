#import <string>

class Manual{
    private:
        struct Rule{
            Rule* next;
            int rules[2];

            Rule(int rules[2]);
        };
        struct Update{
            struct Page{
                Page* next;
                Page* last;
                int value;

                Page(int value);
            };
            Page* pages;
            Update* next;

            bool valid;
            int numPages;
            int middleValue;

            void addPage(int value);
            void updateMiddleValue();

            Update();
            ~Update();
        };
        Rule* rules;
        Update* updates;

        void addRule(std::string line);
        void addUpdate(std::string line);
        void checkRules();
    public:
        void readLine(std::string line);
        int addMiddleValues(bool valid);

        Manual();
        ~Manual();
};
