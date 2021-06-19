//@author Hanseungjin(20181512)

struct myposition
{
	int x, y;
	myposition(int col, int row) : x(col), y(row) {}
	myposition() : x(0), y(0) {}
};

class cell{
public:
  myposition tmp;
  char val;
  cell(myposition newtmp , char value){
		tmp.x = newtmp.x;
		tmp.y = newtmp.y;
		val = value;
	}
};
