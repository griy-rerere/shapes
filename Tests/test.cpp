#include <iostream>
#include <gtest/gtest.h>
#include "../Source/Matrix.h"

// TEST (Matrix, CreateSquare)
// {
// 	const size_t R = 128;
// 	const size_t C = 128;
// 	Matrix m(R, C);
// 	for (size_t r = 0; r < R; ++r)
// 		for (size_t c = 0; c < C; ++c)
// 			ASSERT_FALSE (m.get(r, c));
// }

// TEST (Matrix, CreateRow)
// {
// 	const size_t C = 128;
// 	Matrix m(1, C);
// 	for (size_t c = 0; c < C; ++c)
// 		ASSERT_FALSE (m.get(0, c));

// }

// TEST (Matrix, CreateCol)
// {
// 	const size_t R = 128;
// 	Matrix m(R, 1);
// 	for (size_t r = 0; r < R; ++r)
// 		ASSERT_FALSE (m.get(r, 0));
// }

// TEST (Matrix, SetGetSquare)
// {
// 	const size_t R = 128;
// 	const size_t C = 128;
// 	Matrix m(R, C);
// 	for (size_t r = 0; r < R; ++r)
// 		for (size_t c = 0; c < C; ++c)
// 		{
// 			auto val = static_cast<bool>((r + c) % 2);
// 			m.set(r, c, val);
// 			ASSERT_FALSE (m.get(r, c) != val);
// 		}
// }

// TEST (Matrix, GetIncorrect)
// {
// 	const size_t R = 128;
// 	const size_t C = 128;
// 	Matrix m(R, C);
// 	ASSERT_THROW (m.get(129, 1), std::out_of_range);
// }


#include "../Source/App.h"
#include <cmath>

TEST(PointDistance, SamePoint) {
    App app;
    Identi p1 = app.addObject(PrimitiveType::POINT);
    
    Storage<Point<double>>& points = const_cast<Storage<Point<double>>&>(app.getPoints());
    Point<double>* point = app.findObjectById(p1, points);
    point->set_x(0);
    point->set_y(0);
    
    Storage<Identi> ids;
    ids.addItem(p1);
    ids.addItem(p1);
    
    EXPECT_DOUBLE_EQ(app.measure(MutualArrangeType::POINTDISTANCE, ids), 0.0);
}

TEST(PointCoincident, SamePoint) {
    App app;
    Identi p1 = app.addObject(PrimitiveType::POINT);
    
    Storage<Point<double>>& points = const_cast<Storage<Point<double>>&>(app.getPoints());
    Point<double>* point = app.findObjectById(p1, points);
    point->set_x(0);
    point->set_y(0);
    
    Storage<Identi> ids;
    ids.addItem(p1);
    ids.addItem(p1);
    
    EXPECT_DOUBLE_EQ(app.measure(MutualArrangeType::POINTCOINCIDENT, ids), 0.0);
}

TEST(PointCoincident, DifferentPoints) {
    App app;
    Identi p1 = app.addObject(PrimitiveType::POINT);
    Identi p2 = app.addObject(PrimitiveType::POINT);
    
    Storage<Point<double>>& points = const_cast<Storage<Point<double>>&>(app.getPoints());
    Point<double>* point1 = app.findObjectById(p1, points);
    Point<double>* point2 = app.findObjectById(p2, points);
    
    point1->set_x(1);
    point1->set_y(2);
    point2->set_x(4);
    point2->set_y(6);
    
    Storage<Identi> ids;
    ids.addItem(p1);
    ids.addItem(p2);
    
    double distance = app.measure(MutualArrangeType::POINTCOINCIDENT, ids);
    EXPECT_DOUBLE_EQ(distance, 5.0);
}
