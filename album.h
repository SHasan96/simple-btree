#ifndef ALBUM
#define ALBUM

#include <cstring>
#include <string>
#include <fstream>
using namespace std;

const int UpTo = 50;
typedef char String[UpTo];

class Album
{
   public :
       Album (const Album& otherAlbum);
       Album (const String upc, const String artist, const String title); 
       Album ();
       Album & operator = (const Album& otherAlbum);
       friend bool operator < (const Album& a, const Album& b);
       friend bool operator > (const Album& a, const Album& b); 
       friend bool operator == (const Album& a, const Album& b); 
       friend istream & operator >> (istream & stream, Album & C);  
       friend ostream & operator << (ostream & stream, const Album & C);
       friend string padUPC(const string str, const int desiredLength); 
       string getUPC () const; 
       int recordSize() const; 

   private :
       String UPC, Artist, Title;
};
#endif
