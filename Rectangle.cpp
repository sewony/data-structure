#include "Rectangle.h";
Rectangle::Rectangle() {//생성자
	x = 0;
	y = 0;
	width = 0;
	height = 0;
}
Rectangle::~Rectangle() {//소멸자

}
Rectangle Rectangle::operator+(Rectangle& r) // +연산자 오버로딩
{
	Rectangle rect;
	if (x <= r.x) {//두 사각형의 시작점을 비교하여 더 작은 값을 가진 x좌표를 rect.x에 넣음
		rect.x = x;
	}
	else if (r.x < x) {
		rect.x = r.x;
	}
	if (y <= r.y) {//두 사각형의 시작점을 비교하여 더 작은 값을 가진 y좌표를 rect.y에 넣음
		rect.y = y;
	}
	else if (r.y < y) {
		rect.y = r.y;
	}
	if ((x + width) <= (r.x + r.width)) {//두 사각형의 시작점x좌표+width 를 비교하여 더 큰 값을 가진 것에서 rect.x를 빼서rect.width를 구함
		rect.width = r.x + r.width - rect.x;
	}
	else if ((r.x + r.width) < (x + width)) {
		rect.width = x + width - rect.x;
	}
	if ((y + height) <= (r.y + r.height)) {//두 사각형의 시작점y좌표+height 를 비교하여 더 큰 값을 가진 것에서 rect.y를 빼서rect.height를 구함
		rect.height = r.y + r.height - rect.y;
	}
	else if ((r.y + r.y) < (y + width)) {
		rect.height = y + height - rect.y;
	}
	return rect;
}
Rectangle Rectangle::operator/(Rectangle& r) // /연산자 오버로딩
{
	Rectangle rect;
	if((r.x >= x + width)|| (x >= r.x + r.width)||(r.y >= y + height)|| (y >= r.y + r.height)){//서로 겹치는 부분이 없다면 모든걸 0으로 초기화
		rect.x = 0;
		rect.y = 0;
		rect.width = 0;
		rect.height = 0;
	}
	else {
		if (x < r.x) {//두 사각형의 시작점을 비교하여 더 큰 값을 가진 x좌표를 rect.x에 넣음
			rect.x = r.x;
		}
		else if (r.x <= x) {
			rect.x = x;
		}
		if (y < r.y) {//두 사각형의 시작점을 비교하여 더 큰 값을 가진 y좌표를 rect.y에 넣음
			rect.y = r.y;
		}
		else if (r.y <= y) {
			rect.y = y;
		}
		if ((x + width) < (r.x + r.width)) {//두 사각형의 시작점x좌표+width 를 비교하여 더 작은 값을 가진 것에서 rect.x를 빼서rect.width를 구함
			rect.width = x + width - rect.x;
		}
		else if ((r.x + r.width) <= (x + width)) {
			rect.width = r.x + r.width - rect.x;
		}
		if ((y + height) < (r.y + r.height)) {//두 사각형의 시작점y좌표+height 를 비교하여 더 작은 값을 가진 것에서 rect.y를 빼서rect.height를 구함
			rect.height = y + height - rect.y;
		}
		else if ((r.y + r.height) <= (y + height)) {
			rect.height = r.y + r.height - rect.y;
		}
	}
	return rect;
}
bool Rectangle::operator==(Rectangle& r) // ==연산자 오버로딩
{
	if (this == &r)
		return true;
	if ((x == r.x) && (y == r.y) && (height == r.height) && (width == r.width))
		return true;
	else
		return false;
}
ostream& operator<<(ostream& os, Rectangle& r) //<<연산자 오버로딩
{
	os << "X: " << r.x << " Y: " << r.y << " WIDTH: " << r.width << " HEIGHT: " << r.height << endl;
	return os;
}
void Rectangle::read()
{
	cout << "INPUT X: ";
	cin >> x;
	cout << "INPUT Y: ";
	cin >> y;
	cout << "INPUT WIDTH: ";
	cin >> width;
	cout << "INPUT HEIGHT:";
	cin >> height;
}
void Rectangle::print()
{
	cout << "X: " << x << " Y: " << y << " WIDTH: " << width << " HEIGHT: " << height;
}
void Rectangle::getArea()
{
	cout << " AREA: " << width * height << endl;
}