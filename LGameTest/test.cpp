#include "pch.h"


#include "gtest/gtest.h"

#include "../LGame/Cell.h"

TEST(TestCaseName, TestName) {

	Cell newcell;
	
	newcell.setBoardPosition(3, 3);
	newcell.setDataType(0);
	newcell.setup();



	EXPECT_EQ(newcell.getBox().getPosition().x, 100);
	/*EXPECT_EQ(r.position.y, 100);
	EXPECT_EQ(r.getrcolor(), sf::Color::Red);
	EXPECT_EQ(r.position.x, 100);
	EXPECT_EQ(r.position.x, 100);
*/

  EXPECT_TRUE(true);
}

