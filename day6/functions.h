#include <string>

enum Direction{
    UP = 0,
    RIGHT = 1,
    DOWN = 2,
    LEFT = 3,
};

Direction operator++(Direction& s, int);
Direction operator--(Direction& s, int);

class Grid{
    private:
        struct Node {
            Node* next[4];

            bool obstacle;
            bool visted;

            int x;
            int y;

            Node(int x, int y, bool obstacle);
            Node();
        };
        struct Guard {
            struct Path{
                int x;
                int y;
                Direction facing;

                Path* next;

                Path(int x, int y, Direction facing);
            };
            Path* head;
            // adds Path to visted path
            // returns false if duplicate path
            bool addPath();

            Direction dir;
            unsigned int nodesVisted;

            Node* startingNode;
            Node* currentNode;

            // move one time returns true if leaving non-visted node
            // also returns false if hitting nullptr
            bool move();

            Guard(Node* pos);
            ~Guard();
        };
        Node* head;
        Guard guard;

        int xDim;
        int yDim;

        unsigned int loopNodes;

        bool addObstacle(int x, int y);
        bool removeObstacle(int x, int y);

        // simulatePath returns false when in a loop
        bool simulatePath();

        void addNode(bool obstacle = false, bool newLine = false);
        void setGuardPos();
    public:
        unsigned int getNodesVisted();
        unsigned int getLoopNodes();

        //constructor and helper functions
        void readLine(std::string line);
        Grid();
        ~Grid();
};
