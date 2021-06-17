@author Hanseungjin

struct CharPosition
{
	int x, y;
	CharPosition(int col, int row) : x(col), y(row) {}
	CharPosition() : x(0), y(0) {}
};

class cell{
public:
  CharPosition tmp;
  char val;
  cell(CharPosition newtmp , char value){
		tmp.x = newtmp.x;
		tmp.y = newtmp.y;
		val = value;
	}
};
