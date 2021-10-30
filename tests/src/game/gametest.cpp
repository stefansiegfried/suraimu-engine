#include "libsuraimuengine/libsuraimuengine.h"
#include "gtest/gtest.h"

namespace {

// The fixture for testing class Game
class GameTest : public suraimu::Game, public ::testing::Test {
protected:
  GameTest() : suraimu::Game("Foo Game", 640, 480, false) {
    // You can do set-up work for each test here.
  }

  ~GameTest() override {
    // You can do clean-up work that doesn't throw exceptions here.
  }

  // If the constructor and destructor are not enough for setting up
  // and cleaning up each test, you can define the following methods:

  void SetUp() override {
    // Code here will be called immediately after the constructor (right
    // before each test).
  }

  void TearDown() override {
    // Code here will be called immediately after each test (right
    // before the destructor).
  }

  // Objects declared here can be used by all tests in the test suite for Foo.
};

// Tests that SDL was initialized
TEST_F(GameTest, InitTest) {
  Init();
  EXPECT_EQ(is_initialized_, 1);
}

// Tests that the game window title was set correctly from constructor
TEST_F(GameTest, ConstructorTest) {
  EXPECT_EQ(game_window_title_, "Foo Game");
  EXPECT_EQ(game_window_width_, 640);
  EXPECT_EQ(game_window_height_, 480);
}

} // namespace