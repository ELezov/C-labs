// Point.h 
class Point {
public:
	// Конструктор 
	Point(double _х = 0, double _у = 0) : x(_х), y(_у) {}
	// Другие методы 
	void Show() const;
	void operator +=(Point&);

public:
	double x, y;
};
