#include "Enemy1.h"

namespace my
{
    class EnemyPool
    {
    public:

        EnemyPool(int poolSize);
        ~EnemyPool();

        my::Enemy1* GetEnemy();

        void Reset() 
        {
            index = 0;
        }

     private:
        std::vector<my::Enemy1*> pool; // 에너미 배열
        int index = 0;
    };
}