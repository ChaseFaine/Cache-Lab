

class Set
{
   //Each line consists of a tag and a valid bit (we don't know what the actual block contents is)
   class Line
   {
      public:
         int64_t tag;
         bool valid;
   };
   private:
      //Line *lines[associativity];
      Line * lines;               //A set is an array of lines
      int32_t associativity;      //Number of lines per set (the way)
      int32_t getLineNumber(int64_t tag);
      bool firstAccess;
   public:
      Set(); 
      void initialize(int32_t associativity);
      ~Set();
      bool isHit(int64_t tag);
      bool isFull();
      void update(int64_t tag);
      void print();
};
