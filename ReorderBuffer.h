#ifndef GENERAL_LIBS_DEFS
#define GENERAL_LIBS_DEFS

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;
#endif

//struct to hold the data of each element in the ROB queue
struct ROB_element
{
public:
  ROB_element() : valid(), inst(), ROB_ID() {} //default constructor
  ROB_element(int validity, string The_inst, int The_ROB_ID) : valid(validity), inst(The_inst), ROB_ID(The_ROB_ID) {} //overlaoded constructor

  int valid;
  string inst;
  int ROB_ID;
};

//STL structure used to maintain a vector in the pipeline, such that the instructions are inserted and retired inorder. Instructions are inserted at fetch, removed at commit when valid. An example of the contents in the ROB are shown below.
class ReorderBuffer
{
public:
  ReorderBuffer();
  ~ReorderBuffer();

protected:
  deque<ROB_element> ROB; // deque used to manually force FIFO and allow for use of []
  void set_ROB_element(string inst, int PC_num);
};
