// 3.7 An animal shelter holds only dogs and cats, and operates on a strictly "first in, first
// out" basis. People must dopt either the "oldest" (based on arrival time) of all animals
// at the shelter, or they can select whether they would prefer a dog or a cat (and will
// receive the oldest animal of that type). They canno select which specific animal they
// would like. Create the data structures to maintain this system and implement ooperattions 
// such as enqueue, dequeueAny, dequeueDog and dequeueCat. You may use the built-in 
// LinkedList data structure.

#include "..\inc\utils.h"
#include <queue>
using namespace std;

enum AnimalType
{
    Dog = 0, 
    Cat, 
    Error
};

class Animal
{
public:
    Animal(AnimalType iType, int iOrder) :Type(iType), order(iOrder) {}
    int getOrder() { return order; }
private: 
    int order;
    AnimalType Type;
};

class ManageQueue
{    
public:
    ManageQueue() :order(0) {}

    void enqueue(AnimalType at)
    {
        Animal tA(at, order++);
        if (Dog == at) {            
            DogQueue.push(tA);
        } else if (Cat == at) {
            CatQueue.push(tA);
        }
    }

    Animal dequeueDog()
    {
        if (!DogQueue.empty()) {
            Animal tA = DogQueue.front();
            DogQueue.pop();
            return tA;
        } else {
            printf("sorry dog queue is empty.\n");
        }
    }

    Animal dequeueCat()
    {
        if (!CatQueue.empty()) {
            Animal tA = CatQueue.front();
            CatQueue.pop();
            return tA;
        } else {
            printf("sorry cat queue is empty.\n");
        }
    }

    Animal dequeueAny()
    {
        if (CatQueue.empty() && !DogQueue.empty()) {
            return dequeueDog();
        } else if (!CatQueue.empty() && DogQueue.empty()) {
            return dequeueCat();
        } else if (CatQueue.empty() && DogQueue.empty()) {
            printf("All our queue are empty.\n");
        } else {
            Animal tC = CatQueue.front();   
            Animal tD = DogQueue.front();
            if (tC.getOrder() < tD.getOrder) {
                Animal tA = tC;
                dequeueCat();
                return tA;
            } else {
                Animal tA = tD;
                dequeueDog();
                return tA;
            }            
        }
    }
private: 
    queue<Animal>  DogQueue;
    queue<Animal> CatQueue;
    int order;
};

int C3Q7()
{
    cout << "C3Q7" << endl;
    return 0;
}