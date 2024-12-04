class Day1{
    private:
        struct List{ // sorted linked list (head is smallest entry)
            struct Node{
                unsigned int value;
                Node* next;
                unsigned int simularityScore;
                bool simularityScoreCalculated;

                Node(unsigned int input); //constructer
                ~Node(); //destructer
            };
            Node* head;
             
            void addSortedNode(unsigned int value); // automatically add to correct position

            List();
            ~List();
        };
        List list1;
        List list2;

        unsigned int getDiff(List::Node* node1, List::Node* node2);
        void calculateSimularityScore();
    public:
        void addNodePair(unsigned int value1, unsigned int value2);
        unsigned int getTotalDiff();
        unsigned int getTotalSimularityScore();

        Day1();
        ~Day1();
};
