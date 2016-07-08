#include <iostream>

#include "cardapplet.h"
#include "installer.h"
#include "readijc.h"

using namespace std;

int
testReadIJC(char* ijcFileName)
{
  unsigned char *dataBuffer = new unsigned char[10000];
  int len = readBin(ijcFileName, dataBuffer);

  if (len == -1)
  {
    cout << "Error in readBin()" << endl;
    return 1;
  }
  //outputHex(dataBuffer,iDataLength);
  CardApplet* capp = (CardApplet*) buildApplet(dataBuffer, len);
  if (capp->pHeader == NULL)
  {
    cout << "Error in buildApplet()" << endl;
    return 1;
  }

  // Could check some of this info later on
  //capp->displayInfo();

  return 0;
}

int
main(int argc, char **argv)
{
  if (argc < 2)
  {
    cout << "Usage: test_readijc <path to ShortAdd.ijc>" << endl;
    exit(2);
  }

  return testReadIJC(argv[1]);
}