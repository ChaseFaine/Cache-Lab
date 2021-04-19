class Cache
{
   private:
      Set * sets;                      //The cache is an array of sets
      int32_t numSets;                 //number of sets
      int32_t associativity;           //associativity (way)
      int32_t blockOffsetBits;         //number of bits in the block offset
      int32_t setIndexBits;            //number of bits in the set index
      int64_t getBits(int32_t start, int32_t end, int64_t source);  
   public:
      Cache(int32_t associativity, int32_t blockOffsetBits, int32_t setIndexBits);
      ~Cache();
      bool isHit(int64_t address);
      bool isEvict(int64_t address);
      void update(int64_t address);
      void print();
};
