// Point.h 
class Point {
public:
	// ����������� 
	Point(double _� = 0, double _� = 0) : x(_�), y(_�) {}
	// ������ ������ 
	void Show() const;
	void operator +=(Point&);

public:
	double x, y;
};
